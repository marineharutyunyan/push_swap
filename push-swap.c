/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:40:01 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/25 13:29:05 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		count;
	int		*arr;
	t_list	*a_stack;
	t_list	*b_stack;

	if (argc > 1)
	{
		count = get_numbers_count(argc, argv);
		arr = get_all_args(argv, argc);
		a_stack = init_a_stack(arr, count);
		b_stack = init_b_stack();
		if (!has_error(arr, count) && !is_sorted(a_stack))
			push_swap(count, a_stack, b_stack);
	}
}
