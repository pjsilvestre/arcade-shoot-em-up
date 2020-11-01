#include "Turret.h"

/**
 * @brief Creates a Turret with the default missile sprite
 */
Turret::Turret() : Emitter() {
  actorLifespan = Constants::MISSILE_LIFESPAN;
  magnitude = Constants::MISSILE_MAGNITUDE;
  integrationStrategyType = Integration_Strategy_Type::turret;
  direction = glm::vec3(0.0f, -1.0f, 0.0f);

  Sprite missileSprite;
  missileSprite.loadImage(Constants::MISSILE_SPRITE());
  sprite = missileSprite;

  setEmissionSound(Constants::MISSILE_SOUND_EFFECT());
}
