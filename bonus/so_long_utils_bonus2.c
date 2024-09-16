/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsomarri <qsomarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:51:43 by qsomarri          #+#    #+#             */
/*   Updated: 2024/09/10 17:21:58 by qsomarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	extention_checker(char *str)
{
	size_t	len;
	char	*s;

	len = ft_strlen(str);
	s = ft_substr(str, len - 4, 4);
	if (!s)
		return (1);
	if (len < 4)
		return (1);
	if (!ft_strncmp(s, ".ber", 4))
		return (free(s), 1);
	else
		return (free(s), 0);
}
