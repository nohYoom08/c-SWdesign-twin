#ifndef __BGM_H__
#define __BGM_H__
#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <mmsystem.h>

#pragma comment (lib, "winmm.lib")

#define Path_AllClear "bgm/AllClear.wav"
#define Path_Boss "bgm/Boss.wav"
#define Path_Clear "bgm/Clear.wav"
#define Path_Coin "bgm/Coin.wav"
#define Path_Crash "bgm/Crash.wav"
#define Path_Fail "bgm/Fail.wav"
#define Path_Interface "bgm/Interface.wav"
#define Path_Intro "bgm/Intro.wav"
#define Path_Razor "bgm/Razor.wav"
#define Path_Select "bgm/Select.wav"
#define Path_Stage_1 "bgm/Stage_1.wav"
#define Path_Stage_2 "bgm/Stage_2.wav"
#define Path_Stage_3 "bgm/Stage_3.wav"
#define Path_Stage_4 "bgm/Stage_4.wav"
#define Path_Stage_5 "bgm/Stage_5.wav"
#define Path_TimeStop "bgm/TimeStop.wav"

#define TRUE 1
#define FALSE 0

void PlayBgm(char* Path_Music) {
    WCHAR wPath_Music[100];
    MultiByteToWideChar(CP_ACP, 0, Path_Music, -1, wPath_Music, sizeof(wPath_Music) / sizeof(WCHAR));
    PlaySound(wPath_Music, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void PlayEffect(char* Path_Music) {
    WCHAR wPath_Music[100];
    MultiByteToWideChar(CP_ACP, 0, Path_Music, -1, wPath_Music, sizeof(wPath_Music) / sizeof(WCHAR));
    PlaySound(wPath_Music, NULL, SND_FILENAME | SND_ASYNC);
}


void StopBgm() {
    PlaySound(NULL, NULL, 0);
}

#endif
