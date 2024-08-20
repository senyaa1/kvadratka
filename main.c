#include <stdint.h>

#include "solver.h"
#include "io.h"

int main()
{
	quadratic_eq_t eq = (quadratic_eq_t){0, 0, 0, 0, 0, NOT_CALCULATED};
	int read_nums = read_coeffs(&eq);
	if(read_nums != 3)
		return 1;

	solve_quadratic(&eq);

	return pretty_print_roots(&eq);
}
