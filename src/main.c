/** @file main.c
 *  @brief Main file
 *
 *  Contains main function which runs kvadratka
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
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

	switch(argc)
	{
		case 4:
			if(!read_coeffs_from_argv(&eq, argv)) 
			{
				printf("incorrect args!\n");
				return 1;
			}
			break;
		case 2:
			if(strcmp(argv[1], "-t"))
			{
				printf("incorrect args!\n");
				return 1;
			}
			run_all_sq_tests();
			return 0;
		case 1:
			read_coeffs(&eq);
			break;
		default:
			printf("incorrect args!\n");
			return 1;

	}

	solve_quadratic(&eq);
	return pretty_print_roots(&eq);
}

