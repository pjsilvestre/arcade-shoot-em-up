#include "Utility.h"

float Utility::clamp(float value, float min, float max) {
  if (value < min) {
    return min;
  } else if (max < value) {
    return max;
  }

  return value;
}