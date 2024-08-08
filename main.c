

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <mmsystem.h>

#pragma comment (lib, "winmm.lib")

#include "Cursor.h"
#include "Info.h"
#include "MapInfo.h"
#include "Data_Module.h"
#include "Stage_UI.h"
#include "Bgm.h"

#define TRUE 1
#define FALSE 0

#define MINUTE 60

#define SPACE 32

#define MAX_BULLET 10000
#define MAX_PIECE 3

#define START_CURSOR_X 70
#define START_CURSOR_Y 26
#define HELP_CURSOR_Y 29
#define RECORD_CURSOR_Y 32

#define PAUSE_HELP_CURSOR_Y 16
#define PAUSE_QUIT_CURSOR_Y 19



/* Search Table */
        
// main Search              (main �Լ�)
// Board Search             (���Ӻ��� ȭ�� �Լ� ����)
// ProcessKey Search        (Ű �Է� ����)
// ShowDelete Search        (Show, Delete �Լ� ����)
// DetectCollision Search   (DetectCollision �Լ� ����)
// BlockUpDown Search       (BlockUp, BlockDown �Լ� ����)
// ShiftJump Search         (Shift, Jump �Լ� ����)
// BulletShoot Search       (Bullet ���� �� �߻� �Լ� ����)




/* header Table */

// Cursor.h                 (Remove, Set, GetĿ�� �Լ� ����)
// Data_Module.h            (������ ��� ���� �Լ� ����)
// Info.h                   (��� �� ��ü ����ǥ, ����Լ�, ������ ���� ����)
// MapInfo.h                (�������� ������ �迭 ����)
// Stage_UI.h               (�������̽� ��� ����)





// Variable Search
// (�������� ����)
// Variable
// Variable
//=======================================================================================================
int gameBoardInfo[50][80];
int flag_page = 0;

int num_stage_first = 1;    //���� ���� ù ���� ����
int limit_time_first = MINUTE * 10;     //�������� ���ѽð� ����
int limit_time_six = MINUTE * 60;

int character_npc_location = 0;
int R_KeyCheck = 0;
int Death = FALSE;

int coin = 0;
int coin_flag = 0;

int goal1 = 0;
int goal2 = 0;
int fail = 0; //���ѽð� �ʰ�, ���� ����

int character1_id = 0;
int character2_id = 1;

int leftRight_1 = 2;
int leftRight_2 = 2;

int b_index1 = 0;
int b_index2 = 0;

int p_index1 = 0;   //12.07
int p_index2 = 0;   //12.07

int time_stop1 = 0; //12.07
int time_stop2 = 0;
int time_stop_flag = 0;

int flag_Bullet = 0;

int weapon_id = 100;
int speed_fall = 50;
int interval = 1;
int life = 0;
int score = 0;

int jumpcheck1 = 0;
int jumpcheck2 = 0;

//npc ����
int npc1_Life = 0;
int npc2_Life = 0;
int npc3_Life = 0;
int npc4_Life = 0;

int npc1_Die_Check = 0;
int npc2_Die_Check = 0;
int npc3_Die_Check = 0;
int npc4_Die_Check = 0;

int turn_npc1 = 0; 
//npc1�� ���� ������ ������ 1�����ϰ� �׿����� �������� �̵����� ���������� �̵����� ����
int turn_npc2 = 0;
int turn_npc3 = 0;
int turn_npc4 = 0;

int turn_Movingblock = 0; //1129

int Razercount = 0;
int count1 = 0;
int RazerSize = 5;


int BossMove1 = 0;
int BossMove2 = 0;
int BossMove1downcheck = 0;
int BossMove2downcheck = 0;

int BossStop1 = 0;
int BossStop2 = 0;

//npc id�� 0���� ����
//========================================================================================================






// Struct Search
// (����ü ����)
// Struct
// Struct
//=======================================================================================================
struct {
    int exist;
    int X, Y;
    int interval;
    int start;
}Bullet_1[MAX_BULLET];
struct {
    int exist;
    int X, Y;
    int interval;
    int start;
}Bullet_2[MAX_BULLET];

struct {
    int exist;
    int X, Y;
    int start;
}Piece_1[MAX_PIECE];
struct {
    int exist;
    int X, Y;
    int start;
}Piece_2[MAX_PIECE];

struct {
    int p1_location[2];
    int p2_location[2];
    int npc1_location[2];
    int npc2_location[2];
    int npc3_location[2];
    int npc4_location[2];
    int Moveblock1_location[2];
    int Moveblock2_location[2];
    int Movingblock_location[2];
    int Boss1_location[2];
    int Boss2_location[2];


}Map_information_Cursor[6];
//=======================================================================================================



/*�Լ� ���� ���� (����)*/
//=======================================================================================================
int ProcessKeyDirection(COORD* cursor);
void RedrawGameBoard(void);
void clearBoard();
void RightUI(int num_stage);
int setTimer(int x, int y, time_t start_time, int limit_time);
void ProcessKeyInput(COORD* p1, COORD* p2);
void ReStart(COORD* p1, COORD* p2, COORD* NPC1, COORD* NPC2, COORD* NPC3, COORD* Block1, COORD* Block2, COORD* Movingblock, COORD* Boss1cursor, COORD* Boss2cursor,int num_stage);

void ShowCharacter(char characterModel[2][1], COORD* cursor, int character_id);
void ShowBullet(int x, int y, int weapon_id, int interval);
void Shownpc1(char npcModel[2][2], COORD* cursor, int npc_id);
void Shownpc2(char npcModel[2][2], COORD* cursor, int npc_id);
void Shownpc3(char npcModel[2][2], COORD* cursor, int npc_id);
void ShowBlock(COORD* cursor);
void ShowItem(int x, int y);

void DeleteCharacter(char characterModel[2][1], COORD* cursor);
void DeleteBullet(int x, int y);
void Deletenpc(char npcModel[2][2], COORD* cursor);
void DeleteBlock(COORD* cursor);


void ShiftLeft_Character(COORD* cursor, int character_id);
void ShiftRight_Character(COORD* cursor, int character_id);
void Jump_Character(COORD* cursor, int character_id);
void ShiftLeft_npc(COORD* cursor, int npc_id);
void ShiftRight_npc(COORD* cursor, int npc_id);

int DetectCollision_Character(int posX, int posY, char characterModel[2][1]);
int DetectCollision_Bullet(int x, int y);
int DetectCollision_npc(int posX, int posY, char npcModel[2][2]);

int BlockUp_Character(COORD* cursor, int character_id);
int BlockDown_Character(COORD* cursor, int character_id);

void Bullet_1_Shoot(COORD* cursor, char characterModel[2][1], int character_id);
void Bullet_2_Shoot(COORD* cursor, char characterModel[2][1], int character_id);

void Piece_1_Start();
void Piece_1_Drop();
void Piece_2_Start();
void Piece_2_Drop();


void ShowMovingBLock(COORD* cursor);  //1129
void ShiftLeft_MovingBlock(COORD* cursor);  //1129
void ShiftRight_MovingBlock(COORD* cursor);  //1129
int DetectCollision_MovingBlockLeft(int posX, int posY);
int DetectCollision_MovingBlockRight(int posX, int posY);
void DeleteMovingBLock(COORD* cursor);


void ShowBoss(char Boss[10][10], COORD* cursor, int Boss_id,int num_stage);
void DeleteBoss(char characterModel[10][10], COORD* cursor);
void ShiftLeft_Boss(COORD* cursor, int Boss_id);
void ShiftRight_Boss(COORD* cursor, int Boss_id);
void ShiftUp_Boss(COORD* cursor, int Boss_id);
void ShiftDown_Boss(COORD * cursor, int Boss_id);
int DetectCollision_Boss(int posX, int posY, char Boss[10][10]);


int DetectCollision_Razer(int posX, int posY, char Razer,int count);
void ShowRazer(char Razer[10], COORD* cursor, int razerId, int count);
void DeleteRazer(char Razer[10], COORD* cursor, int razerId, int count);
void shiftLeftRazer( COORD* cursor, int razerId, int count);

