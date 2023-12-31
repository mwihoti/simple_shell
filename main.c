#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int filed = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (filed)
		: "r" (filed));

	if (ac == 2)
	{
		filed = open(av[1], O_RDONLY);
		if (filed == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_putstr(av[0]);
				_putstr(": 0: Can't open ");
				_putstr(av[1]);
				_putscharacter('\n');
				_putscharacter(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = filed;
	}
	populates_environ_list(info);
	reads_filehistory(info);
	shell(info, av);
	return (EXIT_SUCCESS);
}

