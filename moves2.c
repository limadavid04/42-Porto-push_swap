/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:39:41 by dlima             #+#    #+#             */
/*   Updated: 2023/09/04 14:34:01 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	pa(t_stack *dest, t_stack *src)
{
	push(dest, src);
	ft_printf("pa\n");
}

void	pb(t_stack *dest, t_stack *src)
{
	push(dest, src);
	ft_printf("pb\n");
}
