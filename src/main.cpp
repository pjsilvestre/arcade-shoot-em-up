#include "ofApp.h"
#include "ofMain.h"

int main() {
  ofSetupOpenGL(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, OF_WINDOW);
  ofRunApp(new ofApp());
}
