#include "ofApp.h"

using namespace drawing;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Draw!");
	ofBackground(255);
	button_panel.setup();

	button_panel.add(shift_left.setup("shift left", 250, 50));
	shift_left.addListener(this, &ofApp::shiftLeftPressed);
	button_panel.add(shift_right.setup("shift right", 250, 50));
	shift_right.addListener(this, &ofApp::shiftRightPressed);
	button_panel.add(shift_up.setup("shift up", 250, 50));
	shift_up.addListener(this, &ofApp::shiftUpPressed);
	button_panel.add(shift_down.setup("shift down", 250, 50));
	shift_down.addListener(this, &ofApp::shiftDownPressed);
	button_panel.add(rotate_right.setup("rotate right", 250, 50));
	rotate_right.addListener(this, &ofApp::rotateRightPressed);
	button_panel.add(rotate_left.setup("rotate left", 250, 50));
	rotate_left.addListener(this, &ofApp::rotateLeftPressed);
	button_panel.add(flip_horiz.setup("flip horizontal", 250, 50));
	flip_horiz.addListener(this, &ofApp::flipHorizPressed);
	button_panel.add(flip_vert.setup("flip vertical", 250, 50));
	flip_vert.addListener(this, &ofApp::flipVertPressed);
	button_panel.add(clear.setup("clear", 250, 50));
	clear.addListener(this, &ofApp::clearPressed);
	button_panel.add(save_field.setup("", "file name", "", "", 250, 50));
	button_panel.add(save_button.setup("save", 250, 50));
	save_button.addListener(this, &ofApp::savePressed);
	button_panel.add(open_button.setup("open", 250, 50));
	open_button.addListener(this, &ofApp::openPressed);
	button_panel.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	button_panel.setPosition(900, 20);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(128);

	for (int i = 0; i < DRAWING_HEIGHT; i += (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE)) {
		ofDrawLine(i, 0, i, DRAWING_HEIGHT);
	}

	for (int j = 0; j < DRAWING_HEIGHT; j += (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE)) {
		ofDrawLine(0, j, DRAWING_HEIGHT, j);
	}

	drawCurrentDrawing();

	//rotate_right.
	//rotate_right.draw();
	button_panel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	drawNewBox(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	drawNewBox(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
//this method will do nothing as window resizing is disabled
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::drawCurrentDrawing() {
	for (int i = 0; i < color_arr.size(); i++) {
		for (int j = 0; j < color_arr.size(); j++) {
			int x = i * (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE);
			int y = j * (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE);
			ofColor col = color_arr[i][j];
			ofSetColor(col);
			ofDrawRectangle(x + 1, y + 1, (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE) - 1, (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE) - 1);
		}
	}
}

void ofApp::drawNewBox(int x, int y, int button) {
	if (button == 0) {
		ofSetColor(color);
	} 

	if (button == 2) {
		ofSetColor(ofColor::white);
	}

	int align_x = x - (x % (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE));
	int align_y = y - (y % (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE));
	ofDrawRectangle(align_x + 1, align_y + 1, (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE) - 1, (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE) - 1);
	int arr_x = align_x / (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE);
	int arr_y = align_y / (DRAWING_HEIGHT / Operations::SIZE_OF_SQUARE);
	if (arr_x < Operations::SIZE_OF_SQUARE && arr_x >= 0 && arr_y < Operations::SIZE_OF_SQUARE && arr_y >= 0) {
		if (button == 0) {
			color_arr[arr_x][arr_y] = color;
		}
		else if (button == 2) {
			color_arr[arr_x][arr_y] = ofColor::white;
		}
	}
}

void ofApp::shiftLeftPressed() {
	color_arr = Operations::shiftLeft(color_arr, 3);
}

void ofApp::shiftRightPressed() {
	color_arr = Operations::shiftRight(color_arr, 3);
}

void ofApp::shiftUpPressed() {
	color_arr = Operations::shiftUp(color_arr, 3);
}

void ofApp::shiftDownPressed() {
	color_arr = Operations::shiftDown(color_arr, 3);
}

void ofApp::rotateRightPressed() {
	color_arr = Operations::rotateRight(color_arr);
}

void ofApp::rotateLeftPressed() {
	color_arr = Operations::rotateLeft(color_arr);
}

void ofApp::flipHorizPressed() {
	color_arr = Operations::flipHorizontal(color_arr);
}

void ofApp::flipVertPressed() {
	color_arr = Operations::flipVertical(color_arr);
}

void ofApp::clearPressed() {
	color_arr = Operations::fillWhite();
}

void ofApp::savePressed() {
	FileHandling::writeToFile(save_field, color_arr);
}

void ofApp::openPressed() {
	color_arr = FileHandling::readFile(save_field);
}