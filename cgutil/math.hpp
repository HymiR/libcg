/*
 * math.hpp
 * Copyright (C) HymiR <leghissa@fim.uni-passau.de>
 *
 * This file contains special mathematical rutines for geometrical
 * calculations needed along opengl programming.
 * 
 *
 * math.hpp is free software.
 * 
 * You may redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * math.hpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with test.h.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

#pragma once

#include <cmath>


namespace cgutil
{
	/**
	 * Calculates the floating point remains for given number as numerator and 360 degrees as denominator.
	 * So this function can be used to convert any number to a valid positive angle.
	 */
	inline double afmod(double angle)
	{
		return fmod(faps(angle), 360);
	};


	/**
	 * Calculate radians from a given angle in degrees.
	 */
	inline double rad(double deg)
	{
		return ((double) afmod(deg) * M_PI / 180);
	};


	/**
	 * Calculate angle in degrees from given radians.
	 */
	inline double deg(double rad)
	{
		return afmod(180 / M_PI * rad);
	};
}
