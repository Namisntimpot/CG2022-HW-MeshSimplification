/*
* Generated by python
* Any changes to this file will be overwritten by the next python run
*/

#pragma once

#include "../../config.h"
#if 0\
|| (defined(GL_TRIANGLES))\
|| (defined(GL_LINES))\
|| (defined(GL_POINTS))
namespace Ubpa::gl {
	enum class BasicPrimitiveType : GLenum {
#ifdef GL_TRIANGLES
		Triangles = GL_TRIANGLES,
#endif
#ifdef GL_LINES
		Lines = GL_LINES,
#endif
#ifdef GL_POINTS
		Points = GL_POINTS,
#endif
	};
}
#endif

