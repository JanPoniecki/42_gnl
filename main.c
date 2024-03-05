#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

void print_mem(void *s, int n)
{
	int i = 0;
	while (i < n)
		printf("%d ", ((char *)s)[i++]);
	printf("\n");
}

int main()
{
	int	fd;
	int	i = 0;

	fd = open("test.txt", O_RDONLY);
	// fd = 1;
	while (i++ < 100)
	{
		char *line = get_next_line(fd);
		if (!line)
		{
			break ;
		}
		print_mem(line, 20);
		printf("%li - %s", strlen(line), line);
		free(line);
		printf("-----------------------------------------\n");
	}
	close(fd);
}
