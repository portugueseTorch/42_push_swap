/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:42:41 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/01/05 10:50:45 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	display_stacks(t_s **a, t_s **b)
// {
// 	t_s		*temp;

// 	temp = *a;
// 	printf("A = [ ");
// 	if (temp)
// 	{
// 		for(; temp; temp = temp->next)
// 		{
// 			printf("%d", temp->n);
// 			if (temp->next)
// 				printf(", ");
// 		}
// 	}
// 	printf(" ]\n");
// 	temp = *b;
// 	printf("B = [ ");
// 	if (temp)
// 	{
// 		for(; temp; temp = temp->next)
// 		{
// 			printf("%d", temp->n);
// 			if (temp->next)
// 				printf(", ");
// 		}
// 	}
// 	printf(" ]\n\n");
// }

int	main(int argc, char **argv)
{
	t_s		*a;
	t_s		*b;

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
	execute_rules(&a, &b);
	if (sorted_stacks(&a, &b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	release_stack(&a);
	release_stack(&b);
	return (0);
}
