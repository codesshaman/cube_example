/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltapioca <ltapioca@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:17:26 by ltapioca          #+#    #+#             */
/*   Updated: 2022/05/15 13:49:43 by ltapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_malloc_error(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	ft_str_nbr(char const *s, char c)
{
	size_t	i;
	int		count;

	if (s[0] == 0)
		return (0);
	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void	ft_get_str(char **str, size_t *len, char c)
{
	size_t	i;

	*str = *str + *len;
	*len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

static char	**ft_mry(char **arr, const char *s, char c, size_t count)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	str = (char *)s;
	while (i < count)
	{
		ft_get_str(&str, &len, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (arr[i] == 0)
			return (ft_malloc_error(arr));
		ft_strlcpy(arr[i], str, len + 1);
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**arr;

	if (s == 0)
		return (NULL);
	count = ft_str_nbr(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == 0)
		return (NULL);
	arr = ft_mry(arr, s, c, count);
	return (arr);
}
