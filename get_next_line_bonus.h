/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-makh <hel-makh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:22:28 by hel-makh          #+#    #+#             */
/*   Updated: 2021/11/16 19:22:30 by hel-makh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_free(void *ptr);
char	*get_next_line(int fd);

#endif