//=======================================================================================================
// main Search
//(�����Լ�)
int main() {




    //-------------------------����ü ����------------------------------
    // ��1
    Map_information_Cursor[0].p1_location[0] = 2;  //p1�� x��ǥ
    Map_information_Cursor[0].p1_location[1] = 15;  //p1�� y��ǥ
    Map_information_Cursor[0].p2_location[0] = 2;  //p2�� x��ǥ
    Map_information_Cursor[0].p2_location[1] = 40;  //p2�� y��ǥ
    Map_information_Cursor[0].npc1_location[0] = 130;
    Map_information_Cursor[0].npc1_location[1] = 22;
    Map_information_Cursor[0].npc2_location[0] = 130;
    Map_information_Cursor[0].npc2_location[1] = 46;
    Map_information_Cursor[0].npc3_location[0] = 0;
    Map_information_Cursor[0].npc3_location[1] = 0;
    Map_information_Cursor[0].Movingblock_location[0] = 4;
    Map_information_Cursor[0].Movingblock_location[1] = 1;
    //----------------------------------------------------------

    //��2
    Map_information_Cursor[1].p1_location[0] = 2;  //p1�� x��ǥ
    Map_information_Cursor[1].p1_location[1] = 15;  //p1�� y��ǥ
    Map_information_Cursor[1].p2_location[0] = 2;  //p2�� x��ǥ
    Map_information_Cursor[1].p2_location[1] = 40;  //p2�� y��ǥ
    Map_information_Cursor[1].npc1_location[0] = 40;
    Map_information_Cursor[1].npc1_location[1] = 22;
    Map_information_Cursor[1].npc2_location[0] = 130;
    Map_information_Cursor[1].npc2_location[1] = 22;
    Map_information_Cursor[1].npc3_location[0] = 0;
    Map_information_Cursor[1].npc3_location[1] = 0;
    Map_information_Cursor[1].Movingblock_location[0] = 4;
    Map_information_Cursor[1].Movingblock_location[1] = 1;
    //----------------------------------------------------------
    //��3
    Map_information_Cursor[2].p1_location[0] = 4;  //p1�� x��ǥ   //4
    Map_information_Cursor[2].p1_location[1] = 15;  //p1�� y��ǥ    //15
    Map_information_Cursor[2].p2_location[0] = 4;  //p2�� x��ǥ    //4
    Map_information_Cursor[2].p2_location[1] = 43;  //p2�� y��ǥ
    Map_information_Cursor[2].npc1_location[0] = 130;
    Map_information_Cursor[2].npc1_location[1] = 16;
    Map_information_Cursor[2].npc2_location[0] = 130;
    Map_information_Cursor[2].npc2_location[1] = 8;
    Map_information_Cursor[2].Moveblock1_location[0] = 78;
    Map_information_Cursor[2].Moveblock1_location[1] = 40;
    Map_information_Cursor[2].Moveblock2_location[0] = 94;
    Map_information_Cursor[2].Moveblock2_location[1] = 34;
    Map_information_Cursor[2].npc3_location[0] = 0;
    Map_information_Cursor[2].npc3_location[1] = 0;
    Map_information_Cursor[2].Movingblock_location[0] = 4;
    Map_information_Cursor[2].Movingblock_location[1] = 1;

    //----------------------------------------------------------
    //��4
    Map_information_Cursor[3].p1_location[0] = 4;  //p1�� x��ǥ   //4
    Map_information_Cursor[3].p1_location[1] = 18;  //p1�� y��ǥ    //18
    Map_information_Cursor[3].p2_location[0] = 4;  //p2�� x��ǥ    //4
    Map_information_Cursor[3].p2_location[1] = 43;  //p2�� y��ǥ //43

    Map_information_Cursor[3].npc1_location[0] = 120;
    Map_information_Cursor[3].npc1_location[1] = 22;
    Map_information_Cursor[3].npc2_location[0] = 130;
    Map_information_Cursor[3].npc2_location[1] = 46;
    Map_information_Cursor[3].npc3_location[0] = 70;
    Map_information_Cursor[3].npc3_location[1] = 38;
    Map_information_Cursor[3].Moveblock1_location[0] = 0;
    Map_information_Cursor[3].Moveblock1_location[1] = 0;
    Map_information_Cursor[3].Moveblock2_location[0] = 0;
    Map_information_Cursor[3].Moveblock2_location[1] = 0;
    Map_information_Cursor[3].Movingblock_location[0] = 0;
    Map_information_Cursor[3].Movingblock_location[1] = 1;
    //----------------------------------------------------------
    //��5
    Map_information_Cursor[4].p1_location[0] = 4;  //p1�� x��ǥ   //4
    Map_information_Cursor[4].p1_location[1] = 18;  //p1�� y��ǥ    //18
    Map_information_Cursor[4].p2_location[0] = 4;  //p2�� x��ǥ    //4
    Map_information_Cursor[4].p2_location[1] = 43;  //p2�� y��ǥ //43
  
    Map_information_Cursor[4].npc1_location[0] = 130;
    Map_information_Cursor[4].npc1_location[1] = 46;
    Map_information_Cursor[4].npc2_location[0] = 130;
    Map_information_Cursor[4].npc2_location[1] = 41;
    Map_information_Cursor[4].npc3_location[0] = 120;
    Map_information_Cursor[4].npc3_location[1] = 21;
    Map_information_Cursor[4].Moveblock1_location[0] = 46;
    Map_information_Cursor[4].Moveblock1_location[1] = 14;
    Map_information_Cursor[4].Moveblock2_location[0] = 62;
    Map_information_Cursor[4].Moveblock2_location[1] = 9;
    Map_information_Cursor[4].Movingblock_location[0] = 20;
    Map_information_Cursor[4].Movingblock_location[1] = 35;
    //----------------------------------------------------------
    //��6
    Map_information_Cursor[5].p1_location[0] = 2;  //p1�� x��ǥ   //2
    Map_information_Cursor[5].p1_location[1] = 19;  //p1�� y��ǥ    //19
    Map_information_Cursor[5].p2_location[0] = 2;  //p2�� x��ǥ    //2
    Map_information_Cursor[5].p2_location[1] = 43;  //p2�� y��ǥ //43
    Map_information_Cursor[5].npc1_location[0] = 0;
    Map_information_Cursor[5].npc1_location[1] = 0;
    Map_information_Cursor[5].npc2_location[0] = 0;
    Map_information_Cursor[5].npc2_location[1] = 0;
    Map_information_Cursor[5].npc3_location[0] = 0;
    Map_information_Cursor[5].npc3_location[1] = 0;
    Map_information_Cursor[5].Moveblock1_location[0] = 0;
    Map_information_Cursor[5].Moveblock1_location[1] = 0;
    Map_information_Cursor[5].Moveblock2_location[0] = 0;
    Map_information_Cursor[5].Moveblock2_location[1] = 0;
    Map_information_Cursor[5].Movingblock_location[0] = 0;
    Map_information_Cursor[5].Movingblock_location[1] = 1;

    Map_information_Cursor[5].Boss1_location[0] = 138;
    Map_information_Cursor[5].Boss1_location[1] = 14;
    Map_information_Cursor[5].Boss2_location[0] = 138;
    Map_information_Cursor[5].Boss2_location[1] = 38;



   




    
    //-------------------------����ü ����-------------------------------

    RemoveCursor();

    system("mode con cols=200 lines=100 | title TWIN");
    clock_t start = clock();
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD p1, p2;
    COORD npc1, npc2, npc3;
    COORD block1, block2;

    COORD Movingblock; 
    COORD Boss1cursor;
    COORD Boss2cursor;
    COORD Razer1cursor;
    COORD Razer2cursor;
    COORD Razer3cursor;
    COORD Razer4cursor;

    COORD Selecter = { START_CURSOR_X,START_CURSOR_Y };

    time_t start_time = clock();
    int Time_correction = 0;
    int npc_Speed = 5;
    npc1_Life = 3;
    npc2_Life = 3;
    npc3_Life = 3;
    npc4_Life = 3;

    //---------------
    int kk = 0;



    int start_game = TRUE; 
    //���� ����ȭ�� ���� ����, ���� Ŭ����, ���� ����, ���� ����� �ٽ� ȭ�鿡 ���ƿ� ���

    while (1) { //���� ����
        if (start_game)
            PlayBgm(Path_Interface);
        int page = 0;
        int pause_flag = 0;
        int pause_quit = 0;
        int total_time = 0;

        int num_stage = num_stage_first;

        clearBoard();   //Ŭ�����
        printStartUI_Twin(start_game);  //����ȭ�鿡�� "Ʈ��" Ÿ��Ʋ ��� //��������
        printStartUI_Button(start_game);    //����ȭ�鿡�� ��ư�� ���
        start_game = FALSE;
        page = ProcessKeyDirection(&Selecter);
        SetCurrentCursorPos(0, 0);

        if (page == 1) { // '�����ϱ�' ��ư Ŭ�� ��
            PlayBgm(Path_Intro);


            flag_page = 1;
            printBeforeStart();

            total_time = 0;
            life = 0;
            score = 0;
            coin = 0;
            fail = 0;
            goal1 = goal2 = 0;




            StopBgm();
            while (page) {
                //�������� �ϳ� ���� ����
                //& �����ϰ� �絵�� �� �� �� page�� 0���� �ٲ�鼭 Ż��, �������̽��� ����
                //�絵�� �� : page = 1 ����, �ٽ� ���� ����


                //---------------------------
          
                clearBoard();
                if (num_stage == 6)
                    //���� �ó����� ���
                {   
                    for (int i = 0; i < 50; i++) {
                        for (int j = 0; j < 80; j++) {
                            gameBoardInfo[i][j] = BeforeBossMap[i][j];
                        }
                    }
                    RedrawGameBoard();
                    printBossScenario();
                }
                clearBoard();
                printBeforeStage(num_stage);    //�������� ���� �� "�� O��" ���  //��������


                ReStart(&p1, &p2, &npc1, &npc2, &npc3, &block1, &block2, &Movingblock, &Boss1cursor, &Boss2cursor, num_stage);
                RedrawGameBoard();
                RightUI(num_stage);
                


                switch (num_stage) {
                case 1:
                    PlayBgm(Path_Stage_1);
                    break;
                case 2:
                    PlayBgm(Path_Stage_2);
                    break;
                case 3:
                    PlayBgm(Path_Stage_3);
                    break;
                case 4:
                    PlayBgm(Path_Stage_4);
                    break;
                case 5:
                    PlayBgm(Path_Stage_5);
                    break;
                case 6:
                    PlayBgm(Path_Boss);
                    break;
                default:
                    break;
                }
                time_t start_time = clock();    
                    //���ѽð� üũ�� start_time
                int limit_time = limit_time_first;
                int left_time = limit_time;

                if (num_stage == 6) {
                    limit_time = limit_time_six;
                }

                time_stop1 = time_stop2 = FALSE;
                time_stop_flag = FALSE;
                Death = FALSE;

                while (!pause_quit) { //�������� �ʱ�ȭ �� �����
                    
                    time_t start_time2 = clock();   
                        //�������� �� ��ҵ� �ð�üũ��

                    while (Death == FALSE && goal1 + goal2 != 2 && left_time > 0) {  // ������ �ϳ�
                        

                        if (coin_flag == TRUE) {           //���� �Ծ��� �� RightUI ������Ʈ 
                            RightUI(num_stage);
                            coin_flag = FALSE;
                        }

                        left_time = setTimer(166, 8, start_time, limit_time);



                        //============�ð�����===========(����)//

                        if (left_time < MINUTE * 5 &&
                            (!time_stop1 || !time_stop2)) {    //12.07
                            //12.07 : 3�ܰ質 5�ܰ��� �� ������ ����ֱ�
                            if (num_stage == 1 && time_stop1 != 2) {
                                time_stop1 = 1;
                                ShowItem(48, 21);
                            }
                            else if (num_stage == 2 && time_stop2 != 2) {
                                time_stop2 = 1;
                                ShowItem(78, 22);
                            }
                            else if (num_stage == 3 && time_stop2 != 2) {
                                time_stop2 = 1; //1�� 5�� ������ �� ������ ����ֱ�, 2�� �������� �Ծ��� ���
                                ShowItem(36, 46);
                            }
                            else if (num_stage == 4 && time_stop2 != 2) {
                                time_stop2 = 1;
                                ShowItem(136, 5);
                            }
                            else if (num_stage == 5 && time_stop1 != 2) {
                                time_stop1 = 1;
                                ShowItem(74, 21);
                            }
                        }
                        if (!time_stop_flag && (time_stop1 == 2 || time_stop2 == 2)) {
                            //������ �Ծ��� �� UI����
                            RightUI(num_stage);
                            time_stop_flag = 1;
                        }

                        //============�ð�����===========(��)//



                        if (GetAsyncKeyState(VK_ESCAPE) & 0x0001){  //�Ͻ�����
                           pause_quit = Pause();
                           if (pause_quit == 1) {
                               break;
                           }
                           clearBoard();
                           RedrawGameBoard();
                           RightUI(num_stage);
                        }   

                        if (BlockDown_Character(&p1, character1_id) == 4444) {
                            break;
                        }
                        if (BlockDown_Character(&p2, character2_id) == 4444) {
                            break;
                        }

                        if (goal1 == 1) {       //12.07                 
                           //ĳ����1�� ���������� ������ ĳ����2 �ð����� ��
                            DeleteCharacter(character1_id, &p1);
                            time_stop2 = 0;
                            RightUI(num_stage);
                        }
                        if (goal2 == 1) {
                            //ĳ����2�� ���������� ������ ĳ����2 �ð����� ��
                            DeleteCharacter(character2_id, &p2);
                            time_stop1 = 0;
                            RightUI(num_stage);
                        }

                        //----
                        ShowBoss(Boss[0], &Boss1cursor, 0, num_stage);
                        ShowBoss(Boss[1], &Boss2cursor, 1, num_stage);
                        //-------------------------------------------------
                        time_t end_time = clock();
                        int timecheck = (int)((end_time - start_time2) / (CLOCKS_PER_SEC * 1 / npc_Speed)) + Time_correction;
                        // CLOCKS_PER_SEC/npc_Speed dptj npc_Speed�� �����ϸ� npc�� �ӵ� ������ ������

                        if (timecheck % 2 == 0)
                        {
                            Time_correction += 1;
                            if (turn_Movingblock % 2 == 0) {
                                ShiftLeft_MovingBlock(&Movingblock);
                            }
                            else
                                ShiftRight_MovingBlock(&Movingblock);
                            if (turn_npc1 % 2 == 0)
                                ShiftLeft_npc(&npc1, 0);
                            else
                                ShiftRight_npc(&npc1, 0);

                            if (turn_npc2 % 2 == 0)
                                ShiftRight_npc(&npc2, 1);
                            else
                                ShiftLeft_npc(&npc2, 1);

                            if (npc3.X < p1.X)
                            {
                                ShiftRight_npc(&npc3, 2);
                            }
                            else
                                ShiftLeft_npc(&npc3, 2);
                        }




                        if (timecheck % 40 < 20) {
                            ShowBlock(&block1);
                            DeleteBlock(&block2);

                        }
                        if (timecheck % 40 > 20) {
                            DeleteBlock(&block1);
                            ShowBlock(&block2);
                        }
       
                        //------------------------------------------���� ���� //����
                        /*
                        Piece_1_Start();
                        while (1) {
                            Sleep(100);
                            Piece_1_Drop();
                        }*/

                        if (num_stage == 6) {
                            if (timecheck % 50 <= 49) {
                                if (timecheck % 50 == 0) {
                                    Piece_1_Start();
                                    Piece_2_Start();
                                }
                                Piece_1_Drop();
                                Piece_2_Drop();
                            }
                        }

                        
                        if (timecheck % 70 <= 65) {
                            count1 = 0;
                            if (timecheck % 70 == 0) {
                                RazerSize = (rand() % 2)+2;
                                if (BossMove1 == 0) {
                                    if (Razercount % 2 == 0) {
                                        Razer1cursor.X = Boss1cursor.X - 2 * RazerSize;
                                        Razer1cursor.Y = Boss1cursor.Y + 1;
                                    }
                                    else
                                    {
                                        Razer3cursor.X = Boss1cursor.X - 2 * RazerSize;
                                        Razer3cursor.Y = Boss1cursor.Y + 1;
                                    }
                                }
                                if (BossMove2 == 0) {
                                    if (Razercount % 2 == 0) {
                                        Razer2cursor.X = Boss2cursor.X - 2 * RazerSize;
                                        Razer2cursor.Y = Boss2cursor.Y + 1;
                                    }
                                    else
                                    {
                                        Razer4cursor.X = Boss2cursor.X - 2 * RazerSize;
                                        Razer4cursor.Y = Boss2cursor.Y + 1;
                                    }
                                    

                                }
                            }
                            
                            if (BossMove1 == 0) {
                                if (Razercount % 2 == 0) {
                                    shiftLeftRazer(&Razer1cursor, Razercount, RazerSize);
                                }
                                else {
                                    shiftLeftRazer(&Razer3cursor, Razercount, RazerSize);
                                }
                            }
                            if (BossMove2 == 0) {
                                if (Razercount % 2 == 0) {
                                    shiftLeftRazer(&Razer2cursor, Razercount, RazerSize);
                                }
                                else {
                                    shiftLeftRazer(&Razer4cursor, Razercount, RazerSize);
                                }
                            }
                            
                            //
                            
                        }
                        
                        else if (timecheck % 70 == 69 && count1 ==0) {
                            Razercount++;
                            count1 = 1;
                        }


                        if (BossMove1 == 0) {
                            if (timecheck % 1000 < 999) {
                                if (p1.Y - 2 > Boss1cursor.Y) {
                                    ShiftDown_Boss(&Boss1cursor, 0);
                                }
                                else if (p1.Y - 2 < Boss1cursor.Y)
                                    ShiftUp_Boss(&Boss1cursor, 0);

                            }
                        }
                        

                        if (BossMove1downcheck == 0) {
                            if (BossMove1 == 1) {
                                if (timecheck % 1000 < 999) {
                                    ShiftDown_Boss(&Boss1cursor, 0);
                                }
                            }
                        }

                        if (BossMove1downcheck == 1)
                        {
                            if (BossStop1 == 0) {
                                if (timecheck % 1000 < 999) {
                                    if (Boss1cursor.X > 3)
                                        ShiftLeft_Boss(&Boss1cursor, 0);
                                    
                                        
                                }
                            }
                            else
                                DeleteBoss(Boss[0], &Boss1cursor);
                        }

                        if (BossMove2 == 0) {
                            if (timecheck % 1000 < 999) {
                                if (p2.Y - 2 > Boss2cursor.Y) {
                                    ShiftDown_Boss(&Boss2cursor, 1);
                                }
                                else if (p2.Y - 2 < Boss2cursor.Y)
                                    ShiftUp_Boss(&Boss2cursor, 1);
                            }
                        }
                        if (BossMove2downcheck == 0) {
                            if (BossMove2 == 1) {
                                if (timecheck % 1000 < 999) {
                                    ShiftDown_Boss(&Boss2cursor, 1);
                                }
                            }
                        }

                        if (BossMove2downcheck == 1)
                        {
                            if (BossStop2 == 0){
                                if (timecheck % 1000 < 999) {
                                    if (Boss2cursor.X > 2)
                                        ShiftLeft_Boss(&Boss2cursor, 1);
                                }
                            }
                            else
                                DeleteBoss(Boss[1], &Boss2cursor);
                        }


                        //����-------------------------------------------
                        ProcessKeyInput(&p1, &p2);
                        if (R_KeyCheck == 1)
                            break;

                        if (BossStop1 == TRUE && BossStop2 == TRUE && num_stage == 6)
                            StopBgm();
                    }
    
                    if (Death == TRUE || R_KeyCheck == 1) {
                        goal1 = 0;
                        goal2 = 0;

                        time_stop1 = 0;
                        time_stop2 = 0;
                        time_stop_flag = 0;
                        life++;

                        if (Death == TRUE) {
                                                        
                            DeleteCharacter(characterModel[0], &p1);
                            DeleteCharacter(characterModel[1], &p2);
                            Sleep(100);

                            ShowCharacter(characterModel[0], &p2, 1);
                            ShowCharacter(characterModel[1], &p2, 2);
                            Sleep(100);
                            
                            
                        }
                        Death = FALSE;


                        R_KeyCheck = 0;

                        

                        ReStart(&p1, &p2, &npc1, &npc2, &npc3, &block1, &block2, &Movingblock, &Boss1cursor,&Boss2cursor, num_stage);
                        Shownpc1(npcModel[0], &npc1, 0);  //npcid=0�̶�� �����Ѱ���
                        Shownpc2(npcModel[1], &npc2, 1);  //npcid=0�̶�� �����Ѱ���
                        Shownpc2(npcModel[2], &npc3, 2);  //npcid=0�̶�� �����Ѱ���
                        ShowMovingBLock(&Movingblock);
                        ShowBoss(Boss[0], &Boss1cursor, 0, num_stage);
                        ShowBoss(Boss[1], &Boss2cursor, 1, num_stage);

                 
                        
                        
                        npc1_Die_Check = 0;
                        npc2_Die_Check = 0;
                        npc3_Die_Check = 0;

                        npc1_Life = 3;
                        npc2_Life = 3;
                        npc3_Life = 3;
                        npc4_Life = 3;

                        

                        RedrawGameBoard();
                        RightUI(num_stage);

                    }
                    if (goal1 + goal2 == 2) {       //�������� Ŭ�������� ��
                        StopBgm();

                        clearBoard();
                        if (num_stage == 6) {
                            printClearBoss();
                            clearBoard();
                        }
                        

                        score = SetCurrentScore(limit_time, left_time, score, coin);   //������ ���
                        if (time_stop1 != 2 && time_stop2 != 2)
                            score += 20000;

                        if(num_stage!=6)
                            PlayBgm(Path_Clear); //
                        printClearUI(limit_time, left_time, score, life, coin, num_stage);                           
                        //������ ��� �� �������� ȯ��
                            StopBgm(); //

                        goal1 = goal2 = 0;
                        total_time += limit_time - left_time;
                        num_stage++;


                        //npc life�ʱ�ȭ
                        npc1_Die_Check = 0;
                        npc2_Die_Check = 0;
                        npc3_Die_Check = 0;

                        npc1_Life = 3;
                        npc2_Life = 3;
                        npc3_Life = 3;
                        npc4_Life = 3;


                        break;
                    }

                    if (left_time <= 0) { //�ð� �ʰ���
                        fail = 1;//����
                        break;
                    }
                }

                if (pause_quit) {       //�Ͻ��������� '���ӳ����� => YES�� Ŭ������ ��"
                    score = 0;
                    total_time = 0;
                    life = 0;
                    page = 0;   //���ӽ���ȭ������ ����
                    start_game = TRUE;
                    break;
                }

                else if (fail) { //�ð� �ʰ� ���� ��
                    PlayBgm(Path_Fail);
                    printFailUI();
                    score = 0;
                    while (1) {
                        if (GetAsyncKeyState(0x59) & 0x0001) {  //��õ� YES
                            fail = 0;
                            break;
                        }
                        if (GetAsyncKeyState(0x4E) & 0x0001) {  //��õ� NO
                            page = 0;
                            fail = 0;
                            start_game = TRUE;
                            break;
                        }
                    }
                    StopBgm();
                }


                else if (num_stage > 6) {   //�� Ŭ����� (���������ѹ��� 6�� �Ѿ ��)
                    PlayBgm(Path_AllClear);
                    clearBoard();
                    printFrameUI();
                    setRecords(total_time,score);
                    page = 0;               //����ȭ�� ����
                    score = 0;
                    total_time = 0;
                    start_game = TRUE;
                    StopBgm();
                }
            }
        }

        else if (page == 2) {
            flag_page = 1;
            clearBoard();
            while (page != 4) {
                printHelpUI();
                page = ProcessKeyDirection(&Selecter); //�齺���̽� Ŭ�� �� 4 ��ȯ, while�� Ż��
            }
        }

        else if (page == 3) {
            flag_page = 1;
            clearBoard();
            while (page != 4) {
                printRecrodUI();
                page = ProcessKeyDirection(&Selecter);
            }
        }
        flag_page = 0;
    }
    //Sleep(1000000);
    return 0;

}







