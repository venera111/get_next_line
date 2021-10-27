#include "get_next_line_bonus.h"

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
		str = ft_strjoin(str, buffer);
	return (str);
}

static void	ft_del_fd(t_gnl **head, t_gnl *temp)
{
	t_gnl	*prev;

	if (!(*head) || !head)
		return ;
	if (*head == temp)
	{
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		prev = *head;
		while (prev->next != temp)
			prev = prev->next;
		prev->next = temp->next;
		free(temp);
	}
}

static char	*ft_get_line_remainder(t_gnl **head, t_gnl *temp)
{
	char	*leak;
	size_t	i;
	char	*line;

	if (!(temp->remaind))
	{
		ft_del_fd(head, temp);
		return (NULL);
	}
	i = 0;
	while ((temp->remaind)[i] != '\n' && (temp->remaind)[i])
		i++;
	if (i < ft_strlen(temp->remaind))
	{
		leak = temp->remaind;
		line = ft_substr(leak, 0, ++i);
		temp->remaind = ft_substr(temp->remaind, i, ft_strlen(temp->remaind));
		free(leak);
	}
	else
	{
		line = temp->remaind;
		temp->remaind = NULL;
	}
	return (line);
}

static t_gnl	*ft_get_add_fd(int fd, t_gnl **head)
{
	t_gnl	*new;
	t_gnl	*existed;

	if (!head || !(*head))
	{
		new = ft_lstnew(fd);
		*head = new;
		return (*head);
	}
	existed = *head;
	while (existed)
	{
		if (existed->fd == fd)
			return (existed);
		existed = existed->next;
	}
	new = ft_lstnew(fd);
	new->next = *head;
	*head = new;
	return (*head);
}

char	*get_next_line(int fd)
{
	static t_gnl	*head;
	t_gnl			*temp;
	int				readed;
	char			*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	temp = ft_get_add_fd(fd, &head);
	readed = read(temp->fd, buffer, BUFFER_SIZE);
	while (readed > 0)
	{
		buffer[readed] = '\0';
		temp->remaind = ft_save_buffer(temp->remaind, buffer);
		if (ft_search_new_line(temp->remaind))
			break ;
		readed = read(temp->fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_get_line_remainder(&head, temp));
}
