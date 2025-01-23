/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:07:58 by maiferna          #+#    #+#             */
/*   Updated: 2024/12/03 16:08:00 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*prev_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	prev_node = *stack;
	while (prev_node->next != last_node)
		prev_node = prev_node->next;
	prev_node->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}
