/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:16:39 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/27 11:30:04 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// если такой файл уже был включен где-то раньше,
// то и GET_NEXT_LINE_H будет объявлена, а значит, условный #define будет пропущен, вместе со всеми объявлениями до #endif
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>        // для malloc()
# include <unistd.h>        // для read()
# include <fcntl.h>         // библиотека для системного вызова open()
# include <stdio.h>         // для printf() в main()
# include <stdbool.h>       // для булевых значений

char	*get_next_line(int fd);
char	*ft_strdup(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
