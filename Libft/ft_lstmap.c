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
	t_list		*temp;
	t_list		*ans;
	int			lstlen;

	lstlen = ft_lstsize(lst);
	if (!(temp = malloc(sizeof(t_list) * (lstlen))))
		return (0);
	ans = temp;
	while (lst)
	{
		temp = malloc(sizeof(t_list));
		ft_lstadd_back(&temp, f(lst->content));
		lst = lst->next;
		temp = temp->next;
	}
	return (ans);
}
