#include "Actor.h"

/**
 * @brief Creates an Actor with no Sprite
 */
Actor::Actor()
    : age{0},
      lifespan{Constants::LIFESPAN},
      position{glm::vec3(0.0f)},
      velocity{glm::vec3(0.0f)},
      acceleration{glm::vec3(0.0f)} {}

/**
 * @brief Creates an Actor with a Sprite
 * @param sprite The desired Sprite
 */
Actor::Actor(const Sprite& sprite) : Actor() { this->sprite = sprite; }

/**
 * @brief Updates the Actor's state
 */
void Actor::update() {
  age++;
  updatePosition();
  updateVelocity();
  updateTransformationMatrix();
  sprite.setTransformationMatrix(transformationMatrix);
}

/**
 * @brief Draws the Actor
 */
void Actor::draw() { sprite.draw(); }

/**
 * @brief Moves the Actor in a given direction
 * @param direction The desired direction
 */
void Actor::move(const glm::vec3& direction) {
  acceleration = glm::normalize(direction);
}

/**
 * @brief Moves the Actor up
 */
void Actor::moveUp() {
  // y values shrink upwards
  acceleration.y = -Constants::ACCELERATION;
}

/**
 * @brief Moves the Actor left
 */
void Actor::moveLeft() { acceleration.x = -Constants::ACCELERATION; }

/**
 * @brief Moves the Actor down
 */
void Actor::moveDown() {
  // y values grow downwards
  acceleration.y = Constants::ACCELERATION;
}

/**
 * @brief Moves the Actor right
 */
void Actor::moveRight() { acceleration.x = Constants::ACCELERATION; }

/**
 * @brief Stops the Actor
 */
void Actor::stop() {
  velocity = glm::vec3(0.0f);
  acceleration = glm::vec3(0.0f);
}

//-Private Methods----------------------------------------------

void Actor::updatePosition() {
  // TODO integrate framerate as time delta
  position += velocity;
}

void Actor::updateVelocity() {
  velocity += acceleration;

  velocity.x = Utility::clamp(velocity.x, -Constants::MAX_VELOCITY,
                              Constants::MAX_VELOCITY);
  velocity.y = Utility::clamp(velocity.y, -Constants::MAX_VELOCITY,
                              Constants::MAX_VELOCITY);
}

void Actor::updateTransformationMatrix() {
  transformationMatrix = glm::translate(glm::mat4(1.0f), position);
}
