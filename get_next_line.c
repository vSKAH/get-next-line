/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:38:42 by jbadaire          #+#    #+#             */
/*   Updated: 2023/05/16 14:35:10 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char    *get_next_line(int file_descriptor)
{
    static char    buffer[BUFFER_SIZE + 1];
    int            chars_readed;
    char        *returned_line;

    chars_readed = BUFFER_SIZE;
    returned_line = NULL;
    while (chars_readed > 0)
    {
        if (ft_has_new_line(buffer, &returned_line))
            return (returned_line);
        chars_readed = read(file_descriptor, buffer, BUFFER_SIZE);
    }
    returned_line = ft_increase_line(returned_line, buffer, chars_readed);
    return (returned_line);
}