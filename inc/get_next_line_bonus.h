/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:56:50 by hyecheon          #+#    #+#             */
/*   Updated: 2022/11/04 21:29:54 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE	3000
/*typedef struct s_fd_list
{
	int					fd;
	char				*str;
	struct s_fd_list	*next;
}	t_fd_list;
 */
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char*s1, char *s2);
char	*get_next_line(int fd);

#endif
