/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:21:53 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/28 16:32:06 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close(int a)
{
	(void)a;
	exit(0);
	return (0);
}

int	ft_check_taille(t_map *map)
{
	if (map->nbr_case == map->nbr_line)
		return (1);
	return (0);
}

int	ft_check_return(t_map *map)
{
	if (!ft_count_iterm(map) || ft_line(map) == 1)
		arerr ();
	if (ft_check_map_line(map) == 1 || ft_check_map_line_mur(map) == 1)
		arerr ();
	if (ft_check_taille(map) == 1)
		arerr ();
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		write(1, "erreur f argument\n", 18);
		return (1);
	}
	ft_check_ext(av[1]);
	ft_read_map(&map, av[1]);
	ft_check_contenu(&map);
	ft_count_lenght(&map);
	ft_check_return(&map);
	map.mlx_ptr = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx_ptr, map.nbr_case * 64,
			map.nbr_line * 64, "so_long_bonus");
	parse_map(&map, 0);
	mlx_hook(map.mlx_win, 2, 17 << 0, keypress, &map);
	mlx_hook(map.mlx_win, 17, 1L << 17, ft_close, &map);
	mlx_loop(map.mlx_ptr);
	ft_free(map.map);
	return (0);
}
