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
	// get extended direction vector
	vec3 dir;
	vec3init(dir.v, ray.direction.x * t, ray.direction.y * t, ray.direction.z * t);

	// create the final point and add direction
	point3 newPoint;
	vec3init(newPoint.v, ray.origin.x, ray.origin.y, ray.origin.z);
	vec3add(newPoint.v, dir.v);

	return newPoint;
}