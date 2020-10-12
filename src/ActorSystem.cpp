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
  for (Actor actor : actors) {
    actor.draw();
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