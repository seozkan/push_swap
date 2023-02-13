/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:09:15 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/09 23:37:21 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

/// @brief Bu fonksiyon a yığının en üstündeki iki sayıyı
/// yer değiştirir. Bir öge verilmişse veya hiçbir öge verilmemişse
/// herhangi bir şey yapmaz.
/// @param stack
/// @param j Değeri 0 verilmişse ekrana sa\\n yazar.
void	ft_sa(t_stack **stack, int j)
{
	t_stack	*tmp;

	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

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

/// @brief Stack_a'yı ters döndürür. Böylelikle stack_a'nın tüm
/// elemanları 1 aşağı kaydırılır. Son eleman ise 1. eleman olur.
/// @param stack_a
/// @param j Değeri 0 verilirse ekrana rra\\n bastırır.
void	ft_rra(t_stack **stack_a, int j)
{
	t_stack	*tmp;
	int		i;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	i = 0;
	tmp = *stack_a;
	while ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	(*stack_a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
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
