/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:40:19 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 17:21:24 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_s **s)
{
	int	counter;
	t_s	*temp;

	if (!*s)
		return (0);
	counter = 0;
	temp = *s;
	while (temp)
	{
		temp = temp->next;
		counter ++;
	}
	return (counter);
}

t_s	*stack_last(t_s **s)
{
	t_s	*last;

	if (!*s)
		return (NULL);
	last = *s;
	if (stack_length(s) == 1)
		return (last);
	while (last->next)
		last = last->next;
	return (last);
}

t_s	*stack_snd_last(t_s **s)
{
	t_s	*snd_last;

	if (!*s)
		return (NULL);
	snd_last = *s;
	if (stack_length(s) == 1)
		return (NULL);
	while (snd_last->next->next)
		snd_last = snd_last->next;
	return (snd_last);
}

t_s	*new_stack(int n)
{
	t_s	*new;

	new = (t_s *)malloc(sizeof(t_s));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	return (new);
}
