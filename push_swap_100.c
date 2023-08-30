/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:38:14 by dlima             #+#    #+#             */
/*   Updated: 2023/08/30 18:21:31 by dlima            ###   ########.fr       */
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
		a_cpy->pivots[i] = a_cpy->stack[chunk_size * (i + 1)];
		i++;
	}
	a_cpy->pivots[n_chunks - 1] = a_cpy->stack[a_cpy->size - 1];
}

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
	// int i = 0;
	// write(1, "\n",1);
	// while (i < 5)
	// {
	// 	ft_printf("%d\n", a->pivots[i]);
	// 	i++;
	// }
	// print_stack(a_cpy, a);

}
