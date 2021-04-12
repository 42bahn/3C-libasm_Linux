/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:08:06 by bahn              #+#    #+#             */
/*   Updated: 2021/04/09 16:00:24 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;

ssize_t		_ft_write(int fd, const void *buf, size_t nbyte);
size_t		_ft_read(int fd, void *buf, size_t count);
size_t		_ft_strlen(const char *s);
int			_ft_strcmp(const char *s1, const char *s2);
char		*_ft_strcpy(char *dest, const char *src);
char		*_ft_strdup(const char *s);

#endif

