#include "get_next_line_bonus.h"

int main(void)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;

// ввод из различных файлов
	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text1.txt", O_RDONLY);
	fd3 = open("text2.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd3);
	printf("%s", line);
	free(line);
	// line = get_next_line(1006);
	// printf("%s", line);

// ввод с клавиатуры
	// fd1 = 0;
	// while((line = get_next_line(fd1)))
	// printf("%s", line);
	sleep(10000);

	return 0;
}
