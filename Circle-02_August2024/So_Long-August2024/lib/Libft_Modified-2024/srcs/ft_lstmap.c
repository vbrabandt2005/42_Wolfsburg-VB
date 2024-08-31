/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:56:32 by vbraband          #+#    #+#             */
/*   Updated: 2024/08/26 13:56:33 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (!(new = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
		return (NULL);
	new->content_size = (f(lst))->content_size;
	start = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
			return (NULL);
		else
		{
			new = new->next;
			new->content_size = (f(lst))->content_size;
			lst = lst->next;
		}
	}
	return (start);
}
