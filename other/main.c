/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:40:31 by bduron            #+#    #+#             */
/*   Updated: 2016/12/14 18:07:33 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include "test_runner.h"
#include "libftprintf.h"

#define valp(x) printf(" --> %d\n", x)
#define valft(y) printf(" --> %d\n\n", y)
#define ret(x, y) do {printf(x, y) == ft_printf(x, y); freopen("/dev/null", "w", stdout); } while (0)
#define eval(a,b) do {printf("(%s, %s)\n", #a, #b); \
          valp(printf("p  |"a"|", b)); valft(ft_printf("ft |"a"|", b)); } while (0)

/* test_c *********************************/

int test_c(void)
{
	long  min = LONG_MAX;

    	
  eval("%d", 5);
  eval("%#20.15x", 42);
  eval("%p", NULL);
  eval("%#08x", 42);
  eval("%#8x", 42);
  
  ret("HHWOIHD %d", 42);
   


	printf("ft = %d\n", ft_printf("ft |@moulitest: %#.x %#.0x|\n", 0, 0));
	printf("p = %d\n", printf("p  |@moulitest: %#.x %#.0x|\n", 0, 0));

	printf("ft = %d\n", ft_printf("ft |@moulitest: |%5.o| |%5.0o|\n", 1, 0));
	printf("p = %d\n", printf("p  |@moulitest: |%5.o| |%5.0o|\n", 1, 0));

	ft_printf("ft |@moulitest: |%5o| |%5o|\n", 1, 0);
	printf("p  |@moulitest: |%5o| |%5o|\n", 1, 0);


	printf("p  %30.25lX\n", min);
	ft_printf("ft %30.25lX\n\n", min);
	printf("p  %30.25lo\n", min);
	ft_printf("ft %30.25lo\n\n", min);
	printf("p  %+30.25ld\n", min);
	ft_printf("ft %+30.25ld\n", min);

	printf(" %ld  | %ld \n", sizeof(unsigned), sizeof(long long));
	ft_printf(" %ld  | %ld \n", sizeof(unsigned), sizeof(long long));
	
	unsigned char c;
	c = 0xe1;
	write(1, &c, 1);
	c = 0x88;
	write(1, &c, 1);
	c = 0xb4;
	write(1, &c, 1);
	c = 0x0a;
	write(1, &c, 1);



	int nn = 16;
//	nn = (nn >> 3) << 3;
//	nn = (nn >> 1) << 1;
	printf("%d\n", (nn & ~1));

	printf("%s\n", "䗕䘣㶥䗕");
//	printf("%C\n", '䗕');
	ft_printf("\nft |%c|\n", 'a');
	printf("p  |%c|\n", 'a');

	return (0);
}


