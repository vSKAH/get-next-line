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
char    *ft_growth_line(char *returned_line, char *buffer, int chars_readed);
enum t_boolean   ft_has_new_line(char *buffer, char **returned_line);

char			*get_next_line(int file_descriptor);
int 			read_and_cache(int file_descriptor, t_string_list **cache);
void			add_to_cache(t_string_list **cache, const char *buffer, int _read);
void			cleanup_cache(t_string_list **cache);
void			free_cache(t_string_list **cache);


size_t			ft_strlen(const char string[]);
t_string_list	*ft_lst_get_last(t_string_list *lst);
int				ft_lst_contains_linebreak(t_string_list *lst);
char			*ft_lst_to_string(t_string_list *lst);
char			*ft_alloc_from_lst(t_string_list *lst);
# define GET_NEXT_LINE_H
#endif
