/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:28:21 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/12 13:40:20 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_value(t_stack	**a)
{
	t_stack		*current;	
	int			min;

	if (!a || !(*a))
		return (0);
	min = (*a)->value;
	current = *a;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_min_position(t_stack **a)
{
	int		min;
	int		pos;
	t_stack	*current;

	if (!a || !(*a))
		return (0);
	pos = 0;
	min = find_min_value(a);
	current = *a;
	while (current)
	{
		if (current->value == min)
			return (pos);
		current = current->next;
		pos++;
	}
	return (0);
}

int	count_size(t_stack **a)
{
	int		size;
	t_stack	*tmp;

	tmp = *a;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	move_min_top(t_stack **a, int n)
{
	int		size;
	int		min_pos;
	int		rra_count;

	if (!a || !(*a))
		return ;
	size = count_size(a);
	min_pos = find_min_position(a);
	if (min_pos <= size / n)
	{
		while (min_pos--)
			ra(a);
	}
	else
	{
		rra_count = size - min_pos;
		while (rra_count--)
			rra(a);
	}
}
