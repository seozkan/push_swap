/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:09:15 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/15 00:24:56 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon stack_b'deki ilk elemanı stack_a'ya koyar.
/// stack_b boşsa hiçbir şey yapmaz.
/// @param stack_a
/// @param stack_b
/// @param j Değeri 0 verilirse ekrana pb\\n bastırır.
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
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

/// @brief Bu fonksiyon a yığındaki tüm elemanları 1 yukarı kaydırır. Böylelikle
/// stack_a'nin ilk elemanı son eleman olur.
/// @param stack_a
/// @param j Değeri 0 verilmişse ekrana ra\\n yazar.
void	ft_ra(t_stack **stack_a, int j)
{
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = ft_stack_last(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

/// @brief Bu fonksiyon b yığındaki tüm elemanları 1 yukarı kaydırır. Böylelikle
/// stack_b'nin ilk elemanı son eleman olur.
/// @param stack_b
/// @param j Değeri 0 verilmişse ekrana rb\\n yazar.
void	ft_rb(t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = ft_stack_last(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

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
