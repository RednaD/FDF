/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:19:08 by arusso            #+#    #+#             */
/*   Updated: 2017/12/09 17:20:54 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	if (!(new_lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new_lst = f(lst);
	if (lst->next)
		new_lst->next = ft_lstmap(lst->next, f);
	return (new_lst);
}
