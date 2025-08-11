/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:41:05 by benjamsc          #+#    #+#             */
/*   Updated: 2025/06/26 22:51:33 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

void	ft_dlstdelone(t_dlist *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst->prev)
		lst->prev->next = lst->next;
	if (lst->next)
		lst->next->prev = lst->prev;
	if (lst->content)
		del(lst->content);
	free(lst);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	del(void *content) {
	free(content);
}

int	main(void) {
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew(strdup("Premier")));
	ft_lstadd_back(&list, ft_lstnew(strdup("Deuxième")));
	ft_lstadd_back(&list, ft_lstnew(strdup("Troisième")));

	printf("Liste avant la suppression:\n");
	t_list *current = list;
	while (current) {
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");

	if (list && list->next) {
		t_list *to_delete = list->next;
		list->next = to_delete->next;
		ft_lstdelone(to_delete, &del);
	}

	printf("Liste après la suppression:\n");
	current = list;
	while (current) {
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");

	while (list) {
		t_list *next = list->next;
		ft_lstdelone(list, del);
		list = next;
	}

	return (0);
}
*/
