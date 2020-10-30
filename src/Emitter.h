#pragma once

#include "ActorSystem.h"
#include "Constants.h"

class Emitter {
 public:
  Emitter();

  void update();
  void draw();

  void setLifespan(const float lifespan) { this->lifespan = lifespan; }
  void setMagnitude(const float magnitude) { this->magnitude = magnitude; }
  void setRate(const int rate) { this->spriteRatePerSecond = rate; }
  void setPosition(const glm::vec3& position) { this->position = position; }
  void setDirection(const glm::vec3& direction) { this->direction = direction; }
  void setSprite(const Sprite& sprite) { this->sprite = sprite; }

  void start();
  void stop();
  void setSound(const string& filename);

 private:
  void emit();

  bool started;
  float lifespan;
  float magnitude;
  float spriteRatePerSecond;
  float timeOfLastEmittedActor;
  glm::vec3 position;
  glm::vec3 direction;
  Sprite sprite;
  ActorSystem actors;
  ofSoundPlayer sound;
};
