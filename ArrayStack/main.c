#include "AS.h"
#include<stdio.h>

//ps9012

int	is_VPS(char *str)
{
	int	len;
	int	i;

	len = 0;
	while (str[len] != '\0')
		len++;
	ArrayStack *AS;
	AS = NULL;
	AS_Create_Stack(&AS, len);
	i = 0;
	while (i < len)
	{
		if (str[i] == '(')
			AS_Push(AS, 1);
		else if (str[i] == ')')
		{
			if (AS_Get_Size(AS) == 0)
				return (0);
			else
				AS_Pop(AS);
		}
		i++;
	}
	if (AS_Get_Size(AS) == 0)
		return (1);
	else
		return (0);
}

int	main()
{
	int	t;
	int	i;
	char	**cases;

	scanf("%d", &t);
	i = 0;
	cases = (char **)malloc(sizeof(char*) * t);
	while (i < t)
	{
		cases[i] =(char*)malloc(sizeof(char) * 51);
		scanf("%s", cases[i]);
		if (is_VPS(cases[i]))
			printf("YES\n");
		else
			printf("NO\n");
		i++;
	}
}

