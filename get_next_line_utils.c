/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:37:57 by jbadaire          #+#    #+#             */
/*   Updated: 2023/05/12 15:05:01 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

/**
 * The function calculates the length of a given string.
 *
 * @param string A pointer to a constant character array (string) that we want to find the length of.
 *
 * @return The function `ft_strlen` returns the length of the input string as a `size_t` data type.
 */
size_t ft_strlen(const char *string)
{
	int index;

	index = 0;
    if (string == NULL)
        return (0);
    while (string[index])
		index++;
	return (index);
}


/**
 * The function returns the last element of a linked list.
 *
 * @param lst lst is a pointer to the first node of a linked list of type t_string_list.
 *
 * @return The function `ft_lst_get_last` returns a pointer to the last node of a linked list of type `t_string_list`.
 */
t_string_list *ft_lst_get_last(t_string_list *lst)
{
	t_string_list *latest;

	latest = lst;
	while (latest->next != NULL)
		latest = latest->next;
	return (latest);
}

/**
 * The function checks if the last string in a linked list contains a line break character.
 *
 * @param lst lst is a pointer to a linked list of strings (t_string_list).
 *
 * @return a boolean value (true or false) depending on whether the last string in the given linked list contains a line
 * break character ('\n') or not.
 */
int	ft_lst_contains_linebreak(t_string_list *lst)
{
	t_string_list	*latest;
	size_t			index;

	latest = ft_lst_get_last(lst);
	index = 0;

	while (latest != NULL && latest->string != NULL && latest->string[index])
	{
		if (latest->string[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}
char	*ft_lst_to_string(t_string_list *lst)
{
	char			*string;
	t_string_list	*tmp;
	size_t			index;
	size_t			j_index;

	tmp = lst;
	string = ft_alloc_from_lst(lst);
	index = 0;
	if (!string)
		return (NULL);
	while (tmp)
	{
		j_index = 0;
		while (tmp->string[j_index])
		{
			if (tmp->string[j_index] == '\n')
			{
				string[index++] = tmp->string[j_index];
				break ;
			}
			string[index++] = tmp->string[j_index++];
		}
		tmp = tmp->next;
	}
    if (string[0] == '\0')
        return ( free(string), NULL);
    return (string);
}
char	*ft_alloc_from_lst(t_string_list *lst)
{
	size_t			index;
	size_t			j_index;
    char			*string;

	index = 0;
	j_index = 0;
	while (lst)
	{
        if(lst->string != NULL) {
            index += ft_strlen(lst->string);
            lst = lst->next;
        }
	}
	string = malloc(sizeof(char) * (index + 1));
    if (!string)
		return (NULL);
	while (j_index <= index)
	{
		string[j_index] = '\0';
		j_index++;
	}
	return (string);
}