/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:08:45 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/10 21:41:20 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon yığında yalnızca üç eleman varsa yığını sıralar.
/// @param stack_a
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_stack_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ft_stack_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a, 0);
		if (!ft_is_sorted(*stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_stack_max(*stack_a)) == 1)
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a, 0);
	}
}

/// @brief Bu fonksiyon stack_a'da üç eleman kalana kadar elemanları sıralar
/// ve iter.
/// @param stack_a
/// @param stack_b
void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*tmp;

	while (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
	{
		tmp = *stack_a;
		min = ft_rotate_type_ab(*stack_a, *stack_b);
		while (min >= 0)
		{
			if (min == ft_calc_rarb(*stack_a, *stack_b, tmp->nbr, 'a'))
				min = ft_make_rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (min == ft_calc_rrarrb(*stack_a, *stack_b, tmp->nbr, 'a'))
				min = ft_make_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (min == ft_calc_rarrb(*stack_a, *stack_b, tmp->nbr, 'a'))
				min = ft_make_rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (min == ft_calc_rrarb(*stack_a, *stack_b, tmp->nbr, 'a'))
				min = ft_make_rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

/// @brief Bu fonksiyon yalnızca üç eleman kalana kadar tüm elemanları
/// stack_a'dan stack_b ye iter ve sıralar. Üç eleman kaldığında sıralama
/// işlemi için ft_sort_three
/// fonskiyonu kalan üç elemanı sıralar.
/// @param stack_a
/// @return stack_b
t_stack	**ft_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, stack_b, 0);
	if (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_pb(stack_a, stack_b, 0);
	if (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_sort_b_till_3(stack_a, stack_b);
	if (!ft_is_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

/// @brief Bu fonksiyon stack_a'yı sıralar
/// @param stack_a
/// @param stack_b
/// @return stack_a
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		min = ft_rotate_type_ba(*stack_a, *stack_b);
		while (min >= 0)
		{
			if (min == ft_calc_rarb(*stack_a, *stack_b, tmp->nbr, 'b'))
				min = ft_make_rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (min == ft_calc_rarrb(*stack_a, *stack_b, tmp->nbr, 'b'))
				min = ft_make_rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (min == ft_calc_rrarrb(*stack_a, *stack_b, tmp->nbr, 'b'))
				min = ft_make_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (min == ft_calc_rrarb(*stack_a, *stack_b, tmp->nbr, 'b'))
				min = ft_make_rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

/// @brief Bu fonksiyon stack içinde 2 eleman varsa stack'ı sa (swap)
/// yaparak sıralar. 2'den fazla eleman varsa tüm elemanlar stack_b'ye
/// gönderip sıralar ve stack_a ya geri ittikten sonra son
/// sıralamayı yapar. Çünkü stack_a sıralansa bile sıralamanın doğru
/// olması için minumum sayı stack_a'nın en üstünde yer almalıdır.
/// @param stack_a
/// @param stack_b
void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (ft_stack_size(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a, stack_b);
		stack_a = ft_sort_a(stack_a, stack_b);
		i = ft_find_index(*stack_a, ft_stack_min(*stack_a));
		if (i < ft_stack_size(*stack_a) / 2)
			while ((*stack_a)->nbr != ft_stack_min(*stack_a))
				ft_ra(stack_a, 0);
		else
			while ((*stack_a)->nbr != ft_stack_min(*stack_a))
				ft_rra(stack_a, 0);
	}
}
