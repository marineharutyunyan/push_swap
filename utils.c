/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:23:02 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/25 13:28:03 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back_to_a_stack(t_list *a_stack, t_list *b_stack)
{
	while (b_stack->count)
	{
		node_to_top(b_stack, get_max_value);
		push(b_stack, a_stack);
	}
}

int	is_sorted(t_list *stack)
{
	int		flag;
	int		count;
	t_node	*temp_node;

	count = stack->count;
	flag = 1;
	temp_node = stack->head;
	if (count == 1)
		return (flag);
	else
	{
		while (count - 1)
		{
			if (temp_node->num > temp_node->next->num)
				return (0);
			count--;
			temp_node = temp_node->next;
		}	
	}
	return (flag);
}

int	contain_duplicates(int *arr, int count)
{
	int	flag;
	int	i;
	int	j;

	i = 0;
	flag = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				flag = 1;
			j++;
		}
		i++;
	}
	return (flag);
}

int	get_index(int *arr, int num, int len)
{	
	int	*sorted_arr;
	int	j;

	sorted_arr = bubble_sort(arr, len);
	j = -1;
	while (++j < len)
	{
		if (sorted_arr[j] == num)
		{
			free (sorted_arr);
			return (j);
		}
	}
	free (sorted_arr);
	return (j);
}
