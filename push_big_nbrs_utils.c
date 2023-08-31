/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_big_nbrs_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:40:15 by dlima             #+#    #+#             */
/*   Updated: 2023/08/31 18:05:31 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pivots(t_stack *a_cpy, int n_chunks)
{
	int	chunk_size;
	int	i;

	i = 0;
	chunk_size = a_cpy->size / n_chunks;
	a_cpy->pivots = malloc(sizeof(int) * n_chunks);
	while (i < n_chunks - 1)
	{
		a_cpy->pivots[i] = a_cpy->stack[chunk_size * (i + 1) - 1];
		i++;
	}
	a_cpy->pivots[n_chunks - 1] = a_cpy->stack[a_cpy->size - 1];
}

int	get_index_top(t_stack *a, int mid, int pivot)
{
	int	i;
	int	first_index;

	i = 0;
	first_index = 0;
	while (i <= mid)
	{
		if (a->stack[i] <= pivot)
		{
			first_index = i;
			break ;
		}
		i++;
	}
	return (first_index);
}

int	get_index_bottom(t_stack *a, int mid, int pivot)
{
	int	last_index;
	int	i;

	last_index = a->size - 1;
	i = last_index;
	while (i > mid)
	{
		if (a->stack[i] <= pivot)
		{
			last_index = i;
			break ;
		}
		i--;
	}
	return (last_index);
}

void	push_from_top(t_stack *a, t_stack *b, int pivot)
{

	while (1)
	{
		if (a->stack[0] <= pivot)
		{
			pb(b, a);
			break ;
		}
		ra(a);
	}
}

void	push_from_bottom(t_stack *a, t_stack *b, int pivot)
{
	while (1)
	{
		if (a->stack[0] <= pivot)
		{
			pb(b, a);
			break ;
		}
		rra(a);
	}
}
