#include<stdio.h>
#define size  100
int valid(char s[])
{
	char ch;
	int top=-1,i,a[size];
	for(i=0;s[i]!='\0';i++)
	{
		ch=s[i];
		if(ch=='('||ch=='{'||ch=='[')
		a[++top]=ch;
		else if(ch==')'||ch=='}'||ch==']')
		{
			if(top==-1)
			return 0;
			char tope=a[--top];
			if(ch==')'&&tope!='('||ch=='}'&&tope!='{'||ch==']'&&tope!='[')
			return 0;
		}
		
	}
	return top-1;
}
int main()
{
	char s[100];
	scanf("%s",&s);
	printf("%s\n",valid(s)?"true":"false");
}
