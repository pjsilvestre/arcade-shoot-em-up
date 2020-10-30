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
const float PLAYER_ACCELERATION_DAMPING{0.99f};
const float PLAYER_INITIAL_ACCELERATION{1000.0f};
const float PLAYER_MAX_VELOCITY{500.0f};
const float PLAYER_VELOCITY_DAMPING{0.99f};
const std::string PLAYER_SPRITE();

// Emitter constants
const float EMITTER_MAGNITUDE{1000.0f};
const float MS_PER_S{1000.0f};
const float SPRITES_PER_SECOND{1.0f};

// Turret constants
const float MISSILE_ACCELERATION_MAGNITUDE{5000.0f};
const float MISSILE_LIFESPAN{5.0f};
const std::string MISSILE_SOUND_EFFECT();
const std::string MISSILE_SPRITE();

// Enemy constants
const std::string ENEMY_SPRITE();

}  // namespace Constants