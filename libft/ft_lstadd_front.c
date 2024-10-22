/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:35:29 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:35:31 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

// int main()
// {
// 	t_list *lst[1] = {ft_lstnew("akakaka")};
// 	t_list *new;
// 	new = ft_lstnew("sdds");
// 	ft_lstadd_front(lst, new);
// 	printf("\n> lst %s\n", (char *)new->content);
// 	printf("\n> lst %p\n", new->next);
// 	printf("\n> lst %s\n", (char *)new->next->content);
// 	printf("\n> lst %p\n", *lst);
// }
