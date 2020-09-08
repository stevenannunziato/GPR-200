/*
Modified by : Steven Annunziato
Modified to include a set of ray functions.
Modifications adapted from Peter Shirley's Ray Tracing in One Weekend.
https ://raytracing.github.io/books/RayTracingInOneWeekend.html#overview
*/

#pragma once
#include "gpro/gpro-math/gproVector.h"

// all ray functions are declared here
typedef union ray ray;

union ray
{
	point3 origin;
	vec3 direction;
};

// at: determine the point at origin + t * ray.direction
point3 at(ray ray, float t);