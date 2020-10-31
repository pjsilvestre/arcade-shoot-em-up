#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundColor(ofColor::black);

  player = new Player;
  player->setIntegrationStrategy(new PlayerIntegrationStrategy);

  gui.setup();

  topLeftSpawner.setPosition(glm::vec3(100.0f, -200.0f, 0.0f));
  topRightSpawner.setPosition(
      glm::vec3(Constants::SCREEN_WIDTH - 100.0f, -200.0f, 0.0f));
  middleLeftSpawner.setPosition(
      glm::vec3(-200.0f, Constants::SCREEN_HEIGHT / 2, 0.0f));
  middleLeftSpawner.setDirection(glm::vec3(1.0f, 0.0f, 0.0f));

  topRightSpawner.setRate(0.75f);
  middleLeftSpawner.setRate(0.25f);

  middleLeftSpawner.setIntegrationStrategyType(
      Integration_Strategy_Type::enemy_sine);

  topLeftSpawner.start();
  topRightSpawner.start();
  middleLeftSpawner.start();
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
  topLeftSpawner.update();
  topRightSpawner.update();
  middleLeftSpawner.update();
  missilePositions = player->getMissilePositions();

  for (auto& position : missilePositions) {
    cout << position << endl;
    topLeftSpawner.removeNear(position, 100.0f);
    topRightSpawner.removeNear(position, 100.0f);
    middleLeftSpawner.removeNear(position, 100.0f);
  }
  cout << endl;
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
  topLeftSpawner.draw();
  topRightSpawner.draw();
  middleLeftSpawner.draw();
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
