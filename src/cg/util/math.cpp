/**
 ** This file is part of the cg project.
 ** Copyright 2019 CyberViking Softwareschmiede GbR <leghissa@cyber-viking.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU Lesser General Public License as
 ** published by the Free Software Foundation, either version 3 of the
 ** License, or (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/


#include <cg/util/math.hpp>

#include <cmath>


namespace cg
{
    namespace util
    {
        /**
         * @brief afmod Calculates the floating point remains for given number as numerator and 360 degrees as denominator.
         * So this function can be used to convert any number to a valid positive angle.
         * @param angle
         * @return
         */
        double afmod(double angle)
        {
            return fmod(fabs(angle), 360);
        }


        /**
         * @brief rad Calculate radians from a given angle in degrees.
         * @param deg
         * @return
         */
        double rad(double deg)
        {
            return (afmod(deg) * M_PI / 180);
        }


        /**
         * @brief deg  Calculate angle in degrees from given radians.
         * @param rad
         * @return
         */
        double deg(double rad)
        {
            return afmod(180 / M_PI * rad);
        }
    }
}
