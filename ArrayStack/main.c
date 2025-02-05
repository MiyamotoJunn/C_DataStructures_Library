#include "AS.h"
#include<stdio.h>

//ps10828

int	is_push(char *str)
{
	int i;
	char push[5] = "push";

	i = 0;
	while (push[i] != '\0')
	{
		if (push[i] == str[i])
			i++;
		else
			break;
	}
	if (i == 4)
		return (1);
	else
		return (0);
}	

int	is_pop(char *str)
{
	int i;
	char pop[4] = "pop";

	i = 0;
	while (pop[i] != '\0')
	{
		if (pop[i] == str[i])
			i++;
		else
			break;
	}
	if (i == 3)
		return (1);
	else
		return (0);
}

int	is_top(char *str)
{
	int i;
	char top[4] = "top";

	i = 0;
	while (top[i] != '\0')
	{
		if (top[i] == str[i])
			i++;
		else
			break;
	}
	if (i == 3)
		return (1);
	else
		return (0);
}

int	is_size(char *str)
{
	int i;
	char size[5] = "size";

	i = 0;
	while (size[i] != '\0')
	{
		if (size[i] == str[i])
			i++;
		else
			break;
	}
	if (i == 4)
		return (1);
	else
		return (0);
}

int	is_empty(char *str)
{
	int i;
	char empty[6] = "empty";

	i = 0;
	while (empty[i] != '\0')
	{
		if (empty[i] == str[i])
			i++;
		else
			break;
	}
	if (i == 5)
		return (1);
	else
		return (0);
}

int	main()
{
	int	line;
	int	i;
	ArrayStack *AS;
	char	*command;
	AS_Type	data;

	AS = NULL;
	command = (char*)malloc(sizeof(char) * 5);


	scanf ("%d", &line);
	AS_Create_Stack(&AS, line);
	i = 0;
	while (i < line)
	{
		scanf("%5s", command);
		if (is_push(command))
		{
			scanf("%d", &data);
			AS_Push(AS, data);
		}
		else if (is_pop(command))
			printf("%d\n", AS_Pop(AS));
		else if (is_top(command))
			printf("%d\n", AS_Top(AS));
		else if (is_size(command))
			printf("%d\n", AS_Get_Size(AS));
		else if (is_empty(command))
			printf("%d\n", AS_Is_Empty(AS));

		i++;
	}
}

