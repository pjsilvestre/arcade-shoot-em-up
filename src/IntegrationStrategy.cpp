#include "IntegrationStrategy.h"

/**
 * @brief Describes how an Actor's position, velocity, and acceleration change
 * over time
 * @param position The Actor's position
 * @param velocity The Actor's velocity
 * @param acceleration The Actor's acceleration
 */
void ActorIntegrationStrategy::integrate(glm::vec3& position,
                                         glm::vec3& velocity,
                                         glm::vec3& acceleration) {
  float timestep = 1.0f / ofGetFrameRate();

  position += velocity * timestep;

  if (glm::length(velocity) < Constants::ACTOR_MAX_VELOCITY) {
    velocity += acceleration * timestep;
  }

  velocity *= Constants::ACTOR_VELOCITY_DAMPING;
  acceleration *= Constants::ACTOR_ACCELERATION_DAMPING;
}

/**
 * @brief Describes how an Player's position, velocity, and acceleration change
 * over time
 * @param position The Player's position
 * @param velocity The Player's velocity
 * @param acceleration The Player's acceleration
 */
void PlayerIntegrationStrategy::integrate(glm::vec3& position,
                                          glm::vec3& velocity,
                                          glm::vec3& acceleration) {
  float timestep = 1.0f / ofGetFrameRate();

  position += velocity * timestep;

  if (glm::length(velocity) < Constants::PLAYER_MAX_VELOCITY) {
    velocity += acceleration * timestep;
  }
}
