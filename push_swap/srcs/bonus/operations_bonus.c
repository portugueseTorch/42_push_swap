/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:04:56 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 15:12:56 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_s **a, t_s **b)
{
	swap_stack(a);
	swap_stack(b);
}

void	rotate_both(t_s **a, t_s **b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate_both(t_s **a, t_s **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
