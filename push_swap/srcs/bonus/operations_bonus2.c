/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:04:56 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/01/11 15:08:33 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_s **a, t_s **b)
{
	swap_stack(a, 0);
	swap_stack(b, 0);
}

void	rotate_both(t_s **a, t_s **b)
{
	rotate(a, 0);
	rotate(b, 0);
}

void	reverse_rotate_both(t_s **a, t_s **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
}
