#ifndef MAIN_H
#define MAIN_H

void _execve(char *cmd, char **args, char **env, char *name);
char **create_av(char *line);

#endif
