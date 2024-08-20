#include <stdint.h>
#include <stdio.h>

#include "io.h"
#include "solver.h"


int read_coeffs(coeff_t* a, coeff_t* b, coeff_t* c)
{
	printf("лучшая квадратка v1.0.0\n");
	printf("введи коэффы:\n");
	
	int read_nums = 0;

	printf("a: ");
	read_nums += scanf("%lg", a);
	printf("b: ");
	read_nums += scanf("%lg", b);
	printf("c: ");
	read_nums += scanf("%lg", c);

	if(read_nums != 3)
	{
		printf("коэффы введены неправильно!\n");
		return read_nums;
	}

	printf("коэффы приняты!\n");
	return read_nums;
}

int pretty_print_roots(sq_root_cnt_t cnt, root_t x1, root_t x2)
{
	switch(cnt)
	{
		case NO_ROOTS:
			printf("Корней нет!\n");
			return 0;
		case ONE_ROOT:
			printf("Один корень - x1 = %lg\n", x1);
			return 0;
		case TWO_ROOTS:
			printf("Два корня - x1 = %lg\tx2 = %lg\n", x1, x2);
			return 0;
		case INF_ROOTS:
			printf("Бесконечное кол-во корней!\n");
			return 0; 
		default:
			printf("это что такое?!?!!?!!?!\n!");
			return 1;
	}
}
