#pragma warning(disable:4996)
#include<stdio.h>

int main(void)
{
	//�迭 ���� 
	char name[3][3][10] = {0};
	int score[3][3][4] = {0};
	float avg[3][3] = {0};
	int i, j, k;
	
	//������ ���� 
	char *p_name;
	int *p_score;
	float *p_avg; 
	
	//������ �ּҰ��� 1�������� ǥ�� 
	p_name = **name;
	p_score = **score;
	p_avg = *avg;
	
	for(i=0; i<3; i++)
	{
		printf("Class�Դϴ�..(�̸�/����/����/����) \n");
		
		for(j=0; j<3; j++)
		{
			//�̸� p+0 p+10 p+20 p+30...p+80 ǥ�� 
			printf("�̸� : ") ;
			scanf("%s", p_name+10*(3*i+j));
			
			for(k=0; k<3; k++)
			{
				//���� p+0 p+1 p+2 p+3 p+4 .... p+35
				scanf("%d", p_score+12*i+4*j+k);
				
				//���� p+3 p+7 p+11 ... p+35
				*(p_score+12*i+4*j+3) += *(p_score+12*i+4*j+k);
			}
			//��� p+3 	   =    p+0 + p+1 + p+2 
			*(p_avg+3*i+j) = *(p_score+12*i+4*j+3)/3.f;
		}
	}
	
	for(i=0; i<3; i++)
	{
		printf("==========================================\n");
		printf("Class�Դϴ�..\n");
		
		for(j=0; j<3; j++)
		{
			printf("�̸� : %s\n", p_name+10*(3*i+j));
			
			printf("��\t��\t��\t����\t���\n");
			printf("\n");
			for(k=0; k<4; k++)
			{
				//���� ������ ǥ�� p0 p1 p2 p4.... 
				printf("%d\t", *(p_score+12*i+4*j+k));
			}
			// ��� ������ ǥ�� p+3 p+7 ... p+36 
			printf("%.2f\n", *(p_avg+3*i+j));
			printf("------------------------------------------\n");
		}	
		printf("==========================================\n");
	}
	
}
