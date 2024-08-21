/** @file io.c
 *  @brief File with input/output functions
 *
 *  Contains functions to handle input and output of kvadratka 
 */


#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "io.h"
#include "solver.h"

bool read_coeffs_from_argv(quadratic_eq_t* eq, char** argv)
{
	int cnt = 0;

	cnt += sscanf(argv[1], "%lg", &eq->a);
	cnt += sscanf(argv[2], "%lg", &eq->b);
	cnt += sscanf(argv[3], "%lg", &eq->c);

	return cnt == 3;
}

static void read_until_correct(const char* text, coeff_t* a)
{
	int read_nums = 0;

	while(read_nums != 1)
	{
		printf("%s", text);
		read_nums = scanf("%lg", a);
		if(read_nums == 1)
			break;

		printf("коэффы введены неправильно! Ещё раз\n");

		while ( getchar() != '\n' ); // чистим буффер
	}
}

void read_coeffs(quadratic_eq_t* eq)
{
	printf("лучшая квадратка v1.0.0\n");
	printf("введи коэффы:\n");
	
	read_until_correct("a: ", &eq->a);
	read_until_correct("b: ", &eq->b);
	read_until_correct("c: ", &eq->c);

	printf("коэффы приняты!\n");
}

int pretty_print_roots(quadratic_eq_t* eq)
{
	switch(eq->cnt)
	{
		case NO_ROOTS:
			printf("Корней нет!\n");
			return 0;
		case ONE_ROOT:
			printf("Один корень - x1 = %lg\n", eq->x1);
			return 0;
		case TWO_ROOTS:
			printf("Два корня - x1 = %lg\tx2 = %lg\n", eq->x1, eq->x2);
			return 0;
		case INF_ROOTS:
			printf("Бесконечное кол-во корней!\n");
			return 0; 
		case NOT_CALCULATED:
		default:
			printf("это что такое?!?!!?!!?!\n!");
			return 1;
	}
}
