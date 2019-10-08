/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:14:34 by slenore           #+#    #+#             */
/*   Updated: 2019/10/02 18:15:02 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"

static void	check_block(char **block)
{
	int		line;

	line = 0;
	while (line < 4)
	{
		if (block[line] == NULL || ft_strlen(block[line]) != 4)
		{
			ferror();
		}
		line++;
	}
	if (block[4] && !ft_strequ(block[4], ""))
	{
		ferror();
	}
}

static int	take_block(char ***block, int fd)
{
	int		ret;
	int		line;

	ret = 1;
	line = 0;
	while (line < 5 && ret > 0)
	{
		(*block)[line] = NULL;
		ret = get_next_line(fd, &(*block)[line]);
		line++;
	}
	if (line != 5)
		ferror();
	check_block(*block);
	return (ret);
}

int			reader(char ****res, char *filename)
{
	int		fd;
	int		count;
	char	***block;

	block = (char***)malloc(28 * sizeof(char**));
	count = 0;
	while (count < 28)
	{
		block[count++] = (char**)malloc(5 * sizeof(char*));
	}
	if ((fd = open(filename, O_RDONLY)) < 0)
		ferror();
	count = 0;
	while ((take_block(&(block[count]), fd)) && count < 27)
	{
		count++;
	}
	if (count > 25)
		ferror();
	*res = block;
	return (count);
}
