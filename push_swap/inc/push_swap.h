/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:13:19 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 01:15:01 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <wait.h>
# include <fcntl.h>
# include <error.h>
# include "libft.h"

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}	t_s;

/************** main.c *************/

/************* input.c *************/
int		valid_input(int argc, char **argv);
int		validate(char **arr, int flag);
t_s		*create_stack(char **argv, int flag);

/************* utils.c *************/
void	release_split(char **stash);

/********** stack_utils.c **********/
int		stack_length(t_s **s);
t_s		*new_stack(int n);
t_s		*stack_last(t_s **s);
void	add_block(t_s **s, t_s *new);


#endif