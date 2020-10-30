#pragma once

#include "Actor.h"

class ActorSystem {
 public:
  void update();
  void draw();

  void add(Actor& actor) { actors.push_back(actor); }
  void setPosition(const glm::vec3& position);
  void moveActors(const glm::vec3& direction);

 private:
  void deleteDeadActors();

  vector<Actor> actors{vector<Actor>()};
};
