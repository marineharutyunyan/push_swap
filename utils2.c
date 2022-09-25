/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:12:52 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/17 14:12:55 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	butterfly_algorithm(t_list *a_stack, t_list *b_stack,
int numbers_count, int n)
{
	int static	counter = 0;

	while (counter < numbers_count)
	{
		if (a_stack->head->index < counter)
		{
			push(a_stack, b_stack);
			rotate_down(b_stack);
			counter++;
		}
		else if (a_stack->head->index <= counter + n)
		{		
			push(a_stack, b_stack);
			counter++;
		}
		else
			rotate_down(a_stack);
	}
}

int	has_error(int *arr, int count)
{
	int	flag;

	flag = 0;
	if (contain_duplicates(arr, count))
	{
		flag = 1;
		ft_exit();
	}
	return (flag);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	push_swap(int count, t_list *a_stack, t_list *b_stack)
{
	if (count == 2 && !is_sorted(a_stack))
		swap(a_stack);
	else if (count == 3)
		push_swap_for_3_num(a_stack);
	else if (count == 4)
		push_swap_for_4_num(a_stack, b_stack);
	else if (count == 5)
		push_swap_for_5_num(a_stack, b_stack);
	else
	{	
		if (count > 5 && count < 100)
			butterfly_algorithm(a_stack, b_stack, count, 4);
		else if (count >= 100 && count < 500)
			butterfly_algorithm(a_stack, b_stack, count, 17);
		else if (count >= 500)
			butterfly_algorithm(a_stack, b_stack, count, 35);
		back_to_a_stack(a_stack, b_stack);
	}
}
