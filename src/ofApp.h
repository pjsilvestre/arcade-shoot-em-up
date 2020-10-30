#pragma once

#include "Actor.h"
#include "ActorSystem.h"
#include "Constants.h"
#include "Emitter.h"
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

 private:
  void preventResize();
  void drawStartMessage();

  bool gameNotStarted;
  bool mouseEnabled;
  bool guiShown;

  Player player;
  ofxIntSlider missileRate;
  ofxPanel gui;
};
