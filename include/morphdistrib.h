#include <gmp.h>
#include <stdlib.h>

typedef enum {
  DISTRIB_NONE = 0,
  DISTRIB_UNIFORM,
  DISTRIB_GAUSSIAN
} morph_distrib_type_t;

typedef struct {
  {
    int32_t mean;
    int32_t deviation;
  } gaussian;

  { 
    int32_t lower;
    int32_t upper;
  } uniform;

  morph_distrib_type_t type;
} morph_random_distrib_t;



int32_t morph_distrib_sample_i32(morph_random_distrib_t distrib) {
  switch (distrib.type) {
  case DISTRIB_UNIFORM:
    // FIXME
    int64_t value = distrib.lower + lrand48() % (distrib.upper + 1 - distrib.lower);
    return value;
  case DISTRIB_GAUSSIAN:
    // FIXME
    return lrand48();
  }

}
