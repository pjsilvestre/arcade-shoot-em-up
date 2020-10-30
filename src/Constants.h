#pragma once

#include <string>

namespace Constants {
// General constants
const int SCREEN_HEIGHT{720};
const int SCREEN_WIDTH{1280};

// Sprite constants
const float SPRITE_DIMENSIONS{128.0f};

// Actor constants
const float ACTOR_ACCELERATION_DAMPING{0.99f};
const float ACTOR_INITIAL_ACCELERATION{1000.0f};
const float ACTOR_LIFESPAN{FLT_MAX};
const float ACTOR_MIN_VELOCITY{0.1f};
const float ACTOR_VELOCITY_DAMPING{0.99f};

// Player constants
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

}  // namespace Constants