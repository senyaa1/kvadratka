#pragma once

#include <stdint.h>
#include "solver.h"

int pretty_print_roots(sq_root_cnt_t cnt, root_t x1, root_t x2);
int read_coeffs(coeff_t* a, coeff_t* b, coeff_t* c);
