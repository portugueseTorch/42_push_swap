/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:15:31 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 16:12:35 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(char *rule, t_s **a, t_s **b)
{
	ft_printf("Invalid rule: %s", rule);
	free(rule);
	release_stack(a);
	release_stack(b);
	exit (1);
}
