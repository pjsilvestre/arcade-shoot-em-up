#include "ofApp.h"
#include "ofMain.h"

int main() {
  ofSetupOpenGL(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
                OF_GAME_MODE);
  ofRunApp(new ofApp());
}
