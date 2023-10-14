/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:51:40 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/12 18:06:40 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else if (bit == 0)
		kill(pid, SIGUSR2);
}

int	main(int argc, char *argv[])
{
	int	serverpid;
	int	i;
	int	j;
	int	bit;

	if (argc != 3 || argv[2][0] == '\0')
		return (0);
	serverpid = ft_atoi(argv[1]);
	if (serverpid < 100)
		return (0);
	i = 0;
	while (argv[2][i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			bit = (argv[2][i] >> j) & 1;
			send_bit(serverpid, bit);
			usleep(1000);
			j--;
		}
		i++;
	}
}
