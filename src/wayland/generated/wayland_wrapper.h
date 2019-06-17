/*
 * AUTOGENERATED - DO NOT EDIT
 *
 * This file is generated from wayland.xml
 * To regenerate, run the “refresh-wayland-wrapper” target.
 */

#ifndef MIR_FRONTEND_WAYLAND_WAYLAND_XML_WRAPPER
#define MIR_FRONTEND_WAYLAND_WAYLAND_XML_WRAPPER

#include <experimental/optional>

#include "mir/fd.h"
#include <wayland-server-core.h>

#include "mir/wayland/wayland_base.h"

namespace mir
{
namespace wayland
{

class Callback : public Resource
{
public:
    static char const constexpr* interface_name = "wl_callback";

    static Callback* from(struct wl_resource*);

    Callback(struct wl_resource* resource, Version<1>);
    Callback(struct wl_client* client, int runtime_version, Version<1> static_version);
    virtual ~Callback() = default;

    void send_done_event(uint32_t callback_data) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Opcode
    {
        static uint32_t const done = 0;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
};

class Compositor : public Resource
{
public:
    static char const constexpr* interface_name = "wl_compositor";

    static Compositor* from(struct wl_resource*);

    Compositor(struct wl_resource* resource, Version<4>);
    Compositor(struct wl_client* client, int runtime_version, Version<4> static_version);
    virtual ~Compositor() = default;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Thunks;

    static bool is_instance(wl_resource* resource);

    class Global : public wayland::Global
    {
    public:
        Global(wl_display* display, Version<4>);

        auto interface_name() const -> char const* override;

    private:
        virtual void bind(wl_resource* new_wl_compositor) = 0;
        friend Compositor::Thunks;
    };

private:
    virtual void create_surface(struct wl_resource* id) = 0;
    virtual void create_region(struct wl_resource* id) = 0;
};

class ShmPool : public Resource
{
public:
    static char const constexpr* interface_name = "wl_shm_pool";

    static ShmPool* from(struct wl_resource*);

    ShmPool(struct wl_resource* resource, Version<1>);
    ShmPool(struct wl_client* client, int runtime_version, Version<1> static_version);
    virtual ~ShmPool() = default;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void create_buffer(struct wl_resource* id, int32_t offset, int32_t width, int32_t height, int32_t stride, uint32_t format) = 0;
    virtual void destroy() = 0;
    virtual void resize(int32_t size) = 0;
};

class Shm : public Resource
{
public:
    static char const constexpr* interface_name = "wl_shm";

    static Shm* from(struct wl_resource*);

    Shm(struct wl_resource* resource, Version<1>);
    Shm(struct wl_client* client, int runtime_version, Version<1> static_version);
    virtual ~Shm() = default;

    void send_format_event(uint32_t format) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Error
    {
        static uint32_t const invalid_format = 0;
        static uint32_t const invalid_stride = 1;
        static uint32_t const invalid_fd = 2;
    };

