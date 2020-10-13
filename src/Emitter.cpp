#include "Emitter.h"

/**
 * @brief Create an Emitter with no associated Sprite
 */
Emitter::Emitter()
    : started{false},
      lifespan{Constants::LIFESPAN},
      spriteRatePerSecond{Constants::SPRITES_PER_SECOND},
      timeOfLastEmittedActor{0} {}

/**
 * @brief Create an Emitter with an associated Sprite
 * @param sprite The desired Sprite
 */
Emitter::Emitter(const Sprite& sprite) : Emitter() {
  this->sprite = sprite;

  // TODO encapsulate following into turret class ?
  if (!sound.load(Constants::MISSILE_SOUND_EFFECT())) {
    cerr << Constants::MISSILE_SOUND_EFFECT() << " not found" << endl;
  }
  sound.setMultiPlay(true);
}

/**
 * @brief Update the associated ActorSystem
 */
void Emitter::update() {
  actors.update();

  if (started) {
    float currentTime = ofGetElapsedTimeMillis();

    if ((currentTime - timeOfLastEmittedActor) > (1000.0 / spriteRatePerSecond)) {
      emit();
    }
  }
}

/**
 * @brief Draw the associated ActorSystem
 */
void Emitter::draw() { actors.draw(); }

/**
 * @brief Start the Emitter
 */
void Emitter::start() {
  started = true;
  float elapsedTime = ofGetElapsedTimeMillis();
}

/**
 * @brief Stop the Emitter
 */
void Emitter::stop() { started = false; }

//-Private Methods----------------------------------------------

/**
 * @brief Emit an Actor from the associated ActorSystem
 */
void Emitter::emit() {
  Actor missile = Actor(sprite);
  missile.setPosition(position);
  missile.setLifespan(lifespan);
  actors.add(missile);

  actors.update();

  actors.moveActors(glm::normalize(direction));
  sound.play();
  timeOfLastEmittedActor = ofGetElapsedTimeMillis();
}
