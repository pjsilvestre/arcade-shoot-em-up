#include "Player.h"

/**
 * @brief Create a Player with the default player sprite
 */
Player::Player() : Actor(Sprite(Constants::PLAYER_SPRITE())) {
  this->setPosition(
      glm::vec3(Constants::SCREEN_WIDTH / 2, Constants::SCREEN_HEIGHT / 2, 0));
  turret = Emitter(Constants::MISSILE_SPRITE());
  turret.setLifespan(Constants::MISSILE_LIFESPAN);
};

/**
 * @brief Update the Player's state
 */
void Player::update() {
  clampPosition();
  turret.setPosition(getPosition());
  turret.setDirection(glm::vec3(0, -1, 0));
  //turret.setDirection(...) TODO dynamic direction
  turret.update();

  Actor::update();
}

/**
 * @brief Draw the Player
*/
void Player::draw() {
  turret.draw();

  Actor::draw();
}

/**
 * @brief Shoot a missile from the Player's turret
 */
void Player::shoot() {
  turret.emit(); // TODO dynamic rate
}

//-Private Methods----------------------------------------------

void Player::clampPosition() {
  glm::vec3 position{getPosition()};
  glm::vec3 newPosition = position;

  newPosition.x = Utility::clamp(newPosition.x, 0, Constants::SCREEN_WIDTH);
  newPosition.y = Utility::clamp(newPosition.y, 0, Constants::SCREEN_HEIGHT);

  setPosition(newPosition);
}
