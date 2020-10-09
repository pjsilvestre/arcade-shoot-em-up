#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundColor(ofColor::darkGrey);
  playerSprite = Sprite("battery.png");
  player = Player(playerSprite);
  player.setPosition(glm::vec3(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f, 0.0f));
}

//--------------------------------------------------------------
void ofApp::update() { player.update(); }

//--------------------------------------------------------------
void ofApp::draw() { player.draw(); }

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  Command* command = inputHandler.handleInput(key);

  if (command) {
    command->execute(player);
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
