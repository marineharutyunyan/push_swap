/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:35:25 by maharuty          #+#    #+#             */
/*   Updated: 2022/09/25 13:27:31 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	char			name;
	int				count;
	struct s_node	*head;
}	t_list;

void	ft_exit(void);
void	push(t_list *a_stack, t_list *b_stack);
void	rotate_down(t_list *stack);
void	rotate_up(t_list *stack);
void	swap(t_list *stack);
void	set_last_node( t_list *new_list, t_node *new_node, t_node *prev_node);
void	rotate_till_top(t_list *stack, int i, int median);
void	node_to_top(t_list *stack, int (func)(t_list *));
void	back_to_a_stack(t_list *a_stack, t_list *b_stack);
void	push_swap_for_3_num(t_list *a_stack);
void	push_swap_for_4_num(t_list *a_stack, t_list *b_stack);
void	push_swap_for_5_num(t_list *a_stack, t_list *b_stack);
void	push_swap(int count, t_list *a_stack, t_list *b_stack);
int		counting_numbers(int i, char **argv);
int		get_numbers_count(int argc, char **argv);
int		*parse_arguments(char **str, int argc, char *string);
int		*get_all_args(char **str, int argc);
int		*bubble_sort(int *array, int len);
int		ft_len(char *str);
int		get_max_value(t_list *stack);
int		get_min_value(t_list *stack);
int		get_median(t_list *stack);
int		has_error(int *arr, int count);
int		ft_atoi( char *str, int i);
int		is_sorted(t_list *stack);
int		contain_duplicates(int *arr, int count);
int		get_index(int *arr, int num, int len);
t_list	*set_first_node(t_node *new_node, int len, char name);
t_list	*init_a_stack(int *arr, int len);
t_list	*init_b_stack(void);
t_node	*initi_node(int *arr, int i, int len);

#endif
