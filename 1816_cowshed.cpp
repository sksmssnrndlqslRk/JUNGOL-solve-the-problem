#include <stdio.h>

int max1=0;


int cmax(int r[], int t){ //�迭���� ���� ū ���� ã�� ã�� ���� ��ȯ
	int max=0;
	for(int i=0;i<t;i++){
		if(r[i]>max){
			max=r[i];
			max1=i;
		}
	}
	return max;
}//hello my name is leegeonhui
int main(void){
	int temp;
	int r[1000]={0,};
	int arr[1000]={0,};
	int M,S,C,a=0;
	int result=0;
	int e;
	int j=0;
	scanf("%d %d %d",&M,&S,&C);
	if(M>=C){//M�� C�� ���ų� Ŭ ���
		result=C;
	}
	else{
		for(int i=0;i<C;i++){
			scanf("%d",&e);
			arr[i]=e;
		}
		for(int i=C-1;i>0;i--){//�������� ����
			for(int j=0;j<i;j++){
				if(arr[j]>arr[j+1]){
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}	//�������� ��
		result=arr[C-1]-arr[0]+1;//�����ϳ��� ������ �ּ� ����(��Ģ)
		for(int i=0;i<C;i++){
			r[i]=arr[i+1]-arr[i]-1;
		}
		while(1){
			if(j==M-1){
				break;
			}
			a=cmax(r,C);//r���� ���� ū �� ã�� �Լ�
			result-=a;
			r[max1]=0;//�ѹ� ����� ���� 0����
			j++;
		}
	}
	printf("%d",result);
	return 0;
}
