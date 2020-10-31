#pragma once

#include "ActorSystem.h"
#include "Constants.h"
#include "IntegrationStrategy.h"

class Emitter {
 public:
  void update();
  void draw();

  void setRate(float rate) { this->spriteRatePerSecond = rate; }
  void setPosition(const glm::vec3& position) { this->position = position; }
  void setDirection(const glm::vec3& direction) { this->direction = direction; }

  void start();
  void stop();
  void setSound(const string& filename);

 protected:
  void emit();

  bool soundLoaded{false};
  bool started{false};
  float lifespan{Constants::ACTOR_LIFESPAN};
  float magnitude{Constants::EMITTER_MAGNITUDE};
  float spriteRatePerSecond{Constants::SPRITES_PER_SECOND};
  float timeOfLastEmittedActor{0.0f};
  ActorSystem actors;
  Integration_Strategy_Type integrationStrategyType{
      Integration_Strategy_Type::actor};
  ofSoundPlayer sound;
  Sprite sprite;
  glm::vec3 direction{glm::vec3(0.0f)};
  glm::vec3 position{glm::vec3(0.0f)};
};
