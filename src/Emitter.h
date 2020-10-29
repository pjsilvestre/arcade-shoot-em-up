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
  void setRate(const int rate) { this->spriteRatePerSecond = rate; }
  void setPosition(const glm::vec3& position) { this->position = position; }
  void setDirection(const glm::vec3& direction) { this->direction = direction; }

  void start();
  void stop();

 private:
  void emit();

  bool started;
  int lifespan;
  float magnitude;
  float spriteRatePerSecond;
  float timeOfLastEmittedActor;
  glm::vec3 position;
  glm::vec3 direction;
  Sprite sprite;
  ActorSystem actors;
  ofSoundPlayer sound;
};
