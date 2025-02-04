#define IS_VALID(iter)								is_valid(size, &iter)

#define GET_TERRAIN(iter)							get_value_const(terrain_data, size, &iter)

#define GET_FLOW(iter, flow)						get_flow(flow_horizontal, flow_vertical, size, &(iter), flow)
#define SET_FLOW(iter, flow, value)					set_flow(flow_horizontal, flow_vertical, size, &(iter), flow, value)
#define ADD_FLOW(iter, flow, value)					set_flow(flow_horizontal, flow_vertical, size, &(iter), flow, GET_FLOW(iter, flow) + value)

#define GET_WATER(iter)								get_value(water_data, size, &iter)
#define SET_WATER(iter, value)						set_value(water_data, size, &iter, value)
#define ADD_WATER(iter, value)						set_value(water_data, size, &iter, GET_WATER(iter) + value)
#define ADD_WATER_DIFFUSED(iter, value)				ADD_WATER(iter, value * DIFFUSION)

#define GET_TOTAL(iter)								(GET_TERRAIN(iter) + GET_WATER(iter))
#define GET_TOTAL_LIMITED(iter)						(GET_WATER(iter) > 0.1 ? GET_TOTAL(iter) : 0)

#define CONST_FLOW									*const_flow
#define CONST_DEPTH									*const_depth