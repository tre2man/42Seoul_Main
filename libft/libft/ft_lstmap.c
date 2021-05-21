/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:44:07 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/21 15:17:25 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list		*ans;
	void		*indata;

	ans = 0;
	while (lst)
	{
		indata = f(lst->content);
		if (!indata)
		{
			ft_lstclear(&ans, del);
			return (0);
		}
		ft_lstadd_back(&ans, ft_lstnew(indata));
		lst = lst->next;
	}
	return (ans);
}
