/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:13:07 by dlima             #+#    #+#             */
/*   Updated: 2023/08/30 17:40:12 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < (a->size - 1))
	{
		j = 0;
		while (j < (a->size - 1 - i))
		{
			if (a->stack[j] > a->stack[j + 1])
			{
				temp = a->stack[j];
				a->stack[j] = a->stack[j + 1];
				a->stack[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	array_cpy(t_stack *a, t_stack *cpy)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		cpy->stack[i] = a->stack[i];
		i++;
	}
}