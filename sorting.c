/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:01:52 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/14 13:16:41 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_items(int a, int b, int *arr)
{
	int	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int	*bubble_sort(int *array, int len)
{
	int	i;
	int	j;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < len)
		arr[i] = array[i];
	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - 1)
			if (arr[j] > arr[j + 1])
				swap_items(j, j + 1, arr);
	}
	return (arr);
}

int	get_max_value(t_list *stack)
{
	t_node	*temp_stack;
	int		max;
	int		temp_count;

	temp_stack = stack->head;
	temp_count = stack->count - 1;
	max = stack->head->index;
	while (temp_count)
	{
		if (max < temp_stack->next->index)
			max = temp_stack->next->index;
		temp_stack = temp_stack->next;
		temp_count--;
	}
	return (max);
}

int	get_min_value(t_list *stack)
{
	t_node	*temp_stack;
	int		min;
	int		temp_count;

	temp_stack = stack->head;
	min = stack->head->index;
	temp_count = stack->count - 1;
	while (temp_count)
	{
		if (min > temp_stack->next->index)
			min = temp_stack->next->index;
		temp_stack = temp_stack->next;
		temp_count--;
	}
	return (min);
}

int	get_median(t_list *stack)
{
	return (stack->count / 2);
}