    struct Format
    {
        static uint32_t const argb8888 = 0;
        static uint32_t const xrgb8888 = 1;
        static uint32_t const c8 = 0x20203843;
        static uint32_t const rgb332 = 0x38424752;
        static uint32_t const bgr233 = 0x38524742;
        static uint32_t const xrgb4444 = 0x32315258;
        static uint32_t const xbgr4444 = 0x32314258;
        static uint32_t const rgbx4444 = 0x32315852;
        static uint32_t const bgrx4444 = 0x32315842;
        static uint32_t const argb4444 = 0x32315241;
        static uint32_t const abgr4444 = 0x32314241;
        static uint32_t const rgba4444 = 0x32314152;
        static uint32_t const bgra4444 = 0x32314142;
        static uint32_t const xrgb1555 = 0x35315258;
        static uint32_t const xbgr1555 = 0x35314258;
        static uint32_t const rgbx5551 = 0x35315852;
        static uint32_t const bgrx5551 = 0x35315842;
        static uint32_t const argb1555 = 0x35315241;
        static uint32_t const abgr1555 = 0x35314241;
        static uint32_t const rgba5551 = 0x35314152;
        static uint32_t const bgra5551 = 0x35314142;
        static uint32_t const rgb565 = 0x36314752;
        static uint32_t const bgr565 = 0x36314742;
        static uint32_t const rgb888 = 0x34324752;
        static uint32_t const bgr888 = 0x34324742;
        static uint32_t const xbgr8888 = 0x34324258;
        static uint32_t const rgbx8888 = 0x34325852;
        static uint32_t const bgrx8888 = 0x34325842;
        static uint32_t const abgr8888 = 0x34324241;
        static uint32_t const rgba8888 = 0x34324152;
        static uint32_t const bgra8888 = 0x34324142;
        static uint32_t const xrgb2101010 = 0x30335258;
        static uint32_t const xbgr2101010 = 0x30334258;
        static uint32_t const rgbx1010102 = 0x30335852;
        static uint32_t const bgrx1010102 = 0x30335842;
        static uint32_t const argb2101010 = 0x30335241;
        static uint32_t const abgr2101010 = 0x30334241;
        static uint32_t const rgba1010102 = 0x30334152;
        static uint32_t const bgra1010102 = 0x30334142;
        static uint32_t const yuyv = 0x56595559;
        static uint32_t const yvyu = 0x55595659;
        static uint32_t const uyvy = 0x59565955;
        static uint32_t const vyuy = 0x59555956;
        static uint32_t const ayuv = 0x56555941;
        static uint32_t const nv12 = 0x3231564e;
        static uint32_t const nv21 = 0x3132564e;
        static uint32_t const nv16 = 0x3631564e;
        static uint32_t const nv61 = 0x3136564e;
        static uint32_t const yuv410 = 0x39565559;
        static uint32_t const yvu410 = 0x39555659;
        static uint32_t const yuv411 = 0x31315559;
        static uint32_t const yvu411 = 0x31315659;
        static uint32_t const yuv420 = 0x32315559;
        static uint32_t const yvu420 = 0x32315659;
        static uint32_t const yuv422 = 0x36315559;
        static uint32_t const yvu422 = 0x36315659;
        static uint32_t const yuv444 = 0x34325559;
        static uint32_t const yvu444 = 0x34325659;
    };

    struct Opcode
    {
        static uint32_t const format = 0;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

    class Global : public wayland::Global
    {
    public:
        Global(wl_display* display, Version<1>);

        auto interface_name() const -> char const* override;

    private:
        virtual void bind(wl_resource* new_wl_shm) = 0;
        friend Shm::Thunks;
    };

private:
    virtual void create_pool(struct wl_resource* id, mir::Fd fd, int32_t size) = 0;
};

class Buffer : public Resource
{
public:
    static char const constexpr* interface_name = "wl_buffer";

    static Buffer* from(struct wl_resource*);

    Buffer(struct wl_resource* resource, Version<1>);
    Buffer(struct wl_client* client, int runtime_version, Version<1> static_version);
    virtual ~Buffer() = default;

    void send_release_event() const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Opcode
    {
        static uint32_t const release = 0;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void destroy() = 0;
};

class DataOffer : public Resource
{
public:
    static char const constexpr* interface_name = "wl_data_offer";

    static DataOffer* from(struct wl_resource*);

    DataOffer(struct wl_resource* resource, Version<3>);
    DataOffer(struct wl_client* client, int runtime_version, Version<3> static_version);
    virtual ~DataOffer() = default;

    void send_offer_event(std::string const& mime_type) const;
    bool version_supports_source_actions();
    void send_source_actions_event(uint32_t source_actions) const;
    bool version_supports_action();
    void send_action_event(uint32_t dnd_action) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Error
    {
        static uint32_t const invalid_finish = 0;
        static uint32_t const invalid_action_mask = 1;
        static uint32_t const invalid_action = 2;
        static uint32_t const invalid_offer = 3;
    };

    struct Opcode
    {
        static uint32_t const offer = 0;
        static uint32_t const source_actions = 1;
        static uint32_t const action = 2;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void accept(uint32_t serial, std::experimental::optional<std::string> const& mime_type) = 0;
    virtual void receive(std::string const& mime_type, mir::Fd fd) = 0;
    virtual void destroy() = 0;
    virtual void finish() = 0;
    virtual void set_actions(uint32_t dnd_actions, uint32_t preferred_action) = 0;
};

class DataSource : public Resource
{
public:
    static char const constexpr* interface_name = "wl_data_source";

    static DataSource* from(struct wl_resource*);

    DataSource(struct wl_resource* resource, Version<3>);
    DataSource(struct wl_client* client, int runtime_version, Version<3> static_version);
    virtual ~DataSource() = default;

