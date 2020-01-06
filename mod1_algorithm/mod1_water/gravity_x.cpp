#include "mod1_water.h"

void 					mod1_water::gravity_debug()
{
# define RED			"\033[0;31m"
# define BLACK			"\033[0m"

	mod1_point2<int>	iter;

	for (iter.y = 0; iter.y < terrain->size.y; iter.y++)
	{
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			if (iter.x)
				printf(":");
			printf("[%+7.2f]:%s%+7.2f%s",
				   water_depth[iter],
				   RED, get_flow(iter, mod1_water::flow_right), BLACK);
		}
		printf("\n");
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			if (iter.x)
				printf("        ");
			printf("    ..    ");
		}
		printf("\n");
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			if (iter.x)
				printf("         ");
			printf("%s %+7.2f %s", RED, get_flow(iter, mod1_water::flow_down), BLACK);
		}
		printf("\n");
		for (iter.x = 0; iter.x < terrain->size.x; iter.x++)
		{
			if (iter.x)
				printf("        ");
			printf("    ..    ");
		}
		printf("\n");
	}
	printf("\n");
}

//#define DEBUG_GRAVITY

void					mod1_water::gravity()
{

#ifdef DEBUG_GRAVITY
	printf("\nBefore gravity (i = %i)\n\n", i++);
	gravity_debug();
#endif

	update_flow();
	limit_flow();

	water_depth_copy.copy(water_depth);

	update_depth();
	diffuse_depth();

	update_model();

#ifdef DEBUG_GRAVITY
	printf("\nAfter gravity (i = %i)\n\n", i);
	gravity_debug();
#endif
}