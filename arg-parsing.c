/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg-parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:27:31 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/25 13:26:28 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	counting_numbers(int i, char **argv)
{
	int	found;
	int	count;
	int	j;

	count = 0;
	found = 0;
	j = 0;
	while (argv[i][j])
	{
		if ((argv[i][j] >= '0' && argv[i][j] <= '9')
				|| (argv[i][j] == '+' || argv[i][j] == '-'))
			found = 1;
		else if (argv[i][j] == ' ' && found)
		{
			found = 0;
			count++;
		}
		j++;
		if (argv[i][j] == '\0' && found)
			count++;
	}
	return (count);
}

int	get_numbers_count(int argc, char **argv)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (++i < argc)
		count += counting_numbers(i, argv);
	return (count);
}

char	*ft_join(char *a, char *b, int c)
{
	char	*res;
	int		len;
	int		i;
	int		temp_index;

	len = ft_len(a) + ft_len(b) + 2;
	res = (char *)malloc(len * sizeof(char));
	i = 0;
	while (a && a[i] != '\0')
	{
		res[i] = a[i];
		i++;
	}
	res[i++] = c;
	temp_index = i;
	i = -1;
	while (b && b[++i] != '\0')
		res[temp_index++] = b[i];
	res[temp_index] = '\0';
	return (res);
}

int	*ft_split(char *str, int count)
{
	int	i;
	int	*arr;
	int	index;

	arr = (int *)malloc(count * sizeof(int));
	index = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
		{
			arr[index] = ft_atoi(str, i);
			index++;
		}
		while (str[i] && str[i] != ' ' && str[i] != '\0')
			i++;
	}
	return (arr);
}

int	*get_all_args(char **str, int argc)
{
	int		count;
	char	*res;
	int		*arr;
	int		i;

	i = 0;
	count = get_numbers_count(argc, str);
	res = NULL;
	while (++i < argc)
		res = ft_join(res, str[i], ' ');
	arr = ft_split(res, count);
	return (arr);
}
