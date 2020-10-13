#include "ActorSystem.h"

/**
 * @brief Update all Actors, deleting dead Actors if necessary
 */
void ActorSystem::update() {
  deleteDeadActors();
  for (Actor& actor : actors) {
    actor.update();
  }
}

/**
 * @brief Draw all Actors
 */
void ActorSystem::draw() {
  for (Actor& actor : actors) {
    actor.draw();
  }
}

/**
 * @brief Set the position of all Actors
 * @param position The desired position
*/
void ActorSystem::setPosition(const glm::vec3& position) {
  for (Actor& actor : actors) {
    actor.setPosition(position);
  }
}

void ActorSystem::deleteDeadActors() {
  auto iterator = actors.begin();

  while (iterator != actors.end()) {
    auto actor = (*iterator);

    if (actor.getAge() > actor.getLifespan()) {
      iterator = actors.erase(iterator);
    } else {
      iterator++;
    }
  }
}