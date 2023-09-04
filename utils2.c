/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:13:07 by dlima             #+#    #+#             */
/*   Updated: 2023/09/04 12:37:12 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	int			i;
	long int	number;
	int			sign;

	sign = 1;
	number = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	number *= sign;
	if (number >= -2147483648 && number <= 2147483647)
		return (1);
	return (0);
}

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

int	max_index2(t_stack *a, int max)
{
	int	i;
	int	max2;

	i = 0;
	max2 = 0;
	while (i < a->size)
	{
		if (a->stack[i] > max2 && a->stack[i] != max)
			max2 = a->stack[i];
		i++;
	}
	return (max2);
}

int	max_index3(t_stack *a, int max, int max2)
{
	int	i;
	int	max3;

	i = 0;
	max3 = 0;
	while (i < a->size)
	{
		if (a->stack[i] > max3 && a->stack[i] != max && a->stack[i] != max2)
			max3 = a->stack[i];
		i++;
	}
	return (max3);
}