// 
// Process Search
// ProcessKey
//=======================================================================================================

int ProcessKeyDirection(COORD* cursor) {
    while (1) {
        SetCurrentCursorPos(cursor->X, cursor->Y);
        if (!flag_page) {
            textcolor(RED);
            printf("��");
        }

        if (GetAsyncKeyState(VK_UP) & 0x0001) { //��
            if (cursor->Y > START_CURSOR_Y) {
                SetCurrentCursorPos(cursor->X, cursor->Y);
                printf("  ");
                cursor->Y -= 3;
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x0001) { //�Ʒ�
            if (cursor->Y < RECORD_CURSOR_Y) {
                SetCurrentCursorPos(cursor->X, cursor->Y);
                printf("  ");
                cursor->Y += 3;
            }
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (cursor->Y == START_CURSOR_Y) {
                printf("  ");
                return 1;
            }
            else if (cursor->Y == HELP_CURSOR_Y) {
                printf("  ");
                return 2;
            }
            else if (cursor->Y == RECORD_CURSOR_Y) {
                printf("  ");
                return 3;
            }
        }

        if (GetAsyncKeyState(VK_BACK) & 0x0001){
            printf("  ");
            return 4;
        }
    }
}

int ProcessKeyDirectionPause(COORD* cursor) {
    while (1) {
        SetCurrentCursorPos(cursor->X, cursor->Y);
        printf("��");

        if (GetAsyncKeyState(VK_UP) & 0x0001) { //��
            if (cursor->Y > PAUSE_HELP_CURSOR_Y) {
                SetCurrentCursorPos(cursor->X, cursor->Y);
                printf("  ");
                cursor->Y -= 3;
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x0001) { //�Ʒ�
            if (cursor->Y < PAUSE_QUIT_CURSOR_Y) {
                SetCurrentCursorPos(cursor->X, cursor->Y);
                printf("  ");
                cursor->Y += 3;
            }
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (cursor->Y == PAUSE_HELP_CURSOR_Y) {
                printf("  ");
                return 1;
            }
            else if (cursor->Y == PAUSE_QUIT_CURSOR_Y) {
                printf("  ");
                return 2;
            }
        }

        if (GetAsyncKeyState(VK_BACK) & 0x0001 || GetAsyncKeyState(VK_ESCAPE) & 0x0001) {
            printf("  ");
            return 3;
        }
    }
}
int Pause() {
        int pause_page = 0;
        COORD pause_point = { 75, PAUSE_HELP_CURSOR_Y };

        while (1) {
            clearBoard();
            printPauseUI();
            pause_page = ProcessKeyDirectionPause(&pause_point);
            if (pause_page == 1) {
                clearBoard();
                printPauseHelpUI();
                while (1) {
                    if (GetAsyncKeyState(VK_BACK) & 0x0001) {
                        pause_page = 0; //0�� �׳� �⺻ �Ͻ�����â���� �����Ѵٴ� �ǹ�
                        break;
                    }
                    if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) { //���� â���� ESC���� �� �ٷ� �Ͻ����� â ����
                        return 0;
                    }
                }
            }
            else if (pause_page == 2) {
                clearBoard();
                printPauseQuitUI();
                while (1) {
                    if (GetAsyncKeyState('Y') & 0x0001) {  //yes
                        life = 0;
                        score = 0;
                        coin = 0;
                        return 1;
                    }
                    else if (GetAsyncKeyState('N') & 0x0001) {       //���� ������ no
                        pause_page = 0;
                        break;
                    }
                    else if (GetAsyncKeyState(VK_ESCAPE) & 0x0001) { //���� ������ â���� ESC���� �� �ٷ� �Ͻ����� â ����
                        return 0;
                    }
                }
            }
            else if (pause_page == 3) {
                return 0;           //
            }
        }
    
}
void ProcessKeyInput(COORD* p1, COORD* p2)
{

    if (GetAsyncKeyState('R') & 0x8000) {
        R_KeyCheck = 1;
    }

    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        if (!goal1 && time_stop1 != 2) {
            //12.07 time_stop1=2��� => ĳ���� 1 ���� �ߵ� => �ش� ���ǹ� ���� x
            ShiftLeft_Character(p1, character1_id);
            leftRight_1 = 1;
        }
        if (!goal2 && time_stop2 != 2) {       //12.07
            //time_stop �������� ȹ������ �� ĳ����2 ����
            ShiftLeft_Character(p2, character2_id);
            leftRight_2 = 1;
        }
       
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        if (!goal1 && time_stop1 != 2) {
            ShiftRight_Character(p1, character1_id);
            leftRight_1 = 2;
        }
        if (!goal2 && time_stop2 != 2) {        //12.07
            ShiftRight_Character(p2, character2_id);
            leftRight_2 = 2;
        }
    }

    if (GetAsyncKeyState(VK_UP) & 0x8000) { //��

        if (!goal1 && time_stop1 != 2) {

            Jump_Character(p1, character1_id);
            jumpcheck1 += 1;
        }
        if (!goal2 && time_stop2 != 2) {         //12.07

            Jump_Character(p2, character2_id);
            jumpcheck2 += 1;

        }
        Sleep(20);
        if (!goal1 && time_stop1 != 2) {
            Jump_Character(p1, character1_id);
            jumpcheck1 += 1;

        }
        if (!goal2 && time_stop2 != 2) {         //12.07
            Jump_Character(p2, character2_id);
            jumpcheck2 += 1;

        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            if (!goal1 && time_stop1 != 2)
                ShiftRight_Character(p1, character1_id);
            if (!goal2 && time_stop2 != 2)          //12.07
                ShiftRight_Character(p2, character2_id);

        }
        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            if (!goal1 && time_stop1 != 2)
                ShiftLeft_Character(p1, character1_id);
            if (!goal2 && time_stop2 != 2)           //12.07
                ShiftLeft_Character(p2, character2_id);

        }

        //  Jump_Character(p1);


    }
    Bullet_1_Shoot(p1, characterModel[character1_id], character1_id);
    Bullet_2_Shoot(p2, characterModel[character2_id], character2_id);


    Sleep(speed_fall); //Sleep(spped) �ؼ� speed ���� �����ص���
}







