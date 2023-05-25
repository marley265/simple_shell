#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "general.h"

#define LINE_BUFSIZE 1024;

/* Entry point of the shell */
void start(general_t *info);

/* readline.c */
char *_getline(void);

/* builtins.c */
int builtins(general_t *info, char **arguments);
int check_builtin(general_t *info, char **arguments);

/* exit.c */
void bin_exit(general_t *info, char **arguments);
int number_controller(general_t *info, char *number);

/* cd.c */
void bin_cd(general_t *info, char **arguments);

/* env.c */
void bin_env(general_t *info, char **arguments);
extern char *environ[];

/* echo.c */
void bin_echo(general_t *info, char **arguments);
void echo_printer(int index, char *text, char **arguments);


/* commands.c */
void analyze(char **arguments, general_t *info, char *buff);

/* permissions.c */
int is_executable(char *filename);
int is_file(char *command);

/* environment.c */
char *_getenv(const char *name);
char *which(char *filename, general_t *info);
void is_current_path(char *path, general_t *info);
void get_full_env(void);

/* execute.c */
void execute(char *commands, char **arguments, general_t *info, char *buff);
int current_directory(char *cmd, char **arguments, char *buff,
		      general_t *info);

/* error.c */
char *message_selector(general_t info);
void error(general_t *info);
void error_extra(general_t *info, char *extra);

/* free.c */
void free_pointer(void *ptr);
void free_double_pointer(void **ptr);
/* memory.c */
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* text.c */
void start_prompt(general_t *info);
void prompt(general_t *info);
char *read_prompt();
void sigintHandler(int sig_num);

/* utils_text.c */
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);

/* utils_text2.c */
char *to_string(int number);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_letter(char *s);

/* printers.c */
int _putchar_to_fd(char l, int fd);
int print_to_fd(char *msg, int fd);

/* printers_out.c */
int _putchar(char c);
int print(char *msg);

/* printers_err.c */
int print_err(char *msg);

/* tokenization.c */
char **split_words(char *line, const char *sep);
char *join_words(char *word1, char *word2, char *word3, const char *sep);

/* patterns.c */
void analyze_patterns(general_t *info, char **arguments);
char *pattern_handler(general_t *info, char *string);
char *replace_value(general_t *info, int *index, char *string);

/* patterns_replacer.c */
char *replacement(general_t *info, int *index, char *string);
char *replace_env(general_t *info, char *environment);
#endif
