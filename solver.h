#pragma once

#include <stdint.h>
#include <math.h>
#include <assert.h>

#define SQ_INF_ROOTS 123 

uint8_t solve_quadratic(double a, double b, double c, double* x1, double* x2);
