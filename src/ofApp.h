#pragma once

#include "Actor.h"
#include "ActorSystem.h"
#include "Constants.h"
#include "Emitter.h"
#include "IntegrationStrategy.h"
#include "Player.h"
#include "Sprite.h"
#include "ofMain.h"
#include "ofThread.h"
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
  void preventResize();
  void drawStartMessage();

  bool gameNotStarted{true};
  bool guiShown{false};
  bool mouseEnabled{false};

  // all memory allocated here must be deallocated in exit()
  Player* player{nullptr};
  IntegrationStrategy* playerIntegrationStrategy{nullptr};

  ofxPanel gui;
  Emitter enemyEmitter;
};
