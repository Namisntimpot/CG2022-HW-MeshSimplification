/*
* Generated by python
* Any changes to this file will be overwritten by the next python run
*/

#pragma once

#include "../../config.h"
#include "transform_feedback_type.h"
#if 0\
|| (defined(GL_TRANSFORM_FEEDBACK_BINDING))
namespace Ubpa::gl {
	enum class TransformFeedbackBinding : GLenum {
#ifdef GL_TRANSFORM_FEEDBACK_BINDING
		TransformFeedbackBinding = GL_TRANSFORM_FEEDBACK_BINDING,
#endif
	};
}
#endif

#if 0\
|| (defined(GL_TRANSFORM_FEEDBACK_BINDING) && defined(GL_TRANSFORM_FEEDBACK))
namespace Ubpa::gl {
	inline TransformFeedbackBinding BindOf(TransformFeedbackType type) {
		switch (type) {
#if defined(GL_TRANSFORM_FEEDBACK_BINDING) && defined(GL_TRANSFORM_FEEDBACK)
		case TransformFeedbackType::TransformFeedback:
			return TransformFeedbackBinding::TransformFeedbackBinding;
#endif
		}
	}
}
#endif