// Board Search
// Board
// Board
//=======================================================================================================
void clearBoard() {
    SetCurrentCursorPos(0, 0);
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 189; j++) {
            printf(" ");
        }
        printf("\n");
    }
    SetCurrentCursorPos(0, 0);
}

void RedrawGameBoard(void)
{
    SetCurrentCursorPos(0, 0);
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 80; j++)
            obstacle(gameBoardInfo[i][j]);
        printf("\n");
    }
}

void RightUI(int num_stage) {       //12.07
    int x, y;
    int GBOARD_HEIGHT, GBOARD_WIDTH, GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y;
    int UI_START_X;

    GBOARD_HEIGHT = 18;
    GBOARD_WIDTH = 12;
    GBOARD_ORIGIN_X = 161;
    GBOARD_ORIGIN_Y = 6;

    UI_START_X = 165;

    //�� �κ�
    //�� �κ�
    //�� �κ�
    textcolor(DarkGray);
    //���ʺ�
    for (y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);

        if (y == 0)
        {
            printf("��");
        }
        else {
            printf("��");
        }
    }

    //�غ�
    for (x = 1; x < GBOARD_WIDTH + 1; x++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT);
        printf("��");
    }

    //�����ʺ�
    for (y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + y);
        if (y == 0)
            printf("��");
        else
            printf("��");
    }



    //����
    for (x = 1; x < GBOARD_WIDTH + 1; x++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y);
        printf("��");
    }


    //�� �κ�
    //�� �κ�
    //�� �κ�
    for (y = 0; y <= 0 + GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + GBOARD_HEIGHT + y);

        if (y == GBOARD_HEIGHT)
            printf("��");
        else
            printf("��");
    }

    //�����ʺ�
    for (y = 0; y <= GBOARD_HEIGHT; y++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + (GBOARD_WIDTH + 1) * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT + y);

        if (y == GBOARD_HEIGHT)
            printf("��");
        else
            printf("��");
    }
    for (x = 1; x < GBOARD_WIDTH + 1; x++)
    {
        SetCurrentCursorPos(GBOARD_ORIGIN_X + x * 2, GBOARD_ORIGIN_Y + GBOARD_HEIGHT * 2);
        printf("��");
    }



    //�������� ��
    SetCurrentCursorPos(UI_START_X + 2, GBOARD_ORIGIN_Y - 1);
    textcolor(RED);
    switch (num_stage) {
    case 1:
        printf("STAGE : �� 1 ��");
        break;
    case 2:
        printf("STAGE : �� 2 ��");
        break;
    case 3:
        printf("STAGE : �� 3 ��");
        break;
    case 4:
        printf("STAGE : �� 4 ��");
        break;
    case 5:
        printf("STAGE : �� 5 ��");
        break;
    case 6:
        printf("STAGE : �� �� ��");
        break;
    }



    //��ȰȽ��
    SetCurrentCursorPos(UI_START_X, GBOARD_ORIGIN_Y + 6);
    textcolor(RED);
    printf("��ȰȽ��");
    textcolor(WHITE);
    printf("\tx %d", life);


    //���� ǥ��
    SetCurrentCursorPos(UI_START_X, GBOARD_ORIGIN_Y + 9);
    textcolor(SkyBlue);
    printf("S C O R E");
    textcolor(WHITE);
    printf("\t%06d", score);


    //������
    SetCurrentCursorPos(UI_START_X, GBOARD_ORIGIN_Y + 12);
    obstacle(11);
    printf("\t");
    textcolor(WHITE);
    printf("\tx %d", coin);


    //������
    SetCurrentCursorPos(UI_START_X, GBOARD_ORIGIN_Y + 15);
    textcolor(GREEN);
    printf("I T E M   ");
    if (time_stop1 == 2 || time_stop2 == 2) {
        printf("\t");
        obstacle(500);
    }
    else {
        printf("\t  ");
        SetCurrentCursorPos(UI_START_X, GBOARD_ORIGIN_Y + 15);
        textcolor(GREEN);
        printf("I T E M   ");
        textcolor(WHITE);
        printf("\tX");
    }


    //ĳ���͵� ��Ʈ
    //15��
    //18��
    char Hint_p1[6][4][100] = {
        { "�� ����? �츮",
          "\t ���� ����",
         " \t �����̴µ� ?",
        },
        {"���� ����",
        "\t ������ ����",
        "\t �ʰ� ��������",
        "\t �� �� ����."},

        {"���� ����",
        "\t ��ư����?",
        "",
        ""},

        {"�̷�, ����",
        "\t �� �̸� ����?",
        "\t �ű⿡ ��Ʈ",
        "\t ������ ����?"},

        {"�� ģ����",
        "\t ��� �츱",
        "\t ������� ��",
        "\t ����"},

        {"��� �н���",
        "\t ���־� �ϴ°���?.",
        "\t ��ư�� ��� ������",
        "\t �ϴ°ǰ�?"}
    };

    char Hint_p2[6][4][100] = {
    { "������ ��",
        "\t ���� ����",
        "\t �����±�.",
      ""},

        {"����. ����",
        "\t ������ ����",
        "\t ��ٸ���",
        "\t ������"},

        {"���� �� �ʿ���",
        "\t ���θ���",
        "\t ���̶� ����",
        "\t ���� �� ����."},

        {"���� �����",
        "\t ���� �ִµ�,",
        "\t ���� ��������..?,",
        "\t �� ����..? ��."},

        {"�� �¾Ƶ�",
        "\t �������� ��",
        "\t ������...",
        ""},

        {"��ư���� ������",
        "\t ���� ����",
        "\t ���ߵǴ°� ",
        "\t ������...."}
    };

    //��Ʈâ
    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 2);
    obstacle(96);
    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 3);
    obstacle(97);

    textcolor(WHITE);
    printf(": ");
    printf("%s\n", Hint_p1[num_stage - 1][0]);
    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 4);
    printf("%s\n", Hint_p1[num_stage - 1][1]);
    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 5);
    printf("%s\n", Hint_p1[num_stage - 1][2]);
    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 6);
    printf("%s\n", Hint_p1[num_stage - 1][3]);



    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 8);
    obstacle(98);
    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 9);
    obstacle(99);

    textcolor(WHITE);
    printf(": ");
    printf("%s\n", Hint_p2[num_stage - 1][0]);
    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 10);
    printf("%s\n", Hint_p2[num_stage - 1][1]);
    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 11);
    printf("%s\n", Hint_p2[num_stage - 1][2]);
    SetCurrentCursorPos(UI_START_X, GBOARD_HEIGHT + GBOARD_ORIGIN_Y + 12);
    printf("%s\n", Hint_p2[num_stage - 1][3]);
}

int setTimer(int x, int y, time_t start_time, int limit_time) {
    time_t end_time = clock();
    int left_time = limit_time - (int)((end_time - start_time) / CLOCKS_PER_SEC);
    //���ѽð� - �����ð� = �����ð�
    //time_t������ CLOCKS_PER_SEC���� ������ second�� ȯ������

    SetCurrentCursorPos(x, y);
    //�ð� ǥ���� ��ǥ ����

    //�ð��� ���� ����
    if (left_time >= 60 * 30)
        textcolor(WHITE);
    else if (60 * 5 <= left_time && left_time < 60 * 10)
        textcolor(YELLOW);
    else if (60 * 1 <= left_time && left_time < 60 * 5)
        textcolor(DarkYellow);
    else if (60 * 0 <= left_time && left_time < 60 * 1)
        textcolor(RED);
    else
        textcolor(DarkRed);

    printf("�����ð� %02d : %02d", left_time / 60, left_time % 60);

    return left_time;
}
void ReStart(COORD* p1, COORD* p2, COORD* NPC1, COORD* NPC2, COORD* NPC3, COORD* Block1, COORD* Block2,COORD* Movingblock ,COORD* Boss1cursor, COORD* Boss2cursor, int num_stage) {
    //�� �ʸ��� ����ü �޾Ƽ� --------------------- �缳�� 
    int index_stage = num_stage - 1;
    coin = 0;
    BossStop1 = 0;    //���� ��ž ���� ������ üũ
    BossStop2 = 0;
    BossMove1 = 0;
    BossMove2 = 0;
    BossMove1downcheck = 0;
    BossMove2downcheck = 0;

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 80; j++) {
            gameBoardInfo[i][j] = mapModelInfo[index_stage][i][j];
        }
    }
    p1->X = Map_information_Cursor[index_stage].p1_location[0];
    p1->Y = Map_information_Cursor[index_stage].p1_location[1];

    p2->X = Map_information_Cursor[index_stage].p2_location[0];
    p2->Y = Map_information_Cursor[index_stage].p2_location[1];
    NPC1->X = Map_information_Cursor[index_stage].npc1_location[0];
    NPC1->Y = Map_information_Cursor[index_stage].npc1_location[1];

    NPC2->X = Map_information_Cursor[index_stage].npc2_location[0];
    NPC2->Y = Map_information_Cursor[index_stage].npc2_location[1];

    NPC3->X = Map_information_Cursor[index_stage].npc3_location[0];
    NPC3->Y = Map_information_Cursor[index_stage].npc3_location[1];

    Block1->X = Map_information_Cursor[index_stage].Moveblock1_location[0];
    Block1->Y = Map_information_Cursor[index_stage].Moveblock1_location[1];

    Block2->X = Map_information_Cursor[index_stage].Moveblock2_location[0];
    Block2->Y = Map_information_Cursor[index_stage].Moveblock2_location[1];


    Movingblock->X = Map_information_Cursor[index_stage].Movingblock_location[0];
    Movingblock->Y = Map_information_Cursor[index_stage].Movingblock_location[1];


    Boss1cursor->X= Map_information_Cursor[index_stage].Boss1_location[0];
    Boss1cursor->Y = Map_information_Cursor[index_stage].Boss1_location[1];

    Boss2cursor->X = Map_information_Cursor[index_stage].Boss2_location[0];
    Boss2cursor->Y = Map_information_Cursor[index_stage].Boss2_location[1];


    for (int i = 0; i < MAX_BULLET; i++) {
        Bullet_1[i].exist = 0;
        Bullet_2[i].exist = 0;
    }
    //Razercount = 0;
}
//=======================================================================================================









