#include "StarEmitter.h"

StarEmitter::StarEmitter() : Emitter() {
  actorLifespan = Constants::STAR_LIFESPAN;
  magnitude = Constants::STAR_MAGNITUDE;
  integrationStrategyType = Integration_Strategy_Type::actor;
  direction = glm::vec3(0.0f, 1.0f, 0.0f);

  Sprite starSprite;
  starSprite.loadImage(Constants::STAR_SPRITE());
  sprite = starSprite;
}