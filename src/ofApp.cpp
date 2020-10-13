#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundColor(ofColor::darkGrey);
  gameNotStarted = true;
  mouseEnabled = false;
  guiShown = true;

  gui.setup();
  gui.add(missileRate.setup("missiles per second",
                            Constants::SPRITES_PER_SECOND,
                            Constants::SPRITES_PER_SECOND, 16));
  gui.add(turretDirection.setup("turret direction", {0, -1}, {-1, -1}, {1, 1}));
}

//--------------------------------------------------------------
void ofApp::update() {
  preventResize();

  while (gameNotStarted) {
    return;
  }

  if (mouseEnabled) {
    ofHideCursor();
  } else {
    ofShowCursor();
  }

  auto x = turretDirection->x;
  auto y = turretDirection->y;
  player.setTurretRate(missileRate);
  player.setTurretDirection(glm::vec3(x, y, 0));
  player.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  while (gameNotStarted) {
    drawStartMessage();
    return;
  }

  player.draw();

  if (guiShown) {
    gui.draw();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  while (gameNotStarted) {
    if (key == ' ') {
      gameNotStarted = false;
    }

    return;
  }

  switch (key) {
    case 'h':
      guiShown = !guiShown;
      break;
    case 'm':
      mouseEnabled = !mouseEnabled;
      break;
    case 'w':
      player.moveUp();
      break;
    case 'a':
      player.moveLeft();
      break;
    case 's':
      player.moveDown();
      break;
    case 'd':
      player.moveRight();
      break;
    case ' ':
      player.startTurret();
      break;
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
  switch (key) {
    case 'w':
    case 'a':
    case 's':
    case 'd':
      player.stop();
      break;
    case ' ':
      player.stopTurret();
      break;
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
  if (mouseEnabled) {
    player.setPosition(glm::vec3(x, y, 0));
  }
}

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

//-Private Methods----------------------------------------------

//--------------------------------------------------------------
void ofApp::preventResize() {
  if (ofGetWidth() != Constants::SCREEN_WIDTH ||
      ofGetHeight() != Constants::SCREEN_HEIGHT) {
    ofSetWindowShape(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
  }
}

//--------------------------------------------------------------
void ofApp::drawStartMessage() {
  // TODO replace bitmap string with truetype string

  string startMessage = "Press space to start...";
  ofBitmapFont font;
  ofRectangle boundingBox = font.getBoundingBox(startMessage, 0, 0);
  ofSetColor(ofColor::black);
  ofDrawBitmapString(startMessage,
                     glm::vec3(ofGetWidth() / 2 - boundingBox.width / 2,
                               ofGetHeight() / 2 - boundingBox.height / 2, 0));
}
