/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:44:07 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/23 16:51:14 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list		*ans;
	t_list		*newdata;

	ans = 0;
	while (lst)
	{
		newdata = ft_lstnew(f(lst->content));
		if (!newdata)
		{
			ft_lstclear(&ans, del);
			return (0);
		}
		ft_lstadd_back(&ans, newdata);
		lst = lst->next;
	}
	return (ans);
}
