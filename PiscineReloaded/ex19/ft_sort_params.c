/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksei <aleksei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:26:55 by aleksei           #+#    #+#             */
/*   Updated: 2021/10/31 15:51:32 by aleksei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);


void    ft_putstr(char *str)
{
    while (*str != '\0')
    {
        ft_putchar(*str);
        str++;
    }    
}

int ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while ((s1[i] == s2[i]) && s1[i] && s2[i])
        i++;
    return (s1[i] - s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void ft_print_params(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc == 1)
        return ;
    else 
    {
        while (i < argc)
        {
            ft_putstr(argv[i]);
            ft_putchar('\n');
            i++;
        }
    }
}

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < (argc - 1))
    {
        j = i + 1;
        while(j < argc)
        {
            if (ft_strcmp(argv[i], argv[j]) > 0)
                ft_swap(&argv[i], &argv[j]);
            else
                j++;
        }
        i++;
    }
    ft_print_params(argc, argv);
    return (0);
}
