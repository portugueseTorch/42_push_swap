/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:51:57 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/05 23:06:33 by gda_cruz         ###   ########.fr       */
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
	This function takes the node passed, and returns the number of moves
	required to take that move from stack d to its rightful place in
	stack s
*/
int	moves(t_s *node, t_s **s, t_s **d)
{
	
}

t_s	*find_cheapest(t_s **s, t_s **d)
{
	t_s	*temp;
	t_s	*cheapest;

	if (!*s)
		return (NULL);
	temp = *d;
	cheapest = *d;
	while (temp)
	{
		if (moves(temp, s, d) < moves(cheapest, s, d))
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

void	execute(t_s *cheapest, t_s **s, t_s **d)
{
	
}
