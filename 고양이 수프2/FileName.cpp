#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROOM_WIDTH 13
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

//방이랑 스테이터스창 2-1

//상태창 먼저.
void statusandroom(char name[], int soup, int cp, int gibun,
    int chnmil, int pos, int cher, int scratcher_pos, int tower, int tower_pos) {

    printf("==================== 현재 상태 ===================\n");
    printf("현재까지 만든 수프: %d개\n", soup);
    printf("CP: %d 포인트\n", cp);
    printf("%s의 기분(0~3): %d\n", name, gibun);

    if (gibun == 0) printf("기분이 매우 나쁩니다.\n");
    else if (gibun == 1) printf("심심해 합니다.\n");
    else if (gibun == 2) printf("식빵을 굽습니다.\n");
    else if (gibun == 3) printf("골골송 거립니다.\n");

    printf("집사와의 관계(0~4): %d\n", chnmil);
    if (chnmil == 0) printf("곁에 오는 것조차 싫어 합니다.\n");
    else if (chnmil == 1) printf("간식 자판기 취급 입니다.\n");
    else if (chnmil == 2) printf("그럭저럭 쓸 만한 집사 입니다.\n");
    else if (chnmil == 3) printf("훌륭한 집사로 인정받고 있습니다.\n");
    else if (chnmil == 4) printf("집사 껌딱지 입니다.\n");
    printf("==================================================\n");


    //방 코드
    printf("###############\n#");
    for (int i = 0; i < ROOM_WIDTH; i++) {
        if (i == HME_POS) printf("H");
        else if (i == BWL_POS) printf("B");
        else if (cher && i == scratcher_pos) printf("S");
        else if (tower && i == tower_pos) printf("T");
        else printf(" ");
    }
    printf("#\n#");
    for (int i = 0; i < ROOM_WIDTH; i++) {
        if (i == pos) printf("C");
        else printf(" ");
    }
    printf("#\n###############\n");
}

//2-2 기분변환
int gibunupdate(int gibun) {
    int dice = rand() % 6 + 1;
    printf("주사위 눈이 4이하면 기분이 안좋아집니다.\n");
    printf("기분 주사위를 굴립니다...%d\n", dice);

    if (dice <= 4 && gibun > 0) {
        gibun--;
        printf("기분이 나빠졌습니다.\n");
    }
    else {
        printf("기분은 그대로입니다. \n");
    }
    Sleep(500);
    return gibun;
}


//2-3 고먐미 이동
int catmove(int pos, int chnmil) {
    int dice = rand() % 6 + 1;
    printf("이동 주사위를 굴립니다... %d\n", dice);

    if (dice >= (6 - chnmil)) {
        if (pos < BWL_POS) {
            pos++;
            printf("냄비 쪽으로 이동했습니다.\n");
        }
    }
    else {
        if (pos > HME_POS) {
            pos--;
            printf("집 쪽으로 이동했습니다.\n");
        }
    }
    Sleep(500);
    return pos;
}

//2-4 수프 만들기
int makesoup(int pos) {
    if (pos == BWL_POS) {
        printf("고양이가 수프를 만들었습니다.\n");
        return 1;
    }
    return 0;
}
    

