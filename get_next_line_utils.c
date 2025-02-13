/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:54:19 by emorillo          #+#    #+#             */
/*   Updated: 2025/01/15 20:33:31 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	ch = (unsigned char)c;
	while (*str != ch && *str != '\0')
		str++;
	if ((*str == ch) || (ch == '\0'))
		return (str);
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) + 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	new = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (ft_clean(&s1));
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	ft_clean(&s1);
	return (new);
}

void	*ft_clean(char **mem)
{
	if (mem && *mem)
	{
		free(*mem);
		*mem = NULL;
	}
	return (NULL);
}
