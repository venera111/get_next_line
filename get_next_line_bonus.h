#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct get_next_line
{
	int						fd;
	char					*remaind;
	struct get_next_line	*next;
}	t_gnl;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_gnl	*ft_lstnew(int fd);
bool	ft_search_new_line(char *str);

#endif
