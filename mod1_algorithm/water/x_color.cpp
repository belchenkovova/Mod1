#include "water.h"

using namespace			mod1_algorithm;

void					water::update_color()
{
	point2<int>			iter;
	point3<float>		color;
	float 				total;
	float 				*ptr;

	for (iter.y = 0; iter.y < terrain->size().y; iter.y++)
		for (iter.x = 0; iter.x < terrain->size().x; iter.x++)
		{
			total = get_total_height(iter);
			for (int i = 0; i < 3; i++)
				color[i] = terrain::interpolate_cosine(
					point3<float>(MOD1_WATER_COLOR_A)[i],
					point3<float>(MOD1_WATER_COLOR_B)[i],
					total / MOD1_WATER_COLOR_RANGE);
			ptr = (float *)get_ptr(iter, model_slot::color);
			for (int i = 0; i < 3; i++)
				ptr[i] = color[i];
		}
}