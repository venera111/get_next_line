#include "get_next_line.h"

static bool	ft_search_new_line(char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (true);
	return (false);
}

static char	*ft_save_buffer(char *str, char *buffer)
{
	char	*temp;

	if (str)
	{
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
	}
	else
		str = ft_strdup(buffer);
	return (str);
}

static char	*ft_get_line_remainder(char **str)
{
	char	*temp;
	size_t	i;
	char	*line;

	if (!(*str))
		return (NULL);
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if (i < ft_strlen(*str))
	{
		temp = *str;
		line = ft_substr(*str, 0, ++i);
		*str = ft_substr(*str, i, ft_strlen(*str));
		free(temp);
	}
	else
	{
		line = *str;
		*str = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			readed;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = read(fd, buffer, BUFFER_SIZE);
	while (readed > 0)
	{
		buffer[readed] = '\0';
		str = ft_save_buffer(str, buffer);
		if (ft_search_new_line(str))
			break ;
		readed = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_get_line_remainder(&str));
}
