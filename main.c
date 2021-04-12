#include "includes/libasm.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", _ft_strdup(""));

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

