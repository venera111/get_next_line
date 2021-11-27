#ifndef GET_NEXT_LINE_H //ifndef обеспечивает защиту от многократного включения заголовочного файла
# define GET_NEXT_LINE_H   // константа

#include <stdlib.h> // поиск файла в системных каталогах
#include <unistd.h> // поиск файла в системных каталогах

int		get_next_line(char **line);

#endif
