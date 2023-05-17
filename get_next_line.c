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

/**
 * The function reads a file descriptor,
 * and returns the next line of text from the file.
 *
 * @param file_descriptor The file descriptor is an integer,
 * value that represents an open file in the operating system. It
 * is used to read or write data to/from the file. In this case,
 * the function `get_next_line` takes a file descriptor as a
 * parameter to read data from a file.
 *
 * @return The function `get_next_line` is returning a pointer to,
 * a string that contains the next line from the file
 * associated with the given file descriptor.
 */
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
    returned_line = ft_growth_line(returned_line, buffer, chars_readed);
    return (returned_line);
}