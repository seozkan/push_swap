/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:09:10 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/09 23:37:02 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

/// @brief Bu fonksiyon b yığının en üstündeki iki sayıyı
/// yer değiştirir. Bir öge verilmişse veya hiçbir öge verilmemişse
/// herhangi bir şey yapmaz.
/// @param stack_b
/// @param j Değeri 0 verilmişse ekrana sb\\n yazar.
void	ft_sb(t_stack **stack_b, int j)
{
	t_stack	*tmp;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}
