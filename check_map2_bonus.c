/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:39:21 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/29 17:36:45 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_check_contenu(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nbr_line)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] != 'P' && map->map[i][j] != 'C' &&
				map->map[i][j] != 'E' && map->map[i][j] != '1' &&
				map->map[i][j] != '0' && map->map[i][j] != 'n')
				arerr ();
			j++;
		}
		i++;
	}
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
