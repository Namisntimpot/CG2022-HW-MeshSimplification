/*
* Generated by python
* Any changes to this file will be overwritten by the next python run
*/

#pragma once

#include "../../config.h"
#if 0\
|| (defined(GL_KEEP))\
|| (defined(GL_ZERO))\
|| (defined(GL_REPLACE))\
|| (defined(GL_INCR))\
|| (defined(GL_DECR))\
|| (defined(GL_INVERT))\
|| (defined(GL_INCR_WRAP))\
|| (defined(GL_DECR_WRAP))
namespace Ubpa::gl {
	enum class StencilOperation : GLenum {
#ifdef GL_KEEP
		Keep = GL_KEEP,
#endif
#ifdef GL_ZERO
		Zero = GL_ZERO,
#endif
#ifdef GL_REPLACE
		Replace = GL_REPLACE,
#endif
#ifdef GL_INCR
		Incr = GL_INCR,
#endif
#ifdef GL_DECR
		Decr = GL_DECR,
#endif
#ifdef GL_INVERT
		Invert = GL_INVERT,
#endif
#ifdef GL_INCR_WRAP
		IncrWrap = GL_INCR_WRAP,
#endif
#ifdef GL_DECR_WRAP
		DecrWrap = GL_DECR_WRAP,
#endif
	};
}
#endif
