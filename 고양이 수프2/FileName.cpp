#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROOM_WIDTH 13
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

//���̶� �������ͽ�â

//����â ����.
void statusandroom(char name[], int soup, int cp, int gibun,
    int chnmil, int pos, int cher, int scratcher_pos, int tower, int tower_pos) {

    printf("==================== ���� ���� ===================\n");
    printf("������� ���� ����: %d��\n", soup);
    printf("CP: %d ����Ʈ\n", cp);
    printf("%s�� ���(0~3): %d\n", name, gibun);

    if (gibun == 0) printf("����� �ſ� ���޴ϴ�.\n");
    else if (gibun == 1) printf("�ɽ��� �մϴ�.\n");
    else if (gibun == 2) printf("�Ļ��� �����ϴ�.\n");
    else if (gibun == 3) printf("���� �Ÿ��ϴ�.\n");

    printf("������� ����(0~4): %d\n", chnmil);
    if (chnmil == 0) printf("�翡 ���� ������ �Ⱦ� �մϴ�.\n");
    else if (chnmil == 1) printf("���� ���Ǳ� ��� �Դϴ�.\n");
    else if (chnmil == 2) printf("�׷����� �� ���� ���� �Դϴ�.\n");
    else if (chnmil == 3) printf("�Ǹ��� ����� �����ް� �ֽ��ϴ�.\n");
    else if (chnmil == 4) printf("���� ������ �Դϴ�.\n");
    printf("==================================================\n");


    //�� �ڵ�
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

//2-2 ��к�ȯ
int gibunupdate(int gibun) {
    int dice = rand() % 6 + 1;
    printf("��� �ֻ����� �����ϴ�...%d\n", dice);

    if (dice <= 4 && gibun > 0) {
        gibun--;
        printf("����� ���������ϴ�.\n");
    }
    else {
        printf("����� �״���Դϴ�. \n");
    }
    Sleep(500);
    return gibun;
}

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

    //���� �ݺ��κ�?
    while (1) {
        system("cls");
        printf("-- %d �� --\n", turn);

        //����â
        statusandroom(name, soup, cp, gibun, chnmil, pos, cher, scratcher_pos, tower, tower_pos);
        //���
        gibun = gibunupdate(gibun);

        Sleep(1500);
        turn++;
}

	return 0;
}