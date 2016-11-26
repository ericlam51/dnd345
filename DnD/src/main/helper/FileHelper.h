#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class FileHelper {
public:
	static const string MAP_FILE_FOLDER;
	static const string FIGHTER_FILE_FOLDER;
	static const string HOSTILE_FILE_FOLDER;
	static const string FRIENDLY_FILE_FOLDER;
	static const string CHEST_FILE_FOLDER;
	static vector<string> getFilenamesInDirectory(string foldername);
	static string getDirectoryPath(string foldername);
};
