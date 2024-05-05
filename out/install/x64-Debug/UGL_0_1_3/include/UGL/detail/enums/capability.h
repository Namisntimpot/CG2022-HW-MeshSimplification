/*
* Generated by python
* Any changes to this file will be overwritten by the next python run
*/

#pragma once

#include "../../config.h"
#if 0\
|| (defined(GL_BLEND))\
|| (defined(GL_CLIP_DISTANCE))\
|| (defined(GL_COLOR_LOGIC_OP))\
|| (defined(GL_CULL_FACE))\
|| (defined(GL_DEBUG_OUTPUT))\
|| (defined(GL_DEBUG_OUTPUT_SYNCHRONOUS))\
|| (defined(GL_DEPTH_CLAMP))\
|| (defined(GL_DEPTH_TEST))\
|| (defined(GL_DITHER))\
|| (defined(GL_FRAMEBUFFER_SRGB))\
|| (defined(GL_LINE_SMOOTH))\
|| (defined(GL_MULTISAMPLE))\
|| (defined(GL_POLYGON_OFFSET_FILL))\
|| (defined(GL_POLYGON_OFFSET_LINE))\
|| (defined(GL_POLYGON_OFFSET_POINT))\
|| (defined(GL_POLYGON_SMOOTH))\
|| (defined(GL_PRIMITIVE_RESTART))\
|| (defined(GL_PRIMITIVE_RESTART_FIXED_INDEX))\
|| (defined(GL_RASTERIZER_DISCARD))\
|| (defined(GL_SAMPLE_ALPHA_TO_COVERAGE))\
|| (defined(GL_SAMPLE_ALPHA_TO_ONE))\
|| (defined(GL_SAMPLE_COVERAGE))\
|| (defined(GL_SAMPLE_SHADING))\
|| (defined(GL_SAMPLE_MASK))\
|| (defined(GL_SCISSOR_TEST))\
|| (defined(GL_STENCIL_TEST))\
|| (defined(GL_TEXTURE_CUBE_MAP_SEAMLESS))\
|| (defined(GL_PROGRAM_POINT_SIZE))
namespace Ubpa::gl {
	enum class Capability : GLenum {
#ifdef GL_BLEND
		Blend = GL_BLEND,
#endif
#ifdef GL_CLIP_DISTANCE
		ClipDistance = GL_CLIP_DISTANCE,
#endif
#ifdef GL_COLOR_LOGIC_OP
		ColorLogicOp = GL_COLOR_LOGIC_OP,
#endif
#ifdef GL_CULL_FACE
		CullFace = GL_CULL_FACE,
#endif
#ifdef GL_DEBUG_OUTPUT
		DebugOutput = GL_DEBUG_OUTPUT,
#endif
#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
		DebugOutputSynchronous = GL_DEBUG_OUTPUT_SYNCHRONOUS,
#endif
#ifdef GL_DEPTH_CLAMP
		DepthClamp = GL_DEPTH_CLAMP,
#endif
#ifdef GL_DEPTH_TEST
		DepthTest = GL_DEPTH_TEST,
#endif
#ifdef GL_DITHER
		Dither = GL_DITHER,
#endif
#ifdef GL_FRAMEBUFFER_SRGB
		FramebufferSrgb = GL_FRAMEBUFFER_SRGB,
#endif
#ifdef GL_LINE_SMOOTH
		LineSmooth = GL_LINE_SMOOTH,
#endif
#ifdef GL_MULTISAMPLE
		Multisample = GL_MULTISAMPLE,
#endif
#ifdef GL_POLYGON_OFFSET_FILL
		PolygonOffsetFill = GL_POLYGON_OFFSET_FILL,
#endif
#ifdef GL_POLYGON_OFFSET_LINE
		PolygonOffsetLine = GL_POLYGON_OFFSET_LINE,
#endif
#ifdef GL_POLYGON_OFFSET_POINT
		PolygonOffsetPoint = GL_POLYGON_OFFSET_POINT,
#endif
#ifdef GL_POLYGON_SMOOTH
		PolygonSmooth = GL_POLYGON_SMOOTH,
#endif
#ifdef GL_PRIMITIVE_RESTART
		PrimitiveRestart = GL_PRIMITIVE_RESTART,
#endif
#ifdef GL_PRIMITIVE_RESTART_FIXED_INDEX
		PrimitiveRestartFixedIndex = GL_PRIMITIVE_RESTART_FIXED_INDEX,
#endif
#ifdef GL_RASTERIZER_DISCARD
		RasterizerDiscard = GL_RASTERIZER_DISCARD,
#endif
#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
		SampleAlphaToCoverage = GL_SAMPLE_ALPHA_TO_COVERAGE,
#endif
#ifdef GL_SAMPLE_ALPHA_TO_ONE
		SampleAlphaToOne = GL_SAMPLE_ALPHA_TO_ONE,
#endif
#ifdef GL_SAMPLE_COVERAGE
		SampleCoverage = GL_SAMPLE_COVERAGE,
#endif
#ifdef GL_SAMPLE_SHADING
		SampleShading = GL_SAMPLE_SHADING,
#endif
#ifdef GL_SAMPLE_MASK
		SampleMask = GL_SAMPLE_MASK,
#endif
#ifdef GL_SCISSOR_TEST
		ScissorTest = GL_SCISSOR_TEST,
#endif
#ifdef GL_STENCIL_TEST
		StencilTest = GL_STENCIL_TEST,
#endif
#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
		TextureCubeMapSeamless = GL_TEXTURE_CUBE_MAP_SEAMLESS,
#endif
#ifdef GL_PROGRAM_POINT_SIZE
		ProgramPointSize = GL_PROGRAM_POINT_SIZE,
#endif
	};
}
#endif

