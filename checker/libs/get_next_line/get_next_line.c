/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:23:25 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 12:23:26 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

static char	*ft_free_and_return(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static char	*ft_extract_line(char **saved)
{
	char	*line;
	char	*temp;
	char	*newline_pos;

	if (!*saved || !**saved)
		return (ft_free_and_return(saved));
	newline_pos = ft_strchr_gnl(*saved, '\n');
	if (newline_pos)
	{
		line = ft_substr_gnl(*saved, 0, newline_pos - *saved + 1);
		temp = ft_substr_gnl(*saved, newline_pos - *saved + 1, 
			ft_strlen_gnl(*saved) - (newline_pos - *saved + 1));
		free(*saved);
		*saved = temp;
		if (!*saved || !**saved)
			ft_free_and_return(saved);
		return (line);
	}
	line = ft_substr_gnl(*saved, 0, ft_strlen_gnl(*saved));
	ft_free_and_return(saved);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free_and_return(&saved));
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr_gnl(saved, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (ft_free_and_return(&saved));
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(saved, buffer);
		free(saved);
		saved = temp;
	}
	free(buffer);
	return (ft_extract_line(&saved));
}
