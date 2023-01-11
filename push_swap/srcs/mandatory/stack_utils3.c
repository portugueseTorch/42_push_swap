/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:23:41 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/11 14:00:51 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_min(t_s **s)
{
	int	min;
	int	index;
	int	i;
	t_s	*temp;

	if (!s || !*s)
		return (-1);
	temp = *s;
	min = temp->n;
	index = 0;
	i = 0;
	while (temp)
	{
		if (temp->n < min)
		{
			min = temp->n;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

int	sorted_stacks(t_s **a, t_s **b)
{
	t_s	*temp;

	temp = *a;
	if (stack_length(a) == 1)
		return (1);
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

int	index_source(int num, t_s **b)
{
	int	i;
	t_s	*temp;

	if (!*b)
		return (-1);
	temp = *b;
	i = 0;
	while (temp)
	{
		if (temp->n == num)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}

int	index_dest(int num, t_s **a)
{
	int	i;
	t_s	*temp;

	if (!*a)
		return (-1);
	temp = *a;
	i = 0;
	if (num > get_max(a) || num < get_min(a))
		return (index_of_min(a));
	if (num < temp->n && num > stack_last(a)->n)
		return (0);
	while (temp)
	{
		if (!temp->next || (num > temp->n && num < temp->next->n))
			break ;
		i++;
		temp = temp->next;
	}
	return (i + 1);
}

void	execute_normal_aux(t_cost *c, t_s **a, t_s **b)
{
	if (c->moves_a <= c->length_a / 2 && c->moves_b > c->length_b / 2)
	{
		while (c->moves_a-- > 0)
			rotate(a, 'a');
		while (c->moves_b++ < c->length_b)
			reverse_rotate(b, 'b');
	}
	else if (c->moves_a > c->length_a / 2 && c->moves_b <= c->length_b / 2)
	{
		while (c->moves_a++ < c->length_a)
			reverse_rotate(a, 'a');
		while (c->moves_b-- > 0)
			rotate(b, 'b');
	}
}
