# TWIN
* SW설계기초(줄여서 소설기) 과목의 게임 제작 팀플과제에서 C언어로 제작해본 게임 **TWIN**의 리포지토리
* 동시에 움직이는 두 캐릭터로 주어진 맵을 클리어해야 하는 게임

## 실행 방법
1. `git clone .`
2. twin.exe파일 실행

## 게임 화면 설명

### 시작 화면
<img width = 600 height = 300 src="https://github.com/user-attachments/assets/1ec71957-ebed-4fdf-8246-06cde847363b">
<br>

### 도움말 화면
<img width = 600 height = 300 src="https://github.com/user-attachments/assets/5160b074-331d-40cf-8b2d-2720ddf1a206">
<br>

### 게임 플레이 기록화면
<img width = 600 height = 300 src="https://github.com/user-attachments/assets/f6a9eff2-b6db-4419-aea2-3d2ce722b0c6">
<br>

### 시나리오 화면
<img width = 600 height = 300 src="https://github.com/user-attachments/assets/6f9c3225-c731-4ba2-b183-ad0b50d61ee0">
<br>

### 스테이지 시작 전 화면
<img width = 600 height = 300 src="https://github.com/user-attachments/assets/48999be0-acbe-49b2-92ef-09f3a66e1679">
<br>

### 플레이 화면
<img width = 600 height = 300 src="https://github.com/user-attachments/assets/0a53a6cd-87b1-4427-867f-76c5ca58356b">
<br>

### 일시정지 화면
<img width = 600 height = 300 src="https://github.com/user-attachments/assets/698b49ad-5891-4b26-b5e2-2af197ac573e">
<br>

### 스테이지 클리어 화면
<img width = 600 height = 300 src="https://github.com/user-attachments/assets/dba3cc59-b0d5-4a91-b9bc-11370adf752c">
<br><br>

나머지 스테이지 및 화면은 직접 플레이해보며 확인해볼 수 있음.

## 파일 설명

### main.c
실제로 게임이 실행되는 main함수가 담겨있는 파일이며, 주요 함수 및 구조체, 변수 등이 같이 작성되어있다.

### Bgm.h
배경음악 재생과 관련된 함수코드가 작성되어있다.

### Cursor.h
화면출력에 필요한 커서이동에 관련된 함수코드가 작성되어있다.

### Data_Module.
게임 기록과 관련된 함수코드 및 구조체가 작성되어있다.

### Info.h
색상, 게임 캐릭터 및 몹 모델에 관련된 데이터가 작성되어있다. enum, 함수 및 0,1로 구성된 다차원배열 등으로 구성되어있다.

### MapInfo.h
맵에 관한 데이터가 작성되어있다. 0,1의 데이터로 구성된 다차원 배열로 작성되어있다.

### Sound.h
효과음 재생과 관련된 함수코드가 작성되어있다.

### Stage_UI.h
맵 이외의 게임화면들에 대한 데이터가 작성되어있다. printf()함수와 색상함수 등 출력 위주로 화면을 구성했다.
<br><br><br>

## 폴더 설명
### data
게임 클리어 기록과 관련된 데이터가 작성되어있다. 해당 폴더 내 AllRecord.txt의 입출력을 통해 게임 내에서 관리된다.

### bgm
게임 내 배경음악 및 효과음 파일들이 담겨있다.
<br><br><br>

## 사용 헤더파일(라이브러리)
```
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <conio.h>
#include <time.h>
#include <mmsystem.h>
#include <process.h>
```