///* test_o *********************************/
//
//int test_o(void)
//{
//		int ft, p;
//
//	printf("%o\n", 12);
//	ft_printf("%o\n", -12);
//	ft_printf("%#o\n", 0);
//	printf("%#o\n", 0);
//	printf("ft = %d ", ft_printf("%#10x\n", 1));
//	printf("p = %d ", printf("%#10x\n", 1));
//
//
//	ft = ft_printf("ft |%3p\n", (void*) 455);
//	p = printf("p  |%3p\n", (void*) 455);
//	printf("ft = %d | p = %d\n\n", ft, p);
//
//	ft = ft_printf("ft |%#.10o\n", 8, 0);
//	p = printf("p  |%#.10o\n", 8, 0);
//	printf("ft = %d | p = %d\n\n", ft, p);
//
//	ft = ft_printf("ft |%#-+03x\n", 84);
//	p = printf("p  |%#-+03x\n", 84);
//	printf("ft = %d | p = %d\n\n", ft, p);
//
//	ft = ft_printf("%#.3x\n", 1);
//	p = printf("%#.3x\n", 1);
//	printf("ft = %d | p = %d\n\n", ft, p);
//
//	ft = ft_printf("ft |%#x|\n", 1);
//	p = printf("p  |%#x|\n", 1);
//	printf("ft = %d | p = %d\n", ft, p);
//
//	ft_printf("ft |%#10x|\n", 1);
//	printf("p  |%#10x|\n", 1);
//
//	return (0);
//}	
//
///* struct management  *********************************/
//
//int test_struct(void)
//{
//	int nb = 0;
//		int u = INT_MIN;
//		int p;
//		int ft;
//
//
//		printf("p  |%0--+20u|\n", u);	
//		printf("p  |%lld|\n", nb);
//		ft_printf("ft |%lld|\n", nb);
//
//		printf("p  |%0 20.15%|\n", "hello");
//		ft_printf("ft |%0 20.15%|\n", "hello");
//
//		printf("p  |%.0llo| hello\n", nb);	
//		ft_printf("ft |%.0llo| hello\n\n", nb);	
//	
//		printf("p  |%0--+'15llo|\n", nb);	
//		ft_printf("ft |%0--+'15llo|\n\n", nb);	
//	
//		printf("p  |%-0     +15.10llo|\n", nb);	
//		ft_printf("ft |%-0    +15.10llo|\n\n", nb);	
//	
//		printf("p  |%#0     +15.10llo|\n", nb);	
//	  ft_printf("ft |%#0    +15.10llo|\n\n", nb);	
//	
//		printf("p  |%+20.15llo|\n", nb);	
//		ft_printf("ft |%+20.15llo|\n\n", nb);	
//	
//	printf("p = %d ", printf("%03.d\n", nb));	
//	printf("ft = %d ", ft_printf("%03.d\n", nb));
//
//
//
//
//	//	printf("p  |%18.2d|\n", nb);	
//	//	ft_printf("ft |%18.2d|\n\n", nb);	
//	//
//	//	printf("p  |%18.17d|\n", nb);	
//	//	ft_printf("ft |%18.17d|\n\n", nb);	
//	//
//	//	printf("p  |%18.23d|\n", nb);	
//	//	ft_printf("ft |%18.23d|\n\n", nb);	
//	//	
//	//	printf("p  |%18.18d|\n", nb);	
//	//	ft_printf("ft |%18.18d|\n\n", nb);	
//	//	printf("p  |%018d|\n", nb);	
//	//	ft_printf("ft |%018d|\n\n", nb);	
//	//
//	//
//	//	printf("p  |%-18.23d|\n", nb);	
//	//	ft_printf("ft |%-18.23d|\n\n", nb);	
//	//	
//	//	printf("p  |%-18.18d|\n", nb);	
//	//	ft_printf("ft |%-18.18d|\n\n", nb);	
//	//
//	//	printf("p  |%018d|\n", nb);	
//	//	ft_printf("ft |%018d|\n\n", nb);	
//	//
//	//	printf("p  |%18.2d|\n", nb);	
//	//	ft_printf("ft |%18.2d|\n\n", nb);	
//	//
//	//	printf("p  |%18.17d|\n", nb);	
//	//	ft_printf("ft |%18.17d|\n\n", nb);	
//	//
//	//	printf("p  |%18.23d|\n", nb);	
//	//	ft_printf("ft |%18.23d|\n\n", nb);	
//	//	
//	//	printf("p  |%18.18d|\n", nb);	
//	//	ft_printf("ft |%18.18d|\n\n", nb);	
//	//
//	//
//	//	ft = ft_printf("ft |%018d| = %d digits | ", nb, count_digits(nb));	
//	//	printf("ft = %d\n", ft);
//	//	p = printf("p  |%018d| = %d digits | ", nb, count_digits(nb));	
//	//	printf("p = %d\n", p);
//	//
//	//	ft = ft_printf("ft |%18.1d| = %d digits | ", nb, count_digits(nb));	
//	//	printf("ft = %d\n", ft);
//	//	p = printf("p  |%18.1d| = %d digits | ", nb, count_digits(nb));	
//	//	printf("p = %d\n", p);
//	////	ft_printf("Flags shipping %##-- 000 ++11.21lld\n", 999);
//	////	ft_printf("Flags shipping  %##-- 000 ++11.21lld deuxieme flag %----------------0.999s ici \n");
//	//	//	printf("Flags shipping  %##-- 000 ++11.21d\n");
//	//	//	printf("Flags shipping  %##-- 000 +@+11.21d\n");
//	//
//	//	printf("p  |%-18.2d|\n", nb);	
//	//	ft_printf("ft |%-18.2d|\n\n", nb);	
//	//	printf("p  |%-+10.6d|\n", nb);	
//	//	ft_printf("ft |%-+10.6d|\n\n", nb);	
//	//
//	//	printf("p  |% 10.6d|\n", nb);	
//	//	ft_printf("ft |% 10.6d|\n\n", nb);	
//	return (0);	
//}
//
///* Perf write vs printf *********************************/
//
//int test_perf(void)
//{
//	//int i;
//
//	char s[] = "123456";	
//	printf("\n len = %d\n", ft_printf(s));
//
//	puts("Hello");
//	puts("World");
//
//
//	//	for( i = 0; i < 3000000; i++ ) 
//	//		    printf( "Test string\n" );
//
//	//	for( i = 0; i < 30000000; i++ ) 
//	//	    write(1, "Test string\n", strlen( "Test string\n" ));
//
//	//	for( i = 0; i < 3000000; i++ ) 
//	//		    ft_putstr("Test string\n");
//
//	return (0);	
//}
//
//
///* ft_printf *********************************/
//
//int test_printf(void)
//{
//	//	int count;
//	int nb;
//
//	printf("|%9.3s|\n", "abcdef");	
//	printf("|%-9.3s|\n", "abcdef");	
//	printf("|%.9d|\n", 12345678);
//	printf("|hello ! %n|\n", &nb);
//	printf("|%'d|\n", 9999999);
//	printf("|%#x|\n", 1);
//	printf("|%x|\n", 1235);
//	printf("|%#x|\n", 1235);
//	printf("|%#010x|\n", 1235);
//	printf("|%o|\n", 10);
//	printf("|%#o|\n", 10);
//	printf("|%#.1o|\n", 10);
//	printf("|%#-30.23lx|\n", 922337203685477580);
//	printf("|%+025.23ld|\n", 922337203685477580);
//
//	printf("Hello %1$s, how are you %1$s ?\n", "Bob");
//	ft_putstr("hello " "comment ca va?\n");
//	printf("Bonjour" " comment " "allez vous?"); 
//	printf(" |%0#10x| \n", 7); 
//	printf(" |%010d| \n", 7);
//	printf(" |%.15s| \n", "1234567890");
//	printf("Zero |% d|\n", 7);
//	//	count = printf("Bonjour %s, il fait %dC\n", "Benjamin", 17);
//	//	printf("ft ret = %d\n", count); 
//	//	ft_printf("Bonjour %s, il fait %dC%d\n", "Benjamin", 17, '*');
//
//	//	_ASSERT((int)memchr(s1, '@', sizeof(s1)), (int)ft_memchr(s1, '@', sizeof(s1)), normal usage. );
//
//	return (0);
//}

/* TEST_RUNNER *********************************/

int main(void)
{
	_BEGIN_TEST;
	//	_RUN(test_printf);
	//	_RUN(test_perf);
	//	_RUN(test_struct);
	//	_RUN(test_o);
	_RUN(test_c);

	return (0);
}
