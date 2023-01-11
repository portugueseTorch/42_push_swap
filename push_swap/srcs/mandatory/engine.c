/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:38:56 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/11 11:35:15 by gda_cruz         ###   ########.fr       */
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
		while (stack_length(d) > 0 && stack_length(s) < 5)
			push_stack(d, s, src);
	}
}

void	execute_force(t_cost *c, t_s **a, t_s **b)
{
	if (c->cost_forced <= c->cost_normal)
	{
		if (c->force_up <= c->force_down)
		{
			while (c->moves_a > 0 && c->moves_b > 0)
			{
				rotate_both(a, b);
				c->moves_a--;
				c->moves_b--;
			}
			while (c->moves_a-- > 0)
				rotate(a, 'a');
			while (c->moves_b-- > 0)
				rotate(b, 'b');
		}
		else
			execute_force_aux(c, a, b);
	}
	else
		execute_normal_aux(c, a, b);
}

void	execute(t_cost *c, t_s **a, t_s **b)
{
	if (c->force == 0)
	{
		if (c->moves_a <= c->length_a / 2 && c->moves_b <= c->length_b / 2)
		{
			while (c->moves_a > 0 && c->moves_b > 0)
			{
				rotate_both(a, b);
				c->moves_a--;
				c->moves_b--;
			}
			while (c->moves_a-- > 0)
				rotate(a, 'a');
			while (c->moves_b-- > 0)
				rotate(b, 'b');
		}
		else if (c->moves_a > c->length_a / 2 && c->moves_b > c->length_b / 2)
			execute_aux(c, a, b);
	}
	else
		execute_force(c, a, b);
	push_stack(b, a, 'a');
}

void	sort_general(t_s **a, t_s **b, char src, char dst)
{
	t_cost *cheapest;
	(void) dst;
	while (stack_length(b))
	{
		cheapest = find_cheapest(a, b);
		if (!cheapest)
			return (NULL);
		execute(cheapest, a, b);
		free(cheapest);
	}
	while (!is_sorted(a))
	{
		if (index_of_min(a) <= (stack_length(a) / 2))
			rotate(a, src);
		else
			reverse_rotate(a, src);
	}
}

void	sort_stack(t_s **s, t_s **d, char src, char dst)
{
	if (!s || !*s || !d)
		return ;
	if (stack_length(s) == 2)
		swap_stack(s, 'a');
	else if (stack_length(s) < 6)
		sort_five(s, d, src, dst);
	else
	{
		if (stack_length(s) > 200)
		{
			while (!sub_sorted(s) && stack_length(s) > 5)
				push_stack(s, d, dst);
			if (!sub_sorted(s))
				sort_five(s, d, src, dst);
		}
		else
		{
			while (!sub_sorted(s) && stack_length(s) > 3)
				push_stack(s, d, dst);
			if (!sub_sorted(s))
				sort_three(s, src);
		}
		sort_general(s, d, src, dst);
	}
}
