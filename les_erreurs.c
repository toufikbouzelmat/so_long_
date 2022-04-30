/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   les_erreurs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:17:48 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/29 17:20:41 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	arerr(void)
{
	ft_putendl_fd("Erreur\ncheck your program", 2);
	exit(1);
}

void	ft_initialiser(t_map *map)
{
	map->steps = 0;
	map->e = 0;
	map->p = 0;
	map->c = 0;
}
