/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:58:33 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/29 17:18:06 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define ESCAPE_KEY 53

# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<mlx.h>

typedef struct s_map
{
	char	**map;
	int		nbr_line;
	int		nbr_case;
	int		p;
	int		c;
	int		e;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*test;
	int		position_player_line;
	int		position_player_case;
	int		steps;
	char	*mov;
}	t_map;

int		ft_check_ext(char *s);
char	*get_next_line(int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_read_map(t_map *map, char *av);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_check_contenu(t_map *map);
int		ft_count_iterm(t_map *map);
int		ft_count_lenght(t_map *map);
int		ft_check_map_line(t_map *map);
int		ft_check_map_line_mur(t_map *map);
int		ft_line(t_map *map);
void	ft_win(t_map *map, int i, int j, char *link);
int		parse_map(t_map *map);
int		keypress(int keycode, t_map *map);
void	ft_gauche(t_map *map);
void	ft_droit(t_map *map);
void	ft_haut(t_map *map);
void	ft_bas(t_map *map);
int		ft_count_collect(t_map *map);
void	position_player(t_map *map);
void	count_steps(t_map *map);
void	count_steps_bonus(t_map *map);
int		ft_atoi(const	char *str);
int		ft_check_return(t_map *map);
void	arerr(void);
int		ft_close(int a);
int		ft_check_taille(t_map *map);
void	ft_initialiser(t_map *map);

#endif