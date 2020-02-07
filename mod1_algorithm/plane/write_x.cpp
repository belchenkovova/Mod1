#include "plane.h"

using namespace		mod1_algorithm;

bool				plane::write_height(const point2<int> &iter, const float &z)
{
	float 			*ptr;

	ptr = (float *)pointer(iter, model_slot::point, index_convention::dual_first);
	ptr[1] = z;

	if (is_dual(iter))
	{
		ptr = (float *)pointer(iter, model_slot::point, index_convention::dual_second);
		ptr[1] = z;
		return (true);
	}

	return (false);
}

void				plane::write_color(const point2<int> &iter, const point4<float> &color)
{
	float 			*ptr;

	ptr = (float *)pointer(iter, model_slot::color, index_convention::dual_first);
	color.write_to_ptr(ptr);

	if (is_dual(iter))
	{
		ptr = (float *)pointer(iter, model_slot::color, index_convention::dual_second);
		color.write_to_ptr(ptr);
	}

}