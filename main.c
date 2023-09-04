/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:29:13 by dlima             #+#    #+#             */
/*   Updated: 2023/09/04 14:22:09 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_stack *x)
{
	int	i;
	int	j;
	int	cur;

	i = 0;
	while (i < x->size)
	{
		cur = x->stack[i];
		j = 0;
		while (j < x->size)
		{

			if (cur == x->stack[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	get_list(t_stack *a, char *argv[])
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (ft_strlen(argv[i + 1]) > 11)
		{
			free_stack(a);
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		else if (ft_strlen(argv[i + 1]) == 11)
		{
			if (!(check_int(argv[i + 1])))
			{
				free_stack(a);
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
		}
		a->stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	is_num(char	*str)
{
	int	i;

	i = 0;
	if (str[i] != '-' && (str[i] < '0' || str[i] > '9'))
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(int argc, char *argv[])
{
	if (argc < 2)
		exit(EXIT_SUCCESS);
	while (argc > 1)
	{
		if (!(is_num(argv[argc - 1])))
			return (0);
		argc--;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (!check_arguments(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	a = malloc(sizeof(t_stack));
	a->size = argc - 1;
	a->stack = (int *)ft_calloc(a->size, sizeof(int));
	get_list(a, argv);
	if (!(check_duplicates(a)))
	{
		free_stack(a);
		ft_printf("Error\n");
		return (0);
	}
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	push_swap(a);
	free_stack(a);
	return (0);
}
