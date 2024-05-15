/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:31:31 by gabferna          #+#    #+#             */
/*   Updated: 2023/10/04 11:31:33 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	n = 0;
	while ((str[n] >= 9 && str[n] <= 13) || str[n] == 32)
	{
		n++;
	}
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			sign *= -1;
		n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		res = (res * 10) + (str[n] - 48);
		n++;
	}
	return (sign * res);
}
