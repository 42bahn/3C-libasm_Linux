/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:08:06 by bahn              #+#    #+#             */
/*   Updated: 2021/04/06 14:27:47 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <stdlib.h>

ssize_t		_ft_write(int fd, const void *buf, size_t nbyte);
size_t		_ft_read(int fd, void *buf, size_t count);
size_t		_ft_strlen(const char *s);
int			_ft_strcmp(const char *s1, const char *s2);
char		*_ft_strcpy(char *dest, const char *src);
char		*_ft_strdup(const char *s);

#endif

