#pragma warning (disable:4996)

#ifndef __DATA_MODULE_H__
#define __DATA_MODULE_H__

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdio.h>

#include "Info.h"
#include "Cursor.h"

typedef struct Record {
	char name[16];
	int time;
	int score;
	char grade[16];
}Record;

int getLife();
int SetCurrentData(int time_limit, int time, int score, int life);
void ResetData();
char* getGrade(int score);
void setRecords(int time, int score);
void PrintRecords();



int SetCurrentScore(int limit_time, int left_time, int score, int coin) {
	//�ð� ������ + ���� ������ �߰�
	score +=
		((limit_time - left_time) < 0 ? 0 : limit_time - left_time) * 100 +
		coin * 5000;
	//1�ð� �̳��� Ŭ���� �� ������ (���� �߰�)

	return score;
}

char* getGrade(int score) {
	char* tmp = (char*)malloc(sizeof(char) * 11);
	if (score < 50000)
		strcpy(tmp, "D");
	else if (50000<=score && score < 100000)
		strcpy(tmp, "C");
	else if (100000 <= score && score < 200000)
		strcpy(tmp, "B");
	else if (200000 <= score && score < 300000)
		strcpy(tmp, "A");
	else if (300000 <= score && score < 400000)
		strcpy(tmp, "S");
	else if (400000 <= score && score < 500000)
		strcpy(tmp, "SS");
	else if (500000 <= score)
		strcpy(tmp, "SSS");

	return tmp;
}

