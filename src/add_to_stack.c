/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:01:07 by maiferna          #+#    #+#             */
/*   Updated: 2024/11/25 13:01:09 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Función para crear el stack y añadir los números */

#include "../includes/push_swap.h"

void	add_to_stack(t_stack **stack, int num)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		print_error();
	new_node->value = num;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}
