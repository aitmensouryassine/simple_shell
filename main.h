#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>

extern char **environ;
#define EXIT "exit\n"
#define ENTER "\n"

/* FUNCTIONS */
void _execve(char *cmd, char **args, char **env, char *name);
char **create_av(char *line);
char *_getenv(const char *name);
int check_cmd(char **av);
void _built_in_cd(char **argmts)

/* HELPERS */
int _strlen(const char *str);
void _strcpy(char *dest, const char *src);
void _strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int chdir( const char * path );

/* SIGNAL HANDLERS */
void sigHandler(int sig);

/*alias*/
typedef struct alias
{
	char *key;
	char *value;
	struct alias *next;
} alias;


#endif
