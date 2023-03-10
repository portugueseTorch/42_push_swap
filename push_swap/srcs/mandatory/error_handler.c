/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:15:31 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/01/11 14:53:49 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_handler(char *rule, t_s **a, t_s **b)
{
	ft_printf("Invalid rule: %s", rule);
	free(rule);
	release_stack(a);
	release_stack(b);
	exit (EXIT_FAILURE);
}

void	error_handle(char *err, t_cost *c, t_s **a, t_s **b)
{
	ft_printf("%s\n", err);
	if (c)
		free(c);
	release_stack(a);
	release_stack(b);
	exit (EXIT_FAILURE);
}
