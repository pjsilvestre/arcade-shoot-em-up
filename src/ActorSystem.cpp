#include "ActorSystem.h"

/**
 * @brief Updates all Actors, deleting dead Actors if necessary
 */
void ActorSystem::update() {
  deleteDeadActors();
  for (Actor& actor : actors) {
    actor.update();
  }
}

/**
 * @brief Draws all Actors
 */
void ActorSystem::draw() {
  for (Actor& actor : actors) {
    actor.draw();
  }
}

/**
 * @brief Gets the position of all of the Actors in this ActorSystem
 * @return A vector of Actor positions
 */
vector<glm::vec3> ActorSystem::getActorPositions() {
  vector<glm::vec3> positions;

  for (Actor& actor : actors) {
    positions.push_back(actor.getPosition());
  }

  return positions;
}

/**
 * @brief Removes all Actors within a distance from a point
 * @param point The removal origin
 * @param distance The threshold distance for removal
 */
void ActorSystem::removeNear(const glm::vec3& point, float distance) {
  for (Actor& actor : actors) {
    if (abs(glm::length(actor.getPosition() - point)) < distance) {
      actor.setLifespan(0.0f);

      // TODO better solution for collision sounds, preferably in Emitter
      if (soundLoaded) {
        collisionSound.play();
      }

      actorCollidedCount++;
    }
  }
}

/**
 * @brief Invokes move() on all Actors
 * @param force The applied force
 */
void ActorSystem::moveActors(const glm::vec3& force) {
  for (Actor& actor : actors) {
    actor.move(force);
  }
}

/**
 * @brief Sets the position of all Actors
 * @param position The desired position
 */
void ActorSystem::setPosition(const glm::vec3& position) {
  for (Actor& actor : actors) {
    actor.setPosition(position);
  }
}

/**
 * @brief Sets this ActorSystem's collisionSound effect
 * @param filename The collisionSound to load from bin/data
 */
void ActorSystem::setCollisionSound(const string& filename) {
  if (!collisionSound.load(filename)) {
    cerr << filename << " not found" << endl;
    soundLoaded = false;
  } else {
    soundLoaded = true;
  }
}
//-Private Methods----------------------------------------------

void ActorSystem::deleteDeadActors() {
  auto iterator = actors.begin();

  while (iterator != actors.end()) {
    Actor actor = (*iterator);

    if (actor.getAge() > actor.getLifespan()) {
      // delete allocated memory
      delete actor.getIntegrationStrategy();
      actor.setIntegrationStrategy(nullptr);

      // remove from vector
      iterator = actors.erase(iterator);
    } else {
      iterator++;
    }
  }
}