    void send_target_event(std::experimental::optional<std::string> const& mime_type) const;
    void send_send_event(std::string const& mime_type, mir::Fd fd) const;
    void send_cancelled_event() const;
    bool version_supports_dnd_drop_performed();
    void send_dnd_drop_performed_event() const;
    bool version_supports_dnd_finished();
    void send_dnd_finished_event() const;
    bool version_supports_action();
    void send_action_event(uint32_t dnd_action) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Error
    {
        static uint32_t const invalid_action_mask = 0;
        static uint32_t const invalid_source = 1;
    };

    struct Opcode
    {
        static uint32_t const target = 0;
        static uint32_t const send = 1;
        static uint32_t const cancelled = 2;
        static uint32_t const dnd_drop_performed = 3;
        static uint32_t const dnd_finished = 4;
        static uint32_t const action = 5;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void offer(std::string const& mime_type) = 0;
    virtual void destroy() = 0;
    virtual void set_actions(uint32_t dnd_actions) = 0;
};

class DataDevice : public Resource
{
public:
    static char const constexpr* interface_name = "wl_data_device";

    static DataDevice* from(struct wl_resource*);

    DataDevice(struct wl_resource* resource, Version<3>);
    DataDevice(struct wl_client* client, int runtime_version, Version<3> static_version);
    virtual ~DataDevice() = default;

    void send_data_offer_event(struct wl_resource* id) const;
    void send_enter_event(uint32_t serial, struct wl_resource* surface, double x, double y, std::experimental::optional<struct wl_resource*> const& id) const;
    void send_leave_event() const;
    void send_motion_event(uint32_t time, double x, double y) const;
    void send_drop_event() const;
    void send_selection_event(std::experimental::optional<struct wl_resource*> const& id) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Error
    {
        static uint32_t const role = 0;
    };

    struct Opcode
    {
        static uint32_t const data_offer = 0;
        static uint32_t const enter = 1;
        static uint32_t const leave = 2;
        static uint32_t const motion = 3;
        static uint32_t const drop = 4;
        static uint32_t const selection = 5;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void start_drag(std::experimental::optional<struct wl_resource*> const& source, struct wl_resource* origin, std::experimental::optional<struct wl_resource*> const& icon, uint32_t serial) = 0;
    virtual void set_selection(std::experimental::optional<struct wl_resource*> const& source, uint32_t serial) = 0;
    virtual void release() = 0;
};

class DataDeviceManager : public Resource
{
public:
    static char const constexpr* interface_name = "wl_data_device_manager";

    static DataDeviceManager* from(struct wl_resource*);

    DataDeviceManager(struct wl_resource* resource, Version<3>);
    DataDeviceManager(struct wl_client* client, int runtime_version, Version<3> static_version);
    virtual ~DataDeviceManager() = default;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct DndAction
    {
        static uint32_t const none = 0;
        static uint32_t const copy = 1;
        static uint32_t const move = 2;
        static uint32_t const ask = 4;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

    class Global : public wayland::Global
    {
    public:
        Global(wl_display* display, Version<3>);

        auto interface_name() const -> char const* override;

    private:
        virtual void bind(wl_resource* new_wl_data_device_manager) = 0;
        friend DataDeviceManager::Thunks;
    };

private:
    virtual void create_data_source(struct wl_resource* id) = 0;
    virtual void get_data_device(struct wl_resource* id, struct wl_resource* seat) = 0;
};

class Shell : public Resource
{
public:
    static char const constexpr* interface_name = "wl_shell";

    static Shell* from(struct wl_resource*);

    Shell(struct wl_resource* resource, Version<1>);
    Shell(struct wl_client* client, int runtime_version, Version<1> static_version);
    virtual ~Shell() = default;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Error
    {
        static uint32_t const role = 0;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

    class Global : public wayland::Global
    {
    public:
        Global(wl_display* display, Version<1>);

        auto interface_name() const -> char const* override;

    private:
        virtual void bind(wl_resource* new_wl_shell) = 0;
        friend Shell::Thunks;
    };

private:
    virtual void get_shell_surface(struct wl_resource* id, struct wl_resource* surface) = 0;
};

class ShellSurface : public Resource
{
public:
    static char const constexpr* interface_name = "wl_shell_surface";

    static ShellSurface* from(struct wl_resource*);

    ShellSurface(struct wl_resource* resource, Version<1>);
    ShellSurface(struct wl_client* client, int runtime_version, Version<1> static_version);
    virtual ~ShellSurface() = default;

