/*
 * TODO player explosions on collision
 * TODO new sound effects
 */

#pragma once

#include "Actor.h"
#include "ActorSystem.h"
#include "Constants.h"
#include "Emitter.h"
#include "EnemyEmitter.h"
#include "EnemySystem.h"
#include "ExplosionEmitter.h"
#include "ExplosionSystem.h"
#include "IntegrationStrategy.h"
#include "Player.h"
#include "Score.h"
#include "SoundPlayer.h"
#include "Sprite.h"
#include "StarEmitter.h"
#include "StarSystem.h"
#include "Turret.h"
#include "Utility.h"
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

  ofTrueTypeFont montserratSubrayada;

  StarSystem starSystem;
  EnemySystem enemySystem;
  ExplosionSystem explosionSystem;
  Player player;

  Score score;
  SoundPlayer soundPlayer;

  // following pointers MUST be deallocated in exit()
  IntegrationStrategy* playerIntegrationStrategy{nullptr};
};
