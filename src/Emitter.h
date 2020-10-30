#pragma once

#include "ActorSystem.h"
#include "Constants.h"

class Emitter {
 public:
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

  bool started{false};
  float lifespan{Constants::LIFESPAN};
  float magnitude{Constants::EMITTER_MAGNITUDE};
  float spriteRatePerSecond{Constants::SPRITES_PER_SECOND};
  float timeOfLastEmittedActor{0.0f};
  glm::vec3 position{glm::vec3(0.0f)};
  glm::vec3 direction{glm::vec3(0.0f)};
  Sprite sprite{Sprite()};
  ActorSystem actors{ActorSystem()};
  ofSoundPlayer sound{ofSoundPlayer()};
};