// ShowDelete 
// Show Search
// Delete Search
//=======================================================================================================
// Character
void ShowCharacter(char characterModel[2][1], COORD* cursor, int character_id)
{
    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    // ���⼭ getĿ�� �Ź� �����Ű�� ������ main�� while������ �ʿ� ����

    gameBoardInfo[arrY][arrX] = characterModel[0][0];
    gameBoardInfo[arrY + 1][arrX] = characterModel[1][0];


    // �ð������� ĳ���� ������ �ϴû����� SHOW//
    // �ð������� ĳ���� ������ �ϴû����� SHOW//
    // �ð������� ĳ���� ������ �ϴû����� SHOW//
    if (time_stop1 == 2 && character_id == 0) {
        SetCurrentCursorPos(cursor->X, cursor->Y);
        textcolor(SkyBlue);
        printf("��");

        SetCurrentCursorPos(cursor->X, cursor->Y + 1);
        textcolor(SkyBlue);
        printf("��");
    }

    else if (time_stop2 == 2 && character_id == 1) {
        SetCurrentCursorPos(cursor->X, cursor->Y);
        textcolor(SkyBlue);
        printf("��");

        SetCurrentCursorPos(cursor->X, cursor->Y + 1);
        textcolor(SkyBlue);
        printf("��");
    }

    else {
        if (character_id == 0) {
            SetCurrentCursorPos(cursor->X, cursor->Y);
            obstacle(96);
            SetCurrentCursorPos(cursor->X, cursor->Y + 1);
            obstacle(97);
        }
        else if (character_id == 1) {
            SetCurrentCursorPos(cursor->X, cursor->Y);
            obstacle(98);
            SetCurrentCursorPos(cursor->X, cursor->Y + 1);
            obstacle(99);
        }
    }
}

void DeleteCharacter(char characterModel[2][1], COORD* cursor)
{
    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;

    gameBoardInfo[arrY][arrX] = 0;
    gameBoardInfo[arrY + 1][arrX] = 0;
    SetCurrentCursorPos(cursor->X, cursor->Y);
    printf("  ");
    SetCurrentCursorPos(cursor->X, cursor->Y + 1);
    printf("  ");
}



// --------------------------------------------------------
// Bullet
void ShowBullet(int x, int y, int weapon_id, int interval) {
    SetCurrentCursorPos(x, y);
    if (interval < 0)
        obstacle(weapon_id + 1);
    else if (interval > 0)
        obstacle(weapon_id + 2);
}
void DeleteBullet(int x, int y) {
    SetCurrentCursorPos(x, y);
    printf("  ");  // Print spaces to erase the arrow
}




// --------------------------------------------------------
//npc
void Shownpc1(char npcModel[2][2], COORD* cursor, int npc_id) {


    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    if (npc_id == 0 && npc1_Life <= 0) {    //npc1�� ü���� 0 ���Ϸ� ����������
        npc1_Die_Check = 1;
        gameBoardInfo[arrY][arrX] = 0;
        gameBoardInfo[arrY][arrX + 1] = 0;
        gameBoardInfo[arrY + 1][arrX] = 0;
        gameBoardInfo[arrY + 1][arrX + 1] = 0;
        SetCurrentCursorPos(cursor->X, cursor->Y);
        printf("  ");
        SetCurrentCursorPos(cursor->X, cursor->Y + 1);
        printf("  ");
        SetCurrentCursorPos(cursor->X + 2, cursor->Y);
        printf("  ");
        SetCurrentCursorPos(cursor->X + 2, cursor->Y + 1);
        printf("  ");
        return;
    }
    gameBoardInfo[arrY][arrX] = npcModel[0][0];
    gameBoardInfo[arrY][arrX + 1] = npcModel[0][1];
    gameBoardInfo[arrY + 1][arrX] = npcModel[1][0];
    gameBoardInfo[arrY + 1][arrX + 1] = npcModel[1][1];

    if (npc_id == 0) {
        SetCurrentCursorPos(cursor->X, cursor->Y);
        obstacle(33);
        SetCurrentCursorPos(cursor->X, cursor->Y + 1);
        obstacle(32);
        SetCurrentCursorPos(cursor->X + 2, cursor->Y);
        obstacle(30);
        SetCurrentCursorPos(cursor->X + 2, cursor->Y + 1);
        obstacle(31);

    }
}
void Shownpc2(char npcModel[2][2], COORD* cursor, int npc_id) {

    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    if (npc_id == 1 && npc2_Life <= 0) {    //npc2�� ü���� 0 ���Ϸ� ����������
        npc2_Die_Check = 1;
        gameBoardInfo[arrY][arrX] = 0;
        gameBoardInfo[arrY][arrX + 1] = 0;
        gameBoardInfo[arrY + 1][arrX] = 0;
        gameBoardInfo[arrY + 1][arrX + 1] = 0;
        SetCurrentCursorPos(cursor->X, cursor->Y);
        printf("  ");
        SetCurrentCursorPos(cursor->X, cursor->Y + 1);
        printf("  ");
        SetCurrentCursorPos(cursor->X + 2, cursor->Y);
        printf("  ");
        SetCurrentCursorPos(cursor->X + 2, cursor->Y + 1);
        printf("  ");
        return;
    }
    gameBoardInfo[arrY][arrX] = npcModel[0][0];
    gameBoardInfo[arrY][arrX + 1] = npcModel[0][1];
    gameBoardInfo[arrY + 1][arrX] = npcModel[1][0];
    gameBoardInfo[arrY + 1][arrX + 1] = npcModel[1][1];
    if (npc_id == 1) {
        SetCurrentCursorPos(cursor->X, cursor->Y);
        obstacle(34);
        SetCurrentCursorPos(cursor->X, cursor->Y + 1);
        obstacle(35);
        SetCurrentCursorPos(cursor->X + 2, cursor->Y);
        obstacle(37);
        SetCurrentCursorPos(cursor->X + 2, cursor->Y + 1);
        obstacle(36);

    }
}

void Shownpc3(char npcModel[2][2], COORD* cursor, int npc_id) {


    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    if (npc_id == 2 && npc3_Life <= 0) {    //npc1�� ü���� 0 ���Ϸ� ����������
        npc3_Die_Check = 1;
        gameBoardInfo[arrY][arrX] = 0;
        gameBoardInfo[arrY + 1][arrX] = 0;

        SetCurrentCursorPos(cursor->X, cursor->Y);
        printf("  ");
        SetCurrentCursorPos(cursor->X, cursor->Y + 1);
        printf("  ");

        return;
    }
    gameBoardInfo[arrY][arrX] = npcModel[0][0];
    gameBoardInfo[arrY + 1][arrX] = npcModel[1][0];

    if (npc_id == 2) {
        SetCurrentCursorPos(cursor->X, cursor->Y);
        obstacle(38);
        SetCurrentCursorPos(cursor->X, cursor->Y + 1);
        obstacle(39);


    }
}

void Deletenpc(char npcModel[2][2], COORD* cursor)
{
    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;

    gameBoardInfo[arrY][arrX] = 0;
    gameBoardInfo[arrY][arrX + 1] = 0;
    gameBoardInfo[arrY + 1][arrX] = 0;
    gameBoardInfo[arrY + 1][arrX + 1] = 0;
    SetCurrentCursorPos(cursor->X, cursor->Y);
    printf("  ");
    SetCurrentCursorPos(cursor->X, cursor->Y + 1);
    printf("  ");
    SetCurrentCursorPos(cursor->X + 2, cursor->Y);
    printf("  ");
    SetCurrentCursorPos(cursor->X + 2, cursor->Y + 1);
    printf("  ");
}


// --------------------------------------------------------------
// Block
void ShowBlock(COORD* cursor)
{
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    gameBoardInfo[arrY][arrX] = 1;
    gameBoardInfo[arrY][arrX + 1] = 1;
    gameBoardInfo[arrY + 1][arrX] = 1;
    gameBoardInfo[arrY + 1][arrX + 1] = 1;
    SetCurrentCursorPos(cursor->X, cursor->Y);
    obstacle(1);
    SetCurrentCursorPos(cursor->X + 2, cursor->Y);
    obstacle(1);
    SetCurrentCursorPos(cursor->X, cursor->Y + 1);
    obstacle(1);
    SetCurrentCursorPos(cursor->X + 2, cursor->Y + 1);
    obstacle(1);
}
void DeleteBlock(COORD* cursor)
{
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    gameBoardInfo[arrY][arrX] = 0;
    gameBoardInfo[arrY][arrX + 1] = 0;
    gameBoardInfo[arrY + 1][arrX] = 0;
    gameBoardInfo[arrY + 1][arrX + 1] = 0;
    SetCurrentCursorPos(cursor->X, cursor->Y);
    printf("  ");
    SetCurrentCursorPos(cursor->X + 2, cursor->Y);
    printf("  ");
    SetCurrentCursorPos(cursor->X, cursor->Y + 1);
    printf("  ");
    SetCurrentCursorPos(cursor->X + 2, cursor->Y + 1);
    printf("  ");
}
//=======================================================================================================


//MovingBlock 1129
// --------------------------------------------------------------
void ShowMovingBLock(COORD* cursor)
{
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    gameBoardInfo[arrY][arrX] = 1;
    gameBoardInfo[arrY][arrX+1] = 1;
    gameBoardInfo[arrY][arrX+2] = 1;
    gameBoardInfo[arrY][arrX+3] = 1;
    SetCurrentCursorPos(cursor->X, cursor->Y);
    obstacle(1);
    SetCurrentCursorPos(cursor->X + 2, cursor->Y);
    obstacle(1);
    SetCurrentCursorPos(cursor->X + 4, cursor->Y);
    obstacle(1);
    SetCurrentCursorPos(cursor->X + 6, cursor->Y);
    obstacle(1);
    
}
int DetectCollision_MovingBlockLeft(int posX, int posY)
{
    int x, y;
    int arrX = posX / 2;
    int arrY = posY;
    x = 1;
    if (gameBoardInfo[arrY][arrX - x] == 1)//���� ������ return 1
    {
        turn_Movingblock = 1;
        return 1;
    }
 
    
    return 0;
}
int DetectCollision_MovingBlockRight(int posX, int posY)
{
    int x, y;
    int arrX = posX / 2;
    int arrY = posY;
   

    if (gameBoardInfo[arrY][arrX] == 1)//���� ������ return 1
    {
        turn_Movingblock = 0;

        return 1;
    }

    return 0;
}

void DeleteMovingBLock(COORD* cursor)
{
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    gameBoardInfo[arrY][arrX] = 0;
    gameBoardInfo[arrY][arrX + 1] = 0;
    gameBoardInfo[arrY][arrX + 2] = 0;
    gameBoardInfo[arrY][arrX + 3] = 0;
    SetCurrentCursorPos(cursor->X, cursor->Y);
    printf("  ");
    SetCurrentCursorPos(cursor->X + 2, cursor->Y);
    printf("  ");
    SetCurrentCursorPos(cursor->X + 4, cursor->Y);
    printf("  ");
    SetCurrentCursorPos(cursor->X + 6, cursor->Y);
    printf("  ");

}

void ShiftLeft_MovingBlock(COORD* cursor) {
    
    if (DetectCollision_MovingBlockLeft(cursor->X, cursor->Y)==1)
    {
        

        return;
    }
    DeleteMovingBLock(cursor);
    cursor->X -= 2;
    ShowMovingBLock(cursor);
}

void ShiftRight_MovingBlock(COORD* cursor) {

    if (DetectCollision_MovingBlockRight(cursor->X + 8, cursor->Y)==1)
    {
        return;
    }
    DeleteMovingBLock(cursor);
    cursor->X += 2;
    ShowMovingBLock(cursor);
}


// --------------------------------------------------------------

