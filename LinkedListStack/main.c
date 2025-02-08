#include "LLS.h"
#include<stdio.h>

//ps1935

int	main()
{
	int	N;
	char	*format;
	float	*num_box;
	int	i;

	LinkedListStack *LLS = NULL;
	Node	*newNode;

	format = (char*)malloc(sizeof(char) * 101);

	scanf("%d", &N);
	num_box = (float*)malloc(sizeof(float) * N);
	scanf("%s", format);
	i = 0;
	while (i < N)
	{
		scanf("%f", &num_box[i]);
		printf("numbox[%d] : %f\n",i ,num_box[i]);
		i++;
	}
	LLS_Create_Stack(&LLS);
	while (*format != '\0')
	{
		if (*format != '*' && *format != '/' && *format != '+' && *format != '-')
		{
			float data_to_node = num_box[(int)(*format) - 65];
			newNode = LLS_Create_Node(data_to_node);
			LLS_Push(LLS, newNode);
			printf("MET NUM !\n*format = %c\nnum_box data :%f\n", *format, data_to_node);
		}
		else
		{
			float R_num = LLS_Pop(LLS)->data;
			float L_num = LLS_Pop(LLS)->data;
			float result_num;
			if (*format == '*')
			{
				result_num = L_num * R_num;
				newNode = LLS_Create_Node(result_num);
				LLS_Push(LLS, newNode);
			}
			else if (*format == '/')
			{
				result_num = L_num / R_num;
				newNode = LLS_Create_Node(result_num);
				LLS_Push(LLS, newNode);
			}
			else if (*format == '+')
			{
				result_num = L_num + R_num;
				newNode = LLS_Create_Node(result_num);
				LLS_Push(LLS, newNode);
			}
			else if (*format == '-')
			{
				result_num = L_num - R_num;
				newNode = LLS_Create_Node(result_num);
				LLS_Push(LLS, newNode);
			}
		}
		format++;
	}
	printf("%.2f", LLS_Pop(LLS)->data);
}
