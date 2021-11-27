/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 00:38:14 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/27 11:39:49 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// если такой файл уже был включен где-то раньше,
// то и GET_NEXT_LINE_H будет объявлена, а значит, условный #define будет пропущен, вместе со всеми объявлениями до #endif
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>        // для malloc()
# include <unistd.h>        // для read()
# include <fcntl.h>         // библиотека для системного вызова open()
# include <stdio.h>         // для printf() в main()
# include <stdbool.h>       // для булевых значений

typedef struct get_next_line				// определение структуры для записи файлового дескриптора каждого файла,
											// для сохранения результирующей первой строки из файла,
											// указатель на следующий элемент односвязаного списка, где будет содержаться другой файловый дескриптор
{
	int						fd;				// файловый дескриптор
	char					*remaind;		// результирующая строка из файла
	struct get_next_line	*next;			// указатель на следующий элемент структуры, где будет новый fd
}	t_gnl;									// переименовываем тип данных struct get_next_line в тип t_gnl

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_gnl	*ft_lstnew(int fd);
bool	ft_search_new_line(char *str);

#endif
