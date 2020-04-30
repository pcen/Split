#ifndef DEFS_H
#define DEFS_H

#include "pch.h"

/* Forward declarations
 */
namespace Split
{
	class VertexArray;
	class VertexBuffer;
	class IndexBuffer;
	class Shader;
};

/* OpenGL draw modes
 */
#define STATIC_DRAW 0x88E4

/* OpenGL texture types
 */
#define TEXTURE_2D 0x0DE1

/* Ref names
 */
typedef std::shared_ptr<Split::VertexArray> va_ref;
typedef std::shared_ptr<Split::IndexBuffer> ib_ref;
typedef std::shared_ptr<Split::VertexBuffer> vb_ref;
typedef std::shared_ptr<Split::Shader> shader_ref;

#endif /* DEFS_H */
