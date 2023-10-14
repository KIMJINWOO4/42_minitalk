/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:19:21 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/11 14:25:11 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_recur(int n, int fd)
{
	unsigned char	c;

	if (n == 0)
		return ;
	ft_recur(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned char	digwr;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n > 9)
		ft_recur(n, fd);
	else if (n > 0)
	{
		digwr = (n % 10) + '0';
		write(fd, &digwr, 1);
	}
	else if (!n)
		write(fd, "0", 1);
	else
	{
		n = -(n);
		write(fd, "-", 1);
		ft_recur(n, fd);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	write(fd, s, i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
