/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:33:51 by jbadaire          #+#    #+#             */
/*   Updated: 2023/05/12 15:23:37 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef enum t_boolean
{
    _false,
    _true
} t_boolean;


void    ft_mem_switch(char *buffer, int len);
void ft_fill_of_zero(char *buffer, int index);

char    *ft_str_join(char *returned_line, char *buffer, int chars_readed, int len_line);
char    *ft_increase_line(char *returned_line, char *buffer, int chars_readed);
enum t_boolean   ft_has_new_line(char *buffer, char **returned_line);

char			*get_next_line(int file_descriptor);
# define GET_NEXT_LINE_H
#endif
