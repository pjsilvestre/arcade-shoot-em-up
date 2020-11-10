#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetBackgroundColor(ofColor::black);

  gui.setup();

  playerIntegrationStrategy = new PlayerIntegrationStrategy;
  player.setIntegrationStrategy(playerIntegrationStrategy);

  leftSpawner.setDirection(glm::vec3(1.0f, 0.0f, 0.0f));
  leftSpawner.setPosition(glm::vec3(-200.0f, 0.0f, 0.0f));
  leftSpawner.setRate(0.1f);
  leftSpawner.setIntegrationStrategyType(Integration_Strategy_Type::enemy_sine);

  // TODO properly encapsulate enemy sprite variants
  Sprite specialEnemySprite;
  specialEnemySprite.loadImage("enemy-saucer-orange.png");
  leftSpawner.setSprite(specialEnemySprite);

  topSpawner.start();
  leftSpawner.start();
  starSystem.start();

  addEventListeners();
}

//--------------------------------------------------------------
void ofApp::addEventListeners() {
  ofAddListener(player.missileLaunched, &soundPlayer,
                &SoundPlayer::playMissileSoundEffect);
  ofAddListener(topSpawner.actors.actorCollided, &soundPlayer,
                &SoundPlayer::playCollisionSoundEffect);
  ofAddListener(leftSpawner.actors.actorCollided, &soundPlayer,
                &SoundPlayer::playCollisionSoundEffect);
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

  topSpawner.setPosition(glm::vec3(ofRandomWidth(), -200.0f, 0.0f));
  topSpawner.setRate(ofRandom(0.5f));
  topSpawner.update();

  leftSpawner.setRate(ofRandom(0.1f));
  leftSpawner.update();

  starSystem.update();

  checkCollisions();

  numberOfEnemiesDestroyed =
      topSpawner.getActorCollidedCount() + leftSpawner.getActorCollidedCount();
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

  starSystem.draw();
  topSpawner.draw();
  leftSpawner.draw();
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
  ofRemoveListener(topSpawner.actors.actorCollided, &soundPlayer,
                   &SoundPlayer::playCollisionSoundEffect);
  ofRemoveListener(leftSpawner.actors.actorCollided, &soundPlayer,
                   &SoundPlayer::playCollisionSoundEffect);
}

//-Private Methods----------------------------------------------

//--------------------------------------------------------------
void ofApp::checkCollisions() {
  auto missilePositions = player.getMissilePositions();

  for (auto& position : missilePositions) {
    topSpawner.removeNear(position, 100.0f);
    leftSpawner.removeNear(position, 100.0f);
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

  string scoreMessage = "score: " + to_string(numberOfEnemiesDestroyed);
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
