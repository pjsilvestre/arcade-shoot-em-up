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

vector<glm::vec3> Emitter::getActorPositions() {
  return actors.getActorPositions();
}

/**
 * @brief TODO
 * @param point TODO
 * @param distance TODO
*/
void Emitter::removeNear(const glm::vec3& point, float distance) {
  actors.removeNear(point, distance);
}

/**
 * @brief Start this Emitter
 */
void Emitter::start() { started = true; }

/**
 * @brief Stop this Emitter
 */
void Emitter::stop() { started = false; }

/**
 * @brief Sets this Emitter's sound effect
 * @param filename The sound to load from bin/data
 */
void Emitter::setSound(const string& filename) {
  if (!sound.load(filename)) {
    cerr << filename << " not found" << endl;
    soundLoaded = false;
  } else {
    soundLoaded = true;
  }
}

//-Protected Methods--------------------------------------------

void Emitter::emit() {
  Actor actor;
  actor.setPosition(position);
  actor.setLifespan(lifespan);

  // TODO more elegant solution?
  switch (integrationStrategyType) {
    case (Integration_Strategy_Type::actor): {
      actor.setIntegrationStrategy(new ActorIntegrationStrategy);
      break;
    }
    case (Integration_Strategy_Type::player): {
      actor.setIntegrationStrategy(new PlayerIntegrationStrategy);
      break;
    }
    case (Integration_Strategy_Type::turret): {
      actor.setIntegrationStrategy(new TurretIntegrationStrategy);
      break;
    }
    case (Integration_Strategy_Type::enemy_linear): {
      actor.setIntegrationStrategy(new EnemyLinearIntegrationStrategy);
      break;
    }
    case (Integration_Strategy_Type::enemy_sine): {
      actor.setIntegrationStrategy(new EnemySineIntegrationStrategy);
      break;
    }
    default:
      cerr << "Emitter missing integration strategy" << endl;
      break;
  }

  actor.setSprite(sprite);

  actors.add(actor);
  actors.moveActors(direction * magnitude);

  if (soundLoaded) {
    sound.play();
  }

  timeOfLastEmittedActor = ofGetElapsedTimeMillis();
}
