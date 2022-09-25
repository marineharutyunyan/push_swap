/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:33:03 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/15 12:33:06 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(char c, char name)
{
	write(1, &c, 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	push(t_list *a_stack, t_list *b_stack)
{
	t_node	*temp;

	temp = a_stack->head->next;
	temp->prev = a_stack->head->prev;
	a_stack->head->prev->next = a_stack->head->next;
	if (b_stack->count == 0)
	{	
		b_stack->head = a_stack->head;
		b_stack->head->next = a_stack->head;
		b_stack->head->prev = a_stack->head;
	}
	else
	{
		a_stack->head->next = b_stack->head;
		a_stack->head->prev = b_stack->head->prev;
		b_stack->head->prev->next = a_stack->head;
		b_stack->head->prev = a_stack->head;
	}
	b_stack->head = a_stack->head;
	a_stack->head = temp;
	a_stack->count -= 1;
	b_stack->count += 1;
	ft_print('p', b_stack->name);
}

void	rotate_down(t_list *stack)
{
	ft_print('r', stack->name);
	stack->head = stack->head->next;
}

void	rotate_up(t_list *stack)
{
	stack->head = stack->head->prev;
	write(1, "r", 1);
	ft_print('r', stack->name);
}

void	swap(t_list *stack)
{
	int		temp_num;
	int		temp_index;

	temp_num = stack->head->num;
	temp_index = stack->head->index;
	stack->head->num = stack->head->next->num;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = temp_index;
	stack->head->next->num = temp_num;
	ft_print('s', stack->name);
}
