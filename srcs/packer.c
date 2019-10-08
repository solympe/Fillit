/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 12:16:42 by slenore           #+#    #+#             */
/*   Updated: 2019/10/03 12:34:19 by solympe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_coordinates(t_tetro f, int i, int k, int m_size)
{
	if (k + f.x[0] >= 0 && k + f.x[1] >= 0 && k + f.x[2] >= 0)
	{
		if (k + f.x[0] < m_size && k + f.x[1] < m_size && k + f.x[2] < m_size)
		{
			if (i + f.y[0] < m_size &&
					i + f.y[1] < m_size && i + f.y[2] < m_size)
			{
				if (i < m_size && k < m_size)
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

int		try_plc(t_tetro item, char **s_map, int i, int k)
{
	int m_scale;

	m_scale = ft_strlen(s_map[0]);
	if (check_coordinates(item, i, k, m_scale))
	{
		if (put_tetro(item, s_map, i, k))
		{
			return (1);
		}
	}
	return (0);
}

int		solve(t_tetro *tetro, char **map, int i)
{
	int		m_size;
	int		val;

	if (tetro[i].s[0] == '0')
	{
		return (1);
	}
	val = 0;
	m_size = ft_strlen(map[0]);
	while (val < m_size * m_size)
	{
		if (try_plc(tetro[i], map, val / m_size, val % m_size))
		{
			if (solve(tetro, map, i + 1))
			{
				return (1);
			}
			else
			{
				remove_tetro(tetro[i], map, val / m_size, val % m_size);
			}
		}
		val++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		size;
	t_tetro	*tetro;
	int		map_scale;
	char	**map;

	if (ac != 2)
	{
		ft_putendl("usage: fillit target file");
		return (0);
	}
	tetro = NULL;
	size = tetromaker(&tetro, av[1]);
	map_scale = 2 * ft_sqrt(size);
	map = nake_map(map_scale);
	while (!solve(tetro, map, 0))
	{
		ft_memdel((void**)map);
		map = nake_map(++map_scale);
		if (map_scale > size * size + 2)
		{
			ferror();
		}
	}
	print_map(map);
	return (0);
}
