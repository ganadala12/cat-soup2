#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROOM_WIDTH 13
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

int main(void) {

    int chnmil = 2;     
    int gibun = 3;             
    int cp = 0;     //ťƮ ����Ʈ cp           
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

    printf("**** �߿��̿� ���� ver.2 ****\n");
    printf(" /\\_/\\\n");
    printf("  o.o\n");
    printf("�߿����� �̸��� ���� �ּ���: ");
    scanf_s("%s", name, (unsigned)_countof(name));
    printf("�߿����� �̸��� %s�Դϴ�.\n", name);
    Sleep(1000);
    system("cls");

	return 0;
}