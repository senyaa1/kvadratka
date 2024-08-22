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

	int opt;
	while ((opt = getopt(argc, argv, "t")) != -1) {
		switch (opt) {
		        case 't': 
				run_all_sq_tests();
				return 0;
		        default:
				fprintf(stderr, "Usage: %s [-t] (coefficients)\n", argv[0]);
				return 1;
	        }	
	}

	switch(argc)
	{
		case 4:
			if(!read_coeffs_from_argv(&eq, argv)) 
			{
				printf("incorrect args!\n");
				return 1;
			}
			break;
		default:
		case 1:
			read_coeffs(&eq);
			break;

	}

	solve_quadratic(&eq);
	return pretty_print_roots(&eq);
}

