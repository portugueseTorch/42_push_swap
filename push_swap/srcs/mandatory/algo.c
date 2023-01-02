/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:58:11 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/01/02 14:28:36 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 4 6
// 1 6 4
// 4 1 6
// 4 6 1
// 6 1 4
// 6 4 1
void	sort_three(t_s **s, t_s **d, char source)
{
	while (1)
	{
		if (is_sorted(s))
			break ;
		if (is_max((*s)->n, s))	// first one is the max
			rotate(s, source);
		if (is_max((*s)->next->next->n, s))	// third one is the max
			swap_stack(s, source);
		if (is_max((*s)->next->n, s))	// second one is the max
			reverse_rotate(s, source);
	}
}
