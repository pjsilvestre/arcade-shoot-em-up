#pragma once

#include <string>

namespace Constants {
// app constants
const int SCREEN_WIDTH{1280};
const int SCREEN_HEIGHT{720};

// Sprite constants
const float SPRITE_DIMENSIONS{128.0f};

// Actor constants
const int LIFESPAN{INT_MAX};
const float MAX_VELOCITY{5.0f};
const float ACCELERATION{5.0f};

// Player constants
const std::string PLAYER_SPRITE();
const std::string MISSILE_SPRITE();
const std::string MISSILE_SOUND_EFFECT();
const int MISSILE_LIFESPAN{500};

// Emitter constants
const float SPRITES_PER_SECOND{1.0};

}  // namespace Constants