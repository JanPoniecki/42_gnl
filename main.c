#include "get_next_line.h"

int main()
{
	int	fd;
	int	i = 0;

	fd = open("numbers.dict", O_RDONLY);
	// fd = 1;
	while (i++ < 100)
	{
		char *line = get_next_line(fd);
		if (!line)
		{
			printf("end of file\n");
			break ;
		}
		printf("%s", line);
		free(line);
		printf("-----------------------------------------\n");
	}
	close(fd);
}