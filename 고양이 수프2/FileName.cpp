#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROOM_WIDTH 13
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

void statusandroom(char name[], int soup, int cp, int gibun,
    int chnmil) {

    printf("==================== 현재 상태 ===================\n");
    printf("현재까지 만든 수프: %d개\n", soup);
    printf("CP: %d 포인트\n", cp);
    printf("%s의 기분(0~3): %d\n", name, gibun):

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


}
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

	return 0;
}