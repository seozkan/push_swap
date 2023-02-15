/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:09:05 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/15 21:06:12 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Stack_a'yı ters döndürür. Böylelikle stack_a'nın tüm
/// elemanları 1 aşağı kaydırılır. Son eleman ise 1. eleman olur.
/// @param stack_a
/// @param j Değeri 0 verilirse ekrana rra\\n bastırır.
void	ft_rra(t_stack **stack_a, int j)
{
	t_stack	*last;
	t_stack	*second_last;

	last = *stack_a;
	second_last = NULL;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = last;
	second_last->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
}

/// @brief Stack_b'yi ters döndürür. Böylelikle stack_b'nin tüm
/// elemanları 1 aşağı kaydırılır. Son eleman ise 1. eleman olur.
/// @param stack_b
/// @param j Değeri 0 verilirse ekrana rrb\\n bastırır.
void	ft_rrb(t_stack **stack_b, int j)
{
	t_stack	*last;
	t_stack	*second_last;

	last = *stack_b;
	second_last = NULL;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = last;
	second_last->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}

/// @brief rra ve rrb fonksiyonlarını aynı anda uygular.
/// @param stack_a
/// @param stack_b
/// @param j Değeri 0 verilirse ekrana rrr\\n bastırır.
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int j)
{
	ft_rra(stack_a, 1);
	ft_rrb(stack_b, 1);
	if (j == 0)
		write(1, "rrr\n", 4);
}
