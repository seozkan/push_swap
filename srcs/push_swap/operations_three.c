/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:09:10 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/15 21:05:59 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon a yığının en üstündeki iki sayıyı
/// yer değiştirir. Bir öge verilmişse veya hiçbir öge verilmemişse
/// herhangi bir şey yapmaz.
/// @param stack
/// @param j Değeri 0 verilmişse ekrana sa\\n yazar.
void	ft_sa(t_stack **stack_a, int j)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = NULL;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (j == 0)
		write(1, "sa\n", 3);
}

/// @brief Bu fonksiyon b yığının en üstündeki iki sayıyı
/// yer değiştirir. Bir öge verilmişse veya hiçbir öge verilmemişse
/// herhangi bir şey yapmaz.
/// @param stack_b
/// @param j Değeri 0 verilmişse ekrana sb\\n yazar.
void	ft_sb(t_stack **stack_b, int j)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_b;
	second = NULL;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	if (j == 0)
		write(1, "sb\n", 3);
}

/// @brief Bu fonksiyon ft_sa ve ft_sb fonksiyonlarını aynı anda
/// uygular
/// @param stack_a
/// @param stack_b
/// @param j Değeri 0 verilirse ekrana ss\\n bastırır.
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int j)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	if (j == 0)
		write(1, "ss\n", 3);
}
