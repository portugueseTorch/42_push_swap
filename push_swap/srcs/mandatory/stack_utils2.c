/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:49:54 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/01/03 00:52:31 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_block_end(t_s **s, t_s *new)
{
	t_s	*end;

	if (!new)
		return ;
	if (!*s || !s)
	{
		*s = new;
		return ;
	}
	end = stack_last(s);
	end->next = new;
}

void	add_block_start(t_s **s, t_s *new)
{
	t_s	*start;

	if (!new)
		return ;
	if (!*s || !s)
	{
		*s = new;
		(*s)->next = NULL;
		return ;
	}
	start = *s;
	*s = new;
	(*s)->next = start;
}

void	remove_block(t_s **s)
{
	if (!*s)
		return ;
	if (stack_length(s) == 1)
	{
		*s = NULL;
		return ;
	}
	*s = (*s)->next;
}

int	is_sorted(t_s **s)
{
	t_s	*temp;

	temp = *s;
	if (!temp)
		return (-1);
	while (temp->next)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_max(long int n, t_s **s)
{
	t_s			*temp;

	if (!*s || !s)
		return (-1);
	temp = *s;
	while (temp)
	{
		if (temp->n > n)
			return (0);
		temp = temp->next;
	}
	return (1);
}
