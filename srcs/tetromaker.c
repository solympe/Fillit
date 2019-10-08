/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:38:05 by slenore           #+#    #+#             */
/*   Updated: 2019/10/03 12:47:59 by solympe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static void	create_tetro(t_tetro *tetro)
{
	(tetro)->s = ft_strnew(1);
	(tetro)->x = (int*)malloc(3 * sizeof(int));
	(tetro)->y = (int*)malloc(3 * sizeof(int));
}

static void	set_tetro_cord(t_tetro **tetro, int k, int line, int f)
{
	static int x0;
	static int y0;

	if (f == 0)
	{
		x0 = k;
		y0 = line;
	}
	else if (f < 4)
	{
		(*tetro)->x[f - 1] = k - x0;
		(*tetro)->y[f - 1] = line - y0;
	}
}

static void	tetrobox(char ***block, t_tetro *tetro)
{
	int line;
	int k;
	int f;

	line = 0;
	f = 0;
	while (line < 4)
	{
		k = 0;
		while ((*block)[line][k])
		{
			if ((*block)[line][k] != '#' && (*block)[line][k] != '.'
					&& (*block)[line][k] != '\n')
				ferror();
			if ((*block)[line][k] == '#')
			{
				set_tetro_cord(&tetro, k, line, f);
				f++;
			}
			k++;
		}
		line++;
	}
	if (f != 4)
		ferror();
}

void		check_tetro_cord(t_tetro t)
{
	int c;
	int i;
	int j;

	c = 0;
	i = -1;
	while (++i < 3)
	{
		if ((ft_abs(t.x[i]) == 1 && t.y[i] == 0)
				|| (t.x[i] == 0 && ft_abs(t.y[i]) == 1))
			c = c + 2;
		j = -1;
		while (++j < 3)
		{
			if (ft_abs(t.x[i] - t.x[j]) == 1 && t.y[i] == t.y[j])
				c++;
			if (t.x[i] == t.x[j] && ft_abs(t.y[i] - t.y[j]) == 1)
				c++;
		}
	}
	if (c != 6 && c != 8)
	{
		ferror();
	}
}

int			tetromaker(t_tetro **res, char *filename)
{
	int		count;
	int		size;
	char	***block;
	t_tetro	*tetro;

	size = reader(&block, filename);
	tetro = (t_tetro*)malloc((size + 2) * sizeof(t_tetro));
	count = 0;
	while (count <= size)
	{
		create_tetro(&tetro[count]);
		tetro[count].s[0] = 'A' + count;
		tetrobox(&block[count], &tetro[count]);
		check_tetro_cord(tetro[count]);
		count++;
	}
	create_tetro(&tetro[count]);
	tetro[count].s[0] = '0';
	*res = tetro;
	return (count);
}
