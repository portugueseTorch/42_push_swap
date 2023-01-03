/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:23:41 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/03 00:52:55 by gda_cruz         ###   ########.fr       */
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
