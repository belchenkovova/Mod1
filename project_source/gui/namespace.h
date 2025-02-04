#pragma once

#include "common/mod1_freetype.h"
#include "common/mod1_generic.h"
#include "common/mod1_definition.h"

#include "engine_gl/mod1_engine_gl.h"

#include <string>
#include <map>

namespace			mod1_gui
{
	using			mod1_engine_gl::point2;
	using			mod1_engine_gl::point3;

	using			mod1_engine_gl::functor_ptr;
	using			mod1_engine_gl::functor_ptr_event;
	using			mod1_engine_gl::callback;

	class			font;
	class			symbol;
	class 			label;
	class 			button;
	class 			layout;
	class			system;
};