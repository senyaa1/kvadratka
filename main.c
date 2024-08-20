#include <stdint.h>

#include "solver.h"
#include "io.h"

int main()
{
	coeff_t a = 0, b = 0, c = 0; 
	int read_nums = read_coeffs(&a, &b, &c);
	if(read_nums != 3)
		return 1;

	root_t x1 = 0, x2 = 0;
	sq_root_cnt_t cnt = solve_quadratic(a, b, c, &x1, &x2);

	return pretty_print_roots(cnt, x1, x2);
}
