/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 23:06:50 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/12 13:28:09 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(char **argv, t_stack	**a)
{
	int		loc;
	int		value;
	t_stack *newnode;

	//check if the parameter is valid.
	loc = 1;
	while(argv[loc])
	{
		value = ft_atoi(argv[loc]);
		//verify if atoi can handle overflow, if not, fix it.
		newnode = ft_stacknew(value);
		if (!newnode)
		{
			free(a);
		//	ft_lstclear(a, free);
			return ;
		}
		ft_stackadd_back(a, newnode);
		loc++;
	}
}
