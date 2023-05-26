#ifndef GENERAL_H
#define GENERAL_H

#define _TRUE            1
#define _FALSE           0

#define STDIN            0
#define STDOUT           1
#define STDERR           2

#define NON_INTERACTIVE  0
#define INTERACTIVE      1

#define PERMISSIONS      1
#define NON_PERMISSIONS -1

#define _FILE            10
#define NON_FILE         -10

#define ERROR_MSG_NO_FILE            "File or directory not found"
#define ERROR_MSG_PERMISSION         "Access denied"
#define ERROR_MSG_CMD_NOT_FOUND      "Command does not exist"
#define ERROR_MSG_INVALID_NUMBER     "Invalid numeric value"

#define ERROR_CODE_NO_FILE            3
#define ERROR_CODE_PERMISSION         13
#define ERROR_CODE_CMD_NOT_FOUND      132
#define ERROR_CODE_INVALID_NUMBER     133

typedef struct __attribute__((__packed__))
{
	int argc;                 /* Number of arguments received */
	char **argv;              /* Arguments received */
	int mode;                 /* INTERACTIVE or NON_INTERACTIVE */
	int error_code;           /* Error code for error message */
	char *command;            /* Command to execute */
	int n_commands;           /* Number of commands executed */
	char *value_path;         /* Path of a command */
	int is_current_path;      /* Check if is current path or not */
	int status_code;          /* Last exit code */
	char *buffer;             /* Line readed with the getline */
	char **arguments;         /* Line splited into words */
	char *environment;        /* Last environment variable get it */
	int pid;                  /* Process id */
} general_t;

typedef struct __attribute__((__packed__))
{
	char *message;            /* Error message */
	int code;                /* Error code for identify the error message */
} error_t;

typedef struct __attribute__((__packed__))
{
	char *command;            /* arguments[0] = cmd */
	void (*func)(general_t *info, char **arguments);
} builtin_t;

typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
}alias_t;

typedef struct list_s
{
    char *dir;
    struct list_s *next;
} list_t;
/* global aliases linked list */
alias_t *aliases;
#endif
