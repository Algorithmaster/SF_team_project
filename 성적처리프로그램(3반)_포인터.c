#pragma warning(disable:4996)
#include<stdio.h>

int main(void)
{
	//배열 선언 
	char name[3][3][10] = {0};
	int score[3][3][4] = {0};
	float avg[3][3] = {0};
	int i, j, k;
	
	//포인터 선언 
	char *p_name;
	int *p_score;
	float *p_avg; 
	
	//포인터 주소값을 1차원으로 표현 
	p_name = **name;
	p_score = **score;
	p_avg = *avg;
	
	for(i=0; i<3; i++)
	{
		printf("Class입니다..(이름/국어/영어/수학) \n");
		
		for(j=0; j<3; j++)
		{
			//이름 p+0 p+10 p+20 p+30...p+80 표현 
			printf("이름 : ") ;
			scanf("%s", p_name+10*(3*i+j));
			
			for(k=0; k<3; k++)
			{
				//점수 p+0 p+1 p+2 p+3 p+4 .... p+35
				scanf("%d", p_score+12*i+4*j+k);
				
				//총점 p+3 p+7 p+11 ... p+35
				*(p_score+12*i+4*j+3) += *(p_score+12*i+4*j+k);
			}
			//평균 p+3 	   =    p+0 + p+1 + p+2 
			*(p_avg+3*i+j) = *(p_score+12*i+4*j+3)/3.f;
		}
	}
	
	for(i=0; i<3; i++)
	{
		printf("==========================================\n");
		printf("Class입니다..\n");
		
		for(j=0; j<3; j++)
		{
			printf("이름 : %s\n", p_name+10*(3*i+j));
			
			printf("국\t영\t수\t총점\t평균\n");
			printf("\n");
			for(k=0; k<4; k++)
			{
				//점수 값으로 표현 p0 p1 p2 p4.... 
				printf("%d\t", *(p_score+12*i+4*j+k));
			}
			// 평균 값으로 표현 p+3 p+7 ... p+36 
			printf("%.2f\n", *(p_avg+3*i+j));
			printf("------------------------------------------\n");
		}	
		printf("==========================================\n");
	}
	
}
