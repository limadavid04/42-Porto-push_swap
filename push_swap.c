/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:50:44 by dlima             #+#    #+#             */
/*   Updated: 2023/08/31 15:53:26 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_3(t_stack *a)
{
	if (is_sorted(a))
		return ;
	else if (a->size == 2)
		sa(a);
	else if ((a->stack[0] > a->stack[1]) && (a->stack[1] > a->stack[2]))
	{
		sa(a);
		rra(a);
	}
	else if (max_index(a) == 1 && (a->stack[0] > a->stack[2]))
		rra(a);
	else if (max_index(a) == 0 && (a->stack[1] < a->stack[2]))
		ra(a);
	else if (max_index(a) == 1 && (a->stack[0] < a->stack[2]))
	{
		rra(a);
		sa(a);
	}
	else if (max_index(a) == 2)
		sa(a);
}

void	push_swap_5(t_stack *a, t_stack *b)
{
	int	max;
	int	min;

	max = a->stack[max_index(a)];
	min = a->stack[min_index(a)];

	while (a->size != 3)
	{
		if (a->stack[0] == max || a->stack[0] == min)
			pb(b, a);
		else
			ra(a);
	}
	push_swap_3(a);
	while (b->size != 0)
	{
		if (b->stack[0] == max)
		{
			pa(a, b);
			ra(a);
		}
		else
			pa(a, b);
	}
}

void	push_swap(t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	b->size = 0;
	b->stack = (int *)ft_calloc(a->size, sizeof(int));
	if (a->size <= 3)
		push_swap_3(a);
	else if (a->size <= 5)
		push_swap_5(a, b);
	else if (a->size <= 100)
		push_swap_100(a, b);
	print_stack(a, b);
	free(b->stack);
	free(b);
}

