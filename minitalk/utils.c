/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:00:07 by silim             #+#    #+#             */
/*   Updated: 2021/08/22 17:14:30 by silim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;
	int					count;

	num = 0;
	sign = 1;
	count = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
		count++;
	}
	return (num * sign);
}

void	ft_putnbr(int num)
{
	int	buf;

	if (num > 9)
		ft_putnbr(num / 10);
	buf = (num % 10) + '0';
	write(1, &buf, STDOUT_FILENO);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	put_error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(1);
}

void	put_str(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}
