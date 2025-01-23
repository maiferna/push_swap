/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:00:01 by maiferna          #+#    #+#             */
/*   Updated: 2025/01/10 11:00:04 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min_value(t_stack *stack)
{
	int		min_value;
	t_stack	*temp;

	temp = stack;
	min_value = temp->value;
	while (temp)
	{
		if (temp->value < min_value)
			min_value = temp->value;
		temp = temp->next;
	}
	return (min_value);
}

t_stack	*min_node(t_stack *stack)
{
	t_stack	*min_node;
	long	min;

	min = LONG_MAX;
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
