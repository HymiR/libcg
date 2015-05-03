/*
 * File:   Helpers.cpp
 * Author: vidar
 *
 * Created on 12. Juni 2014, 11:29
 */


#include "Helpers.hpp"
#include "Renderable.hpp"


namespace cg
{
	namespace ger
	{
		Helpers::Helpers() {}

		Helpers::Helpers(const Helpers& orig) {}

		Helpers::~Helpers() {}

		std::string Helpers::getExt(std::string path)
		{
			std::string ext = "";
			if(path.find_last_of(".") != std::string::npos)
				ext = path.substr(path.find_last_of(".") + 1);
			return ext;
		}

		std::string Helpers::getFileName(std::string path)
		{
			std::string FileName = "";
			if(path.find_last_of("/") != std::string::npos) {
				FileName = path.substr(path.find_last_of("/") + 1);
				FileName = FileName.substr(0, FileName.find_last_of("."));
			}
			return FileName;
		}

		std::vector<std::string> Helpers::getFilesFromFolder(std::string path)
		{
			boost::filesystem::path meshfilepath(path);
			std::vector<std::string> files;

			for(boost::filesystem::directory_entry entry : (boost::filesystem::directory_iterator(meshfilepath)))
				files.push_back(entry.path().c_str());

			return files;
		}

		bool Helpers::folderExists(std::string path)
		{
			struct stat buf;
			if(stat(path.c_str(), &buf) != -1) {
				return true;
			}
			return false;
		}

		float Helpers::deg2rad(float deg) { return deg / (360.0f / (2.0f * M_PI)); }

		float Helpers::rad2deg(float rad) { return rad * (360.0f / (2.0f * M_PI)); }
	}
}
