#include "Path.h"

std::string getAppPath() {
	    char cExeFilePath[256];
	    GetModuleFileNameA(NULL, cExeFilePath, 256);
	    std::string exeFilePath = cExeFilePath;
	    int exeNamePos = exeFilePath.find_last_of("\\/");
	    std::string appPath = exeFilePath.substr(0, exeNamePos + 1);
	    return appPath;
}

std::string getAssetsPath() {
    std::string appPath = getAppPath();
    std::string assetsPath = appPath + "\Assets";

    return assetsPath;
}