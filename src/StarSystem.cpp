#include "StarSystem.h"

/**
 * @brief Creates a StarSystem
 */
StarSystem::StarSystem() {
  nearEmitter.setRate(Constants::NEAR_STAR_RATE);
  midEmitter.setRate(Constants::MID_STAR_RATE);
  farEmitter.setRate(Constants::FAR_STAR_RATE);

  nearEmitter.setMagnitude(Constants::NEAR_STAR_MAGNITUDE);
  midEmitter.setMagnitude(Constants::MID_STAR_MAGNTIUDE);
  farEmitter.setMagnitude(Constants::FAR_STAR_MAGNITUDE);

  nearEmitter.setScale(glm::vec3(Constants::NEAR_STAR_SCALE));
  midEmitter.setScale(glm::vec3(Constants::MID_STAR_SCALE));
  farEmitter.setScale(glm::vec3(Constants::FAR_STAR_SCALE));

  starEmitters.push_back(nearEmitter);
  starEmitters.push_back(midEmitter);
  starEmitters.push_back(farEmitter);
}

/**
 * @brief Updates this StarSystem
 */
void StarSystem::update() {
  for (auto& emitter : starEmitters) {
    emitter.setPosition(glm::vec3(ofRandomWidth(), -200.0f, 0.0f));
    emitter.update();
  }
}

/**
 * @brief Draws this StarSystem
 */
void StarSystem::draw() {
  for (auto& emitter : starEmitters) {
    emitter.draw();
  }
}

/**
 * @brief Starts this StarSystem
 */
void StarSystem::start() {
  for (auto& emitter : starEmitters) {
    emitter.start();
  }
}

//-Private Methods----------------------------------------------

/**
 * @brief Creates a StarEmitter with the default star sprite
 */
StarSystem::StarEmitter::StarEmitter() : Emitter() {
  actorLifespan = Constants::STAR_LIFESPAN;
  magnitude = Constants::STAR_MAGNITUDE;
  integrationStrategyType = Integration_Strategy_Type::star;
  direction = glm::vec3(0.0f, 1.0f, 0.0f);

  Sprite starSprite;
  starSprite.loadImage(Constants::STAR_SPRITE());
  sprite = starSprite;
}