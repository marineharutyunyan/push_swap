/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap-helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:53:41 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/15 12:53:43 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_till_top(t_list *stack, int i, int median)
{
	int	num_of_rotates;

	num_of_rotates = i;
	if (i < median)
		num_of_rotates = i;
	else
		num_of_rotates = stack->count - i;
	while (num_of_rotates)
	{
		if (i < median)
			rotate_down(stack);
		else
			rotate_up(stack);
		num_of_rotates--;
	}
}

void	node_to_top(t_list *stack, int (func)(t_list *))
{
	int		i;
	int		median;
	t_node	*temp_node;

	i = -1;
	temp_node = stack->head;
	median = get_median(stack);
	while (++i < stack->count)
	{
		if (temp_node->index == func(stack))
		{			
			rotate_till_top(stack, i, median);
		}
		temp_node = temp_node->next;
	}
}

void	push_swap_for_3_num(t_list *a_stack)
{
	int	first;
	int	second;
	int	thirth;

	first = a_stack->head->index;
	second = a_stack->head->next->index;
	thirth = a_stack->head->prev->index;
	if (thirth > first && thirth < second && first < second)
	{
		rotate_up(a_stack);
		swap(a_stack);
	}
	else if (thirth > first && thirth > second && first > second)
		swap(a_stack);
	else if (thirth < first && thirth < second && first < second)
		rotate_up(a_stack);
	else if (thirth < first && thirth > second && first > second)
		rotate_down(a_stack);
	else if (thirth < first && thirth < second && first > second)
	{
		rotate_down(a_stack);
		swap(a_stack);
	}	
}

void	push_swap_for_4_num(t_list *a_stack, t_list *b_stack)
{
	if (!is_sorted(a_stack))
	{
		node_to_top(a_stack, get_min_value);
		push(a_stack, b_stack);
		push_swap_for_3_num(a_stack);
		push(b_stack, a_stack);
	}	
}

void	push_swap_for_5_num(t_list *a_stack, t_list *b_stack)
{
	if (!is_sorted(a_stack))
	{
		node_to_top(a_stack, get_min_value);
		push(a_stack, b_stack);
		node_to_top(a_stack, get_min_value);
		push(a_stack, b_stack);
		push_swap_for_3_num(a_stack);
		push(b_stack, a_stack);
		push(b_stack, a_stack);
	}	
}
