/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:35:46 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:35:48 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// int main()
// {
// 	t_list *lst = {ft_lstnew("akakaka")};
// 	t_list *new;
// 	void *del;
// 	del = '\0';
// 	char str[] = "oif";		
// 	new = ft_lstnew(&str);
// 	printf("\n\n > the content of lst %s\n", (char *)lst->content);
// 	printf(" > the content of next %s\n",(char *) new->content);
// 	ft_lstadd_back(&lst, new);
// 	ft_lstiter(lst, del);
// 	printf(" > the content of lst %s\n", (char *)lst->content);
// 	printf(" > the content of next %s\n", (char *) lst->next->content);
// }
