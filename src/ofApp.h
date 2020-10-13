#pragma once

#include "Actor.h"
#include "ActorSystem.h"
#include "Constants.h"
#include "Emitter.h"
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
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

 private:
  void preventResize();
  void drawStartMessage();

  bool gameNotStarted;
  Player player;

  // ofxVec2Slider emitterDirection;
  // ofxPanel gui;
};
