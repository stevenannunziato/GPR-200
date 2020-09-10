#pragma once

/*
Modified by : Steven Annunziato

Modifications adapted from Peter Shirley's Ray Tracing in One Weekend.
https ://raytracing.github.io/books/RayTracingInOneWeekend.html#overview
*/

#include "ray.h"
#include <stdbool.h>

void renderImage();
void writeColor(color pixelColor);
color rayColor(const ray r);
float hitSphere(const point3 center, float radius, const ray r);