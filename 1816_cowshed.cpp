#include <stdio.h>

int max1=0;


int cmax(int r[], int t){ //배열에서 가장 큰 수를 찾고 찾을 수를 반환
	int max=0;
	for(int i=0;i<t;i++){
		if(r[i]>max){
			max=r[i];
			max1=i;
		}
	}
	return max;
}
int main(void){
	int temp;
	int r[1000]={0,};
	int arr[1000]={0,};
	int M,S,C,a=0;
	int result=0;
	int e;
	int j=0;
	scanf("%d %d %d",&M,&S,&C);
	if(M>=C){//M이 C와 같거나 클 경우
		result=C;
	}
	else{
		for(int i=0;i<C;i++){
			scanf("%d",&e);
			arr[i]=e;
		}
		for(int i=C-1;i>0;i--){//버블정렬 시작
			for(int j=0;j<i;j++){
				if(arr[j]>arr[j+1]){
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}	//버블정렬 끝
		result=arr[C-1]-arr[0]+1;//판자하나로 막을때 최소 길이(규칙)
		for(int i=0;i<C;i++){
			r[i]=arr[i+1]-arr[i]-1;
		}
		while(1){
			if(j==M-1){
				break;
			}
			a=cmax(r,C);//r에서 가장 큰 수 찾는 함수
			result-=a;
			r[max1]=0;//한번 사용한 수는 0으로
			j++;
		}
	}
	printf("%d",result);
	return 0;
}
