/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:38:56 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/05 23:07:00 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_s **s, char src)
{
	while (1)
	{
		if (is_sorted(s))
			break ;
		if (is_max((*s)->n, s))
			rotate(s, src);
		else if (is_max((*s)->next->next->n, s))
			swap_stack(s, src);
		else
			reverse_rotate(s, src);
	}
}

void	sort_five(t_s **s, t_s **d, char src, char dst)
{
	int	size;
	
	size = stack_length(s);
	if (size == 2)
		swap_stack(s, src);
	else
	{
		while (size > 3)
		{
			while (index_of_min(s) != 0)
			{
				if (index_of_min(s) <= size / 2)
					rotate(s, src);
				else
					reverse_rotate(s, src);
			}
			if (is_sorted(s))
				break ;
			push_stack(s, d, dst);
			size = stack_length(s);
		}
		sort_three(s, src);
		while (stack_length(d) > 0)
			push_stack(d, s, src);
	}
}

void	sort_general(t_s **s, t_s **d, char src, char dst);
{
	//At this point, stack B necessarily has at least on element
	//As such, as long as stack b is not empty, keep finding the cheapest move and executing it
	t_s *cheapest;
	(void) dst;
	while (stack_length(d))
	{
		cheapest = find_cheapest(s, d);
		execute(cheapest, s, d);
	}
	while (!is_sorted(s))
	{
		if (index_of_min(s) <= (stack_length(s) / 2))
			rotate(s, src);
		else
			reverse_rotate(s, src);
	}
}

/*	While the stack is not sub-sorted or it has more than 5 numbers, push to b
	A sub-sorted stack will be one where inside it there is a sorted section and
	in this case the first element is also larger than the last, so that the stack
	can be sorted using only reverse or rotates.

	8 9 1 2 3 - valid
	6 7 3 4 5 - valid
	2 3 1 7 4 - invalid
	7 8 4 5 2 3 - invalid
*/
void	sort_stack(t_s **s, t_s **d, char src, char dst)
{
	if (!s || !*s || !d)
		return ;
	if (sorted_stacks(s, d))
		return ;
	if (stack_length(s) < 6)
		sort_five(s, d, src, dst);
	else
	{
		while (!sub_sorted(s) && stack_length(s) > 5)
			push_stack(s, d, dst);
		if (!sub_sorted(s))
			sort_five(s, d, src, dst);
		sort_general(s, d, src, dst);
	}
}
