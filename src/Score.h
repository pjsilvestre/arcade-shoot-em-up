/**
 * @class Score
 * @brief Encapsulates score tracking
 */

#pragma once

#include "ofMain.h"

class Score {
 public:
  int getScore() { return score; }

  void incrementScore(const ofWindowPosEventArgs& unusedArg);
  void reset();

 private:
  int score{0};
};
