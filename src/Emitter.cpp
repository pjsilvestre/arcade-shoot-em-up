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

    if ((currentTime - timeOfLastEmittedActorMilliseconds) >
        (Constants::MS_PER_S / ratePerSecond)) {
      emit();
    }
  }
}

/**
 * @brief Draw the associated ActorSystem
 */
void Emitter::draw() { actors.draw(); }

/**
 * @brief Gets the position of all of the Actors in the associated ActorSystem
 * @return A vector of Actor positions
 */
vector<glm::vec3> Emitter::getActorPositions() {
  return actors.getActorPositions();
}

/**
 * @brief Removes all Actors within a distance from a point
 * @param point The removal origin
 * @param distance The threshold distance for removal
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
 * @brief Sets this Emitter's ActorSystem's collisionSound effect
 * @param filename The audio file to load from bin/data
 */
void Emitter::setCollisionSound(const string& filename) {
  actors.setCollisionSound(filename);
}

/**
 * @brief Sets this Emitter's emissionSound effect
 * @param filename The audio file to load from bin/data
 */
void Emitter::setEmissionSound(const string& filename) {
  if (!emissionSound.load(filename)) {
    cerr << filename << " not found" << endl;
    soundLoaded = false;
  } else {
    soundLoaded = true;
  }
}

//-Protected Methods--------------------------------------------

void Emitter::emit() {
  Actor actor;
  actor.setLifespan(actorLifespan);
  actor.setPosition(position);

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
    emissionSound.play();
  }

  timeOfLastEmittedActorMilliseconds = ofGetElapsedTimeMillis();
}
