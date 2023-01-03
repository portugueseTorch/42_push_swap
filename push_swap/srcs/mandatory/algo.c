/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:58:11 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/01/03 01:06:44 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 4 6
// 1 6 4
// 4 1 6
// 4 6 1
// 6 1 4
// 6 4 1
void	sort_three(t_s **s, char src)
{
	while (1)
	{
		if (is_sorted(s))
			break ;
		if (is_max((*s)->n, s))	// first one is the max
			rotate(s, src);
		if (is_max((*s)->next->next->n, s))	// third one is the max
			swap_stack(s, src);
		if (is_max((*s)->next->n, s))	// second one is the max
			reverse_rotate(s, src);
	}
}

void	sort_four_or_five(t_s **s, t_s **d, char src, char dst)
{
	int	size;

	size = stack_length(s);
	while (size > 3)
	{
		while (index_of_min(s) != 0)
		{
			if (size % 2 == 0)
			{
				if (index_of_min(s) < (size / 2))
					rotate(s, src);
				else
					reverse_rotate(s, src);
			}
			else
			{
				if (index_of_min(s) <= (size / 2))
					rotate(s, src);
				else
					reverse_rotate(s, src);
			}
			display_stacks(s, d);
		}
		push_stack(s, d, dst);
		display_stacks(s, d);
		size = stack_length(s);
	}
	sort_three(s, src);
	while (stack_length(d) > 0)
		push_stack(d, s, src);
}
