#include<stdio.h>
#include<string.h>
int main()
{
	char haystack[100],needle[100];
	scanf("%s",&haystack);
	scanf("%s",&needle);
	int i=0,found=0;
	int a=strlen(haystack);
	int b=strlen(needle);
	for(i=0;i<=a-b;i++)
	{
		if(strncmp(haystack+i,needle,b)==0)
		{
			printf("occurence of %s in %s at %d\n",haystack,needle,i);
			found=1;
		}
	}
		if(!found)
		printf("%s is not found in %s ",haystack,needle);
		return 0;
}
