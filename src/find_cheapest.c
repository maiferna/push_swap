/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheapest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:19:32 by maiferna          #+#    #+#             */
/*   Updated: 2024/12/17 13:19:34 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_cheapest(t_stack *stack_b)
{
	long	best_push_price;
	t_stack	*cheapest_node;

	best_push_price = LONG_MAX;
	if (stack_b == NULL)
		return ;
	while (stack_b)
	{
		if (stack_b->push_cost < best_push_price)
		{
			best_push_price = stack_b->push_cost;
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	cheapest_node->cheapest = true;
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
