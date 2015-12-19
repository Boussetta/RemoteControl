/*
 * shell.c
 *
 *  Created on: 19 Dec 2015
 *      Author: Wissem
 */

/*
 *  Includes bloc
 */

#include "shell.h"
#include "common.h"

/*
 *  variable declaration bloc
 */
int masterToSlavePipe[2];
int slaveToMasterPipe[2];

/*
 *  This function launches shell process
 *  and returns its output stream
 */
void* start_shell_pocess(FILE *shell_process_input_stream,
		FILE *shell_process_output_stream) {
	/* Create Pipes for bidirectional communication*/
	if ((pipe(slaveToMasterPipe) == -1) || (pipe(masterToSlavePipe) == -1)) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	switch (fork()) {
	case -1: /* error */
		perror("fork");
		exit(EXIT_FAILURE);
	case 0: /*shell process*/
		if (close(STDIN_FILENO) == -1) {
			perror("close");
			exit(EXIT_FAILURE);
		}
		if (dup(masterToSlavePipe[0]) < 0) {
			perror("dup");
			exit(EXIT_FAILURE);
		}

		if (close(STDOUT_FILENO) == -1) {
			perror("close");
			exit(EXIT_FAILURE);
		}
		if (dup(slaveToMasterPipe[1]) < 0) {
			perror("dup");
			exit(EXIT_FAILURE);
		}

		if (close(STDERR_FILENO) == -1) {
			perror("close");
			exit(EXIT_FAILURE);
		}
		if (dup(slaveToMasterPipe[1]) < 0) {
			perror("dup");
			exit(EXIT_FAILURE);
		}

		/*close unused file descriptors*/
		if (close(slaveToMasterPipe[0]) == -1
				|| close(masterToSlavePipe[1]) == -1) {
			perror("close");
			exit(EXIT_FAILURE);
		}

		execlp("/bin/sh", "sh", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	default: /*server process*/

		/*close unused file descriptors*/
		close(slaveToMasterPipe[1]);
		close(masterToSlavePipe[0]);

		/*Associate a stream with the reading side file descriptor*/
		shell_process_output_stream = fdopen(slaveToMasterPipe[0], "r");
		if (NULL == shell_process_output_stream) {
			perror("fdopen()");
			exit(EXIT_FAILURE);
		}

		shell_process_input_stream = fdopen(masterToSlavePipe[1], "w");
		if (NULL == shell_process_input_stream) {
			perror("fdopen()");
			exit(EXIT_FAILURE);
		}

		return EXIT_SUCCESS;
	}
}
