/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <aleksei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:01:33 by aleksei           #+#    #+#             */
/*   Updated: 2021/10/31 23:45:59 by aleksei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex27.h"

void ft_display_file(char *filename)
{
    int fd;
    char buf;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return ;
    while (read(fd, &buf, 1))
        write(1, &buf, 1);
    close(fd);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        write(2, "File name missing.\n", 19);
    else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
    else
        ft_display_file(argv[1]);
    return (0); 
}
