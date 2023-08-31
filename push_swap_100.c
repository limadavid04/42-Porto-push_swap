/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:38:14 by dlima             #+#    #+#             */
/*   Updated: 2023/08/31 13:15:05 by dlima            ###   ########.fr       */
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
	else if (a->stack[first_index <= pivot] && !(a->stack[last_index] <= pivot))
		return (1);
	else if (a->stack[last_index <= pivot] && !(a->stack[first_index] <= pivot))
		return (2);
	else if (first_index <= (a->size - 1 - last_index))
		return (1);
	else
		return (2);
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
void	push_by_chunk(t_stack *a, t_stack *b)
{
	int	n_chunk;
	int	i;

	n_chunk = 5;
	i = 0;
	while (i < n_chunk - 1)
	{
		while (1)
		{
			if (get_closest_chunk_nbr(a, a->pivots[i]) == 0)
				break ;
			else if (get_closest_chunk_nbr(a, a->pivots[i]) == 1)
				push_from_top(a, b, a->pivots[i]);
			else if (get_closest_chunk_nbr(a, a->pivots[i]) == 2)
				push_from_bottom(a, b, a->pivots[i]);
		}
		i++;
	}
	//push last chunk;
}


//if get closest function couldnt find a meber of chunk return 0;
void	push_swap_100(t_stack *a, t_stack *b)
{
	t_stack	*a_cpy;

	(void) b;
	a_cpy = malloc(sizeof(t_stack));
	a_cpy->stack = (int *)ft_calloc(a->size, sizeof(int));
	a_cpy->size = a->size;
	array_cpy(a, a_cpy);
	bubble_sort(a_cpy);
	get_pivots(a_cpy, 5);
	a->pivots = a_cpy->pivots;
	free(a_cpy->stack);
	free(a_cpy);
	push_by_chunk(a, b);
	int i = 0;
	write(1, "\n",1);
	while (i < 5)
	{
		ft_printf("%d\n", a->pivots[i]);
		i++;
	}
	write(1, "\n",1);

	// print_stack(a_cpy, a);
}

