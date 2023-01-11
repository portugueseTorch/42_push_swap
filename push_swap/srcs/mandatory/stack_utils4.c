/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:53:01 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/10 16:34:09 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_s **s)
{
	int	max;
	t_s	*temp;

	temp = *s;
	max = temp->n;
	while (temp)
	{
		if (temp->n > max)
			max = temp->n;
		temp = temp->next;
	}
	return (max);
}

int	get_min(t_s **s)
{
	int	min;
	t_s	*temp;

	temp = *s;
	min = temp->n;
	while (temp)
	{
		if (temp->n < min)
			min = temp->n;
		temp = temp->next;
	}
	return (min);
}

void	init_cost(t_s *node, t_cost *c, t_s **a, t_s **b)
{
	if (!node)
		return ;
	c->n = node->n;
	c->length_a = stack_length(a);
	c->length_b = stack_length(b);
	c->moves_a = index_dest(c->n, a);
	c->moves_b = index_source(c->n, b);
	c->cost_normal = 0;
	c->cost_forced = 0;
	c->force_up = 0;
	c->force_down = 0;
	c->force = 0;
}

void	execute_aux(t_cost *c, t_s **a, t_s **b)
{
	while (c->moves_a < c->length_a && c->moves_b < c->length_b)
	{
		reverse_rotate_both(a, b);
		c->moves_a++;
		c->moves_b++;
	}
	while (c->moves_a++ < c->length_a)
		reverse_rotate(a, 'a');
	while (c->moves_b++ < c->length_b)
		reverse_rotate(b, 'b');
}

void	execute_force_aux(t_cost *c, t_s **a, t_s **b)
{
	while (c->moves_a < c->length_a && c->moves_b < c->length_b)
	{
		reverse_rotate_both(a, b);
		c->moves_a++;
		c->moves_b++;
	}
	while (c->moves_a++ < c->length_a)
		reverse_rotate(a, 'a');
	while (c->moves_b++ < c->length_b)
		reverse_rotate(b, 'b');
}
