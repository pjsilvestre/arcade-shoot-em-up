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
 * @brief Sets the position of all Actors
 * @param position The desired position
 */
void ActorSystem::setPosition(const glm::vec3& position) {
  for (Actor& actor : actors) {
    actor.setPosition(position);
  }
}

/**
 * @brief TODO
 * @return TODO
*/
vector<glm::vec3> ActorSystem::getActorPositions() {
  vector<glm::vec3> positions;

  for (Actor& actor : actors) {
    positions.push_back(actor.getPosition());
  }

  return positions;
}

/**
 * @brief TODO
 * @param point TODO
 * @param distance TODO
 */
void ActorSystem::removeNear(const glm::vec3& point, float distance) {
  for (Actor& actor : actors) {
    if (abs(glm::length(actor.getPosition() - point)) < distance) {
      actor.setLifespan(0.0f);
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