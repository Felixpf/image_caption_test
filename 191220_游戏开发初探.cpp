#include <stdio.h>
#include <stdlib.h>

/* ��Ʒ�ṹ */
typedef struct _prop{
	int id;				//���߱�� 
	char name[50];		//�������� 
	double price;		//���߼۸� 
	int stock;			//�����������ڱ����У���ʾ���������� 
	char desc[200];		//�������� 
}Prop;

/* �����ṹ */ 
typedef struct _bag{
	int PlayerId;		//������ұ�� 
	int count;			//����Ŀǰ�������� 
	int max;			//�������������� 
	Prop prop[8];		//����Ŀǰ�������� 
}Bag;

/* ��ҽṹ */
typedef struct _player{
	int id;				//��ұ�� 
	char name[50];		//������� 
	char pass[50];		//������� 
	Bag bag;			//��ұ��� 
	double gold;		//��ҽ�ң�������ʾ����ʱת��ͭ�����ҽ�ң�	
	double zuanshi;		//�����ʯ 
}Player;

/* �������� */
Prop *props;
Player *players;
int propCount = 0, playerCount = 0;	//���� 
void Init();			//��ʼ����Ϸ���� 
void ShowProp();
void ShowPlayer();
 
int main(){
	//1.��ʼ������
	Init();
	//2.��ӡ��ʼ������ 
	ShowProp();
	return 0;
}

void Init(){
	static Prop propArray[] = {			//�����̵� 
		{1, "˫�����鿨", 3000, 10, "�����һ�ѵõ����ѵ�ǮǮ��"},
		{2, "���õĵ���", 5000,  4, "ֻ��Զ�ۣ����ɽ�ս"}, 
		{3, "���������", 8000, 10, "�ô�Ҳ�ǰ�����������ô"}, 
		{4, "�޼���",    18888,  2, "��������רҵ��"}, 
		{5, "ֱ��һ����",66666, 10, "����֮����ԣ�30��ǰ���ã�"}, 
	}; 
	props = propArray;					//�趨ָ��ָ�� 
	//propCount = sizeof(propArray) / sizeof(Prop);
	propCount = 5;
	
	static Player playerArray[] = {		//��ҳ�ʼ�� 
		{1, "����ëë��",	 "123456", .gold=50000,},
		{2, "̩�ް�����", 	 "123456", .gold=150000,},
		{3, "Ԫʼ����֮ͽ",  "123456", .gold=250000,},
		{4, "�Ǻ�",          "123456", .gold=550000,}
	}; 
	players = playerArray;
	//playerCount = sizeof(playerArray) / sizeof(Player);
	playerCount = 4;
	
}
void ShowProp(){
	int i;
	if(props == NULL)
		return;
	printf("%-6s%-15s����\t���\t��Ʒ����\n", "���", "����");
	for(i=0; i<propCount; i++){
		printf("%-6d%-15s%.2lf\t%d\t%s\n", props[i].id, props[i].name, props[i].price, props[i].stock, props[i].desc);
	} 
}
  
