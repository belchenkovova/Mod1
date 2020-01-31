#include "model_data.h"

using namespace		mod1_engine_gl;

void 				*model_data::get_ptr(const int &index, const slot_type &slot)
{
	if (slot == slot_type::point)
		return (&point_buffer[3 * index]);
	else if (slot == slot_type::index)
		return (&index_buffer[3 * index]);
	else if (slot == slot_type::normal)
		return (&normal_buffer[3 * index]);
	else if (slot == slot_type::color)
		return (&color_buffer[3 * index]);
	else
		throw (exception_enum());
}

void const			*model_data::get_ptr(const int &index, const slot_type &slot) const
{
	if (slot == slot_type::point)
		return (&point_buffer[3 * index]);
	else if (slot == slot_type::index)
		return (&index_buffer[3 * index]);
	else if (slot == slot_type::normal)
		return (&normal_buffer[3 * index]);
	else if (slot == slot_type::color)
		return (&color_buffer[3 * index]);
	else
		throw (exception_enum());
}

bool				model_data::is_valid(const int &index, const slot_type &slot) const
{
	if (slot == slot_type::point)
		return (point_buffer.is_valid(3 * index));
	else if (slot == slot_type::index)
		return (index_buffer.is_valid(3 * index));
	else if (slot == slot_type::normal)
		return (normal_buffer.is_valid(3 * index));
	else if (slot == slot_type::color)
		return (color_buffer.is_valid(3 * index));
	else
		throw (exception_enum());
}