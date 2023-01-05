/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:49:26 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/05 10:53:17 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
