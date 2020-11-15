/**
 * @class Score
 * @brief Encapsulates score tracking
 */

#pragma once

class Score {
 public:
  int getScore() { return score; }

  void incrementScore(const ofWindowPosEventArgs& unusedArg) { score++; }
  void reset() { score = 0; }

 private:
  int score{0};
};
