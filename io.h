/** @file io.h
 *  @brief File with input/output functions
 *
 *  Contains functions to handle input and output of kvadratka 
 */
#pragma once

#include <stdint.h>
#include "solver.h"

/** @brief Prints coefficients to stdout
 *  @param eq Quadratic equation
 *  @return Exit code
 */
int pretty_print_roots(quadratic_eq_t* eq);
/** @brief Reads coefficients from the stdin
 *  @param eq Quadratic equation
 *  @return void
 */
void read_coeffs(quadratic_eq_t* eq);
