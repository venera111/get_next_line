#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*begin;

	begin = s;
	while (*s)
		s++;
	return ((size_t)(s - begin));
}

char	*ft_strdup(char const *str)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (result)
	{
		i = 0;
		while (str[i])
		{
			result[i] = str[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
