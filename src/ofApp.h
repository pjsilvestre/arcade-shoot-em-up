/*
 * TODO decouple audio into separate class
 * TODO player health
 * TODO enemy explosions on death
 * TODO player explosions on death
 * TODO juice player movement
 * TODO parallax star field
 * TODO new sound effects
 */

#pragma once

#include "Actor.h"
#include "ActorSystem.h"
#include "Constants.h"
#include "Emitter.h"
#include "EnemySpawner.h"
#include "IntegrationStrategy.h"
#include "Player.h"
#include "Sprite.h"
#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void exit();

 private:
  void checkCollisions();
  void drawStartMessage();
  void drawScore();
  void preventResize();

  bool gameNotStarted{true};
  bool guiShown{false};
  bool mouseEnabled{false};
  int numberOfEnemiesDestroyed{0};

  ofxPanel gui;
  Player player;
  EnemySpawner topSpawner;
  EnemySpawner leftSpawner;

  // following pointers MUST be deallocated in exit()
  IntegrationStrategy* playerIntegrationStrategy{nullptr};
};
