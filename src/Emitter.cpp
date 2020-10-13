#include "Emitter.h"

/**
 * @brief Create an Emitter with an associated Sprite
 * @param sprite The desired Sprite
 */
Emitter::Emitter(const Sprite& sprite) : sprite{sprite} {}

/**
 * @brief Update the associated ActorSystem
 */
void Emitter::update() { actors.update(); }

/**
 * @brief Draw the associated ActorSystem
 */
void Emitter::draw() { actors.draw(); }

/**
 * @brief Emit an Actor from the associated ActorSystem
 */
void Emitter::emit() {
  Actor missile = Actor(sprite);
  missile.setPosition(glm::vec3(1280 / 2, 720 / 2, 1));
  missile.setLifespan(500);
  actors.add(missile);

  actors.moveActors(glm::vec3(0, -1, 0));
}
