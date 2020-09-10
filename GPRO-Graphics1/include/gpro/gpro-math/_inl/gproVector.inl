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
	gproVector.h
	Interface for vectors. Sets an example for C and C++ compatible headers.

	Modified by: Steven Annunziato
	Modified to include more vector3 utility functions.
	Modifications adapted from Peter Shirley's Ray Tracing in One Weekend.
	https://raytracing.github.io/books/RayTracingInOneWeekend.html#overview
*/

#ifdef _GPRO_VECTOR_H_
#ifndef _GPRO_VECTOR_INL_
#define _GPRO_VECTOR_INL_

#include <math.h>
#include <stdio.h>

#ifdef __cplusplus

inline vec3::vec3()
	: x(0.0f), y(0.0f), z(0.0f)
{
}
inline vec3::vec3(float const xc, float const yc, float const zc)
	: x(xc), y(yc), z(zc)
{
}
inline vec3::vec3(float3 const vc)
	: x(vc[0]), y(vc[1]), z(vc[2])
{
}
inline vec3::vec3(vec3 const& rh)
	: x(rh.x), y(rh.y), z(rh.z)
{
}

inline vec3& vec3::operator =(vec3 const& rh)
{
	x = rh.x;
	y = rh.y;
	z = rh.z;
	return *this;
}

inline vec3& vec3::operator +=(vec3 const& rh)
{
	x += rh.x;
	y += rh.y;
	z += rh.z;
	return *this;
}

inline vec3 const vec3::operator +(vec3 const& rh) const
{
	return vec3((x + rh.x), (y + rh.y), (z + rh.z));
}

#endif	// __cplusplus

// float3 functions
inline floatv vec3default(float3 v_out)
{
	v_out[0] = v_out[1] = v_out[2] = 0.0f;
	return v_out;
}
inline floatv vec3init(float3 v_out, float const xc, float const yc, float const zc)
{
	v_out[0] = xc;
	v_out[1] = yc;
	v_out[2] = zc;
	return v_out;
}
inline floatv vec3copy(float3 v_out, float3 const v_rh)
{
	v_out[0] = v_rh[0];
	v_out[1] = v_rh[1];
	v_out[2] = v_rh[2];
	return v_out;
}

inline floatv vec3add(float3 v_lh_sum, float3 const v_rh)
{
	v_lh_sum[0] += v_rh[0];
	v_lh_sum[1] += v_rh[1];
	v_lh_sum[2] += v_rh[2];
	return v_lh_sum;
}
inline floatv vec3subtract(float3 v_lh_value, float3 const v_rh)
{
	v_lh_value[0] -= v_rh[0];
	v_lh_value[1] -= v_rh[1];
	v_lh_value[2] -= v_rh[2];
	return v_lh_value;
}

inline floatv vec3sum(float3 v_sum, float3 const v_lh, float3 const v_rh)
{
	return vec3init(v_sum, (v_lh[0] + v_rh[0]), (v_lh[1] + v_rh[1]), (v_lh[2] + v_rh[2]));
}

inline floatv vec3multiply(float3 v_out, float k)
{
	v_out[0] = v_out[0] * k;
	v_out[1] = v_out[1] * k;
	v_out[2] = v_out[2] * k;
	return v_out;
}

inline floatv vec3divide(float3 v_value, float k)
{
	v_value[0] /= k;
	v_value[1] /= k;
	v_value[2] /= k;
	return v_value;
}

inline float lengthSquared(float3 v_value)
{
	return v_value[0] * v_value[0] + v_value[1] * v_value[1] + v_value[2] * v_value[2];
}
inline float length(float3 v_value)
{
	return (float)sqrt(lengthSquared(v_value));
}

//vec3 functions
inline void vec3print(vec3 vec)
{
	printf("%f %f %f\n", vec.x, vec.y, vec.z);
}

inline float dot(const vec3 lhs, const vec3 rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}
inline vec3 cross(const vec3 lhs, const vec3 rhs)
{
	float x = lhs.v[1] * rhs.v[2] - lhs.v[2] * rhs.v[1];
	float y = lhs.v[2] * rhs.v[0] - lhs.v[0] * rhs.v[2];
	float z = lhs.v[0] * rhs.v[1] - lhs.v[1] * rhs.v[0];
	vec3 crossProduct;
	vec3init(crossProduct.v, x, y, z);
	return crossProduct;
}
inline vec3 vec3unit(vec3 vec) 
{
	float magnitude = length(vec.v);
	vec3 unit;
	vec3init(unit.v, vec.v[0] / magnitude, vec.v[1] / magnitude, vec.v[2] / magnitude);
	return unit;
}


#endif	// !_GPRO_VECTOR_INL_
#endif	// _GPRO_VECTOR_H_