#ifndef MAIN_H
#define MAIN_H

extern char **environ;
#define EXIT "exit\n"
#define ENTER "\n"

/* FUNCTIONS */
void _execve(char *cmd, char **args, char **env, char *name);
char **create_av(char *line);
char *_getenv(const char *name);
int check_cmd(char **av);

/* HELPERS */
int _strlen(const char *str);
void _strcpy(char *dest, const char *src);
void _strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);

/* SIGNAL HANDLERS */
void ctrl_c_handler();

#endif
