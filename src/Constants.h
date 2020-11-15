#pragma once

#include <string>

namespace Constants {
// General constants
const int SCREEN_HEIGHT{1080};
const int SCREEN_WIDTH{1920};

// Sprite constants
const float SPRITE_DIMENSIONS{128.0f};

// Actor constants
const float ACTOR_ACCELERATION_DAMPING{0.99f};
const float ACTOR_INITIAL_ACCELERATION{1000.0f};
const float ACTOR_LIFESPAN{FLT_MAX};
const float ACTOR_MAX_VELOCITY{500.0f};
const float ACTOR_VELOCITY_DAMPING{0.99f};

// Player constants
const float PLAYER_INITIAL_ACCELERATION{10000.0f};
const float PLAYER_MAX_VELOCITY{1000.0f};
const std::string PLAYER_SPRITE();

// Emitter constants
const float EMITTER_MAGNITUDE{ACTOR_INITIAL_ACCELERATION};
const float EMITTER_MAX_VELOCITY{ACTOR_MAX_VELOCITY};
const float MS_PER_S{1000.0f};
const float SPRITES_PER_SECOND{1.0f};

// Turret constants
const float MISSILE_LIFESPAN{5.0f};
const float MISSILE_MAGNITUDE{10000.0f};
const float MISSILE_MAX_VELOCITY{1500.0f};
const std::string MISSILE_SOUND_EFFECT();
const std::string MISSILE_SPRITE();

// EnemyEmitter constants
const float ENEMY_LIFESPAN{10.0f};
const float ENEMY_MAGNITUDE{1000.0f};
const float ENEMY_MAX_VELOCITY{500.0f};
const float ENEMY_RATE{0.5f};
const std::string COLLISION_SOUND_EFFECT();
const std::string ENEMY_SPRITE();

// IntegrationStrategy constants
const float SINE_WAVE_AMPLITUDE{400.0f};
const float SINE_WAVE_FREQUENCY{1.5f};

// StarEmitter constants
const float STAR_LIFESPAN{10.0f};
const float STAR_MAGNITUDE{1000.0f};
const float NEAR_STAR_MAGNITUDE{1000.0f};
const float MID_STAR_MAGNTIUDE{750.0f};
const float FAR_STAR_MAGNITUDE{200.0f};
const float NEAR_STAR_RATE{0.1f};
const float MID_STAR_RATE{0.75f};
const float FAR_STAR_RATE{10.0f};
const float NEAR_STAR_SCALE{1.0f};
const float MID_STAR_SCALE{0.5f};
const float FAR_STAR_SCALE{0.25f};
const std::string STAR_SPRITE();

// ExplosionEmitter constants
const int EXPLOSION_GROUP_SIZE{25};
const float EXPLOSION_ACCELERATION_DAMPING{0.9f};
const float EXPLOSION_LIFESPAN{1.0f};
const float EXPLOSION_MAGNITUDE{10000.0f};
const float EXPLOSION_VELOCITY_DAMPING{0.95f};
const std::string EXPLOSION_SPRITE();

}  // namespace Constants