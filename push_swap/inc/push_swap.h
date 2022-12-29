/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:13:19 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/29 17:31:33 by gda-cruz         ###   ########.fr       */
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
void	display_stacks(t_s **a, t_s **b);

/************** algo.c *************/
void	bubble_sort(t_s **a, t_s **b);

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
void	swap_stack(t_s **s, char stack);
void	push_stack(t_s **src, t_s **dst, char stack);
void	rotate(t_s **s, char stack);
void	reverse_rotate(t_s **s, char stack);

/************** BONUS **************/
void	redirect_rule(char *rule, t_s **a, t_s **b);
void	execute_rules(t_s **a, t_s **b);
void	swap_both(t_s **a, t_s **b);
void	rotate_both(t_s **a, t_s **b);
void	reverse_rotate_both(t_s **a, t_s **b);
void	error_handler(char *rule, t_s **a, t_s **b);

#endif