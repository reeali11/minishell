/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:35:52 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:35:53 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int main()
// {
// 	t_list *lst[1] = {ft_lstnew("orign")};
// 	t_list *new;
// 	new = ft_lstnew("add_back");
// 	ft_lstadd_back(lst, new);
// 	new = ft_lstnew("add_front");
// 	ft_lstadd_front(lst, new);
// 	printf("\n\n > lst %s\n", ft_lstlast(new)->content);
// }
