/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:13:19 by gda-cruz          #+#    #+#             */
/*   Updated: 2023/01/09 21:11:21 by gda_cruz         ###   ########.fr       */
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
	long int	n;				// number being evaluated (content of s->n)
	int			moves_a;		// moves to get the evaluated node to the right place in stack a
	int			moves_b;		// moves to get the evaluated node to the top of stack b
	int			length_a;		// length of stack a
	int			length_b;		// length of stack b
	int			cost_normal;	// cost of executing implied moves_a and moves_b in the natural order
	int			cost_forced;	// cost of forcing execution of moves implied using rr or rrr
	int			force_up;		// flag to signal that we are using rrr
	int			force_down;		// flag to signal that we are using rr
	t_s			*cheapest;		// cheapest node to work with next
	t_s			*temp;			// temporary for iteration
}	t_cost;


/************** main.c *************/
void	display_stacks(t_s **a, t_s **b);

/************* engine.c ************/
void	sort_three(t_s **s, char src);
void	sort_five(t_s **s, t_s **d, char src, char dst);
void	sort_stack(t_s **s, t_s **d, char src, char dst);
void	sort_general(t_s **a, t_s **b, char src, char dst);
void	execute(t_cost *c, t_s **a, t_s **b);
void	execute_force(t_cost *c, t_s **a, t_s **b);

/********** engine_utils.c *********/
void	execute(t_cost *c, t_s **a, t_s **b);
int		sub_sorted(t_s **s);
int		moves(t_s *node, t_cost *c, t_s **a, t_s **b);
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

/********** stack_utils4.c *********/
int		get_max(t_s **s);
int		get_min(t_s **s);

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