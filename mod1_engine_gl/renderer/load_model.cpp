#include "renderer.h"

using namespace			mod1_engine_gl;

void					renderer::load_model(model *model)
{
	model->load();
	model_array.push_back(model);
}