//PIECE
//---------------------------------------------------------------
void ShowPiece(int x, int y) {
    SetCurrentCursorPos(x, y);
    obstacle(108);
}
void DeletePiece(int x, int y) {
    SetCurrentCursorPos(x, y);
    printf("  ");
}
void AddPiece(int x, int y) {
    int arrX = x / 2;
    int arrY = y;
    gameBoardInfo[arrX][arrY] = 1;
    SetCurrentCursorPos(x, y);
    obstacle(1);
}
//---------------------------------------------------------------


//12.07
//ShowItem
void ShowItem(int x, int y) {
    int arrX = x / 2;
    int arrY = y;

    if (goal1 || goal2) {
        gameBoardInfo[arrY][arrX] = 0;
    }
    else {
        SetCurrentCursorPos(x, y);
        obstacle(500);
        gameBoardInfo[arrY][arrX] = 500;
    }
}
//---------------------------------------------------------------



// DetectCollision
// DetectCollision Search
// Detect Search
//=======================================================================================================
// Character
int DetectCollision_Character(int posX, int posY, char characterModel[2][1])
{
    int x, y;
    int arrX = posX / 2;
    int arrY = posY;
    for (x = 0; x < 1; x++)
    {
        for (y = 0; y < 2; y++)
        {
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 1)
            {
                // arrY�� ������ǥ, �ű⼭ y���� ���� �ϳ��� �����ϸ鼭 �������� ��ĭ�� �����ϴ� ��Ȳ
                return 0;
            }


            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 10)  //��Ͽ� ������
            {
                return 2;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 2)  //���� ������
            {
                return 2;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 5)  //�������� ��ֹ��� ������
            {
                return 0;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 22)  //�������� ��ֹ��� ����� ��ư�� ������
            {
                return 9;
            }

            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 96|| gameBoardInfo[arrY + y][arrX + x] == 97 ||gameBoardInfo[arrY + y][arrX + x] == 98|| gameBoardInfo[arrY + y][arrX + x] == 99)  //ĳ���ͳ��� ������
            {
                return 0;
            }
            

            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 6 || gameBoardInfo[arrY + y][arrX + x] == 7 || gameBoardInfo[arrY + y][arrX + x] == 8 || gameBoardInfo[arrY + y][arrX + x] == 9)  //�ﰢ�� ��ֹ��� ������
            {

                return 2;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 11)  //���ο� ������coin
            {
                return 30;
            }
            if (characterModel[y][x] != 0 && 
                gameBoardInfo[arrY + y][arrX + x] == 30 || gameBoardInfo[arrY + y][arrX + x] == 31 || gameBoardInfo[arrY + y][arrX + x] == 32 || gameBoardInfo[arrY + y][arrX + x] == 33 ||
                gameBoardInfo[arrY + y][arrX + x] == 34 || gameBoardInfo[arrY + y][arrX + x] == 35 || gameBoardInfo[arrY + y][arrX + x] == 36 || gameBoardInfo[arrY + y][arrX + x] == 37 || 
                gameBoardInfo[arrY + y][arrX + x] == 38 || gameBoardInfo[arrY + y][arrX + x] == 39 || gameBoardInfo[arrY + y][arrX + x] == 12)  //npc�� ������
            {

                return 2;
            }

            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 40)  //������ ������ ������
            {
                return 100;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 41)  //�Ʒ����� ������ ������
            {
                return 101;
            }
            //=-------------------------------------map 5 ����-------------------------------------------------------------


            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 71)  //�����̵� ���п� ������
            {
                return 71;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 72)  //�����̵� ���п� ������
            {
                return 72;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 73)  //�����̵� ���п� ������
            {
                return 73;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 74)  //�����̵� ���п� ������
            {
                return 74;
            }

            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 75)  //�����̵� ���п� ������
            {
                return 75;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 76)  //�����̵� ���п� ������
            {
                return 76;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 77)  //�����̵� ���п� ������
            {
                return 77;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 78)  //�����̵� ���п� ������
            {
                return 78;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 79)  //�����̵� ���п� ������
            {
                return 79;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 80)  //�����̵� ���п� ������
            {
                return 80;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 81)  //�����̵� ���п� ������
            {
                return 81;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 82)  //�����̵� ���п� ������
            {
                return 82;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 83)  //�����̵� ���п� ������
            {
                return 83;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 84)  //�����̵� ���п� ������
            {
                return 84;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 85)  //�����̵� ���п� ������
            {
                return 85;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 86)  //�����̵� ���п� ������
            {
                return 86;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 87)  //�����̵� ���п� ������
            {
                return 87;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 88)  //�����̵� ���п� ������
            {
                return 88;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 89)  //�����̵� ���п� ������
            {
                return 89;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 90)  //�����̵� ���п� ������
            {
                return 90;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 50)  //�����̵� ���п� ������
            {
                return 50;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 51)  //�����̵� ���п� ������
            {
                return 51;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 52)  //�����̵� ���п� ������
            {
                return 52;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 53)  //�����̵� ���п� ������
            {
                return 53;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 54)  //�����̵� ���п� ������
            {
                return 54;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 55)  //�����̵� ���п� ������
            {
                return 55;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 56)  //�����̵� ���п� ������
            {
                return 56;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 57)  //�����̵� ���п� ������
            {
                return 57;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 91)  //�����̵� ���п� ������
            {
                return 91;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 92)  //�����̵� ���п� ������
            {
                return 92;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 93)  //����1 ���� ������ ������
            {
                return 93;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 94)  //����2 ���� ������ ������
            {
                return 94;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 193)  //����1 ���� ������ ������
            {
                return 193;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 194)  //����2 ���� ������ ������
            {
                return 194;
            }

            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 500)  //�����ۿ� ���� ��
            {
                return 500;
            }
        }
    }
    return 1;
}
/* return 2�̸� ���
*  return 30�̸� ���� ����
*  return 9�̸� �������� ��ֹ� ����
*  return 100,101�̸� �������� ���
*/


// --------------------------------------------------------
// Bullet
int DetectCollision_Bullet(int x, int y) {
    // ȭ��� �ٸ� ���� ��� ���� �浹 �˻� ������ �����մϴ�.
    int arrX = x / 2;
    int arrY = y;

    // ���� ��ҿ��� �浹�� ���� ������ ���� �䱸�� �°� �����մϴ�.
    if (gameBoardInfo[arrY][arrX] > 0) {
        if (gameBoardInfo[arrY][arrX] == 30 || gameBoardInfo[arrY][arrX] == 31 || gameBoardInfo[arrY][arrX] == 32 || gameBoardInfo[arrY][arrX] == 33) {//npc1�� �⵹
            npc1_Life--;
        }
        if (gameBoardInfo[arrY][arrX] == 34 || gameBoardInfo[arrY][arrX] == 35 || gameBoardInfo[arrY][arrX] == 36 || gameBoardInfo[arrY][arrX] == 37) {//npc2�� �⵹
            npc2_Life--;

        }
        if (gameBoardInfo[arrY][arrX] == 38 || gameBoardInfo[arrY][arrX] == 39) {//npc3�� �⵹
            //11/28�� ���� ���� npc�� ü���� ����

        }
        // ���ϰ� �浹
        return 0;
    }

    // �ʿ��� ��� �� ���� �浹 �˻� ������ �߰��մϴ�.

    return 1;  // �浹 ����
}

// npc
int DetectCollision_npc(int posX, int posY, char npcModel[2][2])
{
    int x, y;
    int arrX = posX / 2;
    int arrY = posY;
    for (x = 0; x < 2; x++)
    {
        for (y = 0; y < 2; y++)
        {
            if (characterModel[y][x] != 0 && (gameBoardInfo[arrY + y][arrX + x] == 96 || gameBoardInfo[arrY + y][arrX + x] == 97 || gameBoardInfo[arrY + y][arrX + x] == 98 || gameBoardInfo[arrY + y][arrX + x] == 99)) //ĳ���Ϳ� ������ return 2
            {
                // arrY�� ������ǥ, �ű⼭ y���� ���� �ϳ��� �����ϸ鼭 �������� ��ĭ�� �����ϴ� ��Ȳ
                return 2;
            }
            if (characterModel[y][x] != 0 && gameBoardInfo[arrY + y][arrX + x] == 1 ||
                gameBoardInfo[arrY + y][arrX + x] == 5 ||
                gameBoardInfo[arrY + y][arrX + x] == 6 ||
                gameBoardInfo[arrY + y][arrX + x] == 7 ||
                gameBoardInfo[arrY + y][arrX + x] == 8 ||
                gameBoardInfo[arrY + y][arrX + x] == 9 ||
                gameBoardInfo[arrY + y][arrX + x] == 10 ||
                gameBoardInfo[arrY + y][arrX + x] == 11 ||
                gameBoardInfo[arrY + y][arrX + x] == 22 ||
                gameBoardInfo[arrY + y][arrX + x] == 40 ||
                gameBoardInfo[arrY + y][arrX + x] == 41
                ) //���� ������ return 1
            {
                return 1;
            }

        }
    }
    return 0;
}


//PIECE 
int DetectCollision_Piece(int x, int y) {
    int arrX = x / 2;
    int arrY = y;

    // ���� ��ҿ��� �浹�� ���� ������ ���� �䱸�� �°� �����մϴ�.
    if (gameBoardInfo[arrY][arrX] > 0) {
        if (gameBoardInfo[arrY][arrX] == 1 || gameBoardInfo[arrY][arrX] == 6 ||
            gameBoardInfo[arrY][arrX] == 7 || gameBoardInfo[arrY][arrX] == 8 ||
            gameBoardInfo[arrY][arrX] == 9 || gameBoardInfo[arrY][arrX] == 10)  //������ �浹
        {
            return 1;
        }
        if (gameBoardInfo[arrY][arrX] == 96 || gameBoardInfo[arrY][arrX] == 97 ||   //ĳ���Ϳ� �浹
            gameBoardInfo[arrY][arrX] == 98 || gameBoardInfo[arrY][arrX] == 99)
        {
            return 2;
        }

        if (gameBoardInfo[arrY][arrX] == 11) //���� �浹
        {
            return 3;
        }
    }


    return 0;
}
//=======================================================================================================





// BlockUpDown
// BlockUpDown Search
// UpDown Search
//=======================================================================================================
int BlockUp_Character(COORD* cursor, int character_id)
{
    if (!DetectCollision_Character(cursor->X, cursor->Y - 1, characterModel[character_id]))
    {
        return 0;
    }
    DeleteCharacter(characterModel[character_id], cursor);
    cursor->Y -= 1;


    ShowCharacter(characterModel[character_id], cursor, character_id);
    return 1;
}

int BlockDown_Character(COORD* cursor, int character_id)
{
    DeleteCharacter(characterModel[character_id], cursor);

    cursor->Y += 1;
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 93)
    {
        BossStop1 = 1;
        return 1;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 94)
    {
        BossStop2 = 1;
        return 1;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 0)  //���� �������
    {
        cursor->Y -= 1;
        if (character_id == 0 && jumpcheck1 != 100)
            jumpcheck1 = 0;
        if (character_id == 1 && jumpcheck2 != 100)
            jumpcheck2 = 0;

    }

    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 2)  //�״� ��ֹ��� �������
    {
        Death = TRUE;
        return 4444;

    }


    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 100)
    {
        cursor->Y -= 1;

        if(character_id == 0){
            goal1 = 1;
            jumpcheck1 = 100;
        }
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 101)
    {
        cursor->Y -= 1;
        if (character_id == 1) {
            goal2 = 1;
            jumpcheck2 = 100;
        }
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 30)
    {
        coin += 1;
        coin_flag = 1;
    }

    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 9)  // ��ֹ� ���� ��ư ��������
    {
        for (int i = 0; i < 49; i++)
            for (int j = 0; j < 80; j++)
                if (gameBoardInfo[i][j] == 5)
                    gameBoardInfo[i][j] = 0;

        RedrawGameBoard();
        return 1;

    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 71)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);
        cursor->X = 80;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 73)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);
        cursor->X = 70;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 72)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 82;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 74)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 46;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }


    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 75)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 76)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }

    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 77)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 78)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 79)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 80)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }

    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 81)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 38;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 82)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 83)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 84)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 85)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 86)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 87)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 34;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 88)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 38;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 89)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 46;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 90)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 50)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 18;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 51)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 52)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 53)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 54)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 114;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 55)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 56)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 114;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y, characterModel[character_id]) == 57)
    {
        cursor->Y -= 1;
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 34;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }

    
    if (DetectCollision_Character(cursor->X, cursor->Y + 1, characterModel[character_id]) == 500) {   //time_stop ����
        if (time_stop1 == 1) {
            time_stop1 = 2;
        }
        else if (time_stop2 == 1)
            time_stop2 = 2;
    }


    ShowCharacter(characterModel[character_id], cursor, character_id);
    return 1;
}
//=======================================================================================================








