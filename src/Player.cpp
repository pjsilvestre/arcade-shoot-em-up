#include "Player.h"

/**
 * @brief Creates a Player
 */
Player::Player() : Actor() {
  initialAcceleration = Constants::PLAYER_INITIAL_ACCELERATION;
  position =
      glm::vec3(Constants::SCREEN_WIDTH / 2, Constants::SCREEN_HEIGHT / 2, 0);
  sprite.loadImage(Constants::PLAYER_SPRITE());
};

/**
 * @brief Updates this Player's state
 */
void Player::update() {
  clampPosition();
  turret.setPosition(position);
  turret.update();
  Actor::update();
}

/**
 * @brief Draws this Player
 */
void Player::draw() {
  turret.draw();
  Actor::draw();
}

/**
 * @brief Gets the position of all of the Player's in-flight missiles
 * @return A vector of missile positions
 */
vector<glm::vec3> Player::getMissilePositions() {
  return turret.getActorPositions();
}

/**
 * @brief Moves this Player up
 */
void Player::moveUp() {
  // y values shrink upwards
  acceleration.y = -initialAcceleration;
}

/**
 * @brief Moves this Player left
 */
void Player::moveLeft() { acceleration.x = -initialAcceleration; }

/**
 * @brief Moves this Player down
 */
void Player::moveDown() {
  // y values grow downwards
  acceleration.y = initialAcceleration;
}

/**
 * @brief Moves this Player right
 */
void Player::moveRight() { acceleration.x = initialAcceleration; }

void Player::stop() { acceleration = glm::vec3(0.0f); }

/**
 * @brief Starts the turret
 */
void Player::startTurret() {
  turret.start();
  ofEventArgs noArgs;
  ofNotifyEvent(missileLaunched, noArgs, this);
  // TODO either send event every time a missile is launched, or limit turret to
  // one shot per keypress
}

/**
 * @brief Stops the turret
 */
void Player::stopTurret() { turret.stop(); }

//-Private Methods----------------------------------------------

void Player::clampPosition() {
  glm::vec3 newPosition = position;

  newPosition.x = Utility::clamp(newPosition.x, 0, Constants::SCREEN_WIDTH);
  newPosition.y = Utility::clamp(newPosition.y, 0, Constants::SCREEN_HEIGHT);

  position = newPosition;
}
