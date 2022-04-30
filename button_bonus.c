/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:27:00 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/28 18:23:35 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	keypress(int keycode, t_map *map)
{
	static int	k;

	if (keycode == ESCAPE_KEY)
	{
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		exit(0);
	}
	else if (keycode == D_KEY)
		ft_droit(map, k);
	else if (keycode == A_KEY)
		ft_gauche(map, k);
	else if (keycode == W_KEY)
		ft_bas(map, k);
	else if (keycode == S_KEY)
		ft_haut(map, k);
	k++;
	return (0);
}

void	ft_droit(t_map *map, int k)
{
	int	i;
	int	j;

	position_player(map);
	i = map->position_player_line;
	j = map->position_player_case;
	if (map->map[i][j + 1] == '0' || map->map[i][j + 1] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i][j + 1] = 'P';
		map->steps++;
		parse_map(map, k);
	}
	if (map->map[i][j + 1] == 'n')
	{
		printf("you Lost\n");
		exit(0);
	}
	if (ft_count_collect(map) == 0 && map->map[i][j + 1] == 'E')
	{
		map->steps++;
		exit(0);
	}
}

void	ft_gauche(t_map *map, int k)
{
	int	i;
	int	j;

	position_player(map);
	i = map->position_player_line;
	j = map->position_player_case;
	if (map->map[i][j - 1] == '0' || map->map[i][j - 1] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i][j - 1] = 'P';
		map->steps++;
		parse_map(map, k);
	}
	if (map->map[i][j - 1] == 'n')
	{
		printf("you Lost\n");
		exit(0);
	}
	else if (ft_count_collect(map) == 0 && map->map[i][j - 1] == 'E')
	{
		map->map[i][j] = '0';
		map->map[i][j - 1] = 'E';
		map->steps++;
		exit(0);
	}
}

void	ft_haut(t_map *map, int k)
{
	int	i;
	int	j;

	position_player(map);
	i = map->position_player_line;
	j = map->position_player_case;
	if (map->map[i + 1][j] == '0' || map->map[i + 1][j] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i + 1][j] = 'P';
		map->steps++;
		parse_map(map, k);
	}
	if (map->map[i + 1][j] == 'n')
	{
		printf("you Lost\n");
		exit(0);
	}
	else if (ft_count_collect(map) == 0 && map->map[i + 1][j] == 'E')
	{
		map->map[i][j] = '0';
		map->map[i + 1][j] = 'E';
		map->steps++;
		exit(0);
	}
}

void	ft_bas(t_map *map, int k)
{
	int	i;
	int	j;

	position_player(map);
	i = map->position_player_line;
	j = map->position_player_case;
	if (map->map[i - 1][j] == '0' || map->map[i - 1][j] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i - 1][j] = 'P';
		map->steps++;
		parse_map(map, k);
	}
	if (map->map[i - 1][j] == 'n')
	{
		printf("you Lost\n");
		exit(0);
	}
	else if (ft_count_collect(map) == 0 && map->map[i - 1][j] == 'E')
	{
		map->map[i][j] = '0';
		map->map[i - 1][j] = 'E';
		map->steps++;
		exit(0);
	}
}
