/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:09:01 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/09 23:55:58 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon verilen yığının son elemanını döndürür.
/// @param stack
/// @return
t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/// @brief Bu fonksiyon verilen yığının eleman sayısını döndürür.
/// @param stack
/// @return Yığının eleman sayısı
int	ft_stack_size(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/// @brief Bu fonksiyon verilen yığının en küçük elemanını döndürür
/// @param stack_a
/// @return Yığının en küçük elemanı
int	ft_stack_min(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

/// @brief Bu fonksiyon verilen yığının en büyük elemanını döndürür
/// @param stack
/// @return Yığının en büyük elemanı
int	ft_stack_max(t_stack *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}
