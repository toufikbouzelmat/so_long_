/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:59:30 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/25 21:05:24 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_count_collect(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->nbr_line)
	{
		j = 0;
		while (j < map->nbr_case - 1)
		{
			if (map->map[i][j] == 'C')
			{	
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	parse_map(t_map *map, int k)
{
	int	i;
	int	j;

	i = -1;
	mlx_clear_window(map->mlx_ptr, map->mlx_win);
	while (++i < map->nbr_line)
	{
		j = -1;
		while (++j < map->nbr_case)
		{
			if (map->map[i][j] == '1')
				ft_win(map, i, j, "./filexpm/tr.xpm");
			else if (map->map[i][j] == '0')
				ft_win(map, i, j, "./filexpm/obsidian.xpm");
			else if (map->map[i][j] == 'P')
				ft_win(map, i, j, "./filexpm/poulet.xpm");
			else if (map->map[i][j] == 'C')
				ft_win(map, i, j, "./filexpm/coll.xpm");
			else if (map->map[i][j] == 'E')
				ft_win(map, i, j, "./filexpm/panier.xpm");
			else if (map->map[i][j] == 'n')
				ft_ennemie(map, k);
		}
	}
}

void	ft_win(t_map *map, int i, int j, char *link)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	map->test = mlx_xpm_file_to_image(map->mlx_ptr, link, &width, &height);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->test, j * 64, \
	i * 64);
	ft_put_string_mov(map);
}

void	position_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nbr_line)
	{
		j = 0;
		while (j <= map->nbr_case)
		{
			if (map->map[i][j] == 'P')
			{
					map->position_player_line = i;
					map->position_player_case = j;
			}
			j++;
		}
		i++;
	}
}

int	ft_ennemie(t_map *map, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nbr_line)
	{
		j = 0;
		while (j < map->nbr_case)
		{
			if (map->map[i][j] == 'n')
			{
				if (k % 2 == 0)
					ft_win(map, i, j, "./filexpm/loup22.xpm");
				else
					ft_win(map, i, j, "./filexpm/loup33.xpm");
			}
			j++;
		}
		i++;
	}
	return (0);
}
