/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:08:39 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/10 21:27:54 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon yığını sıralamak için hangi döndürme kombinasyonunun
/// kullanılacağına karar verir. Dönüş işlemlerinden sonra itme işlemi kalır.
/// Fonksiyon B'den A'ya itme işlemi esnasında kullanılır
/// @param stack_a
/// @param stack_b
/// @return Döndürme işleminin kaç adımda tamamlanacağını belirten sayı.
int	ft_rotate_type_ba(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	t_stack	*tmp;

	tmp = stack_b;
	min = ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
	while (tmp)
	{
		if (ft_calc_rarb(stack_a, stack_b, tmp->nbr, 'b') < min)
			min = ft_calc_rarb(stack_a, stack_b, tmp->nbr, 'b');
		if (ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'b') < min)
			min = ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
		if (ft_calc_rarrb(stack_a, stack_b, tmp->nbr, 'b') < min)
			min = ft_calc_rarrb(stack_a, stack_b, tmp->nbr, 'b');
		if (ft_calc_rrarb(stack_a, stack_b, tmp->nbr, 'b') < min)
			min = ft_calc_rrarb(stack_a, stack_b, tmp->nbr, 'b');
		tmp = tmp->next;
	}
	return (min);
}

/// @brief Bu fonksiyon yığını sıralamak için hangi döndürme kombinasyonunun
/// kullanılacağına karar verir. Dönüş işlemlerinden sonra itme işlemi kalır.
/// Fonksiyon A'den B'ya itme işlemi esnasında kullanılır
/// @param stack_a
/// @param stack_b
/// @return Döndürme işleminin kaç adımda tamamlanacağını belirten sayı.
int	ft_rotate_type_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	t_stack	*tmp;

	tmp = stack_a;
	min = ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
	while (tmp)
	{
		if (ft_calc_rarb(stack_a, stack_b, tmp->nbr, 'a') < min)
			min = ft_calc_rarb(stack_a, stack_b, tmp->nbr, 'a');
		if (ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'a') < min)
			min = ft_calc_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
		if (ft_calc_rarrb(stack_a, stack_b, tmp->nbr, 'a') < min)
			min = ft_calc_rarrb(stack_a, stack_b, tmp->nbr, 'a');
		if (ft_calc_rrarb(stack_a, stack_b, tmp->nbr, 'a') < min)
			min = ft_calc_rrarb(stack_a, stack_b, tmp->nbr, 'a');
		tmp = tmp->next;
	}
	return (min);
}
