/*
 * Copyright © 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Thomas Voss <thomas.voss@canonical.com>
 *              Alan Griffiths <alan@octopull.co.uk>
 */

#ifndef MIR_TEST_STUB_SERVER_H_
#define MIR_TEST_STUB_SERVER_H_

#include "mir_protobuf.pb.h"
#include "mir/thread/all.h" 

namespace mir
{
namespace test
{

struct MockServerTool : mir::protobuf::DisplayServer
{
    virtual void create_surface(google::protobuf::RpcController* /*controller*/,
                 const mir::protobuf::SurfaceParameters* request,
                 mir::protobuf::Surface* response,
                 google::protobuf::Closure* done)
    {
        printf("hthing...\n");
        response->mutable_id()->set_value(13); // TODO distinct numbers & tracking
        response->set_width(request->width());
        response->set_height(request->height());
        response->set_pixel_format(request->pixel_format());
        response->mutable_buffer()->set_buffer_id(22);

        std::unique_lock<std::mutex> lock(guard);
        surface_name = request->surface_name();
        wait_condition.notify_one();

        done->Run();
    }

    virtual void next_buffer(
        ::google::protobuf::RpcController* /*controller*/,
        ::mir::protobuf::SurfaceId const* /*request*/,
        ::mir::protobuf::Buffer* response,
        ::google::protobuf::Closure* done)
    {
        response->set_buffer_id(22);

        std::unique_lock<std::mutex> lock(guard);
        wait_condition.notify_one();
        done->Run();
    }


    virtual void release_surface(::google::protobuf::RpcController* /*controller*/,
                         const ::mir::protobuf::SurfaceId* /*request*/,
                         ::mir::protobuf::Void* /*response*/,
                         ::google::protobuf::Closure* /*done*/)
    {
        // TODO need some tests for releasing surfaces
    }


    virtual void connect(
        ::google::protobuf::RpcController*,
                         const ::mir::protobuf::ConnectParameters* request,
                         ::mir::protobuf::Connection*,
                         ::google::protobuf::Closure* done)
    {
        printf("hthing...connect\n");
        app_name = request->application_name();
        done->Run();
    }

    virtual void disconnect(google::protobuf::RpcController* /*controller*/,
                 const mir::protobuf::Void* /*request*/,
                 mir::protobuf::Void* /*response*/,
                 google::protobuf::Closure* done)
    {
        std::unique_lock<std::mutex> lock(guard);
        wait_condition.notify_one();
        done->Run();
    }

    std::mutex guard;
    std::string surface_name;
    std::condition_variable wait_condition;
    std::string app_name;
};

}
}
#endif /* MIR_TEST_STUB_SERVER_H_ */
