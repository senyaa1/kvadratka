/** @file main.c
 *  @brief Main file
 *
 *  Contains main function which runs kvadratka
 */
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "solver.h"
#include "tester.h"
#include "io.h"

/** @brief Kvadratka entry
 *
 * This is the program entrypoint
 *
 * @return Should not return
 */
int main(int argc, char** argv)
{
	quadratic_eq_t eq = (quadratic_eq_t){0, 0, 0, 0, 0, NOT_CALCULATED};

	if(argc == 4 && read_coeffs_from_argv(&eq, argv)) 
	{
		solve_quadratic(&eq);
		return pretty_print_roots(&eq);
	}

	int opt;
	while ((opt = getopt(argc, argv, "ht")) != -1) {
		switch (opt) {
		        case 't': 
				run_all_sq_tests();
				return 0;
			case 'h':
		        default:
				if(argc == 4) break;
				fprintf(stderr, "Usage: %s [-t] (coefficients)\n", argv[0]);
				return 1;
	        }	
	}

	read_coeffs(&eq);
	solve_quadratic(&eq);
	return pretty_print_roots(&eq);
}

