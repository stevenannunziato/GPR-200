/*
   Copyright 2020 Daniel S. Buckstein

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

/*
	GPRO-Graphics1.c/.cpp
	Main source file for GPRO-Graphics1 library.

	Modified by: Steven Annunziato
	Modified to include most major functions for the assignment.

	Modifications adapted from Peter Shirley's Ray Tracing in One Weekend.
	https://raytracing.github.io/books/RayTracingInOneWeekend.html#overview
*/

#include "gpro/gpro-math/gproVector.h"
#include "image.h"
#include "ray.h"

#include <stdio.h>
#include <stdlib.h>

void renderImage() {

	// image properties
	const float ASPECT_RATIO = 16.0f / 9.0f;
	const int IMAGE_WIDTH = 400;
	const int IMAGE_HEIGHT = (int)(IMAGE_WIDTH / ASPECT_RATIO);

	// camera properties
	float viewport_height = 2.0f;
	float viewport_width = ASPECT_RATIO * viewport_height;
	float focal_length = 1.0f;

	// origin point
	point3 origin;
	vec3default(origin.v);
	// horizontal vector
	vec3 horizontal;
	vec3init(horizontal.v, viewport_width, 0.0f, 0.0f);
	// vertical vector
	vec3 vertical;
	vec3init(vertical.v, 0.0f, viewport_height, 0.0f);
	// lower left-hand corner vector
	vec3 lower_left_corner;
	vec3copy(lower_left_corner.v, origin.v);
	vec3 half_horizontal;
	vec3copy(half_horizontal.v, horizontal.v);
	vec3divide(half_horizontal.v, 2.0f);
	vec3 half_vertical;
	vec3copy(half_vertical.v, vertical.v);
	vec3divide(half_vertical.v, 2.0f);
	vec3 focal_vector;
	vec3init(focal_vector.v, 0.0f, 0.0f, focal_length);
	vec3subtract(lower_left_corner.v, half_horizontal.v);
	vec3subtract(lower_left_corner.v, half_vertical.v);
	vec3subtract(lower_left_corner.v, focal_vector.v);

	// create ppm file for the image
	printf("P3\n%i %i\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);

	// create rgb values per pixel
	for (int i = IMAGE_HEIGHT - 1; i >= 0; --i) {
		// print progress indicator to the error output stream
		fprintf(stderr, "\rScanlines remaining: %i \n", i);
		fflush(stderr);
		for (int j = 0; j < IMAGE_WIDTH; ++j) {
			// create coordinates to pass to a ray
			float u = (float)j / (IMAGE_WIDTH - 1);
			float v = (float)i / (IMAGE_HEIGHT - 1);
			// create the ray
			ray r;
			vec3init(r.origin.v, origin.x, origin.y, origin.z);
			vec3 direction;
			vec3copy(direction.v, lower_left_corner.v);
			vec3 multiplied_horizontal;
			vec3copy(multiplied_horizontal.v, horizontal.v);
			vec3multiply(multiplied_horizontal.v, u);
			vec3 multiplied_vertical;
			vec3copy(multiplied_vertical.v, vertical.v);
			vec3multiply(multiplied_vertical.v, v);
			vec3add(direction.v, multiplied_horizontal.v);
			vec3add(direction.v, multiplied_vertical.v);
			vec3subtract(direction.v, origin.v);
			vec3init(r.direction.v, direction.x, direction.y, direction.z);

			color pixelColor = rayColor(r);
			writeColor(pixelColor);
		}
	}
	fprintf(stderr, "\nDone.\n");
}

void writeColor(color pixelColor)
{
	// create individual rgb values
	int jr = (int)(255.999 * pixelColor.v[0]);
	int jg = (int)(255.999 * pixelColor.v[1]);
	int jb = (int)(255.999 * pixelColor.v[2]);

	printf("%i %i %i\n", jr, jg, jb);
}

color rayColor(const ray r)
{
	// create a unit direction
	vec3 unitDirection = vec3unit(r.direction);
	float t = 0.5f * (unitDirection.y + 1.0f);

	// calculate the final color
	color finalColor;
	vec3init(finalColor.v, 1.0f, 1.0f, 1.0f);
	vec3multiply(finalColor.v, 1.0f - t);
	color colorToAdd;
	vec3init(colorToAdd.v, 1.0f, 1.0f, 0.5f);
	vec3multiply(colorToAdd.v, t);
	vec3add(finalColor.v, colorToAdd.v);
	return finalColor;
}