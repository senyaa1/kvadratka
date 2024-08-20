#include <stdint.h>

#include "solver.h"
#include "io.h"

int main()
{
	quadratic_eq_t eq = (quadratic_eq_t){0, 0, 0, 0, 0, NOT_CALCULATED};

	read_coeffs(&eq);
	solve_quadratic(&eq);

	return pretty_print_roots(&eq);
}
