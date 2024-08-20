#include <stdint.h>
#include <stdio.h>

#include "io.h"
#include "solver.h"


int read_coeffs(quadratic_eq_t* eq)
{
	printf("лучшая квадратка v1.0.0\n");
	printf("введи коэффы:\n");
	
	int read_nums = 0;

	printf("a: ");
	read_nums += scanf("%lg", &eq->a);
	printf("b: ");
	read_nums += scanf("%lg", &eq->b);
	printf("c: ");
	read_nums += scanf("%lg", &eq->c);

	if(read_nums != 3)
	{
		printf("коэффы введены неправильно!\n");
		return read_nums;
	}

	printf("коэффы приняты!\n");
	return read_nums;
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
