/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:41:04 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/11 17:41:06 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BONUS_H
# define _BONUS_H
# include <stdlib.h>

/*
** Bonus Part
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void*));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void*),
											void (*del)(void*));
#endif
