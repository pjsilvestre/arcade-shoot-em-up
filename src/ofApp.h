/*
 * TODO player health (1 life?)
 * TODO enemy explosions on death
 * TODO player explosions on death
 * TODO juice player movement
 * TODO new sound effects
 */

#pragma once

#include "ActorSystem.h"
#include "Constants.h"
#include "EnemySystem.h"
#include "Player.h"
#include "Score.h"
#include "SoundPlayer.h"
#include "StarSystem.h"
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
  void checkCollisions();
  void drawStartMessage();
  void drawScore();
  void preventResize();

  bool gameNotStarted{true};
  bool guiShown{false};
  bool mouseEnabled{false};

  StarSystem starSystem;
  EnemySystem enemySystem;
  Player player;

  ofxPanel gui;
  Score score;
  SoundPlayer soundPlayer;

  // following pointers MUST be deallocated in exit()
  IntegrationStrategy* playerIntegrationStrategy{nullptr};
};
