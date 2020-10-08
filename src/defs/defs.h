#pragma once

#include "pch.h"

namespace Split
{
	class VertexArray;
	class VertexBuffer;
	class IndexBuffer;
	class Shader;
};

// OpenGL Buffer Usage Hints
#define STATIC_DRAW 0x88E4

// OpenGL Texture Types
#define TEXTURE_2D 0x0DE1

using va_ref = std::shared_ptr<Split::VertexArray>;
using ib_ref = std::shared_ptr<Split::IndexBuffer>;
using vb_ref = std::shared_ptr<Split::VertexBuffer>;
using shader_ref = std::shared_ptr<Split::Shader>;
