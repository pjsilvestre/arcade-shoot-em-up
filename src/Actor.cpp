#include "Actor.h"

/**
 * @brief Updates this Actor's state
 */
void Actor::update() {
  integrate();
  updateTransformationMatrix();
  sprite.setTransformationMatrix(transform);
}

/**
 * @brief Draws this Actor
 */
void Actor::draw() { sprite.draw(); }

/**
 * @brief Gets this Actor's age in seconds
 */
float Actor::getAge() { return ofGetElapsedTimef() - spawnTime; }

/**
 * @brief Moves this Actor according to a given force
 * @param direction The applied force
 */
void Actor::move(const glm::vec3& force) { acceleration = force; }

//-Protected Methods--------------------------------------------

void Actor::integrate() {
  float timestep = 1.0f / ofGetFrameRate();

  position += velocity * timestep;

  if (glm::length(velocity) < maxVelocity) {
    velocity += acceleration * timestep;
  }

  velocity *= velocityDamping;
  acceleration *= accelerationDamping;

  if (integrationStrategy != nullptr) {
    integrationStrategy->integrate();
  }
  else {
    cerr << "Actor missing integrationStrategy" << endl;
  }
}

void Actor::updateTransformationMatrix() {
  transform = glm::translate(glm::mat4(1.0f), position);
}
