/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:13:19 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 12:38:48 by gda-cruz         ###   ########.fr       */
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

/************** free.c *************/
void	release_split(char **stash);
void	release_stack(t_s **s);

/********** stack_utils.c **********/
int		stack_length(t_s **s);
t_s		*new_stack(int n);
t_s		*stack_last(t_s **s);
t_s		*stack_snd_last(t_s **s);

/********** stack_utils2.c *********/
void	add_block_end(t_s **s, t_s *new);
void	add_block_start(t_s **s, t_s *new);
void	remove_block(t_s **s);

/*********** operations.c **********/
void	swap_stack(t_s **s);
void	push_stack(t_s **src, t_s **dst);
void	rotate(t_s **s);
void	reverse_rotate(t_s **s);

#endif