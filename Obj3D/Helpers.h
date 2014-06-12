/* 
 * File:   Helpers.h
 * Author: vidar
 *
 * Created on 12. Juni 2014, 11:29
 */

#ifndef HELPERS_H
#define	HELPERS_H
#include <cstring>
#include <vector>
#include <boost/filesystem.hpp>
#include <sys/stat.h>

class Helpers {
public:
	  Helpers();
	  Helpers(const Helpers& orig);
	  virtual ~Helpers();
	  
	  static std::string getExt(std::string path);
	  static std::vector<std::string> getFilesFromFolder(std::string path);
	  static bool folderExists(std::string path);
	  static std::string getFileName(std::string path);
	  
private:

};

#endif	/* HELPERS_H */
