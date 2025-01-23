/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:27:14 by maiferna          #+#    #+#             */
/*   Updated: 2024/11/08 12:27:17 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

// UTILS
int		ft_atol(const char *str);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
int		ft_lstsize(t_stack *lst);
int		find_min_value(t_stack *stack);
int		find_index(t_stack *stack_a, int value);
t_stack	*min_node(t_stack *stack);

// FREE AND ERROR
void	free_stack(t_stack *stack);
void	print_error(void);

// CHECK ARGS AND ADD TO STACK
int		check_args(char **argv);
int		check_duplicates(t_stack *a);
int		check_if_sorted(t_stack *a);
void	add_to_stack(t_stack **stack, int value);
t_stack	*process_args(int argc, char **argv);
t_stack	*process_two_args(char *argv);

// OPERATIONS
	// SWAP
void	ft_swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
	// PUSH
void	ft_push(t_stack **stack_from, t_stack **stack_to);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
	// ROTATE
void	ft_rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
	// REVERSE ROTATE
void	ft_reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

// SORT
	//SORT TWO
void	sort_two(t_stack **stack_a);
	// SORT THREE
void	sort_three(t_stack **stack_a);
	// SORT FOUR
void	sort_four(t_stack **stack_a, t_stack **stack_b);
	// SORT FIVE
void	sort_five(t_stack **stack_a, t_stack **stack_b);
	// SORT MORE THAN FIVE
void	sort_numbers(t_stack **stack_a, t_stack **stack_b);
void	set_index(t_stack *stack);
void	find_cheapest(t_stack *stack_b);
t_stack	*get_cheapest(t_stack *stack);
void	push_cost(t_stack *stack_a, t_stack *stack_b);
void	find_target_b(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	ready_to_push(t_stack **stack, t_stack *node, char identifier);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);

#endif
