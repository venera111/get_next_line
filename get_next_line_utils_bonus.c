#include "get_next_line_bonus.h"

bool	ft_search_new_line(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (true);
	return (false);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

t_gnl	*ft_lstnew(int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->remaind = NULL;
	new->next = NULL;
	return (new);
}
