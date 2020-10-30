#include "Actor.h"

/**
 * @brief Creates an Actor with no Sprite
 */
Actor::Actor()
    : initialAcceleration{Constants::ACCELERATION},
      spawnTime{ofGetElapsedTimef()},
      lifespan{Constants::LIFESPAN},
      position{glm::vec3(0.0f)},
      velocity{glm::vec3(0.0f)},
      acceleration{glm::vec3(0.0f)} {}

/**
 * @brief Updates the Actor's state
 */
void Actor::update() {
  updatePosition();
  updateTransformationMatrix();
  sprite.setTransformationMatrix(transformationMatrix);
}

/**
 * @brief Draws the Actor
 */
void Actor::draw() { sprite.draw(); }

/**
 * @brief Gets this Actor's age in seconds
 */
float Actor::getAge() { return ofGetElapsedTimef() - spawnTime; }

/**
 * @brief Moves the Actor in a given direction
 * @param direction The desired direction
 */
void Actor::move(const glm::vec3& direction) { acceleration = direction; }

/**
 * @brief Moves the Actor up
 */
void Actor::moveUp() {
  // y values shrink upwards
  acceleration.y = -initialAcceleration;
}

/**
 * @brief Moves the Actor left
 */
void Actor::moveLeft() { acceleration.x = -initialAcceleration; }

/**
 * @brief Moves the Actor down
 */
void Actor::moveDown() {
  // y values grow downwards
  acceleration.y = initialAcceleration;
}

/**
 * @brief Moves the Actor right
 */
void Actor::moveRight() { acceleration.x = initialAcceleration; }

/**
 * @brief Stops the Actor
 */
void Actor::dampMotion() {
  while (glm::length(acceleration) > 0.1) {
    acceleration *= Constants::ACCELERATION_DAMPING;
  }
}

//-Private Methods----------------------------------------------

void Actor::updatePosition() {
  float timestep = 1.0f / ofGetFrameRate();

  position += velocity * timestep;
  velocity += acceleration * timestep;
  velocity *= Constants::VELOCITY_DAMPING;

  if (glm::length(velocity) < Constants::MIN_VELOCITY) {
    velocity = glm::vec3(0.0f);
  }
}

void Actor::updateTransformationMatrix() {
  transformationMatrix = glm::translate(glm::mat4(1.0f), position);
}
