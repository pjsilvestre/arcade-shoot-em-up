#include "Emitter.h"

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

/**
 * @brief Sets this Emitter's sound effect
 * @param filename The sound to load from bin/data
 */
void Emitter::setSound(const string& filename) {
  if (!sound.load(filename)) {
    cerr << filename << " not found" << endl;
  }
}

//-Protected Methods--------------------------------------------

void Emitter::emit() {
  Actor missile;
  missile.setPosition(position);
  missile.setLifespan(lifespan);
  missile.setSprite(sprite);

  actors.add(missile);
  actors.moveActors(direction * magnitude);

  sound.play();

  timeOfLastEmittedActor = ofGetElapsedTimeMillis();
}
