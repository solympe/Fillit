/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slenore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:02:50 by slenore           #+#    #+#             */
/*   Updated: 2019/09/06 13:15:15 by slenore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int base, int p)
{
	int i;
	int res;

	res = base;
	i = 1;
	while (i < p)
	{
		res = res * base;
		i++;
	}
	if (p == 0)
		return (1);
	return (res);
}
