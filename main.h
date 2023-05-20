#ifndef MAIN_H
#define MAIN_H

void _execve(char *cmd, char **args, char **env, char *name);
char **create_av(char *line);

/* HELPERS */
int _strlen(const char *str)
void _strcpy(char *dest, const char *src);
void _strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);

#endif
