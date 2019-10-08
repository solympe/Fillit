/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:18:49 by slenore           #+#    #+#             */
/*   Updated: 2019/10/02 18:14:16 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	select_line(char **str, char **line)
{
	int			end;
	char		*temp;

	end = 0;
	while ((*str)[end] != '\n' && (*str)[end] != '\0')
		end++;
	if ((*str)[end] == '\n')
	{
		*line = ft_strsub(*str, 0, end);
		temp = ft_strdup(&((*str)[end + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static	int	get_result(char **str, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && str[fd] == NULL)
		return (0);
	else
		return (select_line(&str[fd], line));
}

static int	fill_str(int fd, char **str)
{
	int			ret;
	char		*temp;
	char		buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (*str == NULL)
			*str = ft_strdup(buff);
		else
		{
			temp = ft_strjoin((*str), buff);
			free(*str);
			*str = temp;
		}
		if (ft_strchr(*str, '\n'))
			break ;
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char *str[FD_SIZE];

	ret = 1;
	if (fd < 0 || line == NULL || fd > FD_SIZE)
		return (-1);
	if (str[fd])
		if (ft_strchr(str[fd], '\n'))
			return (get_result(str, line, ret, fd));
	ret = fill_str(fd, &str[fd]);
	return (get_result(str, line, ret, fd));
}
