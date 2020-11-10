/**
 * @class SoundPlayer
 * @brief Encapsulates playing of sound effects after observing ofEvents
 */

#pragma once

#include "ofMain.h"
#include "Constants.h"

class SoundPlayer {
 public:
  SoundPlayer();
  void playMissileSoundEffect(const ofEventArgs& unusedArg);
  void playCollisionSoundEffect(const ofEventArgs& unusedArg);

 private:
  bool collisionSoundLoaded;
  bool missileSoundLoaded;

  ofSoundPlayer collisionSound;
  ofSoundPlayer missileSound;
};
