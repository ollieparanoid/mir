/*
 * Copyright © 2018 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 2 or 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Christopher James Halse Rogers <christopher.halse.rogers@canonical.com>
 */

#ifndef MIR_PLATFORM_TEXTURE_H_
#define MIR_PLATFORM_TEXTURE_H_

namespace mir
{
namespace graphics
{
namespace gl
{

class Program;
class ProgramFactory;

/**
 * A buffer containing a GL-renderable texture, and the shader program required to render it.
 */
class Texture
{
public:
    Texture() = default;
    virtual ~Texture();

    Texture(Texture const&) = delete;
    Texture& operator=(Texture const&) = delete;

    /**
     * Get the shader program required to render from this texture.
     *
     * The returned Program must have been constructed from a ProgramFactory passed in a
     * call to shader(). It need not be reconstructed each call; indeed, since shader compilation
     * is relatively expensive, implementations are encouraged to construct a program exactly
     * once for each unique shader snippet.
     *
     * \see ProgramFactory::compile_fragment_shader()
     *
     * \param [in] factory  Factory to turn the required shader snippet into a full Program
     * \return  A reference to a Program, which *must* have been generated by factory
     */
    virtual Program const& shader(ProgramFactory& factory) const = 0;

    virtual bool y_inverted() const = 0;

    /**
     * Bind this texture to the necessary texture unit(s)
     *
     * This is called immediately prior to texturing the window primitive(s) using the
     * shader program.
     */
    virtual void bind() = 0;

    /**
     * Called by the renderer immediately *after* the texture has been used in a GL call.
     *
     * This may be useful for the platform if some synchronisation is required around texture use.
     */
    virtual void add_syncpoint() = 0;
};
}
}
}

#endif //MIR_PLATFORM_TEXTURE_H_