    void send_ping_event(uint32_t serial) const;
    void send_configure_event(uint32_t edges, int32_t width, int32_t height) const;
    void send_popup_done_event() const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Resize
    {
        static uint32_t const none = 0;
        static uint32_t const top = 1;
        static uint32_t const bottom = 2;
        static uint32_t const left = 4;
        static uint32_t const top_left = 5;
        static uint32_t const bottom_left = 6;
        static uint32_t const right = 8;
        static uint32_t const top_right = 9;
        static uint32_t const bottom_right = 10;
    };

    struct Transient
    {
        static uint32_t const inactive = 0x1;
    };

    struct FullscreenMethod
    {
        static uint32_t const default_ = 0;
        static uint32_t const scale = 1;
        static uint32_t const driver = 2;
        static uint32_t const fill = 3;
    };

    struct Opcode
    {
        static uint32_t const ping = 0;
        static uint32_t const configure = 1;
        static uint32_t const popup_done = 2;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void pong(uint32_t serial) = 0;
    virtual void move(struct wl_resource* seat, uint32_t serial) = 0;
    virtual void resize(struct wl_resource* seat, uint32_t serial, uint32_t edges) = 0;
    virtual void set_toplevel() = 0;
    virtual void set_transient(struct wl_resource* parent, int32_t x, int32_t y, uint32_t flags) = 0;
    virtual void set_fullscreen(uint32_t method, uint32_t framerate, std::experimental::optional<struct wl_resource*> const& output) = 0;
    virtual void set_popup(struct wl_resource* seat, uint32_t serial, struct wl_resource* parent, int32_t x, int32_t y, uint32_t flags) = 0;
    virtual void set_maximized(std::experimental::optional<struct wl_resource*> const& output) = 0;
    virtual void set_title(std::string const& title) = 0;
    virtual void set_class(std::string const& class_) = 0;
};

class Surface : public Resource
{
public:
    static char const constexpr* interface_name = "wl_surface";

    static Surface* from(struct wl_resource*);

    Surface(struct wl_resource* resource, Version<4>);
    Surface(struct wl_client* client, int runtime_version, Version<4> static_version);
    virtual ~Surface() = default;

    void send_enter_event(struct wl_resource* output) const;
    void send_leave_event(struct wl_resource* output) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Error
    {
        static uint32_t const invalid_scale = 0;
        static uint32_t const invalid_transform = 1;
    };

