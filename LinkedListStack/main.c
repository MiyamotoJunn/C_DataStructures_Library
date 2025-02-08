#include "StringLLS.h"
#include<stdio.h>

//ps1918

int	Is_High(char top, char tokken)
{
	int	top_score;
	int	tokken_score;

	if (top == '(')
		return (0);
	if (top == '*' || top == '/')
		top_score = 2;
	else
		top_score = 1;
	if (tokken == '*' || tokken == '/')
		tokken_score = 2;
	else
		tokken_score = 1;
	return (top_score >= tokken_score);
}

char	*infix_to_postfix(char *infix)
{
	int	i;
	int	j;
	char	*postfix;
	char	*box;
	LinkedListStack *LLS = NULL;
	Node	*newNode;

	box = (char *)malloc(sizeof(char) + 1);
	LLS_Create_Stack(&LLS);
	postfix = (char*)malloc(sizeof(char) * 101);
	i = 0;
	j = 0;
	box[1] = '\0';
	while (infix[i] != '\0')
	{
		if (infix[i] != '(' && infix[i] != ')' && infix[i] != '*'
				&& infix[i] != '/' && infix[i] != '+' && infix[i] != '-')
		{
			postfix[j] = infix[i];
			j++;
		}
		else
		{
			if (infix[i] == '(')
			{
				box[0] = infix[i];
				newNode = LLS_Create_Node(box);
				LLS_Push(LLS, newNode);
			}
			else if (infix[i] != ')')
			{
				postfix[j] = ' ';
				j++;
				if (LLS_Is_Empty(LLS))
				{
					box[0] = infix[i];
					newNode = LLS_Create_Node(box);
					LLS_Push(LLS, newNode);
				}
				else
				{
					while (Is_High(LLS->top->data[0], infix[i]))
					{
						postfix[j] = LLS_Pop(LLS)->data[0];
						j++;
						postfix[j] = ' ';
						j++;
						if (LLS_Is_Empty(LLS))
							break;
					}
					box[0] = infix[i];
					newNode = LLS_Create_Node(box);
					LLS_Push(LLS, newNode);
				}
			}
			else if (infix[i] == ')')
			{
				while (LLS_Top(LLS)->data[0] != '(')
				{
					postfix[j] = ' ';
					j++;
					postfix[j] = LLS_Pop(LLS)->data[0];
					j++;
				}
				LLS_Pop(LLS);
			}
		}
		i++;
	}
	while (! LLS_Is_Empty(LLS))
	{
		postfix[j] = ' ';
		j++;
		postfix[j] = LLS_Pop(LLS)->data[0];
		j++;
	}
	postfix[j] = '\0';
	return (postfix);
}

int	main()
{
	char	*infix = (char*)malloc(sizeof(char) * 101);
	char	*postfix;

	printf("Enter infix : ");
	scanf("%s", infix);
	printf("infix : %s\n", infix);
	postfix = infix_to_postfix(infix);
	printf("postfix : %s\n", postfix);

}
