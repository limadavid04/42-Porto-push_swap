/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_big_nbrs_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:40:15 by dlima             #+#    #+#             */
/*   Updated: 2023/09/04 14:22:09 by dlima            ###   ########.fr       */
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
