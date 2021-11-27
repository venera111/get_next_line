#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int		r;
	// иництализируем указатель
	char	*line;
	// указатель ни на что не указывает
	line = NULL;
	// пока функция возвращает число > 0
	// функция принимаем на вход адрес указателя
	while ((r = get_next_line(&line)) > 0)
	{
		// печатаем содержимое строки line
		printf("%s\n", line);
		// всегда будет печататься r = 1
		printf("r: %d\n", r);
		// освобождаем выделенную память в get_next_line
		free(line);
	}
	//printf("%s", line);
	//free(line);
	//sleep(100000);
}
