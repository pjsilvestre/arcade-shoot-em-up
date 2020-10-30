#include "Turret.h"

/**
 * @brief Creates a Turret with the default missile sprite
 */
Turret::Turret()
    : Emitter(Constants::MISSILE_SPRITE(), &Constants::MISSILE_SOUND_EFFECT()) {
  this->setMagnitude(Constants::MISSILE_ACCELERATION_MAGNITUDE);
  this->setLifespan(Constants::MISSILE_LIFESPAN);
}