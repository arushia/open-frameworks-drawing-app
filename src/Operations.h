#include "ofColor.h"
#include<iostream>
#include<vector>
#include <fstream>

namespace drawing {
	class Operations {
	private:
		static std::vector<std::vector<ofColor>> rotateStep(std::vector<std::vector<ofColor>> old_arr);
		
	public:
		static const int SIZE_OF_SQUARE = 40;
		static std::vector<std::vector<ofColor>> fillWhite();
		static std::vector<std::vector<ofColor>> shiftLeft(std::vector<std::vector<ofColor>> old_arr, int amount);
		static std::vector<std::vector<ofColor>> shiftRight(std::vector<std::vector<ofColor>> old_arr, int amount);
		static std::vector<std::vector<ofColor>> shiftUp(std::vector<std::vector<ofColor>> old_arr, int amount);
		static std::vector<std::vector<ofColor>> shiftDown(std::vector<std::vector<ofColor>> old_arr, int amount);
		static std::vector<std::vector<ofColor>> rotateRight(std::vector<std::vector<ofColor>> old_arr);
		static std::vector<std::vector<ofColor>> rotateLeft(std::vector<std::vector<ofColor>> old_arr);
		static std::vector<std::vector<ofColor>> flipHorizontal(std::vector<std::vector<ofColor>> old_arr);
		static std::vector<std::vector<ofColor>> flipVertical(std::vector<std::vector<ofColor>> old_arr);

	};
}