#include "Actor.h"

/**
 * @brief Updates this Actor's state
 */
void Actor::update() {
  integrate();
  updateTransform();
  sprite.setTransform(transform);
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
 * @param force The applied force
 */
void Actor::move(const glm::vec3& force) { acceleration = force; }

//-Protected Methods--------------------------------------------

void Actor::integrate() {
  if (integrationStrategy != nullptr) {
    // TODO better solution that doesn't break encapsulation?
    integrationStrategy->integrate(position, velocity, acceleration);
  } else {
    cerr << "Actor missing integration strategy" << endl;
  }
}

void Actor::updateTransform() {
  transform = glm::translate(glm::mat4(1.0f), position);
}
