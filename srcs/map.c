/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:30:45 by slenore           #+#    #+#             */
/*   Updated: 2019/10/02 18:14:47 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void	print_map(char **map)
{
	int		i;
	char	*s;

	i = 0;
	while (map[i])
	{
		s = map[i];
		ft_putendl(s);
		i++;
	}
}

char	**nake_map(int scale)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc((scale + 1) * sizeof(char*));
	while (i < scale)
	{
		map[i] = (char*)malloc(scale + 1);
		ft_memset(map[i], 46, scale);
		map[i][scale] = '\0';
		i++;
	}
	map[scale] = 0;
	return (map);
}

int		put_tetro(t_tetro f, char **m, int i, int k)
{
	if (m[i][k] == '.')
	{
		if (m[i + f.y[0]][k + f.x[0]] == '.')
		{
			if (m[i + f.y[1]][k + f.x[1]] == '.')
			{
				if (m[i + f.y[2]][k + f.x[2]] == '.')
				{
					m[i][k] = f.s[0];
					m[i + f.y[0]][k + f.x[0]] = f.s[0];
					m[i + f.y[1]][k + f.x[1]] = f.s[0];
					m[i + f.y[2]][k + f.x[2]] = f.s[0];
					return (1);
				}
			}
		}
	}
	return (0);
}

void	remove_tetro(t_tetro f, char **m, int i, int k)
{
	m[i][k] = '.';
	m[i + f.y[0]][k + f.x[0]] = '.';
	m[i + f.y[1]][k + f.x[1]] = '.';
	m[i + f.y[2]][k + f.x[2]] = '.';
}

void	ferror(void)
{
	ft_putendl("error");
	exit(0);
}
