/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:35:22 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:35:24 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (new && lst)
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

// int main()
// {
// 	t_list *lst = {ft_lstnew("akakaka")};
// 	t_list *new;
// 	char str[] = "oif";
// 	new = ft_lstnew(&str);
// 	printf("\n\n > lst %p\n", (char *)lst);
// 	printf(" > lst %p\n", lst->next);
// 	printf(" > lst %p\n", new);
// 	ft_lstadd_back(&lst, new);
// 	printf("\n\n > lst %s\n", (char *)lst->content);
// 	printf("\n\n > lst %s\n", (char *)lst->next->content);
// }