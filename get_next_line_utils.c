/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miron <miron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 20:16:03 by miron             #+#    #+#             */
/*   Updated: 2020/11/27 22:10:24 by miron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len;

	if (!dst || !src)
		return (0);
	len = 0;
	while (++len < size && *src)
		*(dst++) = *(src++);
	if (size)
		*dst = '\0';
	while (*(src++))
		len++;
	return (len - 1);
}

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *newdst;
	unsigned char *newsrc;

	newdst = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	if (dst == src)
		return (dst);
	else if (dst < src)
	{
		while (len--)
			*(newdst++) = *(newsrc++);
	}
	else
	{
		while (len--)
			newdst[len] = newsrc[len];
	}
	return (dst);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t len1;
	size_t len2;
	size_t i;
	char *mem;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(mem = (char *)malloc(sizeof(*mem) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		mem[i++] = *(s1++);
	while (*s2)
		mem[i++] = *(s2++);
	mem[i] = '\0';
	return (mem);
}

char *ft_strdup(const char *s1)
{
	size_t len;
	char *mem;

	len = ft_strlen(s1);
	mem = malloc(len + 1);
	if (!mem)
		return (NULL);
	ft_memmove(mem, s1, len);
	mem[len] = '\0';
	return (mem);
}

char *ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}