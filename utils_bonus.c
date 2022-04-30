/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:36:05 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/29 17:19:51 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_string_mov(t_map *map)
{
	char	*str;

	str = ft_itoa(map->steps);
	mlx_string_put(map->mlx_ptr, map->mlx_win, 10, 1, 0x99FF99, "Move:");
	mlx_string_put(map->mlx_ptr, map->mlx_win, 10, 20, 0x404040, str);
	free(str);
}
