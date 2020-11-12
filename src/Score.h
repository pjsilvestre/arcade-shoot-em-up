/**
 * @class Score
 * @brief Encapsulates score tracking
 */

#pragma once

class Score {
 public:
  void incrementScore(const ofWindowPosEventArgs& unusedArg) { score++; }
  int getScore() { return score; }

 private:
  int score{0};
};
