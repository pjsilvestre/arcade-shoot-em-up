/**
 * @class ActorSystem
 * @brief Encapsulates a collection of Actors
 */

#pragma once

#include "Actor.h"
#include "ofEvent.h"

class ActorSystem {
 public:
  void update();
  void draw();

  void add(Actor& actor) { actors.push_back(actor); }
  int getActorCollidedCount() { return actorCollidedCount; }

  vector<glm::vec3> getActorPositions();
  void moveActors(const glm::vec3& direction);
  void removeNear(const glm::vec3& point, float distance);
  void setPosition(const glm::vec3& position);

  ofEvent<const ofEventArgs> actorCollided;

 private:
  void deleteDeadActors();

  int actorCollidedCount;
  vector<Actor> actors;
};
