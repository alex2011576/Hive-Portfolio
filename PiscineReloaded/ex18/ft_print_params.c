/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <aleksei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:26:55 by aleksei           #+#    #+#             */
/*   Updated: 2021/10/31 14:52:11 by aleksei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc == 1)
        return (0);
    else 
    {
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                ft_putchar(argv[i][j]);
                j++;
            }
            ft_putchar('\n');
            i++;
        }
    }
    return (0);
}
