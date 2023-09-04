/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nbrs_into_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:16:47 by dlima             #+#    #+#             */
/*   Updated: 2023/09/04 14:22:09 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_limit_to_exit(t_stack *b, int max_i, int min_i)
{
	int	min_diff;
	int	max_diff;

	if (max_i <= (b->size - 1 - max_i))
		max_diff = max_i;
	else
		max_diff = b->size - 1 - max_i;
	if (min_i <= (b->size - 1 - min_i))
		min_diff = min_i;
	else
		min_diff = b->size - 1 - min_i;
	if (max_diff <= min_diff)
		return (1);
	return (0);
}

int	check_for_optimization(t_stack *b)
{
	int	min_i;
	int	max_i;
	int	get_from_top;

	get_from_top = 0;
	min_i = min_index(b);
	max_i = max_index(b);
	if (find_closest_limit_to_exit(b, max_i, min_i) == 1)
	{
		if (max_i <= (b->size - 1 - max_i))
			get_from_top = 1;
	}
	else
	{
		if (min_i <= (b->size - 1 - min_i))
			get_from_top = 1;
	}
	if (get_from_top == 1)
		return (1);
	return (0);

}

void	push_max(t_stack *a, t_stack *b, int max_i)
{
	int	max;
	int	get_from_top;

	get_from_top = 0;
	max = b->stack[max_i];
	if (max_i <= (b->size - 1 - max_i))
		get_from_top = 1;
	while (1)
	{
		if (b->stack[0] == max)
		{
			pa(a, b);
			break ;
		}
		else if (get_from_top == 1)
			rb(b);
		else if (get_from_top == 0)
			rrb(b);
	}
}

void	push_min(t_stack *a, t_stack *b, int min_i)
{
	int	min;
	int	get_from_top;

	get_from_top = 0;
	min = b->stack[min_i];
	if (min_i <= (b->size - 1 - min_i))
		get_from_top = 1;
	while (1)
	{
		if (b->stack[0] == min)
		{
			pa(a, b);
			if (check_for_optimization(b))
				rr(a, b);
			else
				ra(a);
			break ;
		}
		else if (get_from_top == 1)
			rb(b);
		else if (get_from_top == 0)
			rrb(b);
	}
}


void	sort_nbrs_into_a(t_stack *a, t_stack *b)
{
	int	min_i;
	int	max_i;
	int	min;

	while (b->size != 0)
	{
		min_i = min_index(b);
		max_i = max_index(b);
		if (find_closest_limit_to_exit(b, max_i, min_i) == 1)
			push_max(a, b, max_i);
		else
			push_min(a, b, min_i);
	}
	min = a->stack[min_index(a)];
	while (a->stack[0] != min)
		rra(a);
}

