#include "Player.h"

/**
 * @brief Creates a Player
 */
Player::Player() : Actor() {
  accelerationDamping = Constants::PLAYER_ACCELERATION_DAMPING;
  initialAcceleration = Constants::PLAYER_INITIAL_ACCELERATION;
  maxVelocity = Constants::PLAYER_MAX_VELOCITY;
  velocityDamping = Constants::PLAYER_VELOCITY_DAMPING;
  position =
      glm::vec3(Constants::SCREEN_WIDTH / 2, Constants::SCREEN_HEIGHT / 2, 0);
  sprite.setImage(Constants::PLAYER_SPRITE());
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
 * @brief Starts the turret
 */
void Player::startTurret() { turret.start(); }

/**
 * @brief Stops the turret
 */
void Player::stopTurret() { turret.stop(); }

//-Protected Methods--------------------------------------------

void Player::clampPosition() {
  glm::vec3 newPosition = position;

  newPosition.x = Utility::clamp(newPosition.x, 0, Constants::SCREEN_WIDTH);
  newPosition.y = Utility::clamp(newPosition.y, 0, Constants::SCREEN_HEIGHT);

  position = newPosition;
}

void Player::integrate() {
  // TODO customize player movement
  float timestep = 1.0f / ofGetFrameRate();

  position += velocity * timestep;

  if (glm::length(velocity) < maxVelocity) {
    velocity += acceleration * timestep;
  }

  velocity *= velocityDamping;
  acceleration *= accelerationDamping;
}
