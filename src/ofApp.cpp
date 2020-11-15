#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundColor(ofColor::black);

  gui.setup();

  playerIntegrationStrategy = new PlayerIntegrationStrategy;
  player.setIntegrationStrategy(playerIntegrationStrategy);

  starSystem.start();
  enemySystem.start();

  addEventListeners();
}

//--------------------------------------------------------------
void ofApp::addEventListeners() {
  ofAddListener(player.missileLaunched, &soundPlayer,
                &SoundPlayer::playMissileSoundEffect);
  ofAddListener(enemySystem.actorCollided, &soundPlayer,
                &SoundPlayer::playCollisionSoundEffect);
  ofAddListener(enemySystem.actorCollided, &score, &Score::incrementScore);
  ofAddListener(enemySystem.actorCollided, &explosionSystem,
                &ExplosionSystem::explode);
  ofAddListener(enemySystem.actorCollided, &player, &Player::removeMissiles);
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

  starSystem.update();
  enemySystem.update();
  explosionSystem.update();
  player.update();

  checkCollisions();
}

//--------------------------------------------------------------
void ofApp::draw() {
  while (gameNotStarted) {
    drawStartMessage();
    return;
  }

  starSystem.draw();
  enemySystem.draw();
  explosionSystem.draw();
  player.draw();

  drawScore();

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
void ofApp::exit() {
  delete playerIntegrationStrategy;
  playerIntegrationStrategy = nullptr;

  removeEventListeners();
}

//--------------------------------------------------------------
void ofApp::removeEventListeners() {
  ofRemoveListener(player.missileLaunched, &soundPlayer,
                   &SoundPlayer::playMissileSoundEffect);
  ofRemoveListener(enemySystem.actorCollided, &soundPlayer,
                   &SoundPlayer::playCollisionSoundEffect);
  ofRemoveListener(enemySystem.actorCollided, &score, &Score::incrementScore);
  ofRemoveListener(enemySystem.actorCollided, &explosionSystem,
                   &ExplosionSystem::explode);
  ofRemoveListener(enemySystem.actorCollided, &player, &Player::removeMissiles);
}

//-Private Methods----------------------------------------------

//--------------------------------------------------------------
void ofApp::checkCollisions() {
  auto missilePositions = player.getMissilePositions();

  for (auto& position : missilePositions) {
    enemySystem.removeNear(position, 100.0f);
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

//--------------------------------------------------------------
void ofApp::drawScore() {
  // TODO replace bitmap string with truetype string

  string scoreMessage = "score: " + to_string(score.getScore());
  ofBitmapFont font;
  ofRectangle boundingBox = font.getBoundingBox(scoreMessage, 0, 0);
  ofSetColor(ofColor::white);
  ofDrawBitmapString(
      scoreMessage,
      glm::vec3(boundingBox.width / 2, 10.0f + boundingBox.height / 2, 0));
}

//--------------------------------------------------------------
void ofApp::preventResize() {
  if (ofGetWidth() != Constants::SCREEN_WIDTH ||
      ofGetHeight() != Constants::SCREEN_HEIGHT) {
    ofSetWindowShape(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
  }
}
