#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	//disabling window resizing: https://forum.openframeworks.cc/t/how-to-disable-window-resizing/23338
	ofGLFWWindowSettings settings;
	settings.resizable = false;
	settings.width = drawing::ofApp::DRAWING_HEIGHT + 400;
	settings.height = drawing::ofApp::DRAWING_HEIGHT;
	ofCreateWindow(settings);

	ofRunApp(new drawing::ofApp());

}
