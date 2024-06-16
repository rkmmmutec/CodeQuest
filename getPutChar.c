#include <stdio.h>

int main()
{

	char c;

	printf("Enter the character : ");
	c=getchar();
	printf("Entered String : ");
	putchar(c);

	char b[30];

	printf("\n Enter array of characters : ");

	for(int i=0 ; i<30 ;i++)
	 b[i]=getchar();

	for(int j=0;j<30;j++)
	 putchar(b[j]);



return 0;
}
