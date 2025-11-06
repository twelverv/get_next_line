/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuzuki <yusuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:39:25 by yusuzuki          #+#    #+#             */
/*   Updated: 2025/11/05 19:14:37 by yusuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stash)
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		len = i + 2;
	else
		len = i + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	ft_strlcpy(res, stash, len);
	return (res);
}

static char	*update_stash(char *stash)
{
	char	*newline;
	char	*new_stash;

	newline = ft_strchr(stash, '\n');
	if (!newline)
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(newline + 1);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	bytes_read = 1;
	while ((stash == NULL || !ft_strchr(stash, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buffer);
		if (!stash)
			return (NULL); // ← malloc失敗対応
	}

	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL); // ← malloc失敗 or 空stash対応
	}

	stash = update_stash(stash);
	if (!stash && line[0] == '\0')
	{
		free(line);
		return (NULL); // ← ファイル終端で空行防止
	}

	return (line);
}
