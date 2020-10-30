#include "Player.h"

/**
 * @brief Creates a Player with the default player sprite
 */
Player::Player() : Actor() {
  this->setPosition(
      glm::vec3(Constants::SCREEN_WIDTH / 2, Constants::SCREEN_HEIGHT / 2, 0));

  Sprite sprite;
  sprite.setImage(Constants::PLAYER_SPRITE());
  this->setSprite(sprite);
};

/**
 * @brief Updates the Player's state
 */
void Player::update() {
  clampPosition();
  turret.setPosition(getPosition());
  turret.update();
  Actor::update();
}

/**
 * @brief Draws the Player
 */
void Player::draw() {
  turret.draw();
  Actor::draw();
}

/**
 * @brief Starts the turret
 */
void Player::startTurret() { turret.start(); }

/**
 * @brief Stops the turret
 */
void Player::stopTurret() { turret.stop(); }

//-Private Methods----------------------------------------------

void Player::clampPosition() {
  glm::vec3 position{getPosition()};
  glm::vec3 newPosition = position;

  newPosition.x = Utility::clamp(newPosition.x, 0, Constants::SCREEN_WIDTH);
  newPosition.y = Utility::clamp(newPosition.y, 0, Constants::SCREEN_HEIGHT);

  setPosition(newPosition);
}
