/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:11:00 by bduron            #+#    #+#             */
/*   Updated: 2016/12/16 09:10:46 by bduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
#define _RUN(function_name)\
	printf( YEL "[%s] \n" RESET /*"\n"*/, #function_name);\
	function_name();\
	printf("\n");

#define _ASSERT(x,y,m)\
	do { int arg1 = x; int arg2 = y;\
	if(arg1 == arg2)\
		printf("[" GRN "OK" RESET "]" " %s[" CYN "%d" RESET "] == %s[" CYN "%d" RESET "]\n", #x, arg1, #y, arg2); \
   	else\
		printf("[" RED "XX" RESET "] %s[" CYN "%d" RESET "] == %s[" CYN "%d" RESET "]\nError: %s (Line: %d File: %s)\n", #x, arg1, #y, arg2, #m, __LINE__, __FILE__);}  \
	while (0)

#define _BEGIN_TEST\
	printf("\n[" MAG "--- RUNNING TESTS ---" RESET "]\n\n") 





// Usage : _ASSERT(function_x, function_y, error message);

/* EXEMPLE D'UTILISATION 

	void test_memcmp(void)
   	{
		_ASSERT(ft_memcmp(s0, s1, 13), memcmp(s0, s1, 18), int_max unsupported. );
		_ASSERT(ft_memcmp(s0, s1, 13), memcmp(s0, s1, 13),);	
	}
	
	int main(void)	
	{
		run_test(test_memcmp);
	}

*/
