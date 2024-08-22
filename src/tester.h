#pragma once

#include "solver.h"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


typedef enum test_result
{
	PASSED = 1,
	FAILED = 2,
	TESTING_ERROR = 4
} test_result_t;


void print_test_result(const char* test_name, test_result_t result);
test_result_t test_sq(quadratic_eq_t* input, quadratic_eq_t* expected_output);
void run_all_sq_tests();
