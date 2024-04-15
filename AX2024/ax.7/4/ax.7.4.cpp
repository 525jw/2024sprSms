#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=0;i<n;i++)
	{
		scanf(" %d %d",&arr[i].strt,&arr[i].end);
	}
	sort(0,n-1);
	int res=0;
	int chk=arr[0].strt;
	for(int i=0;i<n;i++)
	{
		if(arr[i].strt>=chk)
		{
			res++;
			chk=arr[i].end;
		}
	}
	printf("%d",res);
	return 0;
}