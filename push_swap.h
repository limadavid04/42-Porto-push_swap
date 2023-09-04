/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:04:29 by dlima             #+#    #+#             */
/*   Updated: 2023/09/04 14:22:07 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

typedef struct Stack
{
	int	*stack;
	int	size;
	int	*pivots;
}	t_stack;

void	print_stack(t_stack *a, t_stack *b);
void	swap(t_stack *x);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *x);
void	reverse_rotate(t_stack *x);
int		is_sorted(t_stack *x);
void	free_stack(t_stack *a);
void	sa(t_stack *a);
void	sb(t_stack *a);
void	pa(t_stack *dest, t_stack *src);
void	pb(t_stack *dest, t_stack *src);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	push_swap(t_stack *a);
void	push_swap_3(t_stack *a);
int		max_index(t_stack *a);
int		min_index(t_stack *a);
void	push_swap_100(t_stack *a, t_stack *b, int bigger_100);
void	bubble_sort(t_stack *a);
void	array_cpy(t_stack *a, t_stack *cpy);
int		max_index2(t_stack *a, int max);
int		max_index3(t_stack *a, int max, int max2);
void	push_from_top(t_stack *a, t_stack *b, int pivot);
void	get_pivots(t_stack *a_cpy, int n_chunks);
void	sort_nbrs_into_a(t_stack *a, t_stack *b);
int		check_int(char *str);
#endif
