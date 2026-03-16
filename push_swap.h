/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:46:20 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/16 08:00:52 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

void	push_swap(char **argv);

typedef struct		s_stack
{

	int				index;
	int				value;
	struct s_stack	*next;
}					t_stack;

void	parsing(char **argv, t_stack **a);
t_stack *ft_stacknew(int content);
void    ft_stackadd_back(t_stack **a, t_stack *new);
t_stack *ft_stacklast(t_stack *a);
//void	ft_lstclear(t_stack **lst, void (*del)(void *));
void	sa_ab(t_stack **a);
void	pa_ab(t_stack **a, t_stack **b);
void	ra_ab(t_stack **a);
void	rra_ab(t_stack **a);
void	sb_ab(t_stack **b);
void	pb_ab(t_stack **a, t_stack **b);
void	rb_ab(t_stack **b);
void	rrb_ab(t_stack **b);
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sb(t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **b);
double  count_disorder(t_stack **a);
void	adaptive_strategy(t_stack **a, t_stack **b, double disorder);
int		ft_atoi(const char *nptr);
int		ft_sqrt(int nb);
void	medium_strategy(t_stack **a, t_stack **b);
void    simple_strategy(t_stack **a, t_stack **b);
int		main(int argc, char **argv);
int		find_min_value(t_stack **a);
int		find_min_position(t_stack **a);
int		count_size(t_stack **a);
void	move_min_top(t_stack **a, int n);

#endif
