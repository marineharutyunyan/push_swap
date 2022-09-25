/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:34:25 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/15 12:34:28 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*set_first_node(t_node *new_node, int len, char name)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		ft_exit();
	new_list->count = len;
	new_list->name = name;
	new_node->prev = new_node;
	new_list->head = new_node;
	return (new_list);
}

void	set_last_node(t_list *new_list, t_node *new_node, t_node *prev_node)
{
		new_node->prev = prev_node;
		prev_node->next = new_node;
		new_node->next = new_list->head;
		new_list->head->prev = new_node;
}

t_node	*initi_node(int *arr, int i, int len)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->next = NULL;
	new_node->num = arr[i];
	new_node->index = get_index(arr, arr[i], len);
	return (new_node);
}

t_list	*init_a_stack(int *arr, int len)
{
	t_node	*new_node;
	t_node	*prev_node;
	t_list	*new_list;
	int		i;

	i = -1;
	prev_node = 0;
	new_list = 0;
	while (++i < len)
	{
		new_node = initi_node(arr, i, len);
		if (i == 0)
			new_list = set_first_node(new_node, len, 'a');
		else if (i == len - 1)
			set_last_node(new_list, new_node, prev_node);
		else
		{
			new_node->prev = prev_node;
			prev_node->next = new_node;
		}
		prev_node = new_node;
	}
	return (new_list);
}

t_list	*init_b_stack(void)
{
	t_list	*b_stack;

	b_stack = (t_list *)malloc(sizeof(t_list));
	b_stack->head = NULL;
	b_stack->name = 'b';
	b_stack->count = 0;
	return (b_stack);
}
