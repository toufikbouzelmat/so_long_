/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:58:53 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/28 18:14:23 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_lines(char *av)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(av, O_RDWR);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		i++;
	}
	close (fd);
	return (i);
}

int	ft_count_lenght(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < map->nbr_line)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			j++;
		}
		count = j;
		i++;
	}
	map->nbr_case = count;
	return (count);
}

int	ft_read_map(t_map *map, char *av)
{
	int		fd;
	char	*line;

	map->nbr_line = ft_count_lines(av);
	if (!map->nbr_line)
	{
		write(1, "map invalid\n", 14);
		exit(1);
	}
	map->map = malloc(sizeof(char *) * map->nbr_line);
	map->nbr_line = 0;
	fd = open(av, O_RDWR);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->map[map->nbr_line] = line;
		map->nbr_line++;
	}
	close(fd);
	return (map->nbr_line);
}

int	ft_check_map_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = map->nbr_case;
	while (i < map->nbr_line)
	{
		if (map->map[i][0] != '1' || map->map[i][j - 1] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_line(t_map *map)
{
	int	i;
	int	j;
	int	count;

	count = map->nbr_case;
	i = 0;
	j = 0;
	while (i < map->nbr_line)
	{
		while (map->map[i][j] != '\0')
		{
			j++;
		}
		if (j != count)
			return (1);
		i++;
	}
	return (0);
}
