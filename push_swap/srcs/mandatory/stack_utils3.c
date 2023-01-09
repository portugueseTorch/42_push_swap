/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:23:41 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/09 19:31:06 by gda_cruz         ###   ########.fr       */
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

// 4 5 6 0 2
// 0 1 2 3 4
int	index_dest(int num, t_s **a)
{
	int	i;
	t_s *temp;

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
			break;
		i++;
		temp = temp->next;
	}
	return (i + 1);
}
