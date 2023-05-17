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

/**
 * The function shifts the contents of a buffer by a given length,
 * and fills the remaining space with zeros.
 *
 * @param buffer A pointer to a character array
 * (string) that represents a buffer.
 * @param len The length of the portion of the buffer
 * that needs to be switched/moved to the beginning of the buffer.
 */
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

/**
 * The function fills a character buffer with null characters
 * starting from a given index until the end of the buffer or
 * until a non-null character is encountered.
 *
 * @param buffer A pointer to a character array
 * (string) that needs to be filled with null characters.
 * @param index The parameter "index" is an integer
 * variable that represents the starting index of the buffer array where
 * the function will start filling with null characters ('\0').
 */
void ft_fill_of_zero(char *buffer, int index) {
    while (buffer[index] && index < BUFFER_SIZE)
        buffer[index++] = '\0';
}

/**
 * The function concatenates two strings and returns the result.
 *
 * @param returned_line A pointer to a string that
 * has already been allocated and contains some characters.
 * @param buffer The buffer parameter is a pointer to a
 * character array that contains the characters to be added to the
 * returned_line.
 * @param nb_of_char nb_of_char is the number
 * of characters to be added to the string.
 * @param len_line The length of the string "returned_line".
 *
 * @return a pointer to a newly allocated string that
 * is the concatenation of the input strings `returned_line` and `buffer`.
 */
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

/**
 * The function takes in a string, a buffer, and the number of characters read,
 * and returns a new string that is the concatenation of the two input strings.
 *
 * @param returned_line The parameter `returned_line` is a pointer
 * to a character array that represents the line that has
 * been read from a file or input stream.
 * It may be NULL if no line has been read yet.
 *
 * @param buffer The buffer parameter is a pointer to a character array
 * that contains the data read from a file or input stream.
 *
 * @param chars_readed The parameter `chars_readed` is an integer that represents
 * the number of characters read from a file
 * or input stream by a function. It is used in the function `ft_increase_line`
 * to determine how many characters to append to
 * the `returned_line` string. If `chars_readed` is
 *
 * @return a pointer to a character, which is the updated string
 * after concatenating the previous string (returned_line)
 * with the new string (buffer) using the ft_str_join function.
 * Before returning the updated string, the function also
 * frees the memory allocated for the previous string using the free function.
 */
char    *ft_growth_line(char *returned_line, char *buffer, int chars_readed)
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

/**
 * The function checks if a given buffer contains a new line
 * character and returns a boolean value,
 * while also increasing the line count and switching memory if necessary.
 *
 * @param buffer A pointer to a character array (string) that contains
 * the input buffer to be searched for a new line character.
 *
 * @param returned_line A pointer to a pointer to a char,
 * which will be used to store the line that is extracted from the buffer.
 *
 * @return an enum value of either `_true` or `_false`,
 * depending on whether a new line character was found in the `buffer` parameter.
 * Additionally, the function is modifying the `returned_line` parameter
 * by increasing its size and copying the contents of `buffer` up to the
 * new line character (if it exists).
 */
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
    *returned_line = ft_growth_line(*returned_line, buffer, ++index);
    if (returned_line == NULL)
        return (_false);
    return (ft_mem_switch(buffer, index), is_new_line);
}
