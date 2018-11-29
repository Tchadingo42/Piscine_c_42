/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:56:41 by chbelan           #+#    #+#             */
/*   Updated: 2018/11/17 17:39:04 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	word_counter(const char *str, char c)
{
	intlen;

	len = 0;
	while (*str != 0 && *str != delim)
    {
		len += 1;
		str += 1;
    }
	return (len);
}

static int	count_substrings(const char *str, char delim)
{
	inti;

	i = 1;
	while (*str != 0)
    {
		if (*str == delim)
			i += 1;
		str += 1;
    }
	return (i);
}
char		**ft_strplit(char *str, char c)
{
	char	**word_tab;
	int	tab_index;
	int	word_len;
	int	word_count;

	word_count = count_substrings(str, c);
	if (!word_count)
		return (0);
	word_tab = malloc((1 + word_count) * sizeof(str));
	if (!word_tab)
		return (0);
	tab_index = 0;
	while (*str != 0)
    {
		if (*str != c)
		{
			word_len = substring_length(str, c);
			word_tab[tab_index++] = my_strtok(str, c);
			str += word_len;
		}
		else
			str += 1;
    }
	word_tab[tab_index] = 0;
	return (word_tab);
}
