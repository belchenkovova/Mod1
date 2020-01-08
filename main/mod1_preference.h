#pragma once

#include "mod1_primitive.h"

//											GLOBAL

#define MOD1_NORMAL_TEST					MOD1_DISABLE

#define MOD1_USE_TERRAIN					MOD1_ENABLE
#define MOD1_USE_WATER						MOD1_DISABLE

#define MOD1_LIGHT_AMBIENT_INTENSITY		0.2
#define MOD1_LIGHT_POINT_INTENSITY			0.8
#define MOD1_LIGHT_POINT_POSITION			1000, 3000, 1000

#define MOD1_LIGHT_CUBE						MOD1_ENABLE
#define MOD1_LIGHT_CUBE_SIDE				50

#define MOD1_CAMERA_MOVEMENT_SPEED			100
#define MOD1_CAMERA_ROTATION_SPEED			0.04

//											TERRAIN

#define MOD1_TERRAIN_NOISE					MOD1_ENABLE

#define MOD1_TERRAIN_NOISE_HILL				MOD1_ENABLE
#define MOD1_TERRAIN_NOISE_HILL_FREQUENCY	0.2
#define MOD1_TERRAIN_NOISE_HILL_RANGE		200
#define MOD1_TERRAIN_NOISE_HILL_ADD			0.8

#define MOD1_TERRAIN_NOISE_A				MOD1_ENABLE
#define MOD1_TERRAIN_NOISE_A_FREQUENCY		0.015
#define MOD1_TERRAIN_NOISE_A_RANGE			5000

#define MOD1_TERRAIN_NOISE_B				MOD1_ENABLE
#define MOD1_TERRAIN_NOISE_B_FREQUENCY		0.05
#define MOD1_TERRAIN_NOISE_B_RANGE			400

//											WATER

#define MOD1_WATER_FLOOD_POINT

#define MOD1_WATER_CONST_A					1000
#define MOD1_WATER_CONST_g					10
#define MOD1_WATER_CONST_dt					50000

#define MOD1_WATER_HIDDEN					-1000

#define MOD1_WATER_COLOR_A					0, 0.62, 1
#define MOD1_WATER_COLOR_B					0, 0.05, 0.1
#define MOD1_WATER_COLOR_RANGE				10000