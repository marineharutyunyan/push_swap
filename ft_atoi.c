/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:36:04 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/23 11:36:09 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	are_all_digits(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (is_digit(str[i]))
		{
			if (count > 10)
				ft_exit();
			count++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

void	check_for_valid_int_range(int sign, int num)
{
	if ((sign * num) > 2147483647 || (sign * num) < -2147483648)
		ft_exit();
}

int	ft_atoi( char *str, int i)
{
	long long int	num;
	int				sign;

	sign = 1;
	num = 0;
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (str[i] == '-' && ++i)
			sign = -1;
		else if (str[i] == '+')
			i++;
		if (is_digit(str[i]))
		{
			if (are_all_digits(str, i))
			{
				num = num * 10;
				num += str[i] - 48;
				i++;
			}
		}
		else
			ft_exit();
	}
	check_for_valid_int_range(sign, num);
	return (sign * num);
}
