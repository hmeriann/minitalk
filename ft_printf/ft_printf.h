/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:10:57 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:10:58 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	args;
	int		index;
	int		isnegative;
	int		left_align;
	int		zero_prefix;
	int		width;
	int		dot;
	int		tochnost;
	int		total_length;
}			t_print;

void	ft_putchar(char c, t_print *tab);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int len, t_print *tab);
void	ft_print_str(char *str, t_print *tab);
t_print	*ft_init_tab(t_print *tab);
int		ft_parcewidth(const char *str, t_print *tab, va_list ap);
int		ft_parcetochn(const char *str, t_print *tab, va_list ap);
int		ft_parceflags(const char *str, t_print *tab, va_list ap);
void	ft_parcespec(const char *str, t_print *tab, va_list ap);
void	ft_print_c(int c, t_print *tab);
void	ft_find_num_idx(int len, unsigned long number, int base, char *str);
char	*ft_itoa(unsigned long long number, int base);
void	ft_print_d_ralign(int len, t_print *tab);
void	ft_print_tochn_pstv(char *str, int len, t_print *tab);
void	ft_make_print_d(long long nbr, t_print *tab);
void	ft_print_d(int number, t_print *tab);
void	ft_print_u_ralign(char *str, char sym, int len, t_print *tab);
void	ft_print_u_lalign(char *str, int len, t_print *tab);
void	ft_print_u(unsigned int number, t_print *tab);
void	ft_print_p_lalign(char *str, int len, t_print *tab);
void	ft_print_p(unsigned long long number, t_print *tab);
void	ft_print_ralign(char *str, char sym, int len, t_print *tab);
void	ft_print_lalign(char *str, int len, t_print *tab);
char	*ft_itoa_upperx(unsigned long long number, int base);
void	ft_print_lalign(char *str, int len, t_print *tab);
void	ft_print_uppx(long long nbr, char sym, t_print *tab);
void	ft_print_upperx(unsigned long number, t_print *tab);
void	ft_print_smx_ralign(char *str, char sym, int len, t_print *tab);
void	ft_print_smx_lalign(char *str, int len, t_print *tab);
void	ft_print_smx(long long nbr, char sym, t_print *tab);
void	ft_print_x(unsigned long number, t_print *tab);
void	ft_make_print_main(t_print *tab, const char *str, va_list ap);
int		ft_printf(const char *str, ...);

#endif
