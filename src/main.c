/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:37:09 by maiferna          #+#    #+#             */
/*   Updated: 2024/11/07 11:37:11 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* static void print_stack(t_stack *stack)
{
    t_stack *current = stack;
    //printf("Contenido de la pila:\n");
    while (current)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
} */

// Separa y organiza los argumentos
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = process_args(argc, argv);
	if (!check_duplicates(stack_a) && !check_if_sorted(stack_a))
		sort(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}
