/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:45:08 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/05 18:19:41 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char **argv)
{
	int		i1;
	int		i2;
	char	*tmp;

	i2 = argc;
	i1 = 1;
	while (++i1 <= argc)
	{
		i2 = 1;
		while (++i2 <= argc - 1)
		{
			if (ft_strcmp(argv[i2], argv[i2 - 1]) < 0)
			{
				tmp = argv[i2];
				argv[i2] = argv[i2 - 1];
				argv[i2 - 1] = tmp;
			}
		}
	}
	i1 = 0;
	while (++i1 < argc)
		ft_putstr(argv[i1]);
}
