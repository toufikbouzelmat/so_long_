/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:34:52 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/29 17:20:00 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

void	f_map_error(void);
void	ext_error(void);
void	fail_err(void);
void	arerr(void);
void	errmap(void);
int		ft_check_ext(char *s);
char	*get_next_line(int fd);
int		ft_read_map(t_map *map, char *av);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_check_contenu(t_map *map);
int		ft_count_iterm(t_map *map);
int		ft_count_lenght(t_map *map);
int		ft_check_map_line(t_map *map);
int		ft_check_map_line_mur(t_map *map);
int		ft_line(t_map *map);
void	ft_win(t_map *map, int i, int j, char *link);
void	parse_map(t_map *map, int k);
int		keypress(int keycode, t_map *map);
void	ft_gauche(t_map *map, int k);
void	ft_droit(t_map *map, int k);
void	ft_haut(t_map *map, int k);
void	ft_bas(t_map *map, int k);
int		ft_count_collect(t_map *map);
void	position_player(t_map *map);
void	ft_put_string_mov(t_map *map);
char	*ft_itoa(int n);
int		ft_ennemie(t_map *map, int k);
int		ft_close(int a);
int		ft_check_return(t_map *map);
void	ft_initialiser(t_map *map);
void	ft_free(char **map);
int		ft_check_taille(t_map *map);
#endif