/*
 * writer.c
 *
 *  Created on: 19 Dec 2015
 *      Author: Wissem
 */

#include "writer.h"
#include "common.h"

char buffer[LINE_BUFFER_SIZE];
FILE * shell_process_input_stream;

void *writerCallBack(void *pdata) {
	shell_process_input_stream = pdata;
	do {
		fgets(buffer, LINE_BUFFER_SIZE, STDIN_FILENO);
		write(shell_process_input_stream, buffer, strlen(buffer));
	} while (1);
	pthread_exit(EXIT_SUCCESS);
}
