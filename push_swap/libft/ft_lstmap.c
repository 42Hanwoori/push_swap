/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:08:51 by whan              #+#    #+#             */
/*   Updated: 2020/11/02 16:10:17 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*new_lst;
	int		new_content;

	new_lst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		ft_lstadd_back(&new_lst, ft_lstnew(new_content));
		if (!new_lst)
		{
			ft_lstclear(&new_lst);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new_lst);
}
