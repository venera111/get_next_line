#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

// ввод из файла
	fd = open("text1.txt", O_RDONLY);
	while((line = get_next_line(fd)))
	printf("%s", line);

// ввод с клавиатуры
	// fd = 0;
	// while((line = get_next_line(fd)))
	// printf("%s", line);

	// return 0;

// для проверки на лики: leaks a.out
	sleep(10000);
	return 0;
}
