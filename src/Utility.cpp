#include "Utility.h"

/**
 * @brief Limits a value between a desired min and max value
 * @param value The value to limit
 * @param min The desired min value
 * @param max The desired max value
 * @return The value, limited by min or max if necessary
 */
float Utility::clamp(float value, float min, float max) {
  if (value < min) {
    return min;
  } else if (max < value) {
    return max;
  }

  return value;
}