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
	GPRO-Graphics1-TestConsole-main.c/.cpp
	Main entry point source file for a Windows console application.

	Modified by: Steven Annunziato
	Modified to output various images found in Peter Shirley's Ray Tracing in One Weekend.

	Modifications adapted from Peter Shirley's Ray Tracing in One Weekend.
	https://raytracing.github.io/books/RayTracingInOneWeekend.html#overview

*/

#include <stdio.h>
#include <stdlib.h>

#include "gpro/gpro-math/gproVector.h"
#include "image.h"


void testVector()
{
	// test array vector initializers and functions
	float3 av, bv, cv, dv;
	vec3default(av);								// -> a = (0, 0, 0)
	vec3init(bv, 1.0f, 2.0f, 3.0f);					// -> b = (1, 2, 3)
	vec3copy(dv, vec3init(cv, 4.0f, 5.0f, 6.0f));	// -> d = c = (4, 5, 6)
	vec3copy(av, dv);								// a = d			-> a = (4, 5, 6)
	vec3add(dv, bv);								// d += b			-> d = (4 + 1, 5 + 2, 6 + 3) = (5, 7, 9)
	vec3sum(dv, bv, bv);							// d = b + b		-> d = (1 + 1, 2 + 2, 3 + 3) = (2, 4, 6)
	vec3add(vec3sum(dv, cv, bv), av);				// d = c + b + a	-> d = (4 + 1 + 4, 5 + 2 + 5, 6 + 3 + 6) = (9, 12, 15)

#ifdef __cplusplus
	// test all constructors and operators
	vec3 a, b(1.0f, 2.0f, 3.0f), c(cv), d(c);		// default; init; copy array; copy
	a = d;											// assign						-> a = (4, 5, 6)
	d += b;											// add assign					-> d = (5, 7, 9)
	d = b + b;										// sum, init, assign			-> d = (2, 4, 6)
	d = c + b + a;									// sum, init, sum, init, assign	-> d = (9, 12, 15)
#endif	// __cplusplus
}


#ifdef __cplusplus
// c++ file io includes
#include <fstream>
#include <string>
#else 
// c file io includes
#include <stdio.h>
#endif


int main(int const argc, char const* const argv[])
{
	testVector();

	// HOW TO OPEN AND WRITE TO A FILE
#ifdef __cplusplus
	// c++ file io includes
	std::ofstream file("file.txt");
	std::string test = "hello";
	file << test << std::endl;
	file.close();
#else 
	// c file io includes
	FILE* filePointer = fopen("test.txt", "w");	// open file for writing
	if (filePointer) {
		char* test = "hello";				// create string, could also do char test[] = "hello"
		fprintf(filePointer, "%s\n", test);	// output string
		fclose(filePointer);				// done, close file
	}	
#endif
	

	renderImage();

	printf("\n\n");
}
