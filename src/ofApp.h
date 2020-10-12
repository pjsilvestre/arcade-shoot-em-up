#pragma once

#include "Actor.h"
#include "ActorSystem.h"
#include "Command.h"
#include "Constants.h"
#include "InputHandler.h"
#include "Player.h"
#include "Sprite.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();

  void drawStartMessage();

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

  void preventResize();

  bool gameNotStarted;
  InputHandler inputHandler;
  ActorSystem enemies;
  Player player;
  Actor enemy;
};
