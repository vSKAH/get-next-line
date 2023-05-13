/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:38:42 by jbadaire          #+#    #+#             */
/*   Updated: 2023/05/12 15:23:37 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char *get_next_line(int file_desc)
{
	static t_string_list *cache;
	char *string;
	void	*t;

	//Si y'a un problème avec les paramètres, on renvoie NULL
	if (BUFFER_SIZE <= 0 || file_desc < 0)
		return (NULL);
	t = read_and_cache(file_desc, &cache);
	if	(t == NULL)
		return (NULL);
	if (cache == NULL)
		return (NULL);
	string = ft_lst_to_string(cache);
	if (string == NULL)
		return (NULL);
	cleanup_cache(&cache);
	return (string);
}

void *read_and_cache(int file_desc, t_string_list **cache)
{
	char		buffer[BUFFER_SIZE];
	size_t		 _read;
	int	is_passed;

	is_passed = 0;
	while (!ft_lst_contains_linebreak(*cache) || !is_passed)
	{
		_read = read(file_desc, buffer, BUFFER_SIZE);
		add_to_cache(cache, buffer, _read);
		is_passed = 1;
		if(_read <= 0)
			return ((void *) NULL);
	}
	return ((void *)(_read));
}

void add_to_cache(t_string_list **cache, const char *buffer, size_t _read)
{
	size_t index;
	t_string_list *new;

	index = 0;
	new = malloc(sizeof(t_string_list));
	if (!new)
		return ;
	new->string = malloc((sizeof(char) * _read));
	if (!new->string)
		return ;
	while (index < _read && buffer[index])
	{
		new->string[index] = buffer[index];
		index++;
	}
	if (*cache == NULL)
		*cache = new;
	else
		ft_lst_get_last(*cache)->next = new;
}

void cleanup_cache(t_string_list **cache)
{
	size_t index;
	t_string_list *copy_lst;
	t_string_list *last_lst;
	size_t j_index;

	copy_lst = malloc(sizeof(t_string_list));
	if (!cache || !copy_lst)
		return;
	index = 0;
	last_lst = ft_lst_get_last(*cache);
	copy_lst->next = NULL;

	while (last_lst->string[index] && last_lst->string[index] != '\n')
		index++;
	if (last_lst->string[index] && last_lst->string[index] == '\n')
		index++;

	copy_lst->string = malloc(sizeof(char) * ((ft_strlen(last_lst->string) - index) + 1));
	if (!copy_lst->string)
		return ;

	j_index = 0;
	while (last_lst->string[index])
		copy_lst->string[j_index++] = last_lst->string[index++];
	copy_lst->string[j_index] = '\0';
	free_cache(*cache);
	*cache = copy_lst;
}

void free_cache(t_string_list *cache)
{
	t_string_list *current;
	t_string_list *next;

	current = cache;
	while (current)
	{
		free(current->string);
		next = current->next;
		free(current);
		current = next;
	}
}