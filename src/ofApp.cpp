#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundColor(ofColor::black);
  gameNotStarted = true;
  mouseEnabled = false;
  guiShown = true;

  gui.setup();

  enemyEmitter.setLifespan(10.0f);
  enemyEmitter.setMagnitude(1000.0f);
  enemyEmitter.setPosition(glm::vec3(100.0f, -200.0f, 0.0f));
  enemyEmitter.setDirection(glm::vec3(0.0f, 1.0f, 0.0f));

  Sprite enemySprite;
  enemySprite.setImage(Constants::ENEMY_SPRITE());
  enemyEmitter.setSprite(enemySprite);
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

  player.update();
  enemyEmitter.update();
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
  enemyEmitter.draw();
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
    case 'e':
      enemyEmitter.start();
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
      break;
    case ' ':
      player.stopTurret();
      break;
    case 'e':
      // enemyEmitter.stop();
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
  ofSetColor(ofColor::white);
  ofDrawBitmapString(startMessage,
                     glm::vec3(ofGetWidth() / 2 - boundingBox.width / 2,
                               ofGetHeight() / 2 - boundingBox.height / 2, 0));
}
