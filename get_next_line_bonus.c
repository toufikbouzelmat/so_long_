/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line._bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:58:44 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/22 15:36:10 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*read_buff_size(int fd, char *lines)
{
	char	*bufer;
	int		i;

	i = 1;
	bufer = malloc(2);
	if (!bufer)
		return (NULL);
	while (!(ft_strchr(lines, '\n')) && i)
	{
		i = read(fd, bufer, 1);
		if (i < 0)
		{
			free(bufer);
			return (NULL);
		}
		bufer[i] = '\0';
		lines = ft_strjoin(lines, bufer);
	}
	free (bufer);
	return (lines);
}

char	*one_line(char *lines)
{
	int	i;

	i = 0;
	if (!lines[i])
		return (NULL);
	while (lines[i] != '\n' && lines[i])
		i++;
	return (ft_substr(lines, 0, i));
}

char	*lines_rest(char *file_line)
{
	int		j;
	char	*dup;

	j = 0;
	while (file_line[j] != '\n' && file_line[j])
		j++;
	if (!file_line[j])
	{
		free(file_line);
		return (NULL);
	}
	dup = ft_substr(file_line, ++j, ft_strlen(file_line));
	free(file_line);
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	*file_line;
	char		*o_line;

	if (fd < 0)
		return (NULL);
	file_line = read_buff_size(fd, file_line);
	if (!file_line)
		return (NULL);
	o_line = one_line(file_line);
	file_line = lines_rest(file_line);
	return (o_line);
}
