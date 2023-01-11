/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:51:57 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/11 15:00:37 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sub_sorted(t_s **s)
{
	t_s			*temp;
	long int	n;

	if (!*s)
		return (-1);
	if (is_sorted(s))
		return (1);
	temp = *s;
	n = temp->n;
	while (temp->next && temp->n < temp->next->n)
		temp = temp->next;
	temp = temp->next;
	while (temp->next)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	if (n < temp->n)
		return (0);
	return (1);
}

void	moves_forced(t_cost *c, t_s **a, t_s **b)
{
	while (c->moves_a > 0 || c->moves_b > 0)
	{
		c->force_up++;
		c->moves_a--;
		c->moves_b--;
	}
	c->moves_a = index_dest(c->n, a);
	c->moves_b = index_source(c->n, b);
	while ((c->moves_a || c->moves_b)
		&& (c->moves_a < c->length_a || c->moves_b < c->length_b))
	{
		c->force_down++;
		c->moves_a++;
		c->moves_b++;
	}
	if (c->force_up <= c->force_down)
		c->cost_forced = c->force_up;
	else
		c->cost_forced = c->force_down;
}

void	moves_normal(t_cost *c, t_s **a, t_s **b)
{
	if (c->moves_a <= c->length_a / 2)
		while (c->moves_a-- > 0)
			c->cost_normal++;
	else
		while (c->moves_a && c->moves_a++ < c->length_a)
			c->cost_normal++;
	if (c->moves_b <= c->length_b / 2)
		while (c->moves_b-- > 0)
			c->cost_normal++;
	else
		while (c->moves_b && c->moves_b++ < c->length_b)
			c->cost_normal++;
	c->moves_a = index_dest(c->n, a);
	c->moves_b = index_source(c->n, b);
	c->force = 1;
	moves_forced(c, a, b);
}

int	moves(t_s *node, t_cost *c, t_s **a, t_s **b)
{
	init_cost(node, c, a, b);
	if (c->moves_a == -1 || c->moves_b == -1)
		error_handle("Error with stacks", c, a, b);
	if (c->moves_a <= c->length_a / 2 && c->moves_b <= c->length_b / 2)
		while ((c->moves_a > 0 || c->moves_b > 0)
			&& c->moves_a-- < c->length_a && c->moves_b-- < c->length_b)
			c->cost_normal++;
	else if (c->moves_a > c->length_a / 2 && c->moves_b > c->length_b / 2)
		while ((c->moves_a < c->length_a || c->moves_b < c->length_b)
			&& c->moves_a++ && c->moves_b++)
			c->cost_normal++;
	else
		moves_normal(c, a, b);
	c->moves_a = index_dest(c->n, a);
	c->moves_b = index_source(c->n, b);
	if (c->force && c->cost_forced < c->cost_normal)
		return (c->cost_forced);
	return (c->cost_normal);
}

t_cost	*find_cheapest(t_s **a, t_s **b)
{
	t_cost	*c;
	int		cheapest_moves;

	c = (t_cost *)malloc(sizeof(t_cost));
	if (!c)
		return (NULL);
	c->temp = (*b)->next;
	c->cheapest = *b;
	cheapest_moves = moves(c->cheapest, c, a, b);
	while (c->temp)
	{
		if (moves(c->temp, c, a, b) < cheapest_moves)
		{
			c->cheapest = c->temp;
			cheapest_moves = moves(c->cheapest, c, a, b);
		}
		c->temp = c->temp->next;
	}
	moves(c->cheapest, c, a, b);
	c->moves_a = index_dest(c->n, a);
	c->moves_b = index_source(c->n, b);
	return (c);
}
