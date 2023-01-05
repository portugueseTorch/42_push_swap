/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:53:01 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/01/05 22:59:21 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_s **s)
{
	int	max;
	t_s	*temp;

	temp = *s;
	max = temp->n;
	while (temp)
	{
		if (temp->n > max)
			max = temp->n;
		temp = temp->next;
	}
	return (max);
}

int	get_min(t_s **s)
{
	int	min;
	t_s	*temp;

	temp = *s;
	min = temp->n;
	while (temp)
	{
		if (temp->n < min)
			min = temp->n;
		temp = temp->next;
	}
	return (min);
}
