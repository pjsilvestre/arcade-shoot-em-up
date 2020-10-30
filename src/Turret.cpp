#include "Turret.h"

/**
 * @brief Creates a Turret with the default missile sprite
 */
Turret::Turret() : Emitter() {
  this->setLifespan(Constants::MISSILE_LIFESPAN);
  this->setMagnitude(Constants::MISSILE_ACCELERATION_MAGNITUDE);

  Sprite sprite;
  sprite.setImage(Constants::MISSILE_SPRITE());
  this->setSprite(sprite);

  this->setSound(Constants::MISSILE_SOUND_EFFECT());
}