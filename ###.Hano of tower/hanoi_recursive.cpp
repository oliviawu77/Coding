#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int tmp=0;
int hanoi(int n,char A,char B,char C){

	int counter =0;
	if(n==0) printf("Error");
	if(n==1){
		printf("%c -> %c\n",A,C);
		tmp+=1;
	}
	else{
		
		hanoi(n-1,A,C,B);
		printf("%c -> %c\n",A,C);
		hanoi(n-1,B,A,C);
		counter+=1;
		tmp=tmp+counter;
	}
	return tmp;
}

int main(){
	int n;
	char a='A', b='B', c='C';
	while(-1){
		printf("Hanoi num = ");
		scanf("%d",&n);
		printf("Hanoi(%d) = %d\n",n,hanoi(n,a,b,c));
		tmp = 0;
	}
}