/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:21:02 by thfirmin          #+#    #+#             */
/*   Updated: 2023/05/23 01:06:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGC_H
# define LIBGC_H
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdarg.h>

typedef struct s_mem
{
	void			*ptr;
	char			*ctx;
	struct s_mem	*next;
}					t_mem;

// GC Memtools
t_mem	*gc_meminit(void);
void	*gc_alloc(void *ptr, char *context, t_mem *mem);
void	gc_free(void *ptr, t_mem **mem);
void	gc_memdelete(t_mem **mem);
void	gc_sumary(t_mem *mem);

// GC Memutils
t_mem	*gc_memnew(void *ptr, char *context);
void	gc_memadd_back(t_mem **mem, t_mem *new);
int		gc_memsize(t_mem *mem);

// GC Printf
int		gc_printf(const char *format, ...);

// GC Pututils
int		gc_puthex_fd(long unsigned int hex, char mode, int fd);
int		gc_putunbr_fd(unsigned int unbr, int fd);
int		gc_putchar_fd(char c, int fd);
int		gc_putnbr_fd(int n, int fd);
int		gc_putstr_fd(char *str, int fd);

// GC Strutils
char	*gc_strdup(const char *str);

#endif
