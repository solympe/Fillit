/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 12:58:11 by slenore           #+#    #+#             */
/*   Updated: 2019/10/02 18:15:35 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct	s_tetro
{
	int		*x;
	int		*y;
	char	*s;
}				t_tetro;
int				reader(char ****res, char *filename);
int				tetromaker(t_tetro **tetro, char *filename);
void			print_map(char **map);
char			**nake_map(int scale);
int				put_tetro(t_tetro f, char **m, int i, int k);
void			remove_tetro(t_tetro f, char **m, int i, int k);
int				ft_sqrt(int nb);
void			ferror(void);
#endif
