#ifndef __STAGE_UI__
#define __STAGE_UI__

#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "Data_Module.h"
#include "Info.h"
#include "Bgm.h"

#define BOARD_WIDTH 188
//좌표기준
#define BOARD_HEIGHT 49

void clearBoardUI() {
	SetCurrentCursorPos(0, 0);
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 189; j++) {
			printf(" ");
		}
		printf("\n");
	}
	SetCurrentCursorPos(0, 0);
}
void ShowKing(char King[10][10], int x, int y) {

	int posX = x;
	int posY = y;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {

			if (King[j][i] == 1) {
				SetCurrentCursorPos(posX+ i * 2, posY + j);
				obstacle(1);
			}

			if (King[j][i] == 2) {
				SetCurrentCursorPos(posX + i * 2, posY + j);
				obstacle(222);
			}

			if (King[j][i] == 4) {
				SetCurrentCursorPos(posX + i * 2, posY + j);
				obstacle(10);
			}
		}
}
void DeleteKing(int x, int y) {

	int posX = x;
	int posY = y;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			SetCurrentCursorPos(posX + i * 2, posY + j);
			printf("  ");
		}
}

void printFrameUI() {
	textcolor(RED);
	printf("  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼\n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("                                                                            \n");
	printf("																			\n");
	printf("																			\n");
	printf("                                                                            \n");
	printf("																			\n");
	printf("																			\n");
	printf("                                                                            \n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	textcolor(RED);
	printf("  ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n");
}

void printStartUI_Twin(int start) {
	if (start)
		Sleep(1000);
	textcolor(RED);
	//91칸, 좌표는 181
	printf("  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼\n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkYellow);
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("                                                                            \n");
	printf("																			\n");
	printf("																			\n");
	printf("                                                                            \n");
	printf("																			\n");
	printf("																			\n");
	printf("                                                                            \n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	printf("																			\n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	textcolor(RED);
	printf("  ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n");

	if (start)
		Sleep(1000);
	SetCurrentCursorPos(0, 8);
	textcolor(YELLOW);
	printf("                                        ■■■■■■■■■■  ■■            ■■            ■■  ■■■■■■■■■■  ■■■■          ■■\n");
	printf("                                        ■■■■■■■■■■  ■■          ■■■■          ■■  ■■■■■■■■■■  ■■■■          ■■\n");
	printf("                                                ■■          ■■          ■■■■          ■■          ■■          ■■ ■■         ■■\n");
	printf("                                                ■■           ■■        ■■  ■■        ■■           ■■          ■■  ■■        ■■\n");
	printf("                                                ■■           ■■        ■■  ■■        ■■           ■■          ■■   ■■       ■■\n");
	printf("                                                ■■            ■■      ■■    ■■      ■■            ■■          ■■    ■■      ■■\n");
	printf("                                                ■■            ■■      ■■    ■■      ■■            ■■          ■■     ■■     ■■\n");
	printf("                                                ■■             ■■    ■■      ■■    ■■             ■■          ■■      ■■    ■■\n");
	printf("                                                ■■             ■■    ■■      ■■    ■■             ■■          ■■       ■■   ■■\n");
	printf("                                                ■■              ■■  ■■        ■■  ■■              ■■          ■■        ■■  ■■\n");
	printf("                                                ■■                ■  ■            ■  ■        ■■■■■■■■■■  ■■         ■■ ■■\n");
	printf("                                                ■■                 ■■              ■■         ■■■■■■■■■■  ■■          ■■■■\n");
}
void printStartUI_Button(int start) {
	if (start)
		Sleep(1000);
	textcolor(GRAY);
	SetCurrentCursorPos(0, 26);
	printf("                                                                              시    작    하    기 \n");
	printf("																			\n");
	printf("																			\n");
	printf("                                                                                  도   움   말 \n");
	printf("																			\n");
	printf("																			\n");
	printf("                                                                            명 예 로 운  환 생 자 들 \n");

}

void printHelpUI() {
	SetCurrentCursorPos(0, 0);
	textcolor(RED);
	printf("  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼\n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	printf("                                                                                                                        \n");
	textcolor(DarkGray);
	printf("                                                                                     ▼ 도  움  말 ▼\n");
	textcolor(RED);
	printf("                                   -------------------------------------------------------------------------------------------------------------------  \n");
	textcolor(GRAY);
	printf("                                   1. 목표                                                                                                              \n");
	printf("                                                                                                                        \n");
	textcolor(WHITE);
	printf("                                    TWIN은 두 캐릭터를 동시에 조작하여 각 스테이지마다의 골인지점까지 도달해서 클리어 해야 하는 게임입니다.             \n");
	printf("                                    골인지점은 맵의 반대편에서 각 캐릭터 색상으로 칠해져있는 위아래 두 칸의 네모블록입니다.                             \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(GRAY);
	printf("                                   2. 조작법                                                                                                            \n");
	printf("                                                                                                                        \n");
	textcolor(WHITE);
	printf("                                    좌/우 방향키 : 두 캐릭터가 동시에 왼쪽 또는 오른쪽으로 이동합니다.                                                  \n");
	printf("                                    위 방향키 : 두 캐릭터가 동시에 점프를 합니다.                                                                       \n");
	printf("                                    스페이스바 : 두 캐릭터가 동시에 투사체를 발사합니다.                                                                \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(GRAY);
	printf("                                   3. 아이템                                                                                                            \n");
	textcolor(WHITE);
	printf("                                                                                                                        \n");
	printf("                                    게임 플레이 도중 제한 시간이 얼마 남지 않은 경우, 특정 캐릭터 화면에 아이템이 등장하며     \n");
	printf("                                    해당 아이템을 획득 시 획득한 캐릭터는 다른 캐릭터가 골인지점에 들어갈 때까지 움직이지 않습니다.                     \n");
	printf("                                    촉박하게 남은 시간 동안, 해당 아이템을 이용하여 얼른 관문을 클리어해주세요!                                         \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(GRAY);
	printf("                                   4. 게임 시스템                                                                                                       \n");
	textcolor(WHITE);
	printf("                                                                                                                        \n");
	printf("                                    제한시간 내에 스테이지를 클리어해야합니다.                                                                          \n");
	printf("                                    장애물에 부딪히거나 낙사 시 해당 스테이지의 시작지점부터 다시 플레이하게 됩니다.                                    \n");
	printf("                                    스테이지 내 제한시간 내에 클리어하지 못 할 시 게임이 종료되며, 제 1장부터 다시 시작해야합니다.                      \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkGray);
	printf("                           B a c k   S p a c e (←)   :   뒤 로 가 기                                                                                   \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	textcolor(RED);
	printf("  ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n");
	SetCurrentCursorPos(0, 0);
}

void printRecrodUI() {
	SetCurrentCursorPos(0, 0);
	textcolor(RED);
	printf("  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼\n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(WHITE);
	printf("                                                                                ▼ 명 예 로 운    환 생 자 들 ▼\n");
	textcolor(GRAY);
	printf("                                                                                                                        \n");
	printf("                                    -------------------------------------------------------------------------------------------------------------------   \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkYellow);
	printf("                                                                                 (상위 10개의 기록만 표시됩니다)        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkGray);
	printf("                                B a c k   S p a c e (←)   :   뒤 로 가 기                                              \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	textcolor(RED);
	printf("  ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n");
	SetCurrentCursorPos(0, 0);
	SetCurrentCursorPos(0, 10);
	PrintRecords();
	SetCurrentCursorPos(0, 0);
}


void printBeforeStage(int num_stage) {
	SetCurrentCursorPos(20, 10);
	Sleep(1000);
	switch (num_stage) {
	case 1:
		textcolor(RED);
		printf("                                                                                         \n");
		printf("                                                            =======================================================================\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||               ■  ■            ■            ■■■■■   ■     ||\n");
		printf("                                                            ||   ■■■■■  ■  ■          ■■                ■       ■■   ||\n");
		printf("                                                            ||       ■    ■■  ■        ■  ■              ■  ■     ■     ||\n");
		printf("                                                            ||     ■  ■    ■  ■            ■            ■      ■   ■     ||\n");
		printf("                                                            ||   ■      ■  ■  ■            ■                  ■■■        ||\n");
		printf("                                                            ||               ■  ■            ■                ■      ■      ||\n");
		printf("                                                            ||               ■  ■            ■                ■      ■      ||\n");
		printf("                                                            ||               ■  ■        ■■■■■              ■■■        ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            =======================================================================\n");
		printf("                                                                       \n");
		Sleep(1000);
		textcolor(GRAY);
		printf("                                                                                      ~ 환생, 역경의 서막 ~                        \n");
		printf("                                                                       \n");
		Sleep(3000);
		break;

	case 2:
		textcolor(RED);
		printf("                                                                       \n");
		printf("                                                            =======================================================================\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||               ■  ■          ■■■          ■■■■■   ■     ||\n");
		printf("                                                            ||   ■■■■■  ■  ■        ■      ■            ■       ■■   ||\n");
		printf("                                                            ||       ■    ■■  ■               ■           ■  ■     ■     ||\n");
		printf("                                                            ||     ■  ■    ■  ■             ■           ■      ■   ■     ||\n");
		printf("                                                            ||   ■      ■  ■  ■            ■                  ■■■        ||\n");
		printf("                                                            ||               ■  ■           ■                 ■      ■      ||\n");
		printf("                                                            ||               ■  ■          ■                  ■      ■      ||\n");
		printf("                                                            ||               ■  ■        ■■■■■              ■■■        ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            =======================================================================\n");
		printf("                                                                       \n");
		Sleep(1000);
		textcolor(GRAY);
		printf("                                                                                          ~ 불협화음 ~                             \n");
		printf("                                                                       \n");
		Sleep(3000);
		break;

	case 3:
		textcolor(RED);
		printf("                                                                       \n");
		printf("                                                            =======================================================================\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||               ■  ■          ■■■■          ■■■■■   ■   ||\n");
		printf("                                                            ||   ■■■■■  ■  ■        ■      ■■            ■       ■■ ||\n");
		printf("                                                            ||       ■    ■■  ■              ■■            ■  ■     ■   ||\n");
		printf("                                                            ||     ■  ■    ■  ■            ■■            ■      ■   ■   ||\n");
		printf("                                                            ||   ■      ■  ■  ■            ■■                  ■■■      ||\n");
		printf("                                                            ||               ■  ■              ■■              ■      ■    ||\n");
		printf("                                                            ||               ■  ■        ■      ■■            ■      ■    ||\n");
		printf("                                                            ||               ■  ■          ■■■■                ■■■      ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            =======================================================================\n");
		printf("                                                                       \n");
		textcolor(GRAY);
		Sleep(1000);
		printf("                                                                                           ~ 점입가경 ~                            \n");
		printf("                                                                       \n");
		Sleep(3000);
		break;
	case 4:
		textcolor(DarkGray);
		printf("                                                                       \n");
		printf("                                                            =======================================================================\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||               ■  ■            ■■■          ■■■■■   ■   ||\n");
		printf("                                                            ||   ■■■■■  ■  ■           ■   ■              ■       ■■ ||\n");
		printf("                                                            ||       ■    ■■  ■          ■    ■            ■  ■     ■   ||\n");
		printf("                                                            ||     ■  ■    ■  ■         ■     ■          ■      ■   ■   ||\n");
		printf("                                                            ||   ■      ■  ■  ■        ■      ■                ■■■      ||\n");
		printf("                                                            ||               ■  ■       ■■■■■■■           ■      ■    ||\n");
		printf("                                                            ||               ■  ■                ■              ■      ■    ||\n");
		printf("                                                            ||               ■  ■                ■                ■■■      ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            =======================================================================\n");
		printf("                                                                       \n");
		textcolor(GRAY);
		Sleep(1000);
		printf("                                                                                           ~ 오리무중 ~                            \n");
		printf("                                                                       \n");
		Sleep(3000);
		break;
	case 5:
		textcolor(RED);
		printf("                                                                       \n");
		printf("                                                            =======================================================================\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||               ■  ■        ■■■■■■        ■■■■■   ■   ||\n");
		printf("                                                            ||   ■■■■■  ■  ■        ■                      ■       ■■ ||\n");
		printf("                                                            ||       ■    ■■  ■        ■                    ■  ■     ■   ||\n");
		printf("                                                            ||     ■  ■    ■  ■        ■■■■■          ■      ■   ■   ||\n");
		printf("                                                            ||   ■      ■  ■  ■                ■■              ■■■      ||\n");
		printf("                                                            ||               ■  ■                  ■            ■      ■    ||\n");
		printf("                                                            ||               ■  ■        ■      ■■            ■      ■    ||\n");
		printf("                                                            ||               ■  ■          ■■■■                ■■■      ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            =======================================================================\n");
		printf("                                                                       \n");
		textcolor(DarkGray);
		Sleep(1000);
		printf("                                                                                           ~ 화룡점정 ~                            \n");
		printf("                                                                       \n");
		Sleep(3000);
		break;
	case 6:
		textcolor(DarkRed);
		printf("                                                                       \n");
		printf("                                                            =======================================================================\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                ■        ■■■■■■■       ■■■■■■  ■    ||\n");
		printf("                                                            ||     ■■■     ■            ■■■                ■       ■    ||\n");
		printf("                                                            ||   ■■■■■   ■          ■■  ■■             ■■      ■■  ||\n");
		printf("                                                            ||       ■       ■              ■                ■  ■     ■    ||\n");
		printf("                                                            ||     ■  ■     ■       ■■■■■■■■       ■      ■   ■    ||\n");
		printf("                                                            ||   ■  ■  ■   ■                                           ■    ||\n");
		printf("                                                            ||       ■       ■            ■■■                  ■■■       ||\n");
		printf("                                                            ||  ■■■■■■■■          ■      ■              ■      ■     ||\n");
		printf("                                                            ||                ■          ■      ■              ■      ■     ||\n");
		printf("                                                            ||                ■            ■■■                  ■■■       ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            ||                                                                   ||\n");
		printf("                                                            =======================================================================\n");
		printf("                                                                       \n");
		Sleep(1000);
		textcolor(RED);
		printf("                                                                                          ~ 염라대왕 ~                             \n");
		printf("                                                                       \n");
		Sleep(3000);
		break;
	default:
		break;
	}


	SetCurrentCursorPos(0, 0);
}


void printBeforeStart() {
	clearBoardUI();
	int Scenario_len = 24;
	char Scenario[50][500] = {
		"                                                                                                                                                     ",

		"세상에 둘도 없는 친구 사이인 두 사람이 있었습니다.",

		"바쁜 일상 와중에 두 사람은 모처럼 휴가를 얻어 함께 여행을 가게 되었습니다.",

		"그렇게 두 사람은 차를 끌고 여행지로 가던 도중",

		"쾅!!!....",

		"...",

		"시간이 얼마나 지났을까요."

		"두 사람 모두 정신을 차렸을 때는 주변이 온통 붉은 빛이었으며",

		"숨이 턱 막힐 정도로 뜨겁고 습한 공기가 두 사람을 에워싸고 있었습니다.",

		"그리고 덥수룩한 수염에 매우 날카로운 눈매를 가지고, 몸집은 3층 건물만한 한 남자가 눈 앞에 나타나더니",

		"\"요즘 이승에서 보기 힘든 우정을 가진 인간들인데, 너무도 어이없게 이 곳에 와버렸군.\"",

		"아무래도 이곳에 대해 잘 아는 사람인 듯 합니다.",

		"\"원래대로라면 각각 따로 환생시험을 봐야하지만,",

		"둘의 우정을 생각해서 두 사람만을 위한 특별한 시험을 치뤄볼까 하네.\"",

		"\"만일 지금 내가 제안하는 이 특별한 시험을 통과한다면,",

		"내 둘의 인연을 다음 생에도 이어갈 수 있도록 해주지. 쌍둥이가 좋으려나?\"",

		"두 사람 모두 갑작스러운 상황과 질문에 그저 멍하니 서로를 바라보기만 했습니다.",

		"\"빨리 결정하게. 당황스러운건 알겠지만, 안타깝게도 시간이 별로 많지 않아서 말이야.",

		"세상 뜨는 인간들이 지금 이 순간에도 자네 둘 뿐인 줄 아나?\"",

		"\"길게 생각할 시간따윈 줄 수 없다네. 어떤가.",

		"두 사람만의 특별한 시험을 치뤄보겠는가? 아니면 따로 환생시험을 볼 텐가? 선택하게.",

		"의문의 남자가 영문모를 말로 계속 재촉하자 두 사람은 당황한 기색을 숨기지 못하며 아무 말도 못하고 있었습니다.",

		"하지만 이내 상황을 어느정도 파악한 듯한 두 사람",

		"두 사람은 동시에 의문의 남자에게 대답했습니다.",

		"...하겠습니다!",
	};

	textcolor(DarkGray);
	SetCurrentCursorPos(120, 40);
	printf("넘 기 기  ( P r e s s  :  S P A C E  B A R ) ▶");
	SetCurrentCursorPos(121, 42);
	printf("이 야 기   생 략 하 기  ( P r e s s  :  R ) ▶");

	int start_posX;

	for (int i = 1; i < Scenario_len; i++) {
		start_posX = (BOARD_WIDTH - strlen(Scenario[i])) / 2;

		if (i == 23)
			textcolor(DarkYellow);
		else
			textcolor(WHITE);

		if (i == 4)
		{
			PlayBgm(Path_Crash);
			Sleep(500);
		}

		SetCurrentCursorPos(0, 20);
		printf("%s", Scenario[0]);

		SetCurrentCursorPos(start_posX, 20);
		printf("%s", Scenario[i]);



		for (int j = 0; j < 30; j++) {
			if (GetAsyncKeyState('R') & 0x0001)	// SKIP
				return;
			if (GetAsyncKeyState(VK_SPACE) & 0x0001)	// NEXT
				break;
			Sleep(100);
		}

		if (i == 4)
		{
			StopBgm();
			PlayBgm(Path_Intro);
		}
	}
}


void printBossScenario() 
{
	int TEXTBOARD_ORIGIN_X, TEXTBOARD_ORIGIN_Y;
	int TEXTBOARD_WIDTH, TEXTBOARD_HEIGHT;
	TEXTBOARD_ORIGIN_X = 4;
	TEXTBOARD_ORIGIN_Y = 32;
	TEXTBOARD_WIDTH = 150/2;
	TEXTBOARD_HEIGHT = 12;

	//TEXTBOARD 부분만 clearBoard
	for (int y = 0; y < TEXTBOARD_HEIGHT; y++) 
	{
		SetCurrentCursorPos(TEXTBOARD_ORIGIN_X, TEXTBOARD_ORIGIN_Y + y);
		for (int x = 0; x <= TEXTBOARD_WIDTH * 2; x++)
			printf(" ");
	}



	//Drawing TEXTBOARD
	textcolor(DarkGray);
	for (int y = 0; y <= TEXTBOARD_HEIGHT; y++) 
	{
		SetCurrentCursorPos(TEXTBOARD_ORIGIN_X, TEXTBOARD_ORIGIN_Y + y);
		if (y == 0)
			printf("●");
		else if (y == TEXTBOARD_HEIGHT)
			printf("●");
		else
			printf("▣");
	}
	for (int y = 0; y <= TEXTBOARD_HEIGHT; y++)
	{
		SetCurrentCursorPos(TEXTBOARD_ORIGIN_X+TEXTBOARD_WIDTH*2, TEXTBOARD_ORIGIN_Y + y);
		if (y == 0)
			printf("●");
		else if (y == TEXTBOARD_HEIGHT)
			printf("●");
		else
			printf("▣");
	}
	for (int x = 1; x <= TEXTBOARD_WIDTH - 1; x++)
	{
		SetCurrentCursorPos(TEXTBOARD_ORIGIN_X + x * 2, TEXTBOARD_ORIGIN_Y);
		printf("▣");
	}
	for (int x = 1; x <= TEXTBOARD_WIDTH-1; x++) 
	{
		SetCurrentCursorPos(TEXTBOARD_ORIGIN_X + x * 2, TEXTBOARD_ORIGIN_Y + TEXTBOARD_HEIGHT);
		printf("▣");
	}


	int Scenario_len = 29;
	char Scenario[50][500] = 
	{
		"                                                                                                                                                  ", // 0

		"이제 여기가 마지막 관문인건가? 정말 쉽지 않았어.", //노랑 1

		"그러게. TV에서나 보던 샴쌍둥이가 바로 이런 기분이었겠군.", //파랑 2

		"그건 그렇고, 여기가 마지막 관문이 맞는건가? 아무것도 없는데?", //파랑 3

		"음, 여기 오기 전에 분명 마지막 관문이라고 들었던 거같은데..",	//노랑 4

		"(쿵!)",	//아무 캐릭 없음 5

		"!",	//파랑, 노랑 6 

		"저게 뭐지?", //파랑 7

		"여기까지 잘 와주었네. 역시 내 안목은 틀리지 않았어", //염라대왕 8

		"..? 당신이 이 곳의 책임자였습니까?",	//노랑 9 

		"하핫, 가장 높진 않지만, 그래도 왕들 중에선 어느정도 서열이 높긴 하지.",	//염라대왕 10

		"늦었지만 이제라도 나를 소개하도록 하겠네. 내 이름은 염라라네.", 

		"?!", //파랑, 노랑 12

		"허허 다들 그런 반응일줄 알았어. 분명 이승에서는 수많은 재판과 지옥을 통과해야 환생할 수 있는 걸로 아는데, 그것들에 비해선 많이 쉬웠겠지.", //염라대왕 13

		"...당신이 염라대왕이라면, 이곳은 지옥이었겠군요. 그렇다면 정말 저희들은 쌍둥이로 환생할 수 있는겁니까?", //파랑 14

		"그렇지. 하지만! 분명 자네들 입으로 마지막 관문이 아직 하나 남았다고 하질 않았나.", //염라대왕 15

		"앗..아아..", //파랑, 노랑 16

		"아직 관문이 하나 남긴 했지만, 그래도 여기까지 온 건 정말 대단하네. 분명 혼자서 환생을 도전하는 것보다는 많이 쉬웠겠지만,", //염라대왕 17

		"그래도 둘의 우정과 협동심이 정말 뛰어났기에 비교적 쉽게 통과할 수 있었던 거네.",

		"그냥 모르는 사람 둘이서 이런 시험을 치르게 한다면 1장은 어찌저찌해도 2장부터는 택도 없단 말이지.",

		"...감사합니다!", //파랑, 노랑 20

		"하하. 감사인사는 됐네. 아직 관문이 하나 더 남았기 때문이지.",	//염라대왕 21

		"마지막 관문은 지금까지 거쳐왔던 관문들과 크게 다르지 않다네. 관문이 시작되면, 나의 분신들이 자네들 있는 곳에 각각 서 있을 것이야.",

		"나의 분신들을 없앨 수 있는 곳으로 도달한 후, 두 사람 모두 지금 내가 있는 환생의 문으로 들어오면 된다네. 그럼 모든 관문을 통과하는 걸세.",

		"행운을 빌지.",

		"(행운을 빈다는 말을 끝으로 사라져버린 염라대왕)",	//아무캐릭 없음 25

		"분신이면 일단 방금 그 염라대왕 본인만 할텐데, 그걸 만들어놓고 그냥 간다고..? 또 그걸 없애고 들어가야하고?", // 노랑 26

		"아예 못하는 걸 시키진 않겠지. 여기까지 어떻게 왔는데, 끝까지 가봐야하지 않겠어?", //파랑 27

		"좋아, 가보자고." //노랑 28
	};

	textcolor(DarkGray);
	SetCurrentCursorPos(TEXTBOARD_ORIGIN_X + TEXTBOARD_WIDTH * 2 - 50, TEXTBOARD_ORIGIN_Y + TEXTBOARD_HEIGHT - 3);
	printf("넘기기 ( P r e s s  :  S P A C E  B A R ) ▶");
	SetCurrentCursorPos(TEXTBOARD_ORIGIN_X + TEXTBOARD_WIDTH * 2 - 44, TEXTBOARD_ORIGIN_Y + TEXTBOARD_HEIGHT - 2);
	printf("이야기 생략하기 ( P r e s s  :  R ) ▶");

	int start_posX, start_posY;
	start_posY = TEXTBOARD_ORIGIN_Y + TEXTBOARD_HEIGHT / 2 - 1;

	textcolor(WHITE);
	for (int i = 1; i < Scenario_len; i++) 
	{
		start_posX = (TEXTBOARD_WIDTH * 2 - strlen(Scenario[i])) / 2 + TEXTBOARD_ORIGIN_X;

		SetCurrentCursorPos(TEXTBOARD_ORIGIN_X+2, start_posY);
		printf("%s", Scenario[0]);
		SetCurrentCursorPos(TEXTBOARD_ORIGIN_X + 2, start_posY+1);
		printf("%s", Scenario[0]);


		if (i == 1 || i == 4 || i == 9 || i == 26 || i == 28)	//노랑 대사
		{
			SetCurrentCursorPos(start_posX, start_posY);
			obstacle(96);
			SetCurrentCursorPos(start_posX, start_posY + 1);
			obstacle(97);
			textcolor(WHITE);
			printf(" : %s", Scenario[i]);
		}
		else if (i == 2 || i == 3 || i == 7 || i == 14 || i == 27)	//파랑 대사
		{
			SetCurrentCursorPos(start_posX, start_posY);
			obstacle(98);
			SetCurrentCursorPos(start_posX, start_posY + 1);
			obstacle(99);
			textcolor(WHITE);
			printf(" : %s", Scenario[i]);
		}

		else if (i == 6 || i == 12 || i == 16 || i == 20)	//파랑 노랑 동시대사
		{
			SetCurrentCursorPos(start_posX, start_posY);
			obstacle(96);
			obstacle(98);
			SetCurrentCursorPos(start_posX, start_posY + 1);
			obstacle(97);
			obstacle(99);
			textcolor(WHITE);
			printf(" : %s", Scenario[i]);
		}

		else if (i == 8 || i == 10 || i == 11 || i == 13 ||	// 염라대왕 대사
			i == 15 || i == 17 || i == 18 || i == 19 ||
			i == 21 || i == 22 || i == 23 || i == 24)
		{
			SetCurrentCursorPos(start_posX, start_posY);
			obstacle(220);
			SetCurrentCursorPos(start_posX, start_posY + 1);
			obstacle(221);
			textcolor(WHITE);
			printf(" : %s", Scenario[i]);
		}
		else	//효과음
		{
			SetCurrentCursorPos(start_posX, start_posY + 1);
			printf("%s", Scenario[i]);

			if (i == 5) 
			{
				ShowKing(King, 120, 14);
				PlayEffect(Path_Select);
			}
			else if (i == 25) 
			{
				DeleteKing(120, 14);
				PlayEffect(Path_Select);
			}
		}



		for (int j = 0; j < 30; j++) {
			if (GetAsyncKeyState('R') & 0x0001)	// SKIP
				return;
			if (GetAsyncKeyState(VK_SPACE) & 0x0001)	// NEXT
				break;
			Sleep(100);
		}

	}
}

void printClearBoss() {
	clearBoardUI();
	int Scenario_len = 22;
	char Scenario[50][500] = {
		"                                                                                                                                                               ",

		"...",

		"환생의 문을 나서자 두 사람은 같은 공간에 들어서며",

		"이전의 뜨거운 공기와 주변이 온통 붉은 빛이었던 것과는 달리 따사로운 빛이 두 사람을 감싸기 시작했습니다.",

		"그리고 두 사람 앞에 염라대왕이 다시 나타났습니다.",

		"\"마지막 관문까지 통과했군. 축하하네!",

		"\"약속했던 대로, 자네 둘은 다음 생에 쌍둥이로 태어나게 될 걸세.\"",

		"\"내가 자네들을 알아본 만큼, 그리고 그것을 증명해낸 만큼\"",

		"\"다음 생에도 둘의 깊은 우애가 이어졌으면 좋겠구만.\"",

		"\"잘 가시게.\"",

		"마지막 말을 끝으로, 염라대왕은 두 사람을 감싸던 빛 속으로 서서히 사라졌습니다.",

		"\"여기까지 올 수 있을까 걱정 많이 했는데, 진짜 성공해버렸네.\"",

		"\"그러게, 진짜 이런 곳이 있는 줄도 몰랐는데 말이야...",

		"갑자기 세상을 떠버리는 바람에 지금까지 살면서 쌓아온 것들이 계속 생각났는데, 그래도 그 중에 하나라도 챙길 수 있어 다행이구만.\"",

		"\"그건 나도 마찬가지지.\"",

		"두 사람은 서로를 뜨겁게 안아주며 말을 이어나갔습니다.",

		"\"그동안 정말 고마웠어. 정말 많은 일이 있었지만, 그래도 너라서 재밌었던 것 같다.\"",

		"\"내가 할 소리다 임마. 다음 생에도 잘 부탁한다.\"",

		"\"물론이지. 이제 슬슬 들어가보자고.\"",

		"이후 두 사람은 염라대왕이 가리켰던 빛을 향해서,",

		"서로에 대한 다음 생의 기대를 안으며, 천천히 발걸음을 이어나갔습니다.",

		"                                                                                                                                                      "
	};

	textcolor(DarkGray);
	SetCurrentCursorPos(120, 40);
	printf("넘 기 기  ( P r e s s  :  S P A C E  B A R ) ▶");
	SetCurrentCursorPos(121, 42);
	printf("이 야 기   생 략 하 기  ( P r e s s  :  R ) ▶");

	int start_posX;

	textcolor(WHITE);
	for (int i = 1; i < Scenario_len; i++) {
		start_posX = (BOARD_WIDTH - strlen(Scenario[i])) / 2;
			
		SetCurrentCursorPos(0, 20);
		printf("%s", Scenario[0]);

		SetCurrentCursorPos(start_posX, 20);
		printf("%s", Scenario[i]);


		for (int j = 0; j < 30; j++) {
			if (GetAsyncKeyState('R') & 0x0001)	// SKIP
				return;
			if (GetAsyncKeyState(VK_SPACE) & 0x0001)	// NEXT
				break;
			Sleep(100);
		}

	}
}

void printPauseUI() {


	textcolor(RED);
	printf("  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼\n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(WHITE);
	printf("                                                     =======================================================================\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                          < 일 시 정 지 >                          ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                           도   움   말                            ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                          게 임  나 가 기                          ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     ||                                                                   ||\n");
	printf("                                                     =======================================================================\n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkGray);
	printf("                B a c k   S p a c e (←)   또는   E S C   :   게 임   재 개                                             \n");
	printf("                                                                                                                        \n");
	printf("                S P A C E   B A R   :   선 택                                                                           \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkRed);
	printf("  ========================================================================================================================================================================================\n");
	textcolor(RED);
	printf("  ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n");

}

void printPauseHelpUI() {
	SetCurrentCursorPos(0, 0);
	textcolor(RED);
	printf("  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼\n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	printf("                                                                                                                        \n");
	textcolor(DarkGray);
	printf("                                                                                     ▼ 도  움  말 ▼\n");
	textcolor(RED);
	printf("                                   -------------------------------------------------------------------------------------------------------------------  \n");
	textcolor(GRAY);
	printf("                                   1. 목표                                                                                                              \n");
	printf("                                                                                                                        \n");
	textcolor(WHITE);
	printf("                                    TWIN은 두 캐릭터를 동시에 조작하여 각 스테이지마다의 골인지점까지 도달해서 클리어 해야 하는 게임입니다.             \n");
	printf("                                    골인지점은 맵의 반대편에서 각 캐릭터 색상으로 칠해져있는 위아래 두 칸의 네모블록입니다.                             \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(GRAY);
	printf("                                   2. 조작법                                                                                                            \n");
	printf("                                                                                                                        \n");
	textcolor(WHITE);
	printf("                                    좌/우 방향키 : 두 캐릭터가 동시에 왼쪽 또는 오른쪽으로 이동합니다.                                                  \n");
	printf("                                    위 방향키 : 두 캐릭터가 동시에 점프를 합니다.                                                                       \n");
	printf("                                    스페이스바 : 두 캐릭터가 동시에 투사체를 발사합니다.                                                                \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(GRAY);
	printf("                                   3. 아이템                                                                                                            \n");
	textcolor(WHITE);
	printf("                                                                                                                        \n");
	printf("                                    게임 플레이 도중 제한 시간이 얼마 남지 않은 경우, 특정 캐릭터 화면에 아이템이 등장하며     \n");
	printf("                                    해당 아이템을 획득 시 획득한 캐릭터는 다른 캐릭터가 골인지점에 들어갈 때까지 움직이지 않습니다.                     \n");
	printf("                                    촉박하게 남은 시간 동안, 해당 아이템을 이용하여 얼른 관문을 클리어해주세요!                                         \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(GRAY);
	printf("                                   4. 게임 시스템                                                                                                       \n");
	textcolor(WHITE);
	printf("                                                                                                                        \n");
	printf("                                    제한시간 내에 스테이지를 클리어해야합니다.                                                                          \n");
	printf("                                    장애물에 부딪히거나 낙사 시 해당 스테이지의 시작지점부터 다시 플레이하게 됩니다.                                    \n");
	printf("                                    스테이지 내 제한시간 내에 클리어하지 못 할 시 게임이 종료되며, 제 1장부터 다시 시작해야합니다.                      \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkGray);
	printf("                        B a c k  S p a c e (←)   :   뒤 로 가 기                                                       \n");
	printf("                                                                                                                        \n");
	printf("                        E S C   :   게 임   재 개                                                                       \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	textcolor(RED);
	printf("  ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n");
	SetCurrentCursorPos(0, 0);
}

void printPauseQuitUI() {


	textcolor(RED);
	printf("  ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼\n");
	textcolor(DarkRed);
	printf("  ==========================================================================================================================================================================================\n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(GRAY);
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                            정말로 게임을 그만두시겠습니까?\n");
	printf("                                                                                                                          \n");
	printf("                                                                       지금까지의 플레이 내용은 저장되지 않습니다.\n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(WHITE);
	printf("                                                                       예 (Press 'Y')           아니오 (Press 'N')\n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkGray);
	printf("                               E S C   :   게 임   재 개                                                                \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	printf("                                                                                                                        \n");
	textcolor(DarkRed);
	printf("  ========================================================================================================================================================================================\n");
	textcolor(RED);
	printf("  ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n");

}

//x:32 y:18
void printClearUI(int limit_time, int left_time, int score, int life, int coin, int num_stage) {
	int time = limit_time - left_time;

	char tmp[100] = "";
	char stage1_name[50] = "제 1 장 - 환생, 역경의 서막";
	char stage2_name[50] = "제 2 장 - 불 협 화 음";
	char stage3_name[50] = "제 3 장 - 점 입 가 경";
	char stage4_name[50] = "제 4 장 - 오 리 무 중";
	char stage5_name[50] = "제 5 장 - 화 룡 점 정";
	char stage6_name[50] = "최 종 장 - 염 라 대 왕";

	switch (num_stage) {
	case 1:
		strcpy(tmp, stage1_name);
		break;
	case 2:
		strcpy(tmp, stage2_name);
		break;
	case 3:
		strcpy(tmp, stage3_name);
		break;
	case 4:
		strcpy(tmp, stage4_name);
		break;
	case 5:
		strcpy(tmp, stage5_name);
		break;
	case 6:
		strcpy(tmp, stage6_name);
		break;
	default:
		break;
	}
	textcolor(YELLOW);
	printf("                                    \n");
	printf("                                    \n");
	printf("                                    \n");
	printf("                                    \n");
	printf("                                    \n");
	printf("                                                                                             \n");
	printf("                                                            =========================================================================\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                   ■     ■              ■■■■■                 ||\n");
	printf("                                                            ||                 ■■     ■                      ■                 ||\n");
	printf("                                                            ||                ■  ■  ■■                  ■  ■                 ||\n");
	printf("                                                            ||              ■     ■   ■           ■■■■■■■■              ||\n");
	printf("                                                            ||                   ■■■ ■                ■■■                   ||\n");
	printf("                                                            ||                 ■      ■               ■      ■                 ||\n");
	printf("                                                            ||                 ■      ■               ■      ■                 ||\n");
	printf("                                                            ||                   ■■■                   ■■■                   ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ||                                                                     ||\n");
	printf("                                                            ========================================================================\n");
	Sleep(1000);
	textcolor(YELLOW);
	SetCurrentCursorPos(0, 20);
	printf("                                                            ||               관 문 명 : \t%s\n", tmp);
	Sleep(500);
	printf("\n");

	printf("                                                            ||               소요 시간 : \t%02d : %02d\n", time / 60, time % 60);
	Sleep(500);
	printf("\n");

	printf("                                                            ||               총 부활 수 : \t%d\n", life);
	Sleep(500);
	printf("\n");

	printf("                                                            ||               코인 개수 : \t%d\n", coin);
	Sleep(500);
	printf("\n");

	printf("                                                            ||               총 점수 : \t\t%06d\n", score);
	Sleep(1000);
	printf("\n");
	printf("\n");

	textcolor(YELLOW);
	printf("                                                            ||");
	textcolor(DarkYellow);
	if (num_stage != 6)
		printf("               잠시 후 다음 관문이 시작됩니다...\n");
	Sleep(3000);
}

void printFailUI() {
	clearBoardUI();
	Sleep(1000);
	textcolor(RED);
	printf("                                    \n");
	printf("                                    \n");
	printf("                                    \n");
	printf("                                    \n");
	printf("                                    \n");
	printf("                                    \n");
	printf("                                                       ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                  ■       ■                    ■  ■               ◀\n");
	printf("                                                       ▶                   ■       ■                    ■  ■              ◀\n");
	printf("                                                       ▶                  ■■      ■        ■■■■■  ■  ■              ◀\n");
	printf("                                                       ▶                ■■  ■    ■          ■  ■    ■  ■              ◀\n");
	printf("                                                       ▶              ■■     ■   ■          ■  ■    ■  ■              ◀\n");
	printf("                                                       ▶                    ■■■■            ■  ■    ■■■              ◀\n");
	printf("                                                       ▶                          ■            ■  ■    ■  ■              ◀\n");
	printf("                                                       ▶                    ■■■■          ■■■■■  ■  ■              ◀\n");
	printf("                                                       ▶                    ■                            ■  ■              ◀\n");
	printf("                                                       ▶                    ■■■■                      ■  ■              ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▶                                                                      ◀\n");
	printf("                                                       ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n");
	Sleep(1000);

	textcolor(DarkGray);
	SetCurrentCursorPos((190 - 40) / 2, 22);
	printf("다 시   도 전 하 시 겠 습 니 까 ?");

	Sleep(1000);

	textcolor(WHITE);
	SetCurrentCursorPos((190 - 18) / 2, 25);
	printf("예   ( Y )");

	Sleep(300);

	SetCurrentCursorPos((190 - 24) / 2, 28);
	printf("아 니 오   ( N )");
}
//■
#endif
