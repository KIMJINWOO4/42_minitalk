/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:02:18 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/12 13:37:53 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandle(int signum)
{
	static char			put;
	static unsigned int	bits;

	if (signum == SIGUSR1)
		put = (put << 1) | 1;
	else if (signum == SIGUSR2)
		put = (put << 1) | 0;
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(put, 1);
		bits = 0;
		put = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
		return (0);
	pid = getpid();
	ft_putstr_fd("SERVER PID :", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, sighandle);
	signal(SIGUSR2, sighandle);
	while (1)
		pause();
	return (0);
}
