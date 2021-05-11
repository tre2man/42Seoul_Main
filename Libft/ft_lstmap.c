/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:44:07 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/11 17:24:35 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list		*ans;
	t_list		*newnode;
	void		*indata;

	ans = 0;
	while (lst)
	{
		indata = f(lst->content);
		if (!(newnode = ft_lstnew(indata)))
		{
			ft_lstclear(&ans, del);
			return (0);
		}
		if (indata)
			ft_lstadd_back(&ans, newnode);
		lst = lst->next;
	}
	return (ans);
}
