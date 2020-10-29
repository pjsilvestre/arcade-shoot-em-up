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

  player.setTurretRate(missileRate);
  auto x = turretDirection->x;
  auto y = turretDirection->y;
  player.setTurretDirection(glm::vec3(x, y, 0));
  player.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  while (gameNotStarted) {
    drawStartMessage();
    return;
  }

  if (guiShown) {
    gui.draw();
  }

  player.draw();
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
      player.dampMotion();
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
