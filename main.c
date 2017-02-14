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
#include <sys/types.h>

#define FILENAME "thefile"

int main()
{
	int fptr;
	time_t rawtime;
	struct tm *timeinfo;

	char buff[20];
	fptr = open(FILENAME,  O_WRONLY);

	if(fptr < 0)
	{
		perror("open()");
		exit(EXIT_FAILURE);
	}

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strcpy(&buff,asctime(timeinfo));

	if(write(fptr, buff, strlen(buff)) < 0)
	{
		perror("write()");
		exit(EXIT_FAILURE);
	}

	printf("written to file: %s", asctime(timeinfo));

	close(fptr);

	return 0;
}
