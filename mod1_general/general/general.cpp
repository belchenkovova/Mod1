#include "general.h"

MOD1_GENERATE_EXCEPTION_DEFINITION(general, exception_arguments)

MOD1_GENERATE_INTERNAL_READ_DEFINITION(general, terrain)
MOD1_GENERATE_INTERNAL_READ_DEFINITION(general, water)

						general::general(int argc, char **argv) :
							mod1_engine_gl::renderer(),
							cl_core(),
							framebuffer(window_width(), window_height()),
							program(),
							light(),
							system(*(mod1_engine_gl::core *)this)
{
MOD1_GENERATE_MESSAGE("")

	light.ambient_intensity = MOD1_GENERAL_LIGHT_AMBIENT_INTENSITY;
	light.direct_direction = glm::vec3(MOD1_GENERAL_LIGHT_DIRECT_DIRECTION);
	light.direct_intensity = MOD1_GENERAL_LIGHT_DIRECT_INTENSITY;

	MOD1_INTERNAL(terrain) = new mod1_algorithm::terrain;
MOD1_GENERATE_MESSAGE("Mod1 General : Terrain is created")
	MOD1_INTERNAL(water) = new mod1_algorithm::water(cl_core, MOD1_INTERNAL(terrain));
MOD1_GENERATE_MESSAGE("Mod1 General : Water is created")

	if (argc < 2)
		throw (exception_arguments());
	first_argument = argv[1];
	second_argument = argc >= 3 ? argv[2] : nullptr;

	font_gill_sans = new mod1_gui::font(MOD1_GENERAL_GILL_SANS, 48, point3<int>(48));
	font_gill_sans_light = new mod1_gui::font(MOD1_GENERAL_GILL_SANS, 48, point3<int>(110));
	gui_level = level::render;

	hint_label = new mod1_gui::label(point2<int>(window_width() / 2, window_height() * 9 / 10), "", font_gill_sans_light);
	hint_layout.push(hint_label);
	hint_drag = true;
	hint_init("Drag mouse to rotate terrain");

	add_callback(mod1_engine_gl::event_type::key_press, general::functor_key, this);
	callback_rotate_start = add_callback(mod1_engine_gl::event_type::mouse_drag, general::functor_rotate_start, this);
	callback_rotate_finish = add_callback(mod1_engine_gl::event_type::mouse_release, general::functor_rotate_finish, this);

	callback_light_a = add_callback(mod1_engine_gl::event_type::key_press, general::functor_light_rotate, this);
	callback_light_b = add_callback(mod1_engine_gl::event_type::key_hold, general::functor_light_rotate, this);
	callback_light_a->block(true);
	callback_light_b->block(true);

MOD1_GENERATE_MESSAGE("Mod1 General : Callbacks are set")

	timer_default_render = add_timer(1. / 10., general::functor_default_render, this);

	timer_gravity = add_timer(1. / 35., functor_gravity, this);
	timer_gravity->block(true);

MOD1_GENERATE_MESSAGE("Mod1 General : Timers are set")

	mod1_gui::button	*button[10];

	button[0] = system.generate_button(window_width() / 2, window_height() * 3 / 9, "Continue", font_gill_sans, functor_continue, this);
	button[1] = system.generate_button(window_width() / 2, window_height() * 4 / 9, "Scenario", font_gill_sans, functor_scenarios, this);
	button[2] = system.generate_button(window_width() / 2, window_height() * 5 / 9, "Light control", font_gill_sans, functor_light_control, this);
	button[3] = system.generate_button(window_width() / 2, window_height() * 6 / 9, "Exit", font_gill_sans, functor_exit, this);

	button[4] = system.generate_button(window_width() / 2, window_height() * 2 / 9, "Rain", font_gill_sans, scenario_rain, this);
	button[5] = system.generate_button(window_width() / 2, window_height() * 3 / 9, "Heavy rain", font_gill_sans, scenario_heavy_rain, this);
	button[6] = system.generate_button(window_width() / 2, window_height() * 4 / 9, "Well", font_gill_sans, scenario_well, this);
	button[7] = system.generate_button(window_width() / 2, window_height() * 5 / 9, "Wave", font_gill_sans, scenario_wave, this);
	button[8] = system.generate_button(window_width() / 2, window_height() * 6 / 9, "4 waves", font_gill_sans, scenario_4_waves, this);
	button[9] = system.generate_button(window_width() / 2, window_height() * 7 / 9, "Flood", font_gill_sans, scenario_flood, this);

	for (int i = 0; i < 4; i++)
		layout_front.push(button[i]);

	for (int i = 4; i < 10; i++)
		layout_scenarios.push(button[i]);

MOD1_GENERATE_MESSAGE("Mod1 General : Buttons are set")
MOD1_GENERATE_MESSAGE("Mod1 General : Ready")
}

					general::~general()
{
	delete MOD1_INTERNAL(terrain);
	delete MOD1_INTERNAL(water);

	delete hint_label;

	delete callback_rotate_start;
	delete callback_rotate_finish;
	delete callback_light_a;
	delete callback_light_b;

	delete timer_default_render;
	delete timer_gravity;
	delete timer_scenario;
}