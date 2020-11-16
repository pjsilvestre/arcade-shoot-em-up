#pragma once

#include "Constants.h"
#include "EnemySystem.h"
#include "ExplosionSystem.h"
#include "IntegrationStrategy.h"
#include "Player.h"
#include "Score.h"
#include "SoundPlayer.h"
#include "StarSystem.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void addEventListeners();

  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);

  void exit();
  void removeEventListeners();

 private:
  void checkMissileEnemyCollisions();
  void checkPlayerEnemyCollisions();
  void drawStartMessage();
  void drawScore();

  bool gameNotStarted{true};
  bool guiShown{false};

  ofTrueTypeFont font;

  StarSystem starSystem;
  EnemySystem enemySystem;
  ExplosionSystem explosionSystem;
  Player player;

  Score score;
  SoundPlayer soundPlayer;

  // following pointers MUST be deallocated in exit()
  IntegrationStrategy* playerIntegrationStrategy{nullptr};
};
