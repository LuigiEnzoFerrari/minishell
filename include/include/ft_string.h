/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenzo-pe <lenzo-pe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:27:25 by lenzo-pe          #+#    #+#             */
/*   Updated: 2021/12/04 00:02:49 by lenzo-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_ctype.h"

// memory
void	ft_memdel(void **ptr);
void	ft_bzero(void *ptr, size_t num);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_memccpy(void *dest, const void *src, int chr, size_t num);
void	*ft_memset(void *ptr, int c, size_t num);
void	*ft_calloc(size_t num, size_t size);

void	ft_strdel(char **str);
void	ft_strrev(char *str);
void	ft_strclr(char *str);

// returns a pointer to a matching char/string
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	*ft_memchr(const void *ptr, int c, size_t num);
char	*ft_strnstr(const char *str, const char *substr, size_t len);
char	*ft_strstr(const char *str, const char *substr);

// returns a allocated string
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);

// returns the result of the joined strings
char	*ft_joindel(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_rejoin(char *s1, char const *s2);
char	*ft_recjoin(char *s1, char *s2, int c);

// compares two given strings and returns the diference 
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t num);

// copies the string from source to dest
char	*ft_strccpy(char *dest, const char *src, size_t c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t num);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);

// concatenates two given string from source to dest
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t num);
char	*ft_strccat(char *dest, char *src, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

void	ft_swapchr(char *a, char *b);

// give the n bytes of a string until...
size_t	ft_strltok(const char *str, int c);
size_t	ft_strlen(const char *str);
size_t	ft_strclen(const char *str, int c);
size_t	ft_strslen(const char *str, const char *substr);
size_t	ft_strnlen(const char *str, size_t maxlen);

size_t	ft_nchar(char *str, int c);
size_t	ft_ndigit(char *str);

char	*ft_skip_c_type(char *str, int (f)(int), int a);

#endif
