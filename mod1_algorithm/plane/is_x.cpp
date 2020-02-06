#include "plane.h"

using namespace		mod1_algorithm;

bool 				plane::is_dual(const point2<int> &iter) const
{
	return (iter.x > 0 && iter.x < MOD1_INTERNAL(size).x - 1 && iter.y < MOD1_INTERNAL(size).y - 1);
}

bool				plane::is_valid(
					const point2<int> &iter,
					const model_slot &slot,
					const index_convention &convention) const
{
	int 			index_local;

	try
	{
		index_local = index(iter, convention);
	}
	catch (const exception_coordinate &exception)
	{
		return (false);
	}
	return (model::is_valid(index_local, slot));
}