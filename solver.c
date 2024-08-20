#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#include "solver.h"

static const double EPS = 0.00001;

static bool d_eq(double a, double b)
{
	return fabs(a - b) < EPS;
}

sq_root_cnt_t solve_quadratic(double a, double b, double c, double* x1, double* x2)
{
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));

	assert(x1);
	assert(x2);
	assert(x1 != x2);
	
	if(d_eq(a, 0) && d_eq(b, 0))
	{
		return (d_eq(c, 0)) ? INF_ROOTS: NO_ROOTS;
	}

	if(d_eq(a, 0))
	{
		*x1 = -c / b;
		return ONE_ROOT;
	}

	double d = (b * b) - 4 * a * c;

	if (d < 0)
	{
		return NO_ROOTS;
	}

	*x1 = (-b + sqrt(d)) / (2 * a);
	*x2 = (-b - sqrt(d)) / (2 * a);
	
	return (d_eq(d, 0)) ? ONE_ROOT : TWO_ROOTS;
}
