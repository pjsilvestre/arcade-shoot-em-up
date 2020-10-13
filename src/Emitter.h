#pragma once

#include "ActorSystem.h"
#include "Constants.h"

class Emitter {
 public:
  Emitter();
  Emitter(const Sprite& sprite);

  void update();
  void draw();

  void setLifespan(const int lifespan) { this->lifespan = lifespan; }
  void setPosition(const glm::vec3& position) { this->position = position; }
  void setDirection(const glm::vec3& direction) { this->direction = direction; }

  void emit();

 private:
  int lifespan;
  glm::vec3 position;
  glm::vec3 direction;

  Sprite sprite;
  ActorSystem actors;
};
