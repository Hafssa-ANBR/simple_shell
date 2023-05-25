#include "shell.h"

/**
 * main - entry point
 * @ac: arg count,main function parameter
 * @av: arg vector, main function parameter
 *
 * Return: 0 on success, 1if not
 */
int main(int ac, char **av)
{
        info_t infos[] = { INFO_INIT };
        int fdt = 2;

        asm ("mov %1, %0\n\t"
                        "add $3, %0"
                        : "=r" (fdt)
                        : "r" (fdt));

        if (ac == 2)
        {
                fdt = open(av[1], O_RDONLY);
                if (fdt == -1)
                {
                        if (errno == EACCES)
                                exit(126);
                        if (errno == ENOENT)
                        {
                                _eputs(av[0]);
                                _eputs(": 0: Can't open ");
                                _eputs(av[1]);
                                _eputchar('\n');
                                _eputchar(BUF_FLUSH);
                                exit(127);
                        }
                        return (EXIT_FAILURE);
                }
                infos->readfd = fdt;
        }
        populate_env_list(infos);
        read_history(infos);
        hsh(infos, av);
        return (EXIT_SUCCESS);
}
