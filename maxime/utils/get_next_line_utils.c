/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:00:19 by kyaubry           #+#    #+#             */
/*   Updated: 2023/09/07 15:24:27 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_chr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_buf_cut(char *dest)
{
	int	i;
	int	j;
	int	indice;

	j = 0;
	i = 0;
	indice = 0;
	while (dest[i] != '\n' && dest[i])
		i++;
	if (dest[i] == '\n')
		i++;
	while (dest[j])
		j++;
	while (indice < j - i)
	{
		dest[indice] = dest[indice + i];
		indice++;
	}
	dest[indice] = '\0';
}

int	ft_len(char *s, int j)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	if (j == 1)
		c = '\n';
	while (s && s[i] && s[i] != c)
		i++;
	if (c == '\n' && s && s[i] && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_25_line(char *s1, char *dest)
{
	free(s1);
	if (dest)
	{
		if (dest[0] == '\0')
		{
			free(dest);
			dest = NULL;
		}
	}
	return (dest);
}

char	*ft_join_modif(char *s1, char *s2)
{
	char	*dest;
	int		t;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ((ft_len(s1, 1) + ft_len(s2, 0)) + 1));
	if (dest)
	{
		while (s1 && s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		t = 0;
		while (s2 && s2[t] && s2[t] != '\n')
		{
			dest[i + t] = s2[t];
			t++;
		}
		dest[i + t] = '\n';
		if (s2 && s2[t] && s2[t] == '\n')
			t++;
		dest[i + t] = '\0';
	}
	return (ft_25_line(s1, dest));
}
