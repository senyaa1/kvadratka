/** @file main.c
 *  @brief Main file
 *
 *  Contains main function which runs kvadratka
 */
#include <stdint.h>
#include <stdio.h>
#include "solver.h"
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

	if (argc == 4)
	{
		if(!read_coeffs_from_argv(&eq, argv)) 
		{
			printf("incorrect args!\n");
			return 1;
		}
	}
	else if(argc == 1)
	{
		read_coeffs(&eq);
	}
	else
	{
		printf("incorrect args!\n");
		return 1;
	}

	solve_quadratic(&eq);
	return pretty_print_roots(&eq);
}
