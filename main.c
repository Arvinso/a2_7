/*
 * main.c
 *
 *  Created on: 2017-02-13
 *      Author: wierie
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILENAME "thefile"

int main()
{
	int *fptr;
	time_t rawtime;
	struct tm *timeinfo;

	char *buff;


	fptr = fopen(FILENAME, "w");

	if(fptr == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
		return 1;
	}

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	buff = asctime(timeinfo);

	printf(buff);

	write(fptr, &buff, sizeof(buff));

	return 0;
}
