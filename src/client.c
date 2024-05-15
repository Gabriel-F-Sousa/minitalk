/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <gabferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:27:47 by gabferna          #+#    #+#             */
/*   Updated: 2024/04/26 14:07:07 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(unsigned int cha, char *sig)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((cha << i) & 128)
			kill(ft_atoi(sig), SIGUSR1);
		else
			kill(ft_atoi(sig), SIGUSR2);
		usleep(50);
		i++;
	}
}

void	send_int(unsigned int nbr, char *sig)
{
	int	i;

	i = (sizeof(unsigned int) * 8) - 1;
	while (i >= 0)
	{
		if ((nbr & (1u << i)) == 0)
			kill(ft_atoi(sig), SIGUSR1);
		if ((nbr & (1u << i)) >= 1)
			kill(ft_atoi(sig), SIGUSR2);
		usleep(50);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int		i;

	if (argc != 3)
	{
		ft_printf("<PID> <STR>\n");
		return (0);
	}
	ft_printf("Start client: %s\n", argv[1]);
	ft_printf("SIZE %d\n", ft_strlen(argv[2]));
	send_int(ft_strlen(argv[2]), argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_char(argv[2][i], argv[1]);
		i++;
	}
	send_char(argv[2][i], argv[1]);
	return (0);
}