// ShiftJump
// Shift Search
// Jump Search
//=======================================================================================================
// Character
void ShiftLeft_Character(COORD* cursor, int character_id)
{
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 9)  // ��ֹ� ���� ��ư ��������
    {
        return;
    }

    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 2)
    {
        Death = TRUE;
    }

    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 100)
    {
        if (character_id == 0) {
            goal1 = 1;
            jumpcheck1 = 100;
        }
        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 101)
    {
        if (character_id == 1) {
            goal2 = 1;
            jumpcheck2 = 100;
        }
        return;
    }

    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 30)
    {
        coin += 1;
        coin_flag = 1;
    }

    if (!DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]))
    {
        return 0;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 71)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }

    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 73)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 72)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 82;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 74)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 46;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 75)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 76)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 77)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 78)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 79)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 80)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 81)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 38;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 82)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 83)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 84)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 85)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 86)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 87)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 34;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 88)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 38;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 89)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 46;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 90)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 50)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 18;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 51)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 52)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 53)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 54)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 114;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 55)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 56)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 114;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 57)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 34;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 193)
    {
        BossMove1 = 1;
    }
    if (DetectCollision_Character(cursor->X - 2 * interval, cursor->Y, characterModel[character_id]) == 194)
    {
        BossMove2 = 1;
    }

    if (DetectCollision_Character(cursor->X-2, cursor->Y, characterModel[character_id]) == 500) {   //time_stop ����
        if (time_stop1 == 1) {
            time_stop1 = 2;
        }
        else if (time_stop2 == 1)
            time_stop2 = 2;
    }


    DeleteCharacter(characterModel[character_id], cursor);
    cursor->X -= 2;
    ShowCharacter(characterModel[character_id], cursor, character_id);
    


}

void ShiftRight_Character(COORD* cursor, int character_id)
{

    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 9)
        // ��ֹ� ���� ��ư ��������
    {
        return;
    }

    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 2)
    {
        Death = TRUE;
    }

    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 100)
    {
        if (character_id==0) {
            goal1 = 1;
            jumpcheck1 = 100;
        }
        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 101)
    {
        if(character_id==1){
            goal2 = 1;
            jumpcheck2 = 100;
        }
        return;

    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 30)
    {
        coin += 1;
        coin_flag = 1;
    }
    if (!DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]))
    {
        return;
    }

    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 71)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 73)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 72)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 82;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 74)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 46;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 75)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 76)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 77)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 78)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 79)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 80)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 81)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 38;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 82)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 83)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 84)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 85)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 86)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 87)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 34;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 88)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 38;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 89)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 46;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 90)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 50)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 18;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 51)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 52)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 53)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 54)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 114;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 55)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 56)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 114;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 57)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 34;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }

    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 91)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 126;
        cursor->Y = 1;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X + 2 * interval, cursor->Y, characterModel[character_id]) == 92)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 134;
        cursor->Y = 44;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }





    if (DetectCollision_Character(cursor->X+2, cursor->Y, characterModel[character_id]) == 500) {   //time_stop ����
        if (time_stop1 == 1) {
            time_stop1 = 2;
        }
        else if (time_stop2 == 1)
            time_stop2 = 2;

    }

    DeleteCharacter(characterModel[character_id], cursor);
    cursor->X += 2;
    ShowCharacter(characterModel[character_id], cursor, character_id);


}
void Jump_Character(COORD* cursor, int character_id)
{
    //printf("%d", jumpcheck2);
    if (character_id == 0 && jumpcheck1 >= 2)
        return;
    if (character_id == 1 && jumpcheck2 >= 2)
        return;



    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 9)
        // ��ֹ� ���� ��ư ��������
    {
        for (int i = 0; i < 49; i++)
            for (int j = 0; j < 80; j++)
                if (gameBoardInfo[i][j] == 5)
                    gameBoardInfo[i][j] = 0;

        RedrawGameBoard();
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 2)
        //��ֹ� �ھ�����
    {
        Death = TRUE;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 1, characterModel[character_id]) == 2)
        //��ֹ� �ھ�����   //====================�� 2���� �ؾ��Ҽ���?
    {
        Death = TRUE;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 100)
    {
        if (character_id == 0)
        {
            goal1 = 1;
        }
        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 101)
    {
        if (character_id == 1) {
            goal2 = 1;
        }
        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 30)
    {
        coin += 1;
        coin_flag = 1;
    }

    if (!DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]))
    {
        return;
    }



    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 71)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 73)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 72)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 82;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 74)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 46;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }

    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 75)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 76)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }

    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 77)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 78)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if(DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 79)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 80)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 81)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 38;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 82)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }

    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 83)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 84)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 4;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 85)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 86)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 154;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 87)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 34;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 88)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 38;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 89)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 46;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 90)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 50)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 18;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 51)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 52)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 80;
        cursor->Y = 38;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 53)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 110;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 54)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 114;
        cursor->Y = 22;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 55)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 70;
        cursor->Y = 30;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 56)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 114;
        cursor->Y = 5;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 57)
    {
        DeleteCharacter(characterModel[character_id], cursor);

        cursor->X = 34;
        cursor->Y = 14;
        ShowCharacter(characterModel[character_id], cursor, character_id);

        return;
    }
    if (DetectCollision_Character(cursor->X, cursor->Y - 2, characterModel[character_id]) == 500) {   //time_stop ����
        if (time_stop1 == 1) {
            time_stop1 = 2;
        }
        else if (time_stop2 == 1)
            time_stop2 = 2;

    }


    DeleteCharacter(characterModel[character_id], cursor);
    cursor->Y -= 2;
    ShowCharacter(characterModel[character_id], cursor, character_id);


    
}
// --------------------------------------------------------
// npc
void ShiftLeft_npc(COORD* cursor, int npc_id) {
    if (npc_id == 0 && npc1_Die_Check == 1)  //npc1�� �׾����� �������
        return;
    if (npc_id == 1 && npc2_Die_Check == 1)  //npc2�� �׾����� �������
        return;
    if (npc_id == 2 && npc3_Die_Check == 1)  //npc2�� �׾����� �������
        return;


    if (DetectCollision_npc(cursor->X - 2, cursor->Y, npcModel[npc_id]) == 2)
        Death = TRUE;
    if (DetectCollision_npc(cursor->X - 2, cursor->Y, npcModel[npc_id]) == 1)
    {
        if (npc_id == 0)
            turn_npc1 += 1;
        if (npc_id == 1)
            turn_npc2 += 1;
        if (npc_id == 2)
            turn_npc3 += 1;

        return;
    }

    Deletenpc(npcModel[npc_id], cursor);
    cursor->X -= 2;
    if (npc_id == 0) {
        Shownpc1(npcModel[npc_id], cursor, npc_id);
    }
    if (npc_id == 1) {
        Shownpc2(npcModel[npc_id], cursor, npc_id);
    }
    if (npc_id == 2) {
        Shownpc3(npcModel[npc_id], cursor, npc_id);
    }
}
void ShiftRight_npc(COORD* cursor, int npc_id) {
    if (npc_id == 0 && npc1_Die_Check == 1)  //npc1�� �׾����� �������
        return;
    if (npc_id == 1 && npc2_Die_Check == 1)  //npc2�� �׾����� �������
        return;
    if (npc_id == 2 && npc3_Die_Check == 1)  //npc3�� �׾����� �������
        return;


    if (DetectCollision_npc(cursor->X + 2, cursor->Y, npcModel[npc_id]) == 2)
        Death = TRUE;
    if (DetectCollision_npc(cursor->X + 2, cursor->Y, npcModel[npc_id]) == 1) {
        if (npc_id == 0)
            turn_npc1 += 1;
        if (npc_id == 1)
            turn_npc2 += 1;
        if (npc_id == 2)
            turn_npc3 += 1;
        return;
    }



    Deletenpc(npcModel[npc_id], cursor);
    cursor->X += 2;
    if (npc_id == 0) {
        Shownpc1(npcModel[npc_id], cursor, npc_id);
    }
    if (npc_id == 1) {
        Shownpc2(npcModel[npc_id], cursor, npc_id);
    }
    if (npc_id == 2) {
        Shownpc3(npcModel[npc_id], cursor, npc_id);
    }
}

//=======================================================================================================
// BulletShoot 
// BulletShoot Search
// Shoot Search
//=======================================================================================================

// --------------------------------------------------------
// Buulet 1
void Bullet_1_Shoot(COORD* cursor, char characterModel[2][1], int character_id) {

    //�Ѿ� �̵�
    for (int i = 0; i < MAX_BULLET; i++) {
        if (Bullet_1[i].exist) {
            if (cursor->X != Bullet_1[i].X || !Bullet_1[i].start) {
                DeleteBullet(Bullet_1[i].X, Bullet_1[i].Y);
                Bullet_1[i].start = 0;
            }
            if (Bullet_1[i].interval < 0)
                Bullet_1[i].X -= 2;
            else if (Bullet_1[i].interval > 0)
                Bullet_1[i].X += 2;

            if (!DetectCollision_Bullet(Bullet_1[i].X + interval, Bullet_1[i].Y)) {
                if (DetectCollision_Bullet(Bullet_1[i].X + interval, Bullet_1[i].Y) == 31) //npc1�� �浹
                    npc1_Life--;


                Bullet_1[i].exist = 0;
            }

            if (Bullet_1[i].exist)
                ShowBullet(Bullet_1[i].X, Bullet_1[i].Y, weapon_id, Bullet_1[i].interval);

        }
    }

    //�Ѿ� �߻�
    if (time_stop1 != 2) {  //�ð������� �ƴ� ��
        if (GetAsyncKeyState(VK_SPACE) & 0x00001) { //SPACE
            if (b_index1 > MAX_BULLET) {
                b_index1 = 0;
                return;
            }

            flag_Bullet = 1;

            if (
                (!DetectCollision_Character(cursor->X + 2, cursor->Y, characterModel[character_id]) && leftRight_1 == 2) ||
                //�������� �ٶ󺸰� �ִµ� ������ ���� �浹�� �ִ� ���
                (!DetectCollision_Character(cursor->X - 2, cursor->Y, characterModel[character_id]) && leftRight_1 == 1))
                //������ �ٶ󺸰� �ִµ� ���� ���� �浹�� �ִ� ���
               return;

            Bullet_1[b_index1].exist = 1;
            Bullet_1[b_index1].start = 1;
            Bullet_1[b_index1].Y = cursor->Y;
            if (leftRight_1 == 1) {
                Bullet_1[b_index1].X = cursor->X;
                Bullet_1[b_index1].interval = -2;
            }
            else if (leftRight_1 == 2) {
                Bullet_1[b_index1].X = cursor->X;
                Bullet_1[b_index1].interval = 2;
            }
            b_index1++;
        }
    }
}

