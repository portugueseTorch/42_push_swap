/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:04:56 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/29 17:05:20 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_s **a, t_s **b)
{
	swap_stack(a, 0);
	swap_stack(b, 0);
	write(1, "ss\n", 3);
}

void	rotate_both(t_s **a, t_s **b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

void	reverse_rotate_both(t_s **a, t_s **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	write(1, "rrr\n", 4);
}
