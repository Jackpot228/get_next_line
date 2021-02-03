/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miron <miron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:34:05 by miron             #+#    #+#             */
/*   Updated: 2020/12/06 14:22:58 by miron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char *check_stringcut(char *stringcut, char **line)
{
	char *ptr_n;

	ptr_n = NULL;
	if (stringcut)
		if ((ptr_n = ft_strchr(stringcut, '\n')))
		{
			*ptr_n = '\0';
			*line = ft_strdup(stringcut);
			ptr_n++;
			ft_strlcpy(stringcut, ptr_n, BUFFER_SIZE);
		}
		else
		{
			*line = ft_strdup(stringcut);
			ft_strclr(stringcut);
		}
	else
		*line = ft_strdup("\0");
	return (ptr_n);
}

int get_next_line(int fd, char **line)
{
	char buff[BUFFER_SIZE + 1];
	int last_read_byte;
	char *ptr_n;
	static char *stringcut = NULL;
	char *tmp;

	if (fd < 0)
		return (-1);
	ptr_n = check_stringcut(stringcut, line);
	while (!ptr_n && (last_read_byte = read(fd, buff, BUFFER_SIZE)))
	{
		buff[last_read_byte] = '\0';
		if ((ptr_n = ft_strchr(buff, '\n')))
		{
			*ptr_n = '\0';
			ptr_n++;
			stringcut = ft_strdup(ptr_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	return (last_read_byte || ft_strlen(*line)) ? 1 : 0;
}

int main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
}