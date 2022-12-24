/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:02:56 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 12:46:38 by gda-cruz         ###   ########.fr       */
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
			printf("%d", temp->n);
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
			printf("%d", temp->n);
			if (temp->next)
				printf(", ");
		}
	}
	printf(" ]\n\n");
}

/*	Two options: either argc == 2 and the numbers are passed as a string in argv[1]
	or the numbers are passed independently as args, each number in argv[x].     */
int	main(int argc, char **argv)
{
	t_s	*a;
	t_s	*b;
	
	if (argc < 2)
	{
		ft_putstr_fd("Error: Too few arguments.\n", 2);
		exit (1);
	}
	if (!valid_input(argc, argv))
	{
		ft_printf("Error\n");
		exit (1);
	}
	if (argc == 2)
		a = create_stack(argv, 0);
	else
		a = create_stack(argv, 1);
	b = NULL;
	release_stack(&a);
	return (0);
}
