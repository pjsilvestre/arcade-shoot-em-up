#include "Emitter.h"

/**
 * @brief Create an Emitter with no associated Sprite
 */
Emitter::Emitter()
    : started{false},
      lifespan{Constants::LIFESPAN},
      magnitude{Constants::EMITTER_MAGNITUDE},
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
    // Arithmetic overflow: Using operator '-' on a 4 byte value and then
    // casting the result to a 8 byte value.
    // float currentTime = ofGetElapsedTimeMillis();

    double currentTime = ofGetElapsedTimeMillis();

    if ((currentTime - timeOfLastEmittedActor) >
        (Constants::MS_PER_S / spriteRatePerSecond)) {
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
void Emitter::start() { started = true; }

/**
 * @brief Stop the Emitter
 */
void Emitter::stop() { started = false; }

//-Private Methods----------------------------------------------

void Emitter::emit() {
  Actor missile = Actor(sprite);  // TODO add more Actor constructors?
  missile.setPosition(position);
  missile.setLifespan(lifespan);

  actors.add(missile);
  actors.moveActors(direction * magnitude);

  sound.play();

  timeOfLastEmittedActor = ofGetElapsedTimeMillis();
}
