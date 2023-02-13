/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:09:05 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/09 23:55:13 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon yığına ra ve rb işlemlerini aynı anda uygular
/// @param stack_a
/// @param stack_b
/// @param j Değeri 0 verilirse ekrana rr\\n bastırır.
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int j)
{
	ft_ra(stack_a, 1);
	ft_rb(stack_b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
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

/// @brief Bu fonksiyon stack_a'daki ilk elemanı stack_b'ye koyar.
/// stack_a boşsa hiçbir şey yapmaz.
/// @param stack_a
/// @param stack_b
/// @param j Değeri 0 verilirse ekrana pb\\n bastırır.
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}

/// @brief Stack_b'yi ters döndürür. Böylelikle stack_b'nin tüm
/// elemanları 1 aşağı kaydırılır. Son eleman ise 1. eleman olur.
/// @param stack_b
/// @param j Değeri 0 verilirse ekrana rrb\\n bastırır.
void	ft_rrb(t_stack **stack_b, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	i = 0;
	tmp = *stack_b;
	while ((*stack_b)->next)
	{
		i++;
		*stack_b = (*stack_b)->next;
	}
	(*stack_b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}
