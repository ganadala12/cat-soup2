#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROOM_WIDTH 13
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

//���̶� �������ͽ�â 2-1

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
    printf("�ֻ��� ���� 4���ϸ� ����� ���������ϴ�.\n");
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


//2-3 ��ι� �̵�
int catmove(int pos, int chnmil) {
    int dice = rand() % 6 + 1;
    printf("�̵� �ֻ����� �����ϴ�... %d\n", dice);

    if (dice >= (6 - chnmil)) {
        if (pos < BWL_POS) {
            pos++;
            printf("���� ������ �̵��߽��ϴ�.\n");
        }
    }
    else {
        if (pos > HME_POS) {
            pos--;
            printf("�� ������ �̵��߽��ϴ�.\n");
        }
    }
    Sleep(500);
    return pos;
}

//2-4 ���� �����
int makesoup(int pos) {
    if (pos == BWL_POS) {
        printf("����̰� ������ ��������ϴ�.\n");
        return 1;
    }
    return 0;
}
    

//�����Լ�
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

        //2-5 ��ȣ�ۿ� ���
        int choice = -1;
        while (choice < 0 || choice > 2) {
            printf("\n ������ �Ͻðڽ��ϱ�?\n");
            printf("0. �ƹ��͵� �� ��\n1. �� �ܾ��ֱ�\n>> ");
            printf("2. �峭�� �� ��� (����: %d��)\n>> ", toymouse);
            scanf_s("%d", &choice);
        }
        int dice = rand() % 6 + 1;

        if (choice == 1) {
            printf("������� ���� �ܾ��־����ϴ�. �ֻ���: %d\n", dice);
            if (dice >= 5 && chnmil < 4) {
                printf("ģ�е��� ����߽��ϴ�!\n");}
            else {
                printf("����̰� �������Դϴ�.\n");
            }
        }
        else if (choice == 2) {
            if (toymouse > 0) {
                toymouse--;
                if (gibun < 3) {
                    gibun++;
                    printf("�峭�� ��� ����ָ� ����� ���������ϴ�!\n");
                }
                else {
                    printf("����� �̹� �ְ��Դϴ�.\n");
                }
            }
            else {
                printf("�峭�� �㰡 �����ϴ�.\n");
            }
        }
        else {
            printf("�ƹ��͵� ���� �ʾҽ��ϴ�.\n");
        }

        // 2-7 CP ����
        int earned_cp = (gibun - 1 >= 0 ? gibun - 1 : 0) + chnmil;
        cp += earned_cp;
        printf("%s�� ��а� ģ�е��� ���� CP�� %d ����Ʈ ����Ǿ����ϴ�.\n", name, earned_cp);
        printf("���� CP: %d ����Ʈ\n", cp);

        // 2-8 ���� ���
        if (cp >= 1) {
            int buy = -1;
            printf("\n[����] � ������ �����Ͻðڽ��ϱ�? (���� CP: %d)\n", cp);
            printf("0. �ƹ� �͵� ���� �ʴ´�.\n");
            printf("1. �峭�� ��: 1 CP%s\n", (toymouse > 0 ? " (ǰ��)" : ""));
            printf("2. ������ ������: 2 CP%s\n", (laser > 0 ? " (ǰ��)" : ""));
            printf("3. ��ũ��ó: 4 CP%s\n", (cher > 0 ? " (ǰ��)" : ""));
            printf("4. Ĺ Ÿ��: 6 CP%s\n>> ", (tower > 0 ? " (ǰ��)" : ""));
            scanf_s("%d", &buy);

            if (buy == 1) {
                if (toymouse > 0) printf("�峭�� ��� �̹� �����߽��ϴ�.\n");
                else if (cp >= 1) {
                    toymouse = 1;
                    cp -= 1;
                    printf("�峭�� �㸦 �����߽��ϴ�!\n");
                }
                else printf("CP�� �����մϴ�.\n");
            }
            else if (buy == 2) {
                if (laser > 0) printf("������ �����ʹ� �̹� �����߽��ϴ�.\n");
                else if (cp >= 2) {
                    laser = 1;  
                    cp -= 2;
                    printf("������ �����͸� �����߽��ϴ�!\n");
                }
                else printf("CP�� �����մϴ�.\n");
            }
            else if (buy == 3) {
                if (cher > 0) printf("��ũ��ó�� �̹� �����߽��ϴ�.\n");
                else if (cp >= 4) {
                    cher = 1;
                    scratcher_pos = 2;
                    cp -= 4;
                    printf("��ũ��ó�� �����߽��ϴ�!\n");
                }
                else printf("CP�� �����մϴ�.\n");
            }
            else if (buy == 4) {
                if (tower > 0) printf("Ĺ Ÿ���� �̹� �����߽��ϴ�.\n");
                else if (cp >= 6) {
                    tower = 1;
                    tower_pos = 10;
                    cp -= 6;
                    printf("Ĺ Ÿ���� �����߽��ϴ�!\n");
                }
                else printf("CP�� �����մϴ�.\n");
            }
        }

        //���
        gibun = gibunupdate(gibun);

        // 2-9 ��������Ʈ
        if (rand() % 5 == 0) {
            printf("\n[��������Ʈ] %s�� ��� ��Ḧ �԰�ʹٰ� �մϴ�.\n",name);
            printf("1. ��޻�Ḧ �ش�.(CP -1, ģ�е� +1)\n");
            printf("2. �Ϲݻ�Ḧ �ش�.(Cp 0 ģ�е� 0\n>> ");
            int event_choice;
            scanf_s("%d", &event_choice);

            if (event_choice == 1) {
                if (cp > 0) {
                    cp--;
                    if (chnmil < 4) chnmil++;
                    printf("ģ�е��� �ö����ϴ�!\n");
                }
                else {
                    printf("CP�� �����ؼ� ��޻�Ḧ ���� ���߽��ϴ٤ФФФ�\n");
                }
            }
            else {
                printf("����̰� �ֿ� �Ÿ��ϴ�.\n");
            }
        }


        //�̵�
        pos = catmove(pos, chnmil);

        //���� �����(����̰� �ൿ�ϱ�)
        if (makesoup(pos)) {        
            soup++;
            if (gibun < 3) {
                gibun++;
                printf("����� ȸ���˴ϴ�!\n");
            }
            else {
                printf("�̹� ����� �ְ��Դϴ�.\n");
            }
        }

        // ��ũ��ó ��ȣ�ۿ�
        if (cher && pos == scratcher_pos && gibun < 3) {
            gibun++;
            printf("��ũ��ó���� ������ ����� ���������ϴ�!\n");
        }

        // ĹŸ����ȣ�ۿ�
        if (tower && pos == tower_pos && gibun < 3) {
            gibun++;
            printf("ĹŸ������ �޽��� ���ϸ� ����� ���������ϴ�!\n");
        }


        Sleep(1500);
        turn++;
}

	return 0;
}