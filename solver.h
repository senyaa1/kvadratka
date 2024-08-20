#pragma once

#include <stdint.h>
#include <math.h>
#include <assert.h>

typedef enum sq_root_cnt {
	NO_ROOTS = 0,
	ONE_ROOT = 1,
	TWO_ROOTS = 2,
	INF_ROOTS = 123
} sq_root_cnt_t;

typedef double coeff_t;
typedef double root_t;

sq_root_cnt_t solve_quadratic(coeff_t a, coeff_t b, coeff_t c, root_t* x1, root_t* x2);
