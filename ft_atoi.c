/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwokim <jinwokim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:47:51 by jinwokim          #+#    #+#             */
/*   Updated: 2023/10/12 14:43:04 by jinwokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	long	result;

	result = 0;
	i = 0;
	while (*(str + i))
		i++;
	if (i >= 11)
		return (-99);
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 48 && *(str + i) <= 57)
		{
			result *= 10;
			result += (*(str + i)) - '0';
		}
		else
			return (-99);
		i++;
	}
	if (result < -2147483648 || result > 2147483647)
		return (-99);
	return ((int)result);
}
