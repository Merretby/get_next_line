/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:34:51 by moer-ret          #+#    #+#             */
/*   Updated: 2023/12/12 10:26:45 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h> 
# include <fcntl.h>

char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, int c);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef MAX
#  define MAX 1024
# endif

#endif