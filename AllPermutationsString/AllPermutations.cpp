#include <bits/stdc++.h>
using namespace std;
void swap(char *c,char *d)
{
//	cout<<*c<<" "<<*d<<endl;
	char  temp;
	temp=*c;
	*c=*d;
	*d=temp;
//	cout<<*c<<" "<<*d<<endl;
}
void FindAllPermutations(char *s,int l,int r)
{
	if(l==r)
	cout<<s<<endl;
	for(int i=l;i<=r;i++)
	{
		swap(s+l,s+i);
		FindAllPermutations(s,l+1,r);
		swap(s+l,s+i);
	}
}
int main()
{
	char s[100];
	cin>>s;
	FindAllPermutations(s,0,strlen(s)-1);
	return 0;
}