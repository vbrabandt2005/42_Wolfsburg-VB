/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:45:08 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/10/31 16:45:09 by vbrabandt        ###   ########.fr       */
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
	int			word_length;
	int			i;

	i = 0;
	word_length = 0;
	while (str[position] == c)
		position++;
	while (str[position + word_length] && str[position + word_length] != c)
	{
		word_length++;
	}
	if (word_length == 0)
	{
		position = 0;
		return (NULL);
	}
	word = malloc(sizeof(char) * (word_length + 1));
	if (!word)
		return (NULL);
	while (i < word_length)
		word[i++] = str[position++];
	word[i] = '\0';
	return (word);
}

char	**split(char *str, char c)
{
	int		word_count;
	char	**result;
	int		i;

	i = 0;
	word_count = count_words(str, c);
	if (!word_count)
		return (NULL);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	while (i < word_count)
	{
		result[i] = get_next_word(str, c);
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
