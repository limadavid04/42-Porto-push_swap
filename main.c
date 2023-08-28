/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:29:13 by dlima             #+#    #+#             */
/*   Updated: 2023/08/28 19:45:58 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_list(int *stack_a, char *argv[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		// ft_printf("%d ", stack_a[i]);
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
	ft_printf("argc = %d\n", argc);
	if (argc < 2)
		return (0);
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
	t_stack	*b;
	// int		*stack_b;


	// while (size > 0)
	// {
	// 	ft_printf("%s ", argv[size]);
	// 	size--;
	// }

	if (!check_arguments(argc, argv))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	a = malloc(sizeof(t_stack));
	a->size = argc - 1;
	a->stack = (int *)ft_calloc(a->size, sizeof(int));
	b = malloc(sizeof(t_stack));
	b->size = 0;
	b->stack = (int *)ft_calloc(a->size, sizeof(int));
	get_list(a->stack, argv, a->size);
	ft_printf("GOOD LIST");
	return (0);
}

//check duplicates
