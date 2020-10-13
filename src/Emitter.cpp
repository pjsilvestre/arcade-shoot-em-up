#include "Emitter.h"

/**
 * @brief Create an Emitter with no associated Sprite
 */
Emitter::Emitter() : lifespan{Constants::LIFESPAN} {}

/**
 * @brief Create an Emitter with an associated Sprite
 * @param sprite The desired Sprite
 */
Emitter::Emitter(const Sprite& sprite) : Emitter() { this->sprite = sprite; }

/**
 * @brief Update the associated ActorSystem
 */
void Emitter::update() { 
  actors.update(); 
}

/**
 * @brief Draw the associated ActorSystem
 */
void Emitter::draw() { actors.draw(); }

/**
 * @brief Emit an Actor from the associated ActorSystem
 */
void Emitter::emit() {
  Actor missile = Actor(sprite);
  missile.setPosition(position);
  missile.setLifespan(lifespan);
  actors.add(missile);

  actors.update();

  actors.moveActors(glm::normalize(direction));
}
