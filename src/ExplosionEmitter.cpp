#include "ExplosionEmitter.h"

ExplosionEmitter::ExplosionEmitter() : Emitter() {
  actorLifespan = Constants::EXPLOSION_LIFESPAN;
  magnitude = Constants::EXPLOSION_MAGNITUDE;
  integrationStrategyType = Integration_Strategy_Type::explosion;

  Sprite explosionSprite;
  explosionSprite.loadImage(Constants::EXPLOSION_SPRITE());
  sprite = explosionSprite;
}
