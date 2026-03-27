/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:38:16 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/27 11:35:15 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*arr_index(t_stack **a)
{
	t_stack *tmp;
	int		*arr;
	int		loc;

	arr = malloc(sizeof(int) * (count_size(*a)));
	if (!arr)
		return (0);
	tmp = *a;
	loc = 0;
	while (tmp)
	{
		arr[loc] = tmp->index;
		loc ++;
		tmp = tmp->next;
	}
	return (arr);
}

static int check_if_sorted(int loc, int lenth, int loc2, int *arr)
{
	while (lenth > 0 && loc != loc2)
	{
		if (arr[loc] != (arr[loc + 1] - 1))
			return (1);
		loc++;
		lenth--;
	}
	return (0);
}

static int	fast_sort(t_stack **a, int *move)
{
	int	*arr;
	int	size;

	size = count_size(*a);
	arr = arr_index(a);
	if (arr[size - 1] == ((arr[0]) - 1))
	{
		if (check_if_sorted(1, size, size - 2, arr) == 0)
			rra(a, move);
		else if (size == 2)
			sa(a, move);
		free(arr);
		return (0);
	}
	if (((arr[0]) == (arr[1] + 1))
		&& ((arr[0] + 1) == (arr[2])))
	{
		if (check_if_sorted(2, size, size - 1, arr) == 0)
		{
			sa(a, move);
			free(arr);
			return (0);
		}
		if (((arr[size - 1] + 1) == arr[1]) && (check_if_sorted(2, size, size - 2, arr) == 0))
		{
			sa(a, move);
			rra(a, move);
			free(arr);
			return (0);
		}
	}
	free(arr);
	return (1);
}

void	simple_strategy(t_stack **a, t_stack **b, int *move)
{
	int	size;

	if (!a || !(*a))
		return ;
	if (fast_sort(a, move) == 0)
		return ;
	size = count_size(*a);
	while (*a)
	{
		move_min_top(a, move);
		pb(a, b, move);
	}
	while (*b)
		pa(a, b, move);
}
