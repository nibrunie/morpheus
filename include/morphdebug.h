#pragma once

#include <stdio.h>
#include <inttypes.h>

#include "morphpoly.h"


static __attribute__((unused)) void morph_poly_display(char* title, morph_poly_t* poly, char* footer)
{
  printf("%s", title);
  for (int i = 0; i < poly->degree; ++i) printf("  C_%d = %"PRIi32"\n", i, poly->coeff_array[i]);
  printf("%s", footer);
}
