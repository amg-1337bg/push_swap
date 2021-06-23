/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:39:21 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/16 11:13:03 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int			i;
	long long	j;

	i = 0;
	j = 0;
	while (*str == 32 || *str == 9 || *str == 11
		|| *str == 12 || *str == 13 || *str == 10)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = 1;
		str++;
	}
	if (*str < 48 && *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		j = j * 10 + *str - '0';
		str++;
	}
	if (i == 1)
		return (j * -1);
	return (j);
}
