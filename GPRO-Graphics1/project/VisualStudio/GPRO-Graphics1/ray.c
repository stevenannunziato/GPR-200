/*
Modified by : Steven Annunziato
Modified to include a set of ray functions.
Modifications adapted from Peter Shirley's Ray Tracing in One Weekend.
https ://raytracing.github.io/books/RayTracingInOneWeekend.html#overview
*/

#include "ray.h"
#include "gpro/gpro-math/gproVector.h"

point3 at(ray ray, float t)
{
	// start with the origin
	vec3 final;
	vec3copy(final.v, ray.origin.v);

	// get extended direction vector
	vec3 dir;
	vec3copy(dir.v, ray.direction.v);
	vec3multiply(dir.v, t);

	vec3add(final.v, dir.v);

	return final;
}