/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:51:57 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/11 01:11:11 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	A sub-sorted stack will be one where inside it there is a sorted section and
	in this case the first element is also larger than the last, so that the stack
	can be sorted using only reverse or rotates.

	8 9 1 2 3 - valid
	6 7 3 4 5 - valid
	2 3 1 7 4 - invalid
	7 8 4 5 2 3 - invalid	*/
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

/*
	This function takes the cost struct, and deals only with cases where they are
	in different halves of the stacks, to evaluate if it's better to let them behave
	normally, or to force both to either rr or rrr
*/
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
/*
	This function will deal only with the scenarios when the numbers are always
	in the same halves of the stacks, so we can always use only one rule (rr)
*/
int	moves(t_s *node, t_cost *c, t_s **a, t_s **b)
{
	init_cost(node, c, a, b);
	// display_stacks(a, b);
	// printf("Number: %li\n\n", c->n);
	if (c->moves_a == -1 || c->moves_b == -1)
		return (-1);
	// printf("length_a: %i\n", c->length_a);
	// printf("length_b: %i\n", c->length_b);
	// printf("moves_a: %i\n", c->moves_a);
	// printf("moves_b: %i\n", c->moves_b);
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
	// printf("\ncost normal: %i\n\n", c->cost_normal);
	// printf("moves_a: %i\n", c->moves_a);
	// printf("moves_b: %i\n\n", c->moves_b);
	// printf("force flag: %i\n", c->force);
	// printf("force up: %i\n", c->force_up);
	// printf("force down: %i\n\n", c->force_down);
	// printf("cost normal: %i\n", c->cost_normal);
	// printf("cost forced: %i\n\n", c->cost_forced);
	// printf("======================================\n\n");
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
			// printf("New cheapest: %li\n", c->cheapest->n);
			// printf("\n======================================\n\n");
		}
		// printf("\n");
		c->temp = c->temp->next;
	}
	moves(c->cheapest, c, a, b);
	c->moves_a = index_dest(c->n, a);
	c->moves_b = index_source(c->n, b);
	// printf("cheapest: %li\n", c->cheapest->n);
	// printf("moves_a: %i\n", c->moves_a);
	// printf("moves_b: %i\n", c->moves_b);;
	// printf("cost normal: %i\n", c->cost_normal);
	// printf("cost forced: %i\n", c->cost_forced);
	// printf("force up: %i\n", c->force_up);
	// printf("force down: %i\n", c->force_down);
	// printf("======================================\n\n");
	return (c);
}
