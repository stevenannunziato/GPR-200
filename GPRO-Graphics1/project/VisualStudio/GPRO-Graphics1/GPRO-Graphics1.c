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

#include <stdio.h>
#include <stdlib.h>

void renderImage() {

	const int IMAGE_WIDTH = 256;
	const int IMAGE_HEIGHT = 256;

	// create ppm text file for the image
	printf("P3\n%i %i\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);

	// create rgb values per pixel
	for (int i = IMAGE_HEIGHT - 1; i >= 0; --i) {
		// print progress indicator to the error output stream
		fprintf(stderr, "\rScanlines remaining: %i \n", i);
		fflush(stderr);
		for (int j = 0; j < IMAGE_WIDTH; ++j) {
			float r = (float)j / (IMAGE_WIDTH - 1);
			float g = (float)i / (IMAGE_HEIGHT - 1);
			float b = 0.25;
			color pixelColor;
			vec3init(pixelColor.v, r, g, b);
			writeColor(pixelColor);
		}
	}
	fprintf(stderr, "\nDone.\n");
}

void writeColor(color pixelColor)
{
	int jr = (int)(255.999 * pixelColor.v[0]);
	int jg = (int)(255.999 * pixelColor.v[1]);
	int jb = (int)(255.999 * pixelColor.v[2]);

	printf("%i %i %i\n", jr, jg, jb);
}
