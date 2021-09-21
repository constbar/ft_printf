#include "libftprintf.h"

int main()
{
	char p = '%';
	char c = 'r';
	ft_printf("%% sign printing: %c\n", p);
	ft_printf("char printing: %c\n", c);
	ft_printf("using width flag: %5.c\n", c);
	ft_printf("\n");

	char *str = "hola todos!";
	ft_printf("str printing\t\t: %s\n", str);
	ft_printf("width 6 and precision 4\t: %6.4s\n", str);
	ft_printf("\n");

	ft_printf("memory address of c: %p\n", &c);
	ft_printf("\n");

	int num = -100;
	ft_printf("simple int printing via d: %d\n", num);
	ft_printf("simple int printing via i: %i\n", num);
	ft_printf("with precision 6: %.6d\n", num);
	ft_printf("with width 10: %10d\n", num);
	ft_printf("with - flag: %-10.d\n", num);
	ft_printf("width 8 and precision 6: %8.6d\n", num);
	ft_printf("\n");

	unsigned int i = 4294967295;
	ft_printf("unsigned int printing: %u\n", i);
	ft_printf("\n");

	int n = 16118;
	ft_printf("hex printing: %x\n", n);

	return 0;
}