/*
 * glm_ostream.hpp
 *
 *  Created on: 13.08.2010
 *      Author: sam
 */


#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>

#include <ostream>
#include <iomanip>


#ifndef GLM_OSTREAM_HPP
#define GLM_OSTREAM_HPP


#define GLM_FORMATTING std::setw(5) << std::setw(3) << std::fixed << std::setfill('0')


template<typename U, glm::precision P>
std::ostream &operator<<(std::ostream &ostr, const glm::detail::tvec1<U, P> &v)
{
	return ostr << GLM_FORMATTING << "(" << v.x << ")";
}


template<typename U, glm::precision P>
std::ostream &operator<<(std::ostream &ostr, const glm::detail::tvec2<U, P> &v)
{
	return ostr << GLM_FORMATTING << "(" << v.x << "," << v.y << ")";
}


template<typename U, glm::precision P>
std::ostream &operator<<(std::ostream &ostr, const glm::detail::tvec3<U, P> &v)
{
	return ostr << GLM_FORMATTING << "(" << v.x << "," << v.y << "," << v.z << ")";
}


template<typename U, glm::precision P>
std::ostream &operator<<(std::ostream &ostr, const glm::detail::tvec4<U, P> &v)
{
	return ostr
		<< GLM_FORMATTING << "(" << v.x << "," << v.y
		<< "," << v.z << "," << v.w << ")";
}


template<typename U, glm::precision P>
std::ostream &operator<<(std::ostream &ostr, const glm::detail::tmat2x2<U, P> &v)
{
	ostr << std::endl;

	glm::detail::tvec2<U, P> row = glm::row(v, 0);
	ostr << "[" << GLM_FORMATTING << row.x << "," << row.y << " " << std::endl;
	row = glm::row(v, 1);
	ostr << " " << GLM_FORMATTING << row.x << "," << row.y << "]" << std::endl;
	return ostr;
}


template<typename U, glm::precision P>
std::ostream &operator<<(std::ostream &ostr, const glm::detail::tmat3x3<U, P> &v)
{
	ostr << std::endl;
	glm::detail::tvec3<U, P> row = glm::row(v, 0);

	ostr << "[" << GLM_FORMATTING
		<< row.x << "," << row.y
		<< "," << row.z << " " << std::endl;

	row = glm::row(v, 1);

	ostr << " " << GLM_FORMATTING
		<< row.x << "," << row.y
		<< "," << row.z << " " << std::endl;

	row = glm::row(v, 2);

	ostr << " " << GLM_FORMATTING
		<< row.x << "," << row.y
		<< "," << row.z << "]" << std::endl;

	return ostr;
}


template<typename U, glm::precision P>
std::ostream &operator<<(std::ostream &ostr, const glm::detail::tmat4x4<U, P> &v)
{
	ostr << std::endl;
	glm::detail::tvec4<U, P> row = glm::row(v, 0);

	ostr << "[" << GLM_FORMATTING
		<< row.x << "," << row.y
		<< "," << row.z << "," << row.w << " " << std::endl;

	row = glm::row(v, 1);
	
	ostr << " " << GLM_FORMATTING
		<< row.x << "," << row.y
		<< "," << row.z << "," << row.w << " " << std::endl;

	row = glm::row(v, 2);
	
	ostr << " " << GLM_FORMATTING
		<< row.x << "," << row.y
		<< "," << row.z << "," << row.w << "]" << std::endl;

	row = glm::row(v, 3);
	
	ostr << " " << GLM_FORMATTING
		<< row.x << "," << row.y
		<< "," << row.z << "," << row.w << "]" << std::endl;

	return ostr;
}

#undef GLM_FORMATTING

#endif // GLM_OSTREAM_HPP
