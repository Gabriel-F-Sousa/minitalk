/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <gabferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:30:24 by gabferna          #+#    #+#             */
/*   Updated: 2024/04/30 10:54:55 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	g_str_size;

void			sig_handler(int signum);
int				process_str(char new_char);
void			receive_int(int signum);
unsigned char	recieve_char(int signum);

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	g_str_size = 0;
	ft_printf("waiting for sig, PID: %d\n", getpid());
	while (1)
	{
		continue ;
	}
	return (0);
}

void	sig_handler(int signum)
{
	unsigned char	new_char;
	static int		i = 0;

	if (g_str_size <= 0)
	{
		receive_int(signum);
		return ;
	}
	new_char = recieve_char(signum);
	i++;
	if (i >= 8)
	{
		if (process_str(new_char))
		{
			i = 0;
			return ;
		}
		new_char = 0;
		i = 0;
	}
}

void	receive_int(int signum)
{
	static unsigned int	new_nbr;
	static int			i = 1;

	if (signum == 12)
	{
		new_nbr = new_nbr << 1;
		new_nbr |= 0x01;
	}
	if (signum == 10)
		new_nbr = new_nbr << 1;
	if (i == sizeof(unsigned int) * 8)
	{
		g_str_size = new_nbr;
		new_nbr = 0;
		i = 1;
		return ;
	}
	i++;
}

unsigned char	recieve_char(int signum)
{
	static unsigned char	new_char = 0;

	if (signum == SIGUSR2)
		new_char = new_char << 1;
	else if (signum == SIGUSR1)
		new_char = (new_char << 1) | 0x01;
	return (new_char);
}

int	process_str(char new_char)
{
	static char			*new_str;
	static unsigned int	index = 0;

	if (!new_str && g_str_size > 0)
		new_str = malloc(sizeof(char) * g_str_size + 1);
	new_str[index] = new_char;
	if (index >= g_str_size)
	{
		ft_printf("%s", new_str);
		free(new_str);
		new_str = NULL;
		g_str_size = 0;
		index = 0;
		return (1);
	}
	index++;
	return (0);
}
