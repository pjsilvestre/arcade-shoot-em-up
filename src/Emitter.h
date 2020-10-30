#pragma once

#include "ActorSystem.h"
#include "Constants.h"

class Emitter {
 public:
  void update();
  void draw();

  void setPosition(const glm::vec3& position) { this->position = position; }
  void setDirection(const glm::vec3& direction) { this->direction = direction; }

  void start();
  void stop();
  void setSound(const string& filename);

 protected:
  void emit();

  bool started{false};
  float lifespan{Constants::ACTOR_LIFESPAN};
  float magnitude{Constants::EMITTER_MAGNITUDE};
  float spriteRatePerSecond{Constants::SPRITES_PER_SECOND};
  float timeOfLastEmittedActor{0.0f};
  glm::vec3 position{glm::vec3(0.0f)};
  glm::vec3 direction{glm::vec3(0.0f)};
  Sprite sprite{Sprite()};
  ActorSystem actors{ActorSystem()};
  ofSoundPlayer sound{ofSoundPlayer()};
};
