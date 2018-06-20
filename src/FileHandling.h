#pragma once
#include <stdlib.h>
#include<iostream>
#include<vector>
#include <fstream>

#include "ofColor.h"
#include "ofUtils.h"
#include "Operations.h"

namespace drawing {
	class FileHandling {

	public: 
		static std::vector<std::vector<ofColor>> readFile(string file_name);
		static void writeToFile(string file_name, std::vector<std::vector<ofColor>> arr);
	};
}