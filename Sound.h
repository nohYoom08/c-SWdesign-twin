#ifndef __SOUND_H__
#define __SOUND_H__

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


#include <Windows.h>   

#pragma comment (lib, "winmm.lib")    
#include <mmsystem.h>;                
#include <Digitalv.h>; 




MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS openShuffleSound;
MCI_PLAY_PARMS playShuffleSound;

int dwID;

void playingBgm(char* Path_Music) {

    WCHAR wPath_Music[100];
    MultiByteToWideChar(CP_ACP, 0, Path_Music, -1, wPath_Music, sizeof(wPath_Music) / sizeof(WCHAR));

    openBgm.lpstrElementName = wPath_Music;            //파일 오픈
    openBgm.lpstrDeviceType = TEXT("waveaudio");    //wav 형식
    mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
    dwID = openBgm.wDeviceID;
    mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm);    //음악 반복 재생
}
void playingShuffleSound(char* Path_Music) {

    WCHAR wPath_Music[100];
    MultiByteToWideChar(CP_ACP, 0, Path_Music, -1, wPath_Music, sizeof(wPath_Music) / sizeof(WCHAR));


    openShuffleSound.lpstrElementName = wPath_Music;    //파일 오픈
    openShuffleSound.lpstrDeviceType = TEXT("waveaudio");    //wav 형식

    mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openShuffleSound);
    dwID = openShuffleSound.wDeviceID;
    mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openShuffleSound);    //음악을 한 번 재생
    Sleep(1800);    //효과음이 재생될 때까지 정지했다가
    mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);    //음원 재생 위치를 처음으로 초기화
}

#endif
