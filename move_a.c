/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:31:00 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/12 15:11:31 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = (*a)->value;
	(*a)->value = ((*a)->next)->value;
	((*a)->next)->value = tmp;
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*tmp;
	int		first;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = *a;
	first = tmp->value;
	while (tmp->next)
	{
		tmp->value = (tmp->next)->value;
		tmp = tmp->next;
	}
	tmp->value = first;
	write(1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*tmp;
	int		last;
	int		stock;
	int		result;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = *a;
	last = (ft_stacklast(*a))->value;
	result = tmp->value;
	while (tmp->next)
	{
		stock = (tmp->next)->value;
		(tmp->next)->value = result;
		tmp = tmp->next;
		result = stock;
	}
	(*a)->value = result;
	write(1, "rra\n", 4);
}
