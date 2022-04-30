/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:39:21 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/28 18:19:51 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ext(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	if (!(s[len - 1] == 'r' && s[len - 2] == 'e' \
	&& s[len - 3] == 'b' && s[len - 4] == '.'))
	{
		write(1, "check extension\n", 16);
		return (1);
	}
	return (0);
}

int	ft_check_contenu(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->nbr_line)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] != 'P' && map->map[i][j] != 'C' &&
				map->map[i][j] != 'E' && map->map[i][j] != '1' &&
				map->map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	ft_count_iterm(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	ft_initialiser(map);
	while (i < map->nbr_line - 1)
	{
		j = 0;
		while (j < map->nbr_case - 1)
		{
			if (map->map[i][j] == 'P')
				map->p += 1;
			if (map->map[i][j] == 'E')
				map->e += 1;
			if (map->map[i][j] == 'C')
				map->c += 1;
			j++;
		}
		i++;
		j = 0;
	}
	if (map->e < 1 || map->p != 1 || map->c < 1)
		return (0);
	return (1);
}

int	ft_check_map_line_mur(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = map->nbr_line;
	while (j < map->nbr_case)
	{
		if (map->map[0][j] != '1' || map->map[i - 1][j] != '1')
		{
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_initialiser(t_map *map)
{
	map->steps = 0;
	map->e = 0;
	map->p = 0;
	map->c = 0;
}
