#pragma once

#include "ofMain.h"
#include "ofxButton.h"
#include "ofxPanel.h"
#include "ofxGui\src\ofxSliderGroup.h"
#include "ofxInputField.h"
#include "FileHandling.h"

namespace drawing {

	class ofApp : public ofBaseApp {

	private:
		std::vector<std::vector<ofColor>> color_arr = Operations::fillWhite();
		ofxPanel button_panel;
		ofxButton shift_left;
		ofxButton shift_right;
		ofxButton shift_up;
		ofxButton shift_down;
		ofxButton rotate_right;
		ofxButton rotate_left;
		ofxButton flip_horiz;
		ofxButton flip_vert;
		ofxButton clear;
		ofxButton save_button;
		ofxButton open_button;
		ofxColorSlider color;
		ofxTextField save_field;

		
	public:
		static const int DRAWING_HEIGHT = 800;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h); //because window resizing is disabled, will never be used
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawCurrentDrawing();
		void drawNewBox(int x, int y, int button);

		void shiftLeftPressed();
		void shiftRightPressed();
		void shiftUpPressed();
		void shiftDownPressed();
		void rotateRightPressed();
		void rotateLeftPressed();
		void flipHorizPressed();
		void flipVertPressed();
		void clearPressed();
		void savePressed();
		void openPressed();

	};

}
