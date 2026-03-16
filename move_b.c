/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:55:58 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/15 20:58:36 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	int	tmp;
	int	tmp2;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = (*b)->value;
	tmp2 = (*b)->index;
	(*b)->value = ((*b)->next)->value;
	(*b)->index = ((*b)->next)->index;
	((*b)->next)->value = tmp;
	((*b)->next)->index = tmp2;
	write(1, "sb\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	int		first;
	int		first2;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = *b;
	first = tmp->value;
	first2 = tmp->index;
	while (tmp->next)
	{
		tmp->value = (tmp->next)->value;
		tmp->index = (tmp->next)->index;
		tmp = tmp->next;
	}
	tmp->value = first;
	tmp->index = first2;
	write(1, "rb\n", 3);
}

static void	rrb_value(t_stack **b)
{
	t_stack	*tmp;
	int		last;
	int		stock;
	int		result;

	tmp = *b;
	last = (ft_stacklast(*b))->value;
	result = tmp->value;
	while (tmp->next)
	{
		stock = (tmp->next)->value;
		(tmp->next)->value = result;
		tmp = tmp->next;
		result = stock;
	}
	(*b)->value = result;
}

static void    rrb_index(t_stack **b)
{
    t_stack *tmp;
    int     last;
    int     stock;
    int     result;

    tmp = *b;
    last = (ft_stacklast(*b))->index;
    result = tmp->index;
    while (tmp->next)
    {
        stock = (tmp->next)->index;
        (tmp->next)->index = result;
        tmp = tmp->next;
        result = stock;
    }
    (*b)->index = result;
}

void rrb(t_stack **b)
{
	if (!b || !(*b) || !((*b)->next))
		return ;

	rrb_value(b);
	rrb_index(b);
	write(1, "rrb\n", 4);
}
