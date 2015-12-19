/*
 * shell.h
 *
 *  Created on: 19 Dec 2015
 *      Author: Wissem
 */

#ifndef SHELL_H_
#define SHELL_H_

#include <stdlib.h>
#include <stdio.h>

void* start_shell_pocess(FILE *shell_process_output_stream,
		FILE *shell_process_input_stream);

#endif /* SHELL_H_ */
