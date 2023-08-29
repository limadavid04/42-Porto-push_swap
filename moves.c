/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:16:09 by dlima             #+#    #+#             */
/*   Updated: 2023/08/29 10:50:17 by dlima            ###   ########.fr       */
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

void	push(t_stack *dest, t_stack *src)
{
	int	top;
	int	i;

	i = dest->size;
	if (src->size == 0)
		return ;
	top = src->stack[0];
	src->stack[0] = 0;
	dest->size++;
	while (i > 0)
	{
		dest->stack[i] = dest->stack[i - 1];
		i--;
	}
	i = 0;
	while (i < src->size - 1)
	{
		src->stack[i] = src->stack[i + 1];
		i++;
	}
	src->stack[src->size - 1] = 0;
	src->size--;
	dest->stack[0] = top;
}

void	rotate(t_stack *x)
{
	int	i;
	int	temp;

	temp = x->stack[0];
	i = 0;
	while (i < x->size - 1)
	{
		x->stack[i] = x->stack[i + 1];
		i++;
	}
	x->stack[x->size - 1] = temp;
}

void	reverse_rotate(t_stack *x)
{
	int	i;
	int	temp;

	i = x->size - 1;
	temp = x->stack[x->size - 1];
	while (i > 0)
	{
		x->stack[i] = x->stack[i - 1];
		i--;
	}
	x->stack[0] = temp;
}
