/**
 *
 *       @file  browser.cpp
 *
 *      @brief  Browse all the files in the directory and subdirs, this class needs to be inherited
 *
 *    @version  1.0
 *       @date  14.06.2011 20:11:02
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <browser/browser.h>

Browser::Browser(string path){
	this->path = path;
}

Browser::~Browser(){}

int Browser::browse(){
	struct stat file_status;                                                             
	if (stat(this->path.c_str(), &file_status) <0) {
		ErrorLogger::log("Could not get stats for path",path);
		return FAILURE;     
	}                                                                                    
	/* Check if file or Folder */
	if (file_status.st_mode & S_IFDIR) {
		return sbrowse(this->path); /* it's a folder */
	}
	/* It's a file */
	apply(this->path);
	return SUCCESS;
}

int Browser::sbrowse(string path){
	DIR *dir = opendir(path.c_str());	
	struct dirent *ent;
	string *newPath = new string();
	string dName;
	if (dir != NULL) {                           
		while ((ent = readdir (dir)) != NULL) {
			dName = ent->d_name;
			buildPath(path, dName, newPath);
			if (!strcmp(ent->d_name,".") ==0 && !strcmp(ent->d_name, "..") == 0 
					&& (ent->d_name[0] != '.')) {   
				if (ent->d_type == DT_DIR ) {
					if(	sbrowse(*newPath) ==  FAILURE){
						free(dir);
						free(ent);
						delete newPath;
						return FAILURE;
					}
				}else{
					apply(*newPath);
				}

			}
		}
	}
	free(dir);
	delete newPath;
	return SUCCESS;
}

void Browser::buildPath(string path, string filename, string* res){
	*res="";
	res->append(path);
	res->append("/");
	res->append(filename);
}

