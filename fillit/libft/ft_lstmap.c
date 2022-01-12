/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtine <jlehtine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:13:40 by jlehtine          #+#    #+#             */
/*   Updated: 2021/11/18 12:25:48 by jlehtine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	ptr = (*f)(lst);
	if (!ptr)
		return (NULL);
	ptr->next = ft_lstmap(lst->next, f);
	return (ptr);
}
