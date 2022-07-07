#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char name[50];
	int kor;
	int math;
	int eng;
}student;

void main() {
	FILE* f1, * f2;
	student s[50] = { 0 };
	f1 = fopen("score.txt", "r");
	for(int i = 0; i < 5; i++)
		fscanf(f1, "%s %d %d %d", s[i].name, &s[i].kor, &s[i].eng, &s[i].math);
	fclose(f1);
	f2 = fopen("result.txt", "w");
	for (int i = 0; i < 5; i++) {
		printf("%s %d %d %d\n", s[i].name, s[i].kor, s[i].eng, s[i].math);
		fprintf(f2, "%s %d %d %d\n", s[i].name, s[i].kor, s[i].eng, s[i].math);
	}
	fclose(f2);
}
