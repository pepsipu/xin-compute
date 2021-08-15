#include "xinc.h"

// quake fisr algo
float xinc_isqrt(float n)
{
  // log(1/sqrt(x)) = -1/2log(x) = -(log(x) >> 1)
  long log_approx = 0x5f3759df - (TO_LONG(n) >> 1);
  // 2^log_approx
  float approx = TO_FLOAT(log_approx);
  // apply newton's method for 1/x^2 - c
  // wolfram alpha simplified version of x - (1/x^2 - c)/'(1/x^2 - c)
  return (-0.5f * approx) * (n * approx * approx - 3);
}