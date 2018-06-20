#include "FileHandling.h"

using namespace drawing;

std::vector<std::vector<ofColor>> FileHandling::readFile(string file_name) {

	ifstream scanner(file_name);

	vector<vector<ofColor>> arr;
	arr = Operations::fillWhite();
	vector<string> split_line;

	string line;

	int red;
	int green;
	int blue;
	int alpha;

	if (scanner.is_open()) {

		while (getline(scanner, line)) {
			split_line = ofSplitString(line, "#");
			int count = 0;
			for (int i = 0; i < Operations::SIZE_OF_SQUARE; i++) {
				for (int j = 0; j < Operations::SIZE_OF_SQUARE; j++) {
					red = ofToInt(split_line.at(count));
					green = ofToInt(split_line.at(count + 1));
					blue = ofToInt(split_line.at(count + 2));
					alpha = ofToInt(split_line.at(count + 3));
					count += 4;
					ofColor new_color = ofColor(red, green, blue, alpha);
					arr[i][j] = new_color;
				}
			}
		}

	}
	else {
		std::cout << "File Not Found!" << std::endl;
	}

	scanner.close();

	return arr;

}

void FileHandling::writeToFile(string file_name, std::vector<std::vector<ofColor>> arr) {
	ofstream output(file_name);

	string file_text = "";

	for (int i = 0; i < Operations::SIZE_OF_SQUARE; i++) {
		for (int j = 0; j < Operations::SIZE_OF_SQUARE; j++) {
			ofColor current = arr[i][j];
			int red_amount = current.r;
			int green_amount = current.g;
			int blue_amount = current.b;
			int alpha_amount = current.a;
			file_text += std::to_string(red_amount) + "#" + std::to_string(green_amount) + "#" 
				+ std::to_string(blue_amount) + "#" + std::to_string(alpha_amount) + "#";
		}
	}


	output << file_text << endl;
	output.close();
}