/*
 * TODO player health (1 life?)
 * TODO player explosions on death
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
#include "ofxGui.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void addEventListeners();

  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);

  void exit();
  void removeEventListeners();

 private:
  void checkMissileEnemyCollisions();
  void checkPlayerEnemyCollisions();
  void drawStartMessage();
  void drawScore();
  void preventResize();

  bool gameNotStarted{true};
  bool guiShown{false};
  bool mouseEnabled{false};

  StarSystem starSystem;
  EnemySystem enemySystem;
  ExplosionSystem explosionSystem;
  Player player;

  ofxPanel gui;
  Score score;
  SoundPlayer soundPlayer;

  // following pointers MUST be deallocated in exit()
  IntegrationStrategy* playerIntegrationStrategy{nullptr};
};
