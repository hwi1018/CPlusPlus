// CplusApp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
	char name[20];
	int age;
	double gpa;
}STUDENT;

int main()
{
	STUDENT* stu;

	stu = (STUDENT*)malloc(sizeof(STUDENT));

	if (stu == NULL)
	{
		printf("동적할당 실패");
		exit(1);
	}

	strcpy_s(stu->name, sizeof(stu->name), "Byeonghwi");
	stu->age = 28;
	stu->gpa = 77.0;

	printf("%s %d %.2lf\n", stu->name, stu->age, stu->gpa);

	free(stu);
	stu = NULL;

	return 0;
}
