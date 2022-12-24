/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:01:19 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 17:21:01 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_s **s)
{
	t_s	*temp;

	if (stack_length(s) < 2 || !*s)
		return ;
	temp = *s;
	*s = temp->next;
	temp->next = temp->next->next;
	(*s)->next = temp;
}

void	push_stack(t_s **src, t_s **dst)
{
	t_s	*temp;

	if (!src)
		return ;
	temp = *src;
	remove_block(src);
	add_block_start(dst, temp);
}

void	rotate(t_s **s)
{
	t_s	*temp;
	t_s	*last;

	if (!*s)
		return ;
	if (stack_length(s) == 1)
		return ;
	else if (stack_length(s) == 2)
		swap_stack(s);
	else
	{
		temp = *s;
		last = stack_last(s);
		*s = temp->next;
		temp->next = NULL;
		last->next = temp;
	}
}

void	reverse_rotate(t_s **s)
{
	t_s	*temp;
	t_s	*snd_last;

	if (!*s)
		return ;
	if (stack_length(s) == 1)
		return ;
	else if (stack_length(s) == 2)
		swap_stack(s);
	else
	{
		temp = *s;
		snd_last = stack_snd_last(s);
		*s = snd_last->next;
		(*s)->next = temp;
		snd_last->next = NULL;
	}
}
