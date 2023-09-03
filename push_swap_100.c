/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:38:14 by dlima             #+#    #+#             */
/*   Updated: 2023/09/03 17:59:52 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_closest_chunk_nbr(t_stack *a, int pivot)
{
	int	mid;
	int	first_index;
	int	last_index;

	mid = ((a->size - 1) / 2);
	first_index = get_index_top(a, mid, pivot);
	last_index = get_index_bottom(a, mid, pivot);

	if (!(a->stack[first_index] <= pivot) && !(a->stack[last_index] <= pivot))
		return (0);
	else if (a->stack[first_index] <= pivot && !(a->stack[last_index] <= pivot))
		return (1);
	else if (a->stack[last_index] <= pivot && !(a->stack[first_index] <= pivot))
		return (2);
	else if (first_index <= (a->size - 1 - last_index))
		return (1);
	else
		return (2);
}


void	push_last_chunk(t_stack *a, t_stack *b)
{
	int	max;
	int	max2;
	int	max3;

	if (a->size <= 3)
	{
		push_swap_3(a);
		return ;
	}
	max = a->stack[max_index(a)];
	max2 = max_index2(a, max);
	max3 = max_index3(a, max, max2);

	while (!(a->size <= 3))
	{
		if (a->stack[0] != max && a->stack[0] != max2 && a->stack[0] != max3)
			pb(b, a);
		else
			ra(a);
	}
	push_swap_3(a);
}

void	push_by_chunk(t_stack *a, t_stack *b, int n_chunks)
{
	int	i;

	i = 0;
	while (i < n_chunks - 1)
	{
		while (1)
		{
			if (get_closest_chunk_nbr(a, a->pivots[i]) == 0)
				break ;
			// else if (get_closest_chunk_nbr(a, a->pivots[i]) == 1)
			push_from_top(a, b, a->pivots[i]);
		// 	else if (get_closest_chunk_nbr(a, a->pivots[i]) == 2)
		// 		push_from_bottom(a, b, a->pivots[i]);
		}
		i++;
	}
	push_last_chunk(a, b);
}

void	push_swap_100(t_stack *a, t_stack *b, int bigger_100)
{
	t_stack	*a_cpy;
	int		n_chunks;

	if (bigger_100 == 1)
		n_chunks = 11;
	else
		n_chunks = 5;
	a_cpy = malloc(sizeof(t_stack));
	a_cpy->stack = (int *)ft_calloc(a->size, sizeof(int));
	a_cpy->size = a->size;
	array_cpy(a, a_cpy);
	bubble_sort(a_cpy);
	get_pivots(a_cpy, n_chunks);
	a->pivots = a_cpy->pivots;
	free(a_cpy->stack);
	free(a_cpy);
	push_by_chunk(a, b, n_chunks);
	sort_nbrs_into_a(a, b);
	free(a->pivots);

	// int i = 0;
	// write(1, "\n",1);
	// while (i < 5)
	// {
	// 	ft_printf("%d\n", a->pivots[i]);
	// 	i++;
	// }
	// write(1, "\n",1);

	// print_stack(a_cpy, a);
}

