/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:57:10 by dlima             #+#    #+#             */
/*   Updated: 2023/08/29 10:36:03 by dlima            ###   ########.fr       */
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
