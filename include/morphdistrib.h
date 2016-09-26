#pragma once

#include <gmp.h>
#include <stdlib.h>

#include "morphtypes.h"




static int32_t morph_distrib_sample_i32(morph_random_distrib_t distrib) {
  switch (distrib.type) {
  case DISTRIB_UNIFORM:
    // FIXME
    return distrib.uniform.lower + rand() % (distrib.uniform.upper + 1 - distrib.uniform.lower);
  case DISTRIB_GAUSSIAN:
  default:
    // FIXME
    return rand();
  }

  return -1;
}
