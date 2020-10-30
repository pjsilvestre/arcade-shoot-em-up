#include "Turret.h"

/**
 * @brief Creates a Turret with the default missile sprite
 */
Turret::Turret() : Emitter() {
  this->setLifespan(Constants::MISSILE_LIFESPAN);
  this->setMagnitude(Constants::MISSILE_ACCELERATION_MAGNITUDE);
  this->setDirection(glm::vec3(0.0f, -1.0f, 0.0f));

  Sprite sprite;
  sprite.setImage(Constants::MISSILE_SPRITE());
  this->setSprite(sprite);

  this->setSound(Constants::MISSILE_SOUND_EFFECT());
}