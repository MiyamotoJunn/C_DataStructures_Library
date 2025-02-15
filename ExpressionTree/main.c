#include "ET.h"
#include <string.h>
int	main()
{
	Node	*p_et;
	char	*str = (char*)malloc(sizeof(char) * 10);
	strcpy(str, "73-61++");
	ET_Build_ET(str, &p_et);
	ET_Inorder_Print(p_et);
	printf("\n");
	printf("%f", ET_Evaluate(p_et));
}
