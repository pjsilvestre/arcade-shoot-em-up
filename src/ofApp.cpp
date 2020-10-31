#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundColor(ofColor::black);

  player = new Player;
  player->setIntegrationStrategy(new PlayerIntegrationStrategy);

  gui.setup();

  leftEnemySpawner.setPosition(glm::vec3(100.0f, -200.0f, 0.0f));
  rightEnemySpawner.setPosition(
      glm::vec3(Constants::SCREEN_WIDTH - 100.0f, -200.0f, 0.0f));

  rightEnemySpawner.setRate(0.75f);

  leftEnemySpawner.start();
  rightEnemySpawner.start();
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

  player->update();
  leftEnemySpawner.update();
  rightEnemySpawner.update();
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

  player->draw();
  leftEnemySpawner.draw();
  rightEnemySpawner.draw();
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
      player->moveUp();
      break;
    case 'a':
      player->moveLeft();
      break;
    case 's':
      player->moveDown();
      break;
    case 'd':
      player->moveRight();
      break;
    case ' ':
      player->startTurret();
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
      player->stop();
      break;
    case ' ':
      player->stopTurret();
      break;
  }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
  if (mouseEnabled) {
    player->setPosition(glm::vec3(x, y, 0));
  }
}

//--------------------------------------------------------------
void ofApp::exit() {
  delete player;
  player = nullptr;

  delete playerIntegrationStrategy;
  playerIntegrationStrategy = nullptr;
}

//-Private Methods----------------------------------------------

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

//--------------------------------------------------------------
void ofApp::preventResize() {
  if (ofGetWidth() != Constants::SCREEN_WIDTH ||
      ofGetHeight() != Constants::SCREEN_HEIGHT) {
    ofSetWindowShape(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
  }
}