//메인함수
int main(void) {

    int chnmil = 2;
    int gibun = 3;
    int cp = 0;     //큐트 포인트 cp           
    int soup = 0;
    int pos = HME_POS;
    int prevpos = HME_POS;
    int cher = 0, scratcher_pos = -1;
    int tower = 0, tower_pos = -1;
    int toymouse = 0;
    int laser = 0;
    int turn = 1;

    char name[20];

    srand((unsigned int)time(NULL));

    printf("**** 야옹이와 수프 ver.2 ****\n");
    printf(" /\\_/\\\n");
    printf("  o.o\n");
    printf("야옹이의 이름을 지어 주세요: ");
    scanf_s("%s", name, (unsigned)_countof(name));
    printf("야옹이의 이름은 %s입니다.\n", name);
    Sleep(1000);
    system("cls");

    //게임 반복부분?
    while (1) {
        system("cls");
        printf("-- %d 턴 --\n", turn);

        //상태창
        statusandroom(name, soup, cp, gibun, chnmil, pos, cher, scratcher_pos, tower, tower_pos);

        //2-5 상호작용 기능
        int choice = -1;
        while (choice < 0 || choice > 2) {
            printf("\n 무엇을 하시겠습니까?\n");
            printf("0. 아무것도 안 함\n1. 턱 긁어주기\n>> ");
            printf("2. 장난감 쥐 사용 (보유: %d개)\n>> ", toymouse);
            scanf_s("%d", &choice);
        }
        int dice = rand() % 6 + 1;

        if (choice == 1) {
            printf("고양이의 턱을 긁어주었습니다. 주사위: %d\n", dice);
            if (dice >= 5 && chnmil < 4) {
                printf("친밀도가 상승했습니다!\n");}
            else {
                printf("고양이가 무반응입니다.\n");
            }
        }
        else if (choice == 2) {
            if (toymouse > 0) {
                toymouse--;
                if (gibun < 3) {
                    gibun++;
                    printf("장난감 쥐로 놀아주며 기분이 좋아졌습니다!\n");
                }
                else {
                    printf("기분이 이미 최고입니다.\n");
                }
            }
            else {
                printf("장난감 쥐가 없습니다.\n");
            }
        }
        else {
            printf("아무것도 하지 않았습니다.\n");
        }

        // 2-7 CP 생산
        int earned_cp = (gibun - 1 >= 0 ? gibun - 1 : 0) + chnmil;
        cp += earned_cp;
        printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", name, earned_cp);
        printf("보유 CP: %d 포인트\n", cp);

        // 2-8 상점 기능
        if (cp >= 1) {
            int buy = -1;
            printf("\n[상점] 어떤 물건을 구매하시겠습니까? (보유 CP: %d)\n", cp);
            printf("0. 아무 것도 사지 않는다.\n");
            printf("1. 장난감 쥐: 1 CP%s\n", (toymouse > 0 ? " (품절)" : ""));
            printf("2. 레이저 포인터: 2 CP%s\n", (laser > 0 ? " (품절)" : ""));
            printf("3. 스크래처: 4 CP%s\n", (cher > 0 ? " (품절)" : ""));
            printf("4. 캣 타워: 6 CP%s\n>> ", (tower > 0 ? " (품절)" : ""));
            scanf_s("%d", &buy);

            if (buy == 1) {
                if (toymouse > 0) printf("장난감 쥐는 이미 구매했습니다.\n");
                else if (cp >= 1) {
                    toymouse = 1;
                    cp -= 1;
                    printf("장난감 쥐를 구매했습니다!\n");
                }
                else printf("CP가 부족합니다.\n");
            }
            else if (buy == 2) {
                if (laser > 0) printf("레이저 포인터는 이미 구매했습니다.\n");
                else if (cp >= 2) {
                    laser = 1;  
                    cp -= 2;
                    printf("레이저 포인터를 구매했습니다!\n");
                }
                else printf("CP가 부족합니다.\n");
            }
            else if (buy == 3) {
                if (cher > 0) printf("스크래처는 이미 구매했습니다.\n");
                else if (cp >= 4) {
                    cher = 1;
                    scratcher_pos = 2;
                    cp -= 4;
                    printf("스크래처를 구매했습니다!\n");
                }
                else printf("CP가 부족합니다.\n");
            }
            else if (buy == 4) {
                if (tower > 0) printf("캣 타워는 이미 구매했습니다.\n");
                else if (cp >= 6) {
                    tower = 1;
                    tower_pos = 10;
                    cp -= 6;
                    printf("캣 타워를 구매했습니다!\n");
                }
                else printf("CP가 부족합니다.\n");
            }
        }

        //기분
        gibun = gibunupdate(gibun);

        // 2-9 돌발퀘스트
        if (rand() % 5 == 0) {
            printf("\n[돌발퀘스트] %s가 고습 사료를 먹고싶다고 합니다.\n",name);
            printf("1. 고급사료를 준다.(CP -1, 친밀도 +1)\n");
            printf("2. 일반사료를 준다.(Cp 0 친밀도 0\n>> ");
            int event_choice;
            scanf_s("%d", &event_choice);

            if (event_choice == 1) {
                if (cp > 0) {
                    cp--;
                    if (chnmil < 4) chnmil++;
                    printf("친밀도가 올랐습니다!\n");
                }
                else {
                    printf("CP가 부족해서 고급사료를 주지 못했습니다ㅠㅠㅠㅠ\n");
                }
            }
            else {
                printf("고양이가 애옹 거립니다.\n");
            }
        }


        //이동
        pos = catmove(pos, chnmil);

        //수프 만들기(고양이가 행동하기)
        if (makesoup(pos)) {        
            soup++;
            if (gibun < 3) {
                gibun++;
                printf("기분이 회복됩니다!\n");
            }
            else {
                printf("이미 기분이 최고입니다.\n");
            }
        }

        // 스크래처 상호작용
        if (cher && pos == scratcher_pos && gibun < 3) {
            gibun++;
            printf("스크래처에서 긁으며 기분이 좋아졌습니다!\n");
        }

        // 캣타워상호작용
        if (tower && pos == tower_pos && gibun < 3) {
            gibun++;
            printf("캣타워에서 휴식을 취하며 기분이 좋아졌습니다!\n");
        }


        Sleep(1500);
        turn++;
}

	return 0;
}