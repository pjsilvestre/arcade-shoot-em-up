/**
 * @class SoundPlayer
 * @brief Encapsulates playing of sound effects after observing ofEvents
 */

#pragma once

#include "Constants.h"
#include "ofMain.h"

class SoundPlayer {
 public:
  SoundPlayer();
  void playMissileSoundEffect(const ofEventArgs& unusedArg);
  void playCollisionSoundEffect(const ofWindowPosEventArgs& unusedArg);

 private:
  bool collisionSoundLoaded;
  bool missileSoundLoaded;

  ofSoundPlayer collisionSound;
  ofSoundPlayer missileSound;
};
