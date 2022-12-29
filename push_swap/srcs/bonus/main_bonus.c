/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:42:41 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/29 17:11:44 by gda-cruz         ###   ########.fr       */
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

void	redirect_rule(char *rule, t_s **a, t_s **b)
{
	if (!ft_strncmp("sa\n", rule, 3))
		swap_stack(a, 'a');
	else if (!ft_strncmp("sb\n", rule, 3))
		swap_stack(b, 'b');
	else if (!ft_strncmp("ss\n", rule, 3))
		swap_both(a, b);
	else if (!ft_strncmp("pa\n", rule, 3))
		push_stack(b, a, 'a');
	else if (!ft_strncmp("pb\n", rule, 3))
		push_stack(a, b, 'b');
	else if (!ft_strncmp("ra\n", rule, 3))
		rotate(a, 'a');
	else if (!ft_strncmp("rb\n", rule, 3))
		rotate(b, 'b');
	else if (!ft_strncmp("rr\n", rule, 3))
		rotate_both(a, b);
	else if (!ft_strncmp("rra\n", rule, 4))
		reverse_rotate(a, 'a');
	else if (!ft_strncmp("rrb\n", rule, 4))
		reverse_rotate(b, 'b');
	else if (!ft_strncmp("rrr\n", rule, 4))
		reverse_rotate_both(a, b);
	else
		error_handler(rule, a, b);
	free(rule);
}

void	execute_rules(t_s **a, t_s **b)
{
	char	*rule;

	rule = get_next_line(0);
	while (rule)
	{
		redirect_rule(rule, a, b);
		rule = get_next_line(0);
	}
	free(rule);
}

int	sorted_stack(t_s **a, t_s **b)
{
	t_s	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	if (*b)
		return (0);
	return (1);
}

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
	if (sorted_stack(&a, &b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	release_stack(&a);
	release_stack(&b);
	return (0);
}
