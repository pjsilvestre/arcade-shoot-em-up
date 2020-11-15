#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundColor(ofColor::black);
  montserratSubrayada.load("MontserratSubrayada-Regular.ttf", 40, true, true);

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

  starSystem.update();
  enemySystem.update();
  explosionSystem.update();
  player.update();

  checkMissileEnemyCollisions();
  checkPlayerEnemyCollisions();
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
void ofApp::checkMissileEnemyCollisions() {
  auto missilePositions = player.getMissilePositions();

  for (auto& position : missilePositions) {
    enemySystem.removeNear(position, Constants::COLLISION_THRESHOLD);
  }
}

//--------------------------------------------------------------
void ofApp::checkPlayerEnemyCollisions() {
  auto position = player.getPosition();
  vector<glm::vec3> enemyPositions = enemySystem.getEnemyPositions();

  for (auto& enemyPosition : enemyPositions) {
    if (abs(glm::length(position - enemyPosition)) <
        Constants::COLLISION_THRESHOLD) {
      score.reset();
    }
  }
}

//--------------------------------------------------------------
void ofApp::drawStartMessage() {
  int verticalOffset = -100;
  vector<string> startMessages = {
      "Use WASD to move",
      "Use space to shoot",
      "Score resets upon player collision with enemy",
      "",
      "",
      "Press space to start"};

  for (auto& message : startMessages) {
    ofRectangle boundingBox =
        montserratSubrayada.getStringBoundingBox(message, 0, 0);
    montserratSubrayada.drawString(
        message, ofGetWidth() / 2 - boundingBox.width / 2,
        ofGetHeight() / 2 - boundingBox.height / 2 + verticalOffset);
    verticalOffset += 50;
  }
}

//--------------------------------------------------------------
void ofApp::drawScore() {
  string scoreMessage = "score: " + to_string(score.getScore());
  ofSetColor(ofColor::white);
  montserratSubrayada.drawString(scoreMessage, 25, 50);
}

//--------------------------------------------------------------
void ofApp::preventResize() {
  if (ofGetWidth() != Constants::SCREEN_WIDTH ||
      ofGetHeight() != Constants::SCREEN_HEIGHT) {
    ofSetWindowShape(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
  }
}
