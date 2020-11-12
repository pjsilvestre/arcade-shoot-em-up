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

/**
 * @brief Describes how, when emitted from a Turret, an Actor's position,
 * velocity, and acceleration change over time
 * @param position The Actor's position
 * @param velocity The Actor's velocity
 * @param acceleration The Actor's acceleration
 */
void TurretIntegrationStrategy::integrate(glm::vec3& position,
                                          glm::vec3& velocity,
                                          glm::vec3& acceleration) {
  float timestep = 1.0f / ofGetFrameRate();

  position += velocity * timestep;

  if (glm::length(velocity) < Constants::MISSILE_MAX_VELOCITY) {
    velocity += acceleration * timestep;
  }
}
/**
 * @brief Describes how, when emitted from a EnemyEmitter, an Actor's position,
 * velocity, and acceleration change over time in a linear fashion
 * @param position The Actor's position
 * @param velocity The Actor's velocity
 * @param acceleration The Actor's acceleration
 */
void EnemyLinearIntegrationStrategy::integrate(glm::vec3& position,
                                               glm::vec3& velocity,
                                               glm::vec3& acceleration) {
  float timestep = 1.0f / ofGetFrameRate();

  position += velocity * timestep;

  if (glm::length(velocity) < Constants::ENEMY_MAX_VELOCITY) {
    velocity += acceleration * timestep;
  }
}

/**
 * @brief Describes how, when emitted from a EnemyEmitter, an Actor's position,
 * velocity, and acceleration change over time in a sine wave fashion
 * @param position The Actor's position
 * @param velocity The Actor's velocity
 * @param acceleration The Actor's acceleration
 */
void EnemySineIntegrationStrategy::integrate(glm::vec3& position,
                                             glm::vec3& velocity,
                                             glm::vec3& acceleration) {
  // TODO accommodate non-horizontal wave movement?
  float timestep = 1.0f / ofGetFrameRate();

  position += velocity * timestep;
  position.y = sineWave.getEvaluation(position.x).y;

  if (glm::length(velocity) < Constants::ENEMY_MAX_VELOCITY) {
    velocity += acceleration * timestep;
  }
}

glm::vec3 EnemySineIntegrationStrategy::SineWave::getEvaluation(float x) {
  // original implementation courtesy Professor Smith
  // prevent potential arithmetic overflow
  double dFrequency = (double)frequency;

  return glm::vec3(
      x,
      -amplitude * sin(dFrequency * x * PI / Constants::SCREEN_WIDTH) +
          (Constants::SCREEN_HEIGHT / 2),
      0);
}

/**
 * @brief Describes how, when emitted from a StarEmitter, an Actor's position,
 * velocity, and acceleration change over time
 * @param position The Actor's position
 * @param velocity The Actor's velocity
 * @param acceleration The Actor's acceleration
 */
void StarIntegrationStrategy::integrate(glm::vec3& position,
                                        glm::vec3& velocity,
                                        glm::vec3& acceleration) {
  float timestep = 1.0f / ofGetFrameRate();

  velocity = acceleration;  // constant velocity
  position += velocity * timestep;
}
