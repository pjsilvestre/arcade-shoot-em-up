#include "SoundPlayer.h"

/**
 * @brief Creates a SoundPlayer
 */
SoundPlayer::SoundPlayer() {
  if (missileSound.load(Constants::MISSILE_SOUND_EFFECT())) {
    missileSoundLoaded = true;
  } else {
    cerr << Constants::MISSILE_SOUND_EFFECT() << " not found" << endl;
    missileSoundLoaded = false;
  }

  if (collisionSound.load(Constants::COLLISION_SOUND_EFFECT())) {
    collisionSoundLoaded = true;
  } else {
    cerr << Constants::COLLISION_SOUND_EFFECT() << " not found" << endl;
    collisionSoundLoaded = false;
  }
}

/**
 * @brief Plays the sound effect associated with launching missiles
 * @param unusedArg Unused argument
 */
void SoundPlayer::playMissileSoundEffect(const ofEventArgs& unusedArg) {
  if (missileSoundLoaded) {
    missileSound.play();
  }
}

/**
 * @brief Plays the sound effect associated with missiles colliding with enemies
 * @param unusedArg Unused argument
 */
void SoundPlayer::playCollisionSoundEffect(const ofEventArgs& unusedArg) {
  if (collisionSoundLoaded) {
    collisionSound.play();
  }
}