#include "EnemySpawner.h"

EnemySpawner::EnemySpawner() : Emitter() {
  lifespan = Constants::ENEMY_LIFESPAN;
  magnitude = Constants::ENEMY_MAGNITUDE;
  spriteRatePerSecond = Constants::ENEMY_RATE;
  integrationStrategyType = Integration_Strategy_Type::enemy_linear;
  direction = glm::vec3(0.0f, 1.0f, 0.0f);

  Sprite enemySprite;
  enemySprite.setImage(Constants::ENEMY_SPRITE());
  sprite = enemySprite;
}