#include "Operations.h"

using namespace drawing;

std::vector<std::vector<ofColor>> Operations::fillWhite() {
	std::vector<std::vector<ofColor>> new_arr;

	for (int i = 0; i < SIZE_OF_SQUARE; i++) {
		std::vector<ofColor> row;
		for (int j = 0; j < SIZE_OF_SQUARE; j++) {
			row.push_back(ofColor::white);
		}
		new_arr.push_back(row);
	}

	return new_arr;
}

std::vector<std::vector<ofColor>> Operations::rotateStep(std::vector<std::vector<ofColor>> old_arr) {
	std::vector<std::vector<ofColor>> to_rotate;

	for (int i = 0; i < SIZE_OF_SQUARE; i++) {
		std::vector<ofColor> new_row(SIZE_OF_SQUARE);
		to_rotate.push_back(new_row);
	}

	for (int i = 0; i < old_arr[0].size(); i++) {
		for (int j = old_arr.size() - 1; j >= 0; j--) {
			to_rotate[i][j] = old_arr[j][i];
		}
	}



	std::vector<std::vector<ofColor>> new_arr;
	for (int i = 0; i < SIZE_OF_SQUARE; i++) {
		std::vector<ofColor> new_row(SIZE_OF_SQUARE);
		new_arr.push_back(new_row);
	}

	for (int i = 0; i < to_rotate.size(); i++) {
		std::vector<ofColor> current = to_rotate[i];
		for (int j = 0; j < to_rotate.size(); j++) {
			new_arr[to_rotate.size() - i - 1][j] = current[j];
		}

	}

	return new_arr;
}


std::vector<std::vector<ofColor>> Operations::shiftLeft(std::vector<std::vector<ofColor>> old_arr, int amount) {
	std::vector<std::vector<ofColor>> new_arr;

	new_arr = fillWhite();

	for (int i = 0; i < old_arr.size() - amount; i++) {
		for (int j = 0; j < old_arr[0].size(); j++) {
			new_arr[i][j] = old_arr[i + amount][j];
		}
	}

	return new_arr;
}

std::vector<std::vector<ofColor>> Operations::shiftRight(std::vector<std::vector<ofColor>> old_arr, int amount) {
	std::vector<std::vector<ofColor>> new_arr;

	new_arr = fillWhite();

	for (int i = 0; i < old_arr.size() - amount; i++) {
		for (int j = 0; j < old_arr[0].size(); j++) {
			new_arr[i + amount][j] = old_arr[i][j];
		}
	}

	return new_arr;
}

std::vector<std::vector<ofColor>> Operations::shiftUp(std::vector<std::vector<ofColor>> old_arr, int amount) {
	std::vector<std::vector<ofColor>> new_arr;

	new_arr = fillWhite();

	for (int i = 0; i < old_arr.size(); i++) {
		for (int j = 0; j < old_arr[0].size() - amount; j++) {
			new_arr[i][j] = old_arr[i][j + amount];
		}
	}

	return new_arr;
}

std::vector<std::vector<ofColor>> Operations::shiftDown(std::vector<std::vector<ofColor>> old_arr, int amount) {
	std::vector<std::vector<ofColor>> new_arr;

	new_arr = fillWhite();

	for (int i = 0; i < old_arr.size(); i++) {
		for (int j = 0; j < old_arr[0].size() - amount; j++) {
			new_arr[i][j + amount] = old_arr[i][j];
		}
	}

	return new_arr;
}

std::vector<std::vector<ofColor>> Operations::rotateRight(std::vector<std::vector<ofColor>> old_arr) {
	std::vector<std::vector<ofColor>> new_arr;
	new_arr = rotateStep(old_arr);

	return new_arr;
}

std::vector<std::vector<ofColor>> Operations::rotateLeft(std::vector<std::vector<ofColor>> old_arr) {
	return rotateRight(rotateRight(rotateRight(old_arr)));
}

std::vector<std::vector<ofColor>> Operations::flipVertical(std::vector<std::vector<ofColor>> old_arr) {
	std::vector<std::vector<ofColor>> new_arr;

	new_arr = fillWhite();

	for (int i = 0; i < old_arr.size(); i++) {
		std::vector<ofColor> current = old_arr[i];
		for (int j = 0; j < old_arr[i].size(); j++) {
			new_arr[i][old_arr[0].size() - 1 - j] = current[j];
		}

	}

	return new_arr;
}

std::vector<std::vector<ofColor>> Operations::flipHorizontal(std::vector<std::vector<ofColor>> old_arr) {
	std::vector<std::vector<ofColor>> new_arr;

	new_arr = fillWhite();

	for (int i = 0; i < old_arr.size(); i++) {
		std::vector<ofColor> current = old_arr[i];
		for (int j = 0; j < old_arr[i].size(); j++) {
			new_arr[old_arr.size() - i - 1][j] = current[j];
		}

	}

	return new_arr;
}