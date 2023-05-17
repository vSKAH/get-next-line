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

void    ft_mem_switch(char *buffer, int len)
{
    int    index;

    index = 0;
    while (index + len < BUFFER_SIZE)
    {
        buffer[index] = buffer[len + index];
        index++;
    }
    ft_fill_of_zero(buffer, index);
}

void ft_fill_of_zero(char *buffer, int index) {
    while (buffer[index] && index < BUFFER_SIZE)
        buffer[index++] = '\0';
}


char    *ft_str_join(char *returned_line, char *buffer, int nb_of_char, int len_line)
{
    int        index;
    char    *result;

    if (len_line + nb_of_char <= 0)
        return (NULL);
    result = malloc((len_line + nb_of_char + 1) * sizeof(char));
    if (!result)
        return (NULL);
    index = 0;
    while (returned_line && returned_line[index])
    {
        result[index] = returned_line[index];
        index++;
    }
    while (index < (len_line + nb_of_char))
    {
        result[index] = *buffer;
        index++;
        buffer++;
    }
    return (result[index] = '\0', result);
}

char    *ft_increase_line(char *returned_line, char *buffer, int chars_readed)
{
    char    *result;
    int        index;

    index = 0;
    if (chars_readed == -1)
        return (free(returned_line), NULL);
    if (returned_line)
        while (returned_line[index])
            index++;
    result = ft_str_join(returned_line, buffer, chars_readed, index);
    return (free(returned_line), result);
}

enum t_boolean   ft_has_new_line(char *buffer, char **returned_line)
{
    int        index;
    enum t_boolean   is_new_line;

    index = 0;
    is_new_line = _false;
    while (buffer[index] && buffer[index] != '\n')
        index++;
    if (buffer[index] == '\n')
        is_new_line = _true;
    *returned_line = ft_increase_line(*returned_line, buffer, ++index);
    if (returned_line == NULL)
        return (_false);
    return (ft_mem_switch(buffer, index), is_new_line);
}
