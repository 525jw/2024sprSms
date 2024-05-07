#include <stdio.h>
#include <string.h>

void reverse(char *str){
    int left=0,right=0;
    while(str[right]!='\0') right++;
    right--;
    while(left<right){
        char temp=str[left];
        str[left]=str[right];
        str[right]=temp;
        left++; right--;
    }
}

int main()
{
    char str[100];
    gets(str);
    reverse(str);
    puts(str);
}