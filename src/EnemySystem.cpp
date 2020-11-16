#include "EnemySystem.h"

/**
 * @brief Creates an EnemySystem
 */
EnemySystem::EnemySystem() {
  addListeners();

  topSpawner.setPosition(glm::vec3(ofRandomWidth(), -200.0f, 0.0f));

  leftSpawner.setDirection(glm::vec3(1.0f, 0.0f, 0.0f));
  leftSpawner.setPosition(glm::vec3(-200.0f, 0.0f, 0.0f));
  leftSpawner.setRate(0.1f);
  leftSpawner.setIntegrationStrategyType(Integration_Strategy_Type::enemy_sine);

  // TODO properly encapsulate enemy sprite variants
  Sprite specialEnemySprite;
  specialEnemySprite.loadImage("enemy-saucer-orange.png");
  leftSpawner.setSprite(specialEnemySprite);

  spawners.push_back(&topSpawner);
  spawners.push_back(&leftSpawner);
}

/**
 * @brief Deletes this EnemySystem
 */
EnemySystem::~EnemySystem() { removeListeners(); }

/**
 * @brief Updates the associated EnemyEmitters
 */
void EnemySystem::update() {
  topSpawner.setPosition(glm::vec3(ofRandomWidth(), -200.0f, 0.0f));
  topSpawner.setRate(ofRandom(0.5f));

  leftSpawner.setRate(ofRandom(0.1f));

  for (auto spawner : spawners) {
    spawner->update();
  }
}

/**
 * @brief Draws the associated EnemyEmitters
 */
void EnemySystem::draw() {
  for (auto spawner : spawners) {
    spawner->draw();
  }
}

vector<glm::vec3> EnemySystem::getEnemyPositions() {
  // TODO optimization; add enemy position only when onscreen

  vector<glm::vec3> enemyPositions;

  for (auto spawner : spawners) {
    auto positions = spawner->getActorPositions();

    for (auto& position : positions) {
      enemyPositions.push_back(position);
    }
  }

  return enemyPositions;
}

/**
 * @brief Removes all Actors for all EnemyEmitters within a distance from a
 * point
 * @param point The removal origin
 * @param distance The threshold distance for removal
 */
void EnemySystem::removeNear(const glm::vec3& point, float distance) {
  for (auto spawner : spawners) {
    spawner->removeNear(point, distance);
  }
}

/**
 * @brief Starts the associated EnemyEmitters
 */
void EnemySystem::start() {
  for (auto spawner : spawners) {
    spawner->start();
  }
}

/**
 * @brief Notifies all listeners that for all EnemyEmitters, at least one
 * underlying Actor has collided
 * @param collisionPosition The collision position
 */
void EnemySystem::notifyCollision(
    const ofWindowPosEventArgs& collisionPosition) {
  ofNotifyEvent(actorCollided, collisionPosition, this);
}

//-Private Methods----------------------------------------------

/**
 * @brief Creates a EnemyEmitter with the default enemy sprite
 */
EnemySystem::EnemyEmitter::EnemyEmitter() : Emitter() {
  actorLifespan = Constants::ENEMY_LIFESPAN;
  magnitude = Constants::ENEMY_MAGNITUDE;
  ratePerSecond = Constants::ENEMY_RATE;
  integrationStrategyType = Integration_Strategy_Type::enemy_linear;
  direction = glm::vec3(0.0f, 1.0f, 0.0f);

  Sprite enemySprite;
  enemySprite.loadImage(Constants::ENEMY_SPRITE());
  sprite = enemySprite;
}

void EnemySystem::addListeners() {
  ofAddListener(topSpawner.actorCollided, this, &EnemySystem::notifyCollision);
  ofAddListener(leftSpawner.actorCollided, this, &EnemySystem::notifyCollision);
}
void EnemySystem::removeListeners() {
  ofRemoveListener(topSpawner.actorCollided, this,
                   &EnemySystem::notifyCollision);
  ofRemoveListener(leftSpawner.actorCollided, this,
                   &EnemySystem::notifyCollision);
}
