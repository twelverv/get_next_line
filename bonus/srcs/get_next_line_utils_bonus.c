/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:54:09 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/10/29 20:23:16 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	letter;

	letter = (char)c;
	while (*s)
	{
		if (*s == letter)
			return ((char *)s);
		s ++;
	}
	if (letter == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin_free(char *dst, char *src)
{
	size_t	dst_len;
	size_t	src_len;
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	res = malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!res)
		return (NULL);
	while (dst && i < dst_len)
	{
		res[i] = dst[i];
		i++;
	}
	while (j < src_len)
	{
		res[i + j] = src[j];
		j++;
	}
	res[i + j] = '\0';
	return (free(dst), res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen((char *)src);
	if (size == 0)
		return (len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		src_len;
	int		i;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len ++;
	copy = (char *) malloc (sizeof(char) * (src_len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}
