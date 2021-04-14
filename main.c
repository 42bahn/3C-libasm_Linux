#include "includes/libasm.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", _ft_atoi_base("      +--42", "0123456789"));
	printf("%d\n", _ft_atoi_base("      -+--ff", "0123456789abcdef"));
	printf("%d\n", _ft_atoi_base("      -+-ff", "0123456789abcdef"));
	printf("%d\n", _ft_atoi_base("      -+abc", "0123456789abcdef"));
	printf("%d\n", _ft_atoi_base("      ----456", "01234567"));
	printf("%d\n", _ft_atoi_base("      ++++123", "01234567"));
	printf("%d\n", _ft_atoi_base("      11111111", "01"));
	printf("%d\n", _ft_atoi_base("      00001111", "01"));
	printf("%d\n", _ft_atoi_base("      12345", "1a2b3c4d5e"));
	printf("%d\n", _ft_atoi_base("      12a4cb", "1a2b3c4d5e"));

	return (0);
}

/* Linux
   printf("%ld\n", _ft_strlen("abcde"));
   printf("\t(return : %ld)\n", _ft_write(1, "abcde", 5));
   ret = _ft_read(1, buf, 5);
   i = 0;
   while (i < ret)
   {
   if (buf[i] == '\n')
   buf[i] = '\0';
   i++;
   }
   printf("%s\t(return : %ld)\n", buf, ret);
   _ft_strcpy(buf, str);
   printf("%s\n", buf);

 */

/* MacOS
   printf("%ld\n", ft_strlen("abcde"));	
   printf("\t(return : %ld)\n", ft_write(1, "abcde", 5));
   ret = ft_read(1, buf, 5);
   i = 0;
   while (i < ret)
   {
   if (buf[i] == '\n')
   buf[i] = '\0';
   i++;
   }
   printf("%s\t(return : %ld)\n", buf, ret);
 */

