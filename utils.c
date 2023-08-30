/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:57:10 by dlima             #+#    #+#             */
/*   Updated: 2023/08/30 17:56:31 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < a->size || i < b->size)
	{
		ft_printf("%d    %d\n", a->stack[i], b->stack[i]);
		i++;
	}
	ft_printf("--   --\n");
	ft_printf("a    b\n");
}

int	is_sorted(t_stack *x)
{
	int	i;

	i = 0;
	while (i < x->size - 1)
	{
		if (!(x->stack[i] < x->stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	free_stack(t_stack *a)
{
	free(a->stack);
	free(a->pivots);
	free(a);
}

int	max_index(t_stack *a)
{
	int	i;
	int	max_index;

	i = 0;
	max_index = i;
	while (i < a->size)
	{
		if (a->stack[i] > a->stack[max_index])
			max_index = i;
		i++;
	}
	return (max_index);

}

int	min_index(t_stack *a)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = i;
	while (i < a->size)
	{
		if (a->stack[i] < a->stack[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

