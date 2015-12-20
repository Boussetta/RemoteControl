/*
 * remote.c
 *
 *  Created on: 19 Dec 2015
 *      Author: Wissem
 */

/*
 * Includes code block
 */

#include "shell.h"
#include "reader.h"
#include "writer.h"
#include "common.h"

/*
 *  variable declaration bloc
 */
pid_t main_process_pid;

int main(int argc, char **argv) {
	int status;
	pthread_t reader, writer;
	FILE *shell_process_output_stream;
	FILE *shell_process_input_stream;

	main_process_pid = getpid();

	/*
	 *  start shell process
	 */
	start_shell_pocess(shell_process_input_stream, shell_process_output_stream);
	if (NULL == shell_process_output_stream) {
		perror("start_shell_pocess");
		exit(EXIT_FAILURE);
	}

	/*
	 *  start reader task
	 */
	if (pthread_create(&reader, NULL, readerCallBack,
			shell_process_output_stream) != 0) {
		perror("pthread_create()");
		exit(EXIT_FAILURE);
	}

	/*
	 *  start writer task
	 */
	if (pthread_create(&writer, NULL, writerCallBack,
			shell_process_input_stream) != 0) {
		perror("pthread_create()");
		exit(EXIT_FAILURE);
	}

	/*
	 *	wait for an end
	 */
	if (pthread_join(reader, NULL) != 0) {
		perror("pthread_join()");
		exit(EXIT_FAILURE);
	}
	if (pthread_join(writer, NULL) != 0) {
		perror("pthread_join()");
		exit(EXIT_FAILURE);
	}
	if (wait(&status) == -1) {
		perror("wait()");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
