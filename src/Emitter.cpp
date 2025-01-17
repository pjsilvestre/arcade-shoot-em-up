#include "Emitter.h"

/**
 * @brief Creates an Emitter
 */
Emitter::Emitter() {
  ofAddListener(actors.actorCollided, this, &Emitter::notifyCollision);
}

/**
 * @brief Deletes this Emitter
 */
Emitter::~Emitter() {
  ofRemoveListener(actors.actorCollided, this, &Emitter::notifyCollision);
}

/**
 * @brief Update the associated ActorSystem
 */
void Emitter::update() {
  actors.update();

  if (started) {
    double currentTime = ofGetElapsedTimeMillis();

    if (oneShotEnabled) {
      emit();
      stop();
    }

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
 * @brief Removes all Actors
 */
void Emitter::removeAll() { actors.removeAll(); }

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
 * @brief Notifies all listeners that an underlying Actor has collided
 * @param collisionPosition The collision position
 */
void Emitter::notifyCollision(const ofWindowPosEventArgs& collisionPosition) {
  ofNotifyEvent(actorCollided, collisionPosition, this);
}

//-Protected Methods--------------------------------------------

void Emitter::emit() {
  Actor actor;
  actor.setLifespan(actorLifespan);
  actor.setPosition(position);
  actor.setScale(scale);

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
    case (Integration_Strategy_Type::star): {
      actor.setIntegrationStrategy(new StarIntegrationStrategy);
      break;
    }
    case (Integration_Strategy_Type::explosion): {
      direction = glm::normalize(
          glm::vec3(ofRandom(-1.0f, 1.0f), ofRandom(-1.0f, 1.0f), 0.0f));
      actor.setIntegrationStrategy(new ExplosionIntegrationStrategy);
      break;
    }
    default:
      cerr << "Emitter missing integration strategy" << endl;
      break;
  }

  actor.setSprite(sprite);

  actors.add(actor);
  actors.moveActors(direction * magnitude);

  timeOfLastEmittedActorMilliseconds = ofGetElapsedTimeMillis();
}
