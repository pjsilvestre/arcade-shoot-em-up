#pragma once

#include <string>

namespace Constants {
// General constants
const int SCREEN_HEIGHT{1000};
const int SCREEN_WIDTH{1000};

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

// EnemySpawner constants
const float ENEMY_LIFESPAN{10.0f};
const float ENEMY_MAGNITUDE{1000.0f};
const float ENEMY_MAX_VELOCITY{500.0f};
const float ENEMY_RATE{0.5f};
const std::string COLLISION_SOUND_EFFECT();
const std::string ENEMY_SPRITE();

// IntegrationStrategy constants
const float SINE_WAVE_AMPLITUDE{400.0f};
const float SINE_WAVE_FREQUENCY{1.5f};

}  // namespace Constants