// --------------------------------------------------------
// Bullet2
void Bullet_2_Shoot(COORD* cursor, char characterModel[2][1], int character_id) {

    //�Ѿ� �̵�
    for (int i = 0; i < MAX_BULLET; i++) {
        if (Bullet_2[i].exist) {
            if (cursor->X != Bullet_2[i].X || !Bullet_2[i].start) {
                DeleteBullet(Bullet_2[i].X, Bullet_2[i].Y);
                Bullet_2[i].start = 0;
            }
            if (Bullet_2[i].interval < 0)
                Bullet_2[i].X -= 2;
            else if (Bullet_2[i].interval > 0)
                Bullet_2[i].X += 2;

            if (!DetectCollision_Bullet(Bullet_2[i].X + interval, Bullet_2[i].Y)) {
                Bullet_2[i].exist = 0;
            }

            if (Bullet_2[i].exist)
                ShowBullet(Bullet_2[i].X, Bullet_2[i].Y, weapon_id, Bullet_2[i].interval);

        }
    }

    //�Ѿ� �߻�
   //�Ѿ� �߻�
    if ((flag_Bullet && time_stop2 != 2) ||     //�ð������� �ƴϰų�
        (!flag_Bullet && GetAsyncKeyState(VK_SPACE) & 0x00001)) {
        // ĳ����1�� �ð������� �Ǿ ĳ����2�� �����̽�Ű �Է��� ���� �� ���� ��
        if (b_index2 > MAX_BULLET) {
            b_index2 = 0;
            return;
        }
        if (
            (!DetectCollision_Character(cursor->X + 2, cursor->Y, characterModel[character_id])&&leftRight_2==2) ||     
                //�������� �ٶ󺸰� �ִµ� ������ ���� �浹�� �ִ� ���
            (!DetectCollision_Character(cursor->X - 2, cursor->Y, characterModel[character_id])&&leftRight_2==1))
                //������ �ٶ󺸰� �ִµ� ���� ���� �浹�� �ִ� ���
            return;

        Bullet_2[b_index2].exist = 1;
        Bullet_2[b_index2].start = 1;
        Bullet_2[b_index2].Y = cursor->Y;
        if (leftRight_2 == 1) {
            Bullet_2[b_index2].X = cursor->X;
            Bullet_2[b_index2].interval = -2;
        }
        else if (leftRight_2 == 2) {
            Bullet_2[b_index2].X = cursor->X;
            Bullet_2[b_index2].interval = 2;
        }
        b_index2++;
        flag_Bullet = 0;
    }
}

//=======================================================================================================
// 
// 
// //=======================================================================================================
// Drop
// Drop Search
// Piece Drop Search
void Piece_1_Start() {

    for (int i = 0; i < MAX_PIECE; i++) {
        Piece_1[i].exist = 1;
        Piece_1[i].X = (rand() % (134 - 40)) / 2 * 2 + 40;
        Piece_1[i].Y = 1;
    }
}
void Piece_1_Drop() {
    int detected;

    for (int i = 0; i < MAX_PIECE; i++) {
        if (Piece_1[i].exist) {
            DeletePiece(Piece_1[i].X, Piece_1[i].Y);

            detected = DetectCollision_Piece(Piece_1[i].X, Piece_1[i].Y + 1);
            if (detected == 1) 
                Piece_1[i].exist = 0;

            else if (detected == 2) {
                Piece_1[i].exist = 0;
                Death = TRUE;
            }


         if (Piece_1[i].exist) {
                if(detected == 3)
                    Piece_1[i].Y += 2;
                else
                    Piece_1[i].Y += 1;

                ShowPiece(Piece_1[i].X, Piece_1[i].Y);
          }
        }
    }
}

void Piece_2_Start() {
    for (int i = 0; i < MAX_PIECE; i++) {
        Piece_2[i].exist = 1;
        Piece_2[i].X = (rand() % (134 - 40)) / 2 * 2 + 40;
        Piece_2[i].Y = 26;
    }
}
void Piece_2_Drop() {
    int detected;

    for (int i = 0; i < MAX_PIECE; i++) {
        if (Piece_2[i].exist) {
            DeletePiece(Piece_2[i].X, Piece_2[i].Y);

            detected = DetectCollision_Piece(Piece_2[i].X, Piece_2[i].Y + 1);
            if (detected == 1) 
                Piece_2[i].exist = 0;

            else if (detected == 2) {
                Piece_2[i].exist = 0;
                Death = TRUE;
            }


            if (Piece_2[i].exist) {
                if (detected == 3)
                    Piece_2[i].Y += 2;
                else
                    Piece_2[i].Y += 1;
                ShowPiece(Piece_2[i].X, Piece_2[i].Y);
            }
        }
    }
}
// ==================================================================================
// 
// 
//-------------------------------------------boss


void ShowBoss(char Boss[10][10], COORD* cursor, int Boss_id,int num_stage) {
    if (num_stage != 6)
        return;
    
    if (BossStop1 == 1 && Boss_id == 0)
        return;
    if (BossStop2 == 1 && Boss_id == 1)
        return;
        
    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    for(int i=0;i<10;i++)
        for (int j = 0; j < 10; j++) {

            if (Boss[j][i] == 3) {
                gameBoardInfo[arrY + j][arrX + i] = 2;
                SetCurrentCursorPos(cursor->X + i * 2, cursor->Y + j);
                if(Razercount%2==0)
                    obstacle(10);
                else
                    obstacle(1);
            }

            if (Boss[j][i] == 4) {
                gameBoardInfo[arrY + j][arrX + i] = 2;
                SetCurrentCursorPos(cursor->X + i * 2, cursor->Y + j);
                if(Boss_id==1)
                    obstacle(96);
                else
                    obstacle(98);
            }

            if (Boss[j][i] == 2){
                gameBoardInfo[arrY + j][arrX + i] = 2;
                SetCurrentCursorPos(cursor->X+i*2, cursor->Y+j);
                if (Boss_id == 0)
                    obstacle(222);
                else
                    obstacle(2);
            }
        }
}
void DeleteBoss(char Boss[10][10], COORD* cursor)
{
    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (Boss[j][i] == 2|| Boss[j][i] == 3||Boss[j][i] == 4) {
                gameBoardInfo[arrY + j][arrX + i] = 0;
                SetCurrentCursorPos(cursor->X + 2 * i, cursor->Y + j);
                printf("  ");
            }
        }
}

int DetectCollision_Boss(int posX, int posY, char Boss[10][10])
{
    int x, y;
    int arrX = posX / 2;
    int arrY = posY;
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            if (Boss[y][x] == 2 && (gameBoardInfo[arrY + y][arrX + x] == 96 || gameBoardInfo[arrY + y][arrX + x] == 97 || gameBoardInfo[arrY + y][arrX + x] == 98 || gameBoardInfo[arrY + y][arrX + x] == 99)) //ĳ���Ϳ� ������ return 2
            {
                return 2;
            }
            if (Boss[y][x] ==2 && (gameBoardInfo[arrY + y][arrX + x] == 1|| gameBoardInfo[arrY + y][arrX + x] == 6 ||
                gameBoardInfo[arrY + y][arrX + x] == 7 || gameBoardInfo[arrY + y][arrX + x] == 8 || gameBoardInfo[arrY + y][arrX + x] == 9 ))
                 //���� ������ return 1
            {
                return 1;
            }

        }
    }
    return 0;
}
void ShiftLeft_Boss(COORD* cursor, int Boss_id) {

    if (DetectCollision_Boss(cursor->X - 2, cursor->Y, Boss[Boss_id]) == 2)
        Death = TRUE;
    /*
    if (DetectCollision_Boss(cursor->X - 2, cursor->Y, Boss[Boss_id]) == 1)
    {
        return;
    }
    */

    
    DeleteBoss(Boss[Boss_id], cursor);
    if (BossStop1 == 1 && Boss_id == 0)
        return;
    if (BossStop2 == 1 && Boss_id == 1)
        return;
    cursor->X -= 2;
    ShowBoss(Boss[Boss_id], cursor, Boss_id, 6);
    
}

void ShiftRight_Boss(COORD* cursor, int Boss_id) {
    if (DetectCollision_Boss(cursor->X + 2, cursor->Y, Boss[Boss_id]) == 2)
        Death = TRUE;
    if (DetectCollision_Boss(cursor->X + 2, cursor->Y, Boss[Boss_id]) == 1)
    {
        return;
    }
    DeleteBoss(Boss[Boss_id], cursor);
    cursor->X += 2;
    ShowBoss(Boss[Boss_id], cursor, Boss_id, 6);
}

void ShiftUp_Boss(COORD* cursor, int Boss_id) {
    if (DetectCollision_Boss(cursor->X, cursor->Y-1, Boss[Boss_id]) == 2)
        Death = TRUE;
    if (DetectCollision_Boss(cursor->X, cursor->Y-1, Boss[Boss_id]) == 1)
    {
        return;
    }
    DeleteBoss(Boss[Boss_id], cursor);
    cursor->Y -= 1;
    ShowBoss(Boss[Boss_id], cursor, Boss_id, 6);
}

void ShiftDown_Boss(COORD* cursor, int Boss_id) {
    if (DetectCollision_Boss(cursor->X, cursor->Y + 1, Boss[Boss_id]) == 2)
        Death = TRUE;
    if (DetectCollision_Boss(cursor->X, cursor->Y + 1, Boss[Boss_id]) == 1)
    {
        if (BossMove1 == 1&& Boss_id==0)
            BossMove1downcheck = 1;
        if (BossMove2 == 1 && Boss_id == 1)
            BossMove2downcheck = 1;
        return;
    }
    DeleteBoss(Boss[Boss_id], cursor);
    cursor->Y += 1;
    ShowBoss(Boss[Boss_id], cursor, Boss_id, 6);
}
//-------------------------������




int DetectCollision_Razer(int posX, int posY, char Razer[10],int count)
{

    int arrX = posX / 2;
    int arrY = posY;
    if (Razercount % 2== 0) {
        if (gameBoardInfo[arrY][arrX] == 96 || gameBoardInfo[arrY][arrX] == 97 || gameBoardInfo[arrY][arrX] == 98 || gameBoardInfo[arrY][arrX] == 99) //ĳ���Ϳ� ������ return 2
        {
            return 1;
        }
        if (gameBoardInfo[arrY][arrX] == 1 || gameBoardInfo[arrY][arrX] == 10 || gameBoardInfo[arrY][arrX] == 6
            || gameBoardInfo[arrY][arrX] == 7 || gameBoardInfo[arrY][arrX] == 8 || gameBoardInfo[arrY][arrX] == 9)                //��,��Ͽ� ������ return 1
        {
            return 1;
        }
    }
    else
    {
        if (gameBoardInfo[arrY][arrX] == 96 || gameBoardInfo[arrY][arrX] == 97 || gameBoardInfo[arrY][arrX] == 98 || gameBoardInfo[arrY][arrX] == 99) //ĳ���Ϳ� ������ return 2
        {
            return 2;
        }
        if (gameBoardInfo[arrY][arrX] == 1 || gameBoardInfo[arrY][arrX] == 10 || gameBoardInfo[arrY][arrX] == 6
            || gameBoardInfo[arrY][arrX] == 7 || gameBoardInfo[arrY][arrX] == 8 || gameBoardInfo[arrY][arrX] == 9)                //��,��Ͽ� ������ return 1
        {
            return 1;
        }
    }
    return 0;
}


void ShowRazer(char Razer[10], COORD* cursor, int razerId, int count) {
    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    if (razerId % 2 == 0) {
        for (int i = 0; i < count; i++) {
            gameBoardInfo[arrY][arrX + i] = 1;
            SetCurrentCursorPos(cursor->X + 2 * i, cursor->Y);
            obstacle(1);
        }
    }
    else
        for (int i = 0; i < count; i++) {
            gameBoardInfo[arrY][arrX + i] = 10;
            SetCurrentCursorPos(cursor->X + 2 * i, cursor->Y);
            obstacle(10);
        }
}

void DeleteRazer(char Razer[10], COORD* cursor, int razerId, int count) {
    int x, y;
    int arrX, arrY;
    arrX = cursor->X / 2;
    arrY = cursor->Y;
    for (int i = 0; i < count; i++) {
        gameBoardInfo[arrY][arrX + i] = 0;
        SetCurrentCursorPos(cursor->X + 2 * i, cursor->Y);
        printf("  ");
    }
}

void shiftLeftRazer(COORD* cursor, int razerId,int count) {
    if (DetectCollision_Razer(cursor->X - 2, cursor->Y,Razer[razerId],count) == 2)
        Death = TRUE;
    if (DetectCollision_Razer(cursor->X - 2, cursor->Y, Razer[razerId],count) == 1)
    {
        return;
    }
    DeleteRazer(Razer[razerId], cursor, razerId, count);
    cursor->X -= 2;
    ShowRazer(Razer[razerId], cursor, razerId, count);
}
