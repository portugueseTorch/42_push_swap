/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:02:56 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/01/09 23:35:24 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stacks(t_s **a, t_s **b)
{
	t_s		*temp;

	temp = *a;
	printf("A = [ ");
	if (temp)
	{
		for(; temp; temp = temp->next)
		{
			printf("%ld", temp->n);
			if (temp->next)
				printf(", ");
		}
	}
	printf(" ]\n");
	temp = *b;
	printf("B = [ ");
	if (temp)
	{
		for(; temp; temp = temp->next)
		{
			printf("%ld", temp->n);
			if (temp->next)
				printf(", ");
		}
	}
	printf(" ]\n\n");
}

int	main(int argc, char **argv)
{
	t_s	*a;
	t_s	*b;

	if (argc < 2 || !valid_input(argc, argv))
	{
		ft_printf("Error\n");
		exit (1);
	}
	if (argc == 2)
		a = create_stack(argv, 0);
	else
		a = create_stack(argv, 1);
	b = NULL;
	display_stacks(&a, &b);
	sort_stack(&a, &b, 'a', 'b');
	printf("\n");
	display_stacks(&a, &b);
	return (0);
}
