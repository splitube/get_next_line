/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghyep <sanghyep@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:23:54 by sanghyep          #+#    #+#             */
/*   Updated: 2023/01/05 14:26:49 by sanghyep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, const char s2[BUFFER_SIZE + 1])
{
	char	*new_str;
	int		s1_len;
	int		s2_len;
	int		idx;

	idx = 0;
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	while (*s1)
		new_str[idx++] = *s1++;
	while (*s2)
		new_str[idx++] = *s2++;
	new_str[idx] = '\0';
	return (new_str);
}

size_t	strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	word_left;

	if (s == NULL)
		return (NULL);
	if (strlen(s) <= start)
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = 0;
		return (substr);
	}
	word_left = strlen(s + start);
	if (word_left < len)
		len = word_left;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize)
	{
		while (len + 1 < dstsize && src[len])
			*(dst++) = src[len++];
		*dst = '\0';
	}
	while (src[len])
		len++;
	return (len);
}

int	contains_nl(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}
