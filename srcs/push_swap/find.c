/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:08:54 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/13 18:38:58 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon yığındaki bir sayının index'ini bulur.
/// @param stack_a
/// @param nbr
/// @return index
int	ft_find_index(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack->nbr != nbr)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

/// @brief Bu fonksiyon sayının stack_b'deki doğru yerini bulur.
/// Başka bir deyişle, nbr_push'ın stack_b'ye gönderildikten sonra
/// hangi indeks numarasını alacağını kontrol eder.
/// @param stack_b
/// @param nbr_push
/// @return nbr_push'un stack_b'deki yeri
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_stack_last(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_stack_max(stack_b)
		|| nbr_push < ft_stack_min(stack_b))
		i = ft_find_index(stack_b, ft_stack_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

/// @brief Bu fonksiyon sayının stack_a'daki doğru yerini bulur.
/// Başka bir deyişle, nbr_push'ın stack_a'ya gönderildikten sonra
/// hangi indeks numarasını alacağını kontrol eder.
/// @param stack_a
/// @param nbr_push
/// @return nbr_push'un stack_a'deki yeri
int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_stack_last(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_stack_max(stack_a)
		|| nbr_push < ft_stack_min(stack_a))
		i = ft_find_index(stack_a, ft_stack_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
