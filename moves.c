/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:16:09 by dlima             #+#    #+#             */
/*   Updated: 2023/08/28 19:47:28 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *x)
{
	int	temp;

	if (x->size < 2)
		return ;
	temp = x->stack[0];
	x->stack[0] = x->stack[1];
	x->stack[1] = temp;
}

void	push(t_stack *a, t_stack *b)
{
	int	top;
	int	temp;
	int	i;

	i = a->size;
	if (b->size == 0)
		return ;
	top = b->stack[0];
	while (i > 0)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = top;
}
