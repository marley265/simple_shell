#ifndef SHELL_H
#define SHELL_H

#define SHELL_BUFSIZE 1024;
#define TOKEN_BUFSIZE 64;
#define TOKEN_DELIM "\t\r\n\a";

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

char *command(char *line, ssize_t bufsize);
#endif