    struct Opcode
    {
        static uint32_t const enter = 0;
        static uint32_t const leave = 1;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void destroy() = 0;
    virtual void attach(std::experimental::optional<struct wl_resource*> const& buffer, int32_t x, int32_t y) = 0;
    virtual void damage(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
    virtual void frame(struct wl_resource* callback) = 0;
    virtual void set_opaque_region(std::experimental::optional<struct wl_resource*> const& region) = 0;
    virtual void set_input_region(std::experimental::optional<struct wl_resource*> const& region) = 0;
    virtual void commit() = 0;
    virtual void set_buffer_transform(int32_t transform) = 0;
    virtual void set_buffer_scale(int32_t scale) = 0;
    virtual void damage_buffer(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
};

class Seat : public Resource
{
public:
    static char const constexpr* interface_name = "wl_seat";

    static Seat* from(struct wl_resource*);

    Seat(struct wl_resource* resource, Version<6>);
    Seat(struct wl_client* client, int runtime_version, Version<6> static_version);
    virtual ~Seat() = default;

    void send_capabilities_event(uint32_t capabilities) const;
    bool version_supports_name();
    void send_name_event(std::string const& name) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Capability
    {
        static uint32_t const pointer = 1;
        static uint32_t const keyboard = 2;
        static uint32_t const touch = 4;
    };

    struct Opcode
    {
        static uint32_t const capabilities = 0;
        static uint32_t const name = 1;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

    class Global : public wayland::Global
    {
    public:
        Global(wl_display* display, Version<6>);

        auto interface_name() const -> char const* override;

    private:
        virtual void bind(wl_resource* new_wl_seat) = 0;
        friend Seat::Thunks;
    };

private:
    virtual void get_pointer(struct wl_resource* id) = 0;
    virtual void get_keyboard(struct wl_resource* id) = 0;
    virtual void get_touch(struct wl_resource* id) = 0;
    virtual void release() = 0;
};

class Pointer : public Resource
{
public:
    static char const constexpr* interface_name = "wl_pointer";

    static Pointer* from(struct wl_resource*);

    Pointer(struct wl_resource* resource, Version<6>);
    Pointer(struct wl_client* client, int runtime_version, Version<6> static_version);
    virtual ~Pointer() = default;

    void send_enter_event(uint32_t serial, struct wl_resource* surface, double surface_x, double surface_y) const;
    void send_leave_event(uint32_t serial, struct wl_resource* surface) const;
    void send_motion_event(uint32_t time, double surface_x, double surface_y) const;
    void send_button_event(uint32_t serial, uint32_t time, uint32_t button, uint32_t state) const;
    void send_axis_event(uint32_t time, uint32_t axis, double value) const;
    bool version_supports_frame();
    void send_frame_event() const;
    bool version_supports_axis_source();
    void send_axis_source_event(uint32_t axis_source) const;
    bool version_supports_axis_stop();
    void send_axis_stop_event(uint32_t time, uint32_t axis) const;
    bool version_supports_axis_discrete();
    void send_axis_discrete_event(uint32_t axis, int32_t discrete) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Error
    {
        static uint32_t const role = 0;
    };

    struct ButtonState
    {
        static uint32_t const released = 0;
        static uint32_t const pressed = 1;
    };

    struct Axis
    {
        static uint32_t const vertical_scroll = 0;
        static uint32_t const horizontal_scroll = 1;
    };

    struct AxisSource
    {
        static uint32_t const wheel = 0;
        static uint32_t const finger = 1;
        static uint32_t const continuous = 2;
        static uint32_t const wheel_tilt = 3;
    };

    struct Opcode
    {
        static uint32_t const enter = 0;
        static uint32_t const leave = 1;
        static uint32_t const motion = 2;
        static uint32_t const button = 3;
        static uint32_t const axis = 4;
        static uint32_t const frame = 5;
        static uint32_t const axis_source = 6;
        static uint32_t const axis_stop = 7;
        static uint32_t const axis_discrete = 8;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void set_cursor(uint32_t serial, std::experimental::optional<struct wl_resource*> const& surface, int32_t hotspot_x, int32_t hotspot_y) = 0;
    virtual void release() = 0;
};

class Keyboard : public Resource
{
public:
    static char const constexpr* interface_name = "wl_keyboard";

    static Keyboard* from(struct wl_resource*);

    Keyboard(struct wl_resource* resource, Version<6>);
    Keyboard(struct wl_client* client, int runtime_version, Version<6> static_version);
    virtual ~Keyboard() = default;

    void send_keymap_event(uint32_t format, mir::Fd fd, uint32_t size) const;
    void send_enter_event(uint32_t serial, struct wl_resource* surface, struct wl_array* keys) const;
    void send_leave_event(uint32_t serial, struct wl_resource* surface) const;
    void send_key_event(uint32_t serial, uint32_t time, uint32_t key, uint32_t state) const;
    void send_modifiers_event(uint32_t serial, uint32_t mods_depressed, uint32_t mods_latched, uint32_t mods_locked, uint32_t group) const;
    bool version_supports_repeat_info();
    void send_repeat_info_event(int32_t rate, int32_t delay) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct KeymapFormat
    {
        static uint32_t const no_keymap = 0;
        static uint32_t const xkb_v1 = 1;
    };

    struct KeyState
    {
        static uint32_t const released = 0;
        static uint32_t const pressed = 1;
    };

    struct Opcode
    {
        static uint32_t const keymap = 0;
        static uint32_t const enter = 1;
        static uint32_t const leave = 2;
        static uint32_t const key = 3;
        static uint32_t const modifiers = 4;
        static uint32_t const repeat_info = 5;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void release() = 0;
};

class Touch : public Resource
{
public:
    static char const constexpr* interface_name = "wl_touch";

    static Touch* from(struct wl_resource*);

    Touch(struct wl_resource* resource, Version<6>);
    Touch(struct wl_client* client, int runtime_version, Version<6> static_version);
    virtual ~Touch() = default;

    void send_down_event(uint32_t serial, uint32_t time, struct wl_resource* surface, int32_t id, double x, double y) const;
    void send_up_event(uint32_t serial, uint32_t time, int32_t id) const;
    void send_motion_event(uint32_t time, int32_t id, double x, double y) const;
    void send_frame_event() const;
    void send_cancel_event() const;
    bool version_supports_shape();
    void send_shape_event(int32_t id, double major, double minor) const;
    bool version_supports_orientation();
    void send_orientation_event(int32_t id, double orientation) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Opcode
    {
        static uint32_t const down = 0;
        static uint32_t const up = 1;
        static uint32_t const motion = 2;
        static uint32_t const frame = 3;
        static uint32_t const cancel = 4;
        static uint32_t const shape = 5;
        static uint32_t const orientation = 6;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void release() = 0;
};

class Output : public Resource
{
public:
    static char const constexpr* interface_name = "wl_output";

    static Output* from(struct wl_resource*);

    Output(struct wl_resource* resource, Version<3>);
    Output(struct wl_client* client, int runtime_version, Version<3> static_version);
    virtual ~Output() = default;

    void send_geometry_event(int32_t x, int32_t y, int32_t physical_width, int32_t physical_height, int32_t subpixel, std::string const& make, std::string const& model, int32_t transform) const;
    void send_mode_event(uint32_t flags, int32_t width, int32_t height, int32_t refresh) const;
    bool version_supports_done();
    void send_done_event() const;
    bool version_supports_scale();
    void send_scale_event(int32_t factor) const;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Subpixel
    {
        static uint32_t const unknown = 0;
        static uint32_t const none = 1;
        static uint32_t const horizontal_rgb = 2;
        static uint32_t const horizontal_bgr = 3;
        static uint32_t const vertical_rgb = 4;
        static uint32_t const vertical_bgr = 5;
    };

    struct Transform
    {
        static uint32_t const normal = 0;
        static uint32_t const _90 = 1;
        static uint32_t const _180 = 2;
        static uint32_t const _270 = 3;
        static uint32_t const flipped = 4;
        static uint32_t const flipped_90 = 5;
        static uint32_t const flipped_180 = 6;
        static uint32_t const flipped_270 = 7;
    };

    struct Mode
    {
        static uint32_t const current = 0x1;
        static uint32_t const preferred = 0x2;
    };

    struct Opcode
    {
        static uint32_t const geometry = 0;
        static uint32_t const mode = 1;
        static uint32_t const done = 2;
        static uint32_t const scale = 3;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

    class Global : public wayland::Global
    {
    public:
        Global(wl_display* display, Version<3>);

        auto interface_name() const -> char const* override;

    private:
        virtual void bind(wl_resource* new_wl_output) = 0;
        friend Output::Thunks;
    };

private:
    virtual void release() = 0;
};

class Region : public Resource
{
public:
    static char const constexpr* interface_name = "wl_region";

    static Region* from(struct wl_resource*);

    Region(struct wl_resource* resource, Version<1>);
    Region(struct wl_client* client, int runtime_version, Version<1> static_version);
    virtual ~Region() = default;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void destroy() = 0;
    virtual void add(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
    virtual void subtract(int32_t x, int32_t y, int32_t width, int32_t height) = 0;
};

class Subcompositor : public Resource
{
public:
    static char const constexpr* interface_name = "wl_subcompositor";

    static Subcompositor* from(struct wl_resource*);

    Subcompositor(struct wl_resource* resource, Version<1>);
    Subcompositor(struct wl_client* client, int runtime_version, Version<1> static_version);
    virtual ~Subcompositor() = default;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Error
    {
        static uint32_t const bad_surface = 0;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

    class Global : public wayland::Global
    {
    public:
        Global(wl_display* display, Version<1>);

        auto interface_name() const -> char const* override;

    private:
        virtual void bind(wl_resource* new_wl_subcompositor) = 0;
        friend Subcompositor::Thunks;
    };

private:
    virtual void destroy() = 0;
    virtual void get_subsurface(struct wl_resource* id, struct wl_resource* surface, struct wl_resource* parent) = 0;
};

class Subsurface : public Resource
{
public:
    static char const constexpr* interface_name = "wl_subsurface";

    static Subsurface* from(struct wl_resource*);

    Subsurface(struct wl_resource* resource, Version<1>);
    Subsurface(struct wl_client* client, int runtime_version, Version<1> static_version);
    virtual ~Subsurface() = default;

    void destroy_wayland_object() const;

    struct wl_client* const client;
    struct wl_resource* const resource;

    struct Error
    {
        static uint32_t const bad_surface = 0;
    };

    struct Thunks;

    static bool is_instance(wl_resource* resource);

private:
    virtual void destroy() = 0;
    virtual void set_position(int32_t x, int32_t y) = 0;
    virtual void place_above(struct wl_resource* sibling) = 0;
    virtual void place_below(struct wl_resource* sibling) = 0;
    virtual void set_sync() = 0;
    virtual void set_desync() = 0;
};

}
}

#endif // MIR_FRONTEND_WAYLAND_WAYLAND_XML_WRAPPER
