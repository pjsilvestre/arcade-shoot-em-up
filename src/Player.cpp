#include "Player.h"

/**
 * @brief Creates a Player
 */
Player::Player() : Actor() {
  initialAcceleration = Constants::PLAYER_INITIAL_ACCELERATION;
  position = glm::vec3(ofGetWidth() / 2, ofGetHeight() / 2, 0);
  sprite.loadImage(Constants::PLAYER_SPRITE());
  turret.enableOneShot();
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

/**
 * @brief Removes all missiles
 * @param unusedArg Unused argument
 */
void Player::removeMissiles(const ofWindowPosEventArgs& unusedArg) {
  turret.removeAll();
}

/**
 * @brief Stops this Player
 */
void Player::stop() { acceleration = glm::vec3(0.0f); }

/**
 * @brief Starts the turret
 */
void Player::startTurret() {
  if (turretEnabled) {
    turret.start();
    ofEventArgs noArgs;
    ofNotifyEvent(missileLaunched, noArgs, this);
    turretEnabled = false;
  }
}

/**
 * @brief Stops the turret
 */
void Player::stopTurret() { turretEnabled = true; }

//-Private Methods----------------------------------------------

/**
 * @brief Creates a Turret with the default missile sprite
 */
Player::Turret::Turret() : Emitter() {
  actorLifespan = Constants::MISSILE_LIFESPAN;
  magnitude = Constants::MISSILE_MAGNITUDE;
  integrationStrategyType = Integration_Strategy_Type::turret;
  direction = glm::vec3(0.0f, -1.0f, 0.0f);

  Sprite missileSprite;
  missileSprite.loadImage(Constants::MISSILE_SPRITE());
  sprite = missileSprite;
}

void Player::clampPosition() {
  glm::vec3 newPosition = position;

  newPosition.x = Utility::clamp(newPosition.x, 0, ofGetWidth());
  newPosition.y = Utility::clamp(newPosition.y, 0, ofGetHeight());

  position = newPosition;
}
