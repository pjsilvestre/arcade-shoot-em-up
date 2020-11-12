#include "EnemyEmitter.h"

EnemyEmitter::EnemyEmitter() : Emitter() {
  actorLifespan = Constants::ENEMY_LIFESPAN;
  magnitude = Constants::ENEMY_MAGNITUDE;
  ratePerSecond = Constants::ENEMY_RATE;
  integrationStrategyType = Integration_Strategy_Type::enemy_linear;
  direction = glm::vec3(0.0f, 1.0f, 0.0f);

  Sprite enemySprite;
  enemySprite.loadImage(Constants::ENEMY_SPRITE());
  sprite = enemySprite;
}