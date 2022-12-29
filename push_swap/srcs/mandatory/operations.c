/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:01:19 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/29 17:40:07 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_s **s, char stack)
{
	t_s	*temp;

	if (stack_length(s) < 2 || !*s)
		return ;
	temp = *s;
	*s = temp->next;
	temp->next = temp->next->next;
	(*s)->next = temp;
	if (stack)
		ft_printf("s%c\n", stack);
}

void	push_stack(t_s **src, t_s **dst, char stack)
{
	t_s	*temp;

	if (!src)
		return ;
	temp = *src;
	if (stack_length(src) == 0)
		return ;
	remove_block(src);
	add_block_start(dst, temp);
	if (stack)
		ft_printf("p%c\n", stack);	
}

void	rotate(t_s **s, char stack)
{
	t_s	*temp;
	t_s	*last;

	if (!*s)
		return ;
	if (stack_length(s) == 1)
		return ;
	else if (stack_length(s) == 2)
		swap_stack(s, stack);
	else
	{
		temp = *s;
		last = stack_last(s);
		*s = temp->next;
		temp->next = NULL;
		last->next = temp;
	}
	if (stack)
		ft_printf("r%c\n", stack);
}

void	reverse_rotate(t_s **s, char stack)
{
	t_s	*temp;
	t_s	*snd_last;

	if (!*s)
		return ;
	if (stack_length(s) == 1)
		return ;
	else if (stack_length(s) == 2)
		swap_stack(s, stack);
	else
	{
		temp = *s;
		snd_last = stack_snd_last(s);
		*s = snd_last->next;
		(*s)->next = temp;
		snd_last->next = NULL;
	}
	if (stack)
		ft_printf("rr%c\n", stack);
}
