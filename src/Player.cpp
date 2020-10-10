#include "Player.h"

/**
 * @brief Update the Player's state
*/
void Player::update() {
  clamp();
  Actor::update();
}

void Player::clamp() {
  glm::vec3 position{getPosition()};
  glm::vec3 newPosition = position;

  if (position.x < 0) {
    newPosition = glm::vec3(0, position.y, 0);
  } else if (Constants::DEFAULT_WIDTH < position.x) {
    newPosition = glm::vec3(Constants::DEFAULT_WIDTH, position.y, 0);
  } else if (position.y < 0) {
    newPosition = glm::vec3(position.x, 0, 0);
  } else if (Constants::DEFAULT_HEIGHT < position.y) {
    newPosition = glm::vec3(position.x, Constants::DEFAULT_HEIGHT, 0);
  }

  setPosition(newPosition);
}
