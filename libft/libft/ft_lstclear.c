/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:35:31 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/11 17:30:02 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	**explore;
	t_list	*temp;

	explore = lst;
	while (*explore && del)
	{
		temp = *explore;
		del((*explore)->content);
		*explore = (*explore)->next;
		free(temp);
	}
}
