#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "solver.h"


uint8_t read_coeffs(double* a, double* b, double* c)
{
	printf("лучшая квадратка v1.0.0\n");
	printf("введи коэффы:\n");
	
	uint8_t read_nums = 0;

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

uint8_t pretty_print_roots(uint8_t cnt, double x1, double x2)
{
	switch(cnt)
	{
		case 0:
			printf("Корней нет!\n");
			return 0;
		case 1:
			printf("Один корень - x1 = %lg\n", x1);
			return 0;
		case 2:
			printf("Два корня - x1 = %lg\tx2 = %lg\n", x1, x2);
			return 0;
		case SQ_INF_ROOTS:
			printf("Бесконечное кол-во корней!\n");
			return 0; 
		default:
			printf("это что такое?!?!!?!!?!\n!");
			return 1;
	}
}
