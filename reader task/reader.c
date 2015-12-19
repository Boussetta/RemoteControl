/*
 * reader.c
 *
 *  Created on: 19 Dec 2015
 *      Author: Wissem
 */

/*
 * Includes code block
 */
#include "reader.h"
#include "common.h"

/*
 *  variable declaration bloc
 */
FILE * shell_process_output_stream;
char buffer[LINE_BUFFER_SIZE];

void *readerCallBack(void *pdata) {
	shell_process_output_stream = pdata;
	do {
		if (NULL
				== fgets(buffer, LINE_BUFFER_SIZE,
						shell_process_output_stream)) {
			perror("fgets");
			exit(EXIT_FAILURE);
		}
		printf("reader > %s", buffer);
	} while (1);
	pthread_exit(EXIT_SUCCESS);
}
