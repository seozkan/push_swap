/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:09:28 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/14 00:28:48 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief ra+rb durumu için gerekli döndürme miktarını hesaplar.
/// @param stack_a
/// @param stack_b
/// @param nbr tmp değişkenin içindeki nbr değerini alan parametre.
/// @return Gerekli döndürme miktarı
int	ft_calc_rarb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod)
{
	int	i;

	if (mod == 'a')
	{
		i = ft_find_place_b(stack_b, nbr);
		if (i < ft_find_index(stack_a, nbr))
			i = ft_find_index(stack_a, nbr);
	}
	else
	{
		i = ft_find_place_a(stack_a, nbr);
		if (i < ft_find_index(stack_b, nbr))
			i = ft_find_index(stack_b, nbr);
	}
	return (i);
}

/// @brief rra+rrb durumu için gerekli döndürme miktarını hesaplar.
/// @param stack_a
/// @param stack_b
/// @param nbr tmp değişkenin içindeki nbr değerini alan parametre.
/// @return Gerekli döndürme miktarı
int	ft_calc_rrarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod)
{
	int	i;

	i = 0;
	if (mod == 'a')
	{
		if (ft_find_place_b(stack_b, nbr))
			i = ft_stack_size(stack_b) - ft_find_place_b(stack_b, nbr);
		if ((i < (ft_stack_size(stack_a) - ft_find_index(stack_a, nbr)))
			&& ft_find_index(stack_a, nbr))
			i = ft_stack_size(stack_a) - ft_find_index(stack_a, nbr);
	}
	else
	{
		if (ft_find_place_a(stack_a, nbr))
			i = ft_stack_size(stack_a) - ft_find_place_a(stack_a, nbr);
		if ((i < (ft_stack_size(stack_b) - ft_find_index(stack_b, nbr)))
			&& ft_find_index(stack_b, nbr))
			i = ft_stack_size(stack_b) - ft_find_index(stack_b, nbr);
	}
	return (i);
}

/// @brief rra+rb durumu için gerekli döndürme miktarını hesaplar.
/// @param stack_a
/// @param stack_b
/// @param nbr tmp değişkenin içindeki nbr değerini alan parametre.
/// @return Gerekli döndürme miktarı
int	ft_calc_rrarb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod)
{
	int	i;

	i = 0;
	if (mod == 'a')
	{
		if (ft_find_index(stack_a, nbr))
			i = ft_stack_size(stack_a) - ft_find_index(stack_a, nbr);
		i = ft_find_place_b(stack_b, nbr) + i;
	}
	else
	{
		if (ft_find_place_a(stack_a, nbr))
			i = ft_stack_size(stack_a) - ft_find_place_a(stack_a, nbr);
		i = ft_find_index(stack_b, nbr) + i;
	}
	return (i);
}

/// @brief ra+rrb durumu için gerekli döndürme miktarını hesaplar.
/// @param stack_a
/// @param stack_b
/// @param nbr tmp değişkenin içindeki nbr değerini alan parametre.
/// @return Gerekli döndürme miktarı
int	ft_calc_rarrb(t_stack *stack_a, t_stack *stack_b, int nbr, char mod)
{
	int	i;

	i = 0;
	if (mod == 'a')
	{
		if (ft_find_place_b(stack_b, nbr))
			i = ft_stack_size(stack_b) - ft_find_place_b(stack_b, nbr);
		i = ft_find_index(stack_a, nbr) + i;
	}
	else
	{
		if (ft_find_index(stack_b, nbr))
			i = ft_stack_size(stack_b) - ft_find_index(stack_b, nbr);
		i = ft_find_place_a(stack_a, nbr) + i;
	}
	return (i);
}
