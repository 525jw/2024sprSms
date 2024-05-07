#include <stdio.h>
#include <string.h>
void bubblesort(int n, char (*str)[20],int* cnt){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(cnt[j]<cnt[j+1]){
                int temp=cnt[j]; cnt[j]=cnt[j+1]; cnt[j+1]=temp;
                char t[25];
                strcpy(t,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],t);
            }
            else if(cnt[j]==cnt[j+1]){
                if(strcmp(str[j],str[j+1])>0){
                    char t[25];
                    strcpy(t,str[j]);
                    strcpy(str[j],str[j+1]);
                    strcpy(str[j+1],t);
                }
            }
        }
    }
}
int main(){
    int n;
    char str[100][20];
    int idx=0;
    int cnt[100]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char inp[20];
        scanf("%s",inp);
		
        //empty -> insert
		if(idx==0){
			strcpy(str[idx],inp);
			cnt[idx]++;
            idx++;
		}
		else{
            // no inp string in str -> insert, if not only cnt++
            int chk=1;
        	for(int j=0;j<idx;j++){
            	if(strcmp(inp,str[j])==0) {
                    cnt[j]++;
                    chk=0;
                    break;
                }
       		}
            if(chk){
                strcpy(str[idx],inp);
                cnt[idx]++;
                idx++;
            }
    	}
    }

    bubblesort(idx,str,cnt);

    for(int i=0;i<idx;i++){
        printf("%d %s",cnt[i],str[i]);
        if(i<idx-1) printf("\n");
    }

    return 0;
}