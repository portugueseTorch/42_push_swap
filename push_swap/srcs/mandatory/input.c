/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:23:46 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 01:36:12 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!argv[1][0])
			return (0);
		return (validate(ft_split(argv[1], ' '), 0));	// In this case, ints were passed as ./push_swap "4 23 68 0 -1"
	}
	else
		return (validate(argv, 1));	// In this case, ints were passed as ./push_swap 4 23 68 0 -1
}

/*	Three tests need to be done: are they in the integer limit, are all args digits, and
	are there any duplicates? Also, allow for + and - at start of args   */
int	validate(char **arr, int flag)
{
	int		i;
	int		j;
	int		k;

	i = flag - 1;
	while (arr[++i])
	{
		if (!arr[i][0])
			return (0);
		j = flag;
		k = 0;
		if (arr[i][k] == '-' || arr[i][k] == '+')	// Ignore + and - at the start of numbers
			k++;
		if (ft_atoi(arr[i]) > INT_MAX || ft_atoi(arr[i]) < INT_MIN)	// Check for limits
			return (0);
		while (arr[i][k])	// Check for non integers
			if (!ft_isdigit(arr[i][k++]))
				return (0);
		while (j < i)
			if (ft_atoi(arr[j++]) == ft_atoi(arr[i]))	// Check for duplicates
				return (0);
	}
	if (!flag)
		release_split(arr);
	return (1);
}

t_s	*create_stack(char **argv, int flag)
{
	t_s		*stack;
	char	**arr;
	int		i;

	if (!flag)
		arr = ft_split(argv[1], ' ');
	else
		arr = argv;
	i = flag;
	stack = new_stack(ft_atoi(arr[i]));
	while (arr[++i])
		add_block(&stack, new_stack(ft_atoi(arr[i])));
	if (!flag)
		release_split(arr);
	return (stack);
}