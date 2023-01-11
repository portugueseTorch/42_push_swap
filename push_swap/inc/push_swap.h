/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:13:19 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/01/11 14:58:42 by gda-cruz         ###   ########.fr       */
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
	long int		n;
	struct s_stack	*next;
}	t_s;

typedef struct s_cost
{
	long int	n;
	int			length_a;
	int			length_b;
	int			moves_a;
	int			moves_b;
	int			cost_normal;
	int			cost_forced;
	int			force_up;
	int			force_down;
	int			force;
	t_s			*cheapest;
	t_s			*temp;
}	t_cost;

/************** main.c *************/
// void	display_stacks(t_s **a, t_s **b);

/************* engine.c ************/
void	sort_three(t_s **s, char src);
void	sort_five(t_s **s, t_s **d, char src, char dst);
void	sort_stack(t_s **s, t_s **d, char src, char dst);
void	sort_general(t_s **a, t_s **b, char src, char dst);
void	execute(t_cost *c, t_s **a, t_s **b);

/********** engine_utils.c *********/
void	execute(t_cost *c, t_s **a, t_s **b);
int		sub_sorted(t_s **s);
int		moves(t_s *node, t_cost *c, t_s **a, t_s **b);
void	moves_normal(t_cost *c, t_s **a, t_s **b);
t_cost	*find_cheapest(t_s **a, t_s **b);

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
void	execute_force(t_cost *c, t_s **a, t_s **b);

/********** stack_utils2.c *********/
void	add_block_end(t_s **s, t_s *new);
void	add_block_start(t_s **s, t_s *new);
void	remove_block(t_s **s);
int		is_sorted(t_s **s);
int		is_max(long int n, t_s **s);

/********** stack_utils3.c *********/
int		index_of_min(t_s **s);
int		sorted_stacks(t_s **a, t_s **b);
int		index_source(int num, t_s **b);
int		index_dest(int num, t_s **a);
void	execute_normal_aux(t_cost *c, t_s **a, t_s **b);

/********** stack_utils4.c *********/
int		get_max(t_s **s);
int		get_min(t_s **s);
void	init_cost(t_s *node, t_cost *c, t_s **a, t_s **b);
void	execute_aux(t_cost *c, t_s **a, t_s **b);
void	execute_force_aux(t_cost *c, t_s **a, t_s **b);

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
void	error_handle(char *err, t_cost *c, t_s **a, t_s **b);

#endif