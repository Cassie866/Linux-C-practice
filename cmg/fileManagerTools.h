#pragma once
#include "fileManager.h"
#include <iostream>

class FileManagerTool
{
public:
	void Sacnner();
	void DeletebyMD5();
	void DeletebyName();
	void DeleteAllCopy();
	//void DeleteFuzzMatchCopy();
	void ShowCopy();
	void ShowAllFiles();
private:
	FileManager _fm;
};