/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qestefan <qestefan@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:50:13 by qestefan          #+#    #+#             */
/*   Updated: 2021/10/27 12:03:35 by qestefan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

bool	ft_search_new_line(char *str)							// поиск символа перевода каретки в результрующей строке remaind
{
	while (*str)
		if (*str++ == '\n')										// если \n находится где-то внутри строки
			return (true);										// возвращаем true
	return (false);
}

char	*ft_strjoin(char const *s1, char const *s2)				// выделяет память для всей результирующей строк, включая buffer
																// записывает buffer в str и возвращает готовую строку
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	const char	*begin;

	if (!s)
		return (0);
	begin = s;
	while (*s)
		s++;
	return ((size_t)(s - begin));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}

t_gnl	*ft_lstnew(int fd)						// создает новый элемент односвязного списка
{
	t_gnl	*new;								// указатель на структуру

	new = (t_gnl *)malloc(sizeof(t_gnl));		// выделяем память в куче под все переменные, находящиеся в структуре (их всего 3)
	if (!new)									// если в выделении памяти отказано,
		return (NULL);							// возвращаем указатель ни на что (void *)
												// если память в куче под структуру выделилась
	new->fd = fd;								// методом обращения к элементу структруры записываем файловый дескриптор, переданный в качестве параметра
	new->remaind = NULL;						// указатель на область памяти, где будет результирующая строка пока оставляем пустым
	new->next = NULL;							// последний элемент односвязного списка всегда должен содержать указатель на NULL
												// что говорит о конце односвязного списка
	return (new);								// возвращаем указатель на созданный элемент списка (на структуру)
}
