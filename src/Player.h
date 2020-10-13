#pragma once

#include "Actor.h"
#include "Constants.h"

class Player : public Actor {
 public:
  Player() : Actor(Sprite(Constants::PLAYER_SPRITE())) {
    this->setPosition(
        glm::vec3(Constants::SCREEN_WIDTH / 2, Constants::SCREEN_HEIGHT / 2, 0));
  };

  void update() override;

 private:
  void clampPosition();
};
