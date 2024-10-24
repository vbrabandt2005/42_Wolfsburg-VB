/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:22:35 by bjbogisc          #+#    #+#             */
/*   Updated: 2024/10/24 16:17:27 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == c)
			++str;
		while (*str != c && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(const char *str, char c)
{
	static int	position = 0;
	char		*word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[position] == c)
		++position;
	while (str[position + len] && str[position + len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
		word[i++] = str[position++];
	word[i] = '\0';
	return (word);
}

char **split(char *s, char c)
{
    int word_count;
    char **result;
    int i;

    i = 0;
    word_count = count_words(s, c);
    if (!word_count)
        return (NULL);
    result = malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return (NULL);
    while (i < word_count)
    {
        result[i] = get_next_word(s, c);
        if (!result[i])
        {
            while (i > 0)
                free(result[--i]);
            free(result);
            return (NULL);
        }
        i++;
    }
    result[i] = NULL;
    return (result);
}
