#include "get_next_line_bonus.h"

int main(void)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;

// ввод из различных файлов
	fd1 = open("text.txt", O_RDONLY);			// фунция open открывает файл text1.txt и записывает номер файлового дескриптора в переменную
	fd2 = open("text1.txt", O_RDONLY);
	fd3 = open("text2.txt", O_RDONLY);
	line = get_next_line(fd1);					// функция считывает первую строку из файла и она присваивается переменной
	printf("%s", line);							// печатаем данную строку
	free(line);									// освобождаем память для последующей проверки на утечки памяти
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

// для проверки на лики leaks a.out				// раскоментировать строку sleep(10000), скомпилировать, запустить исполняемый файл
	// sleep(10000);							// ввести leaks a.out в другом терминале для проверки утечек памяти

	return 0;
}
