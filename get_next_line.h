#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFFER_SIZE 1000
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line_utils.c"

char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s1);
char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
void *ft_memmove(void *dst, const void *src, size_t len);

int get_next_line(int fd, char **line);

#endif