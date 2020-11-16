#include "ExplosionSystem.h"

/**
 * @brief Creates an ExplosionSystem
 */
ExplosionSystem::ExplosionSystem() {
  // TODO refactor Emitter and all related classes to support Emitting > 1 Actor
  // per emission? current implementation sometimes introduces hitching upon
  // first couple of explosions due to maybe memory allocation, which disappears
  // upon subsequent explosions

  for (int i = 0; i < Constants::EXPLOSION_GROUP_SIZE; i++) {
    ExplosionEmitter emitter;
    emitter.enableOneShot();
    emitters.push_back(emitter);
  }
};

/**
 * @brief Updates the associated ExplosionEmitters
 */
void ExplosionSystem::update() {
  for (auto& emitter : emitters) {
    emitter.update();
  }
};

/**
 * @brief Updates the associated ExplosionEmitters
 */
void ExplosionSystem::draw() {
  for (auto& emitter : emitters) {
    emitter.draw();
  }
};

/**
 * @brief Emits explosions with random direction and magnitude at a given
 * position
 * @param collisionPosition The position to emit the explosion from
 */
void ExplosionSystem::explode(const ofWindowPosEventArgs& collisionPosition) {
  auto position = glm::vec3(collisionPosition.x, collisionPosition.y, 0.0f);

  for (auto& emitter : emitters) {
    auto randomDirection =
        glm::vec3(ofRandom(-1.0f, 1.0f), ofRandom(-1.0f, 1.0f), 0.0f);
    float randomMagnitude = ofRandom(Constants::EXPLOSION_MAGNITUDE / 2,
                                     Constants::EXPLOSION_MAGNITUDE);

    emitter.setPosition(position);
    emitter.setDirection(randomDirection);
    emitter.setMagnitude(randomMagnitude);

    emitter.start();
  }
};
//-Private Methods----------------------------------------------

/**
 * @brief Creates a ExplosionEmitter with the default explosion sprite
 */
ExplosionSystem::ExplosionEmitter::ExplosionEmitter() : Emitter() {
  actorLifespan = Constants::EXPLOSION_LIFESPAN;
  magnitude = Constants::EXPLOSION_MAGNITUDE;
  integrationStrategyType = Integration_Strategy_Type::explosion;

  Sprite explosionSprite;
  explosionSprite.loadImage(Constants::EXPLOSION_SPRITE());
  sprite = explosionSprite;
}
