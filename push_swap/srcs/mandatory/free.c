/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:40:28 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 10:43:25 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	release_split(char **stash)
{
	int	i;

	i = 0;
	while (stash[i])
		free(stash[i++]);
	free(stash);
}

void	release_stack(t_s **s)
{
	t_s	*temp;

	temp = *s;
	if (!temp)
		return ;
	while (*s)
	{
		temp = *s;
		*s = temp->next;
		free(temp);
	}
	s = NULL;
}
