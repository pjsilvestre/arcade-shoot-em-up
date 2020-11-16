#include "Score.h"

/**
 * @brief Increments the score by 1
 * @param unusedArg Unused argument
 */
void Score::incrementScore(const ofWindowPosEventArgs& unusedArg) { score++; }

/**
 * @brief Resets the score to 0
 */
void Score::reset() { score = 0; }