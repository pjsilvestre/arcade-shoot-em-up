#pragma once
#include "Actor.h"

class ActorSystem {
 public:
  void update();
  void draw();

  void add(Actor& actor) { actors.push_back(actor); }

 private:
  void deleteDeadActors();
  vector<Actor> actors;
};
