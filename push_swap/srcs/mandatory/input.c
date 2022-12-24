/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:23:46 by gda-cruz          #+#    #+#             */
/*   Updated: 2022/12/24 17:19:30 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(int argc, char **argv)
{
	char	**arr;
	int		valid;

	arr = NULL;
	if (argc == 2)
	{
		if (!argv[1][0])
			return (0);
		arr = ft_split(argv[1], ' ');
		valid = validate(arr, 0);
	}
	else
		valid = validate(argv, 1);
	if (!valid && arr)
		release_split(arr);
	return (valid);
}

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
		if (arr[i][k] == '-' || arr[i][k] == '+')
			k++;
		if (ft_atoi(arr[i]) > INT_MAX || ft_atoi(arr[i]) < INT_MIN)
			return (0);
		while (arr[i][k])
			if (!ft_isdigit(arr[i][k++]))
				return (0);
		while (j < i)
			if (ft_atoi(arr[j++]) == ft_atoi(arr[i]))
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
		add_block_end(&stack, new_stack(ft_atoi(arr[i])));
	if (!flag)
		release_split(arr);
	return (stack);
}