void setRecords(int time, int score) {

	int lines = 0;
	char tmp[100];

	char name[100] = " ";
	char* grade = getGrade(score);

	SetCurrentCursorPos(0, 4);
	textcolor(WHITE);

	printf("\t\t\t\t\t\t\t");
	printf("��� ������ ����Ͻ� �� �����մϴ�!\n");
	printf("\n");
	printf("\n");
	Sleep(1000);

	printf("\t\t\t\t\t\t\t");
	printf("�� ����� ������ ȯ���Ͽ� ���� ������ �ֵ��̷μ� ���� �̾�� �� ���� ���Դϴ�.\n");
	printf("\n");
	printf("\n");
	Sleep(1000);

	printf("\t\t\t\t\t\t\t");
	printf("\'�����ο� ȯ���ڵ�\'�� �ö� �̸��� �Է����ּ���");
	textcolor(RED);
	printf(" (��ĭ ���� �����ڷ� 7�� �̳�)\n");
	printf("\n");
	printf("\n");
	Sleep(1000);

	textcolor(YELLOW);
	printf("\t\t\t\t\t\t\t");
	printf("�̸� : ");

	int cnt = 0; //�̸� �Է� Ƚ��

	int flag = 0;	//�̸� �Է� �� ������ �Ǵ�
	gets(name);
	for (int i = 0; i < strlen(name); i++) {
		if (!(('A' <= name[i] && name[i] <= 'Z') ||	//�����ڰ� �ƴϸ� �Է� X
			('a' <= name[i] && name[i] <= 'z'))) {
			flag = 1;
			break;
		}
	}
	cnt++;

	while (strlen(name) > 7 || flag == 1) {


		SetCurrentCursorPos(0, 16);
		printf("\t\t\t\t\t\t\t");
		textcolor(DarkYellow);
		printf("�����ڷ� ��ĭ ���� 7�� ���Ϸ� �Է����ֽʽÿ�! 5ȸ �Է� �ʰ��� ���Ƿ� �̸��� �Էµ˴ϴ�. (%dȸ ����)\n", 5-cnt);
		Sleep(100);

		SetCurrentCursorPos(0, 16);
		printf("\t\t\t\t\t\t\t");
		textcolor(RED);
		printf("�����ڷ� ��ĭ ���� 7�� ���Ϸ� �Է����ֽʽÿ�! 5ȸ �Է� �ʰ��� ���Ƿ� �̸��� �Էµ˴ϴ�. ");
		textcolor(SkyBlue);
		printf("(%dȸ ����)\n", 5-cnt);
		if (cnt >= 5) {			//5ȸ �Է� �ʰ���
			strcpy(name, "NONE");
			break;
		}


		SetCurrentCursorPos(0, 16+cnt*2);


		textcolor(YELLOW);
		printf("\t\t\t\t\t\t\t");
		printf("\t : ");
		gets(name);
		flag = 0;
		for (int i = 0; i < strlen(name); i++) {
			if (!(('A' <= name[i] && name[i] <= 'Z') ||
				('a' <= name[i] && name[i] <= 'z'))) {
				flag = 1;
				break;
			}
		}
		cnt++;
	}

	SetCurrentCursorPos(0, 16 + cnt * 2);

	textcolor(DarkYellow);
	printf("\n");
	printf("\t\t\t\t\t\t\t");
	printf("%s���� %02d:%02d:%02d���� %d�� ������ �� ����� ������ ȯ���ϰ� ���־����ϴ�!\n",
		name, time / 3600, time % 3600 / 60, time % 60, score);
	printf("\n");
	printf("\n");
	Sleep(500);

	printf("\t\t\t\t\t\t\t");
	printf("����� Ŭ���� ����� ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf(". ");
	Sleep(500);
	printf("%s�Դϴ�.\n", grade);
	printf("\n");
	printf("\n");
	Sleep(1000);

	printf("\t\t\t\t\t\t\t");
	if (strcmp(grade, "SSS") == 0) {
		printf("�����ϵ� �� ����� �ְ��� �� �غ� �Ǿ��ֽ��ϴ�\n");
	}
	else if (strcmp(grade, "SS") == 0) {
		printf("�̺��� �� �Ϻ��ϱ�� ����ϴ�. �ְ�����\n");
	}
	else if (strcmp(grade, "S") == 0) {
		printf("�� ����� �������� ���� ���˴ϴ�. \n");
	}
	else if (strcmp(grade, "A") == 0) {
		printf("�ɱ游 ������ �� �����ϴ�!\n");
	}
	else if (strcmp(grade, "B") == 0) {
		printf("������ ���� ���� ����غ� �� �ְڱ���\n");
	}
	else if (strcmp(grade, "C") == 0) {
		printf("ȯ����Ų �� ��𿡿� :)\n");
	}
	Sleep(2000);

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\t\t\t");
	textcolor(DarkGray);
	printf("��� �� ���� ����ȭ������ ���ư��ϴ�...\n");
	Sleep(3000);

	FILE* fp;
	fp = fopen("data/AllRecord.txt", "a");
	if (fp == NULL)
		printf("AllRecord ������ �� �� �����ϴ�");

	fprintf(fp, "%s %d %d %s\n", name, time, score, grade);

	fclose(fp);


	return;
}



void PrintRecords() {
	FILE* fp;
	fp = fopen("data/AllRecord.txt", "r");
	if (fp == NULL)
		printf("AllRecord������ �� �� �����ϴ�");

	int lines = 0;
	char tmp[500];

	fgets(tmp, sizeof(tmp), fp);
	lines++;
	fgets(tmp, sizeof(tmp), fp);
	while (!feof(fp)) {
		lines++;
		fgets(tmp, sizeof(tmp), fp);
	}
	//printf("lines : %d\n", lines);

	Record* records = (Record*)malloc(sizeof(Record) * lines);
	char name[10]; // ���ڿ��� ������ �迭. ���̴� ����� ��ƾ� �մϴ�.
	int time, score; // ������ ������ ����
	char grade[10]; // ���ڸ� ������ ����

	fseek(fp, 0, SEEK_SET);
	fgets(tmp, sizeof(tmp), fp);	//ó�� �� �� �Ѿ�� (��� ����)
	int cnt = 1;	//�� ��° �ٺ��� ����

	while (cnt < lines && cnt < 11) {
		if (fscanf(fp, "%s %d %d %s\n", name, &time, &score, &grade) != 4) {
			printf("���� �б� ����\n");
			fclose(fp);
			return;
		}
		strcpy(records[cnt].name, name);
		records[cnt].time = time;
		records[cnt].score = score;
		strcpy(records[cnt].grade, grade);

		cnt++;
	}
	fclose(fp);

	//������ ���� ����
	Record tmp_record;
	for (int i = 0; i < lines; i++) {
		for (int j = i + 1; j < lines; j++) {
			if (records[j].score > records[i].score) {
				tmp_record = records[i];
				records[i] = records[j];
				records[j] = tmp_record;
			}
			else if (records[j].score == records[i].score) {
				if (records[j].time < records[i].time) {
					tmp_record = records[i];
					records[i] = records[j];
					records[j] = tmp_record;
				}
			}
		}
	}

	textcolor(DarkYellow);
	printf("\t\t\t\t\t\t\t\t\tRank\tName\t\tTime\t\tScore\tGrade\n");
	textcolor(YELLOW);
	printf("\n");

	lines--; //���� ���� ������ ù �� �����ϸ� lines���� -1�� ���̹Ƿ�
	for (int i = 0; i < lines && i < 10; i++) {
		int hour = records[i].time / 3600;
		int minute = records[i].time % 3600 / 60;
		int second = records[i].time % 60;
		printf("\t\t\t\t\t\t\t\t\t%d\t%s\t\t%02d:%02d:%02d\t%d\t%s\n",
			i + 1, records[i].name, hour, minute, second, records[i].score, records[i].grade);
	}

	return;
}

#endif
