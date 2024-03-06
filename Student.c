#include "studentsystem.h"

void Students(Node* head, nNode* nhead,char *mclass,int num,char*account, char* name) {
	while (1) {

		system("cls");
		loadStudent(head);

		Menu2();

		int c;
		while (scanf("%d", &c) != 1)
		{
			scanf("%*[^\n]%*c");
			printf("����Ƿ�������������\n");
			system("pause");
			system("cls");
			loadStudent(head);
			Menu1();
		}
		scanf("%*[^\n]%*c");


		switch (c) {
		case 1://��ѯ
			Studentfind(head, num);
			break;
		case 2://��ȫ��
			Stdentprintf(head,mclass);
			break;
		case 3://����
			essayStudent(head);
			break;
		case 4://����
			GradeAppeals(nhead, mclass, num, account, name);
			break;
		case 5://������һ��
			return;
			break;
		case 6://�޸��ܱ�����
			sreviseconfidential(head,num);
			break;
		case 7://�����
			srevisemypassword(head,num);
			break;
		case 0://�˳�
			system("cls");
			printf("bye~~\n");
			system("pause");
			exit(0);
			break;
		default:
			printf("�޴�ѡ�����ѡ���\n");
			system("pause");
			break;
		}
	}
}


void Menu2() {
	printf("---Student Information Management System---\n");
	printf("--           student model\t\t --\n");
	printf("--\t      0.�˳� \t\t         --\n");
	printf("--\t      1.�ɼ���ѯ\t         --\n");
	printf("--\t      2.��ѯ����ɼ�\t\t --\n");
	printf("--\t      3.�ɼ����� \t\t --\n");
	printf("--\t      4.�ɼ����� \t\t --\n");
	printf("--\t      5.������һ�� \t         --\n");
	printf("--\t      6.�޸��ܱ�����\t\t --\n");
	printf("--\t      7.�޸��ҵ�����\t\t --\n");
	printf("-------------------------------------------\n");
}

void Studentfind(Node* head,int Num) {//��ѯ��Ϣ
	Node* move = head;
	while (move != NULL) {
		if (move->student.num == Num) {
			printf("ѧ�ţ�%-10d\t �༶��%-10s\t ������%-10s\t \n", move->student.num, move->student.mclass, move->student.name);
			Sleep(100);
			printf("��ѧ: %-10d\t Ӣ��: %-10d\t ���ģ� %-10d\t\n", move->student.score.match, move->student.score.english, move->student.score.chinese);
			Sleep(100);
			printf("------------------------------------------------------------\n");
			Sleep(100);
			system("pause");
			return;
		}
		move = move->next;
	}

	printf("δ�ҵ�\n");
	system("pause");
}

void Stdentprintf(Node* head,char*mclass) {
	if (head->next == NULL) {
		printf("����ѧ��\n");
		system("pause");
		return;
	}
	int a = 0;
	Node* move = head->next;

	while (move != NULL) {

		if(!strcmp(move->student.mclass,mclass)){
			a++;
			printf("ѧ��%d:\n\n", a);

			printf("ѧ�ţ�%-10d\t �༶��%-10s\t ������%-10s\t \n", move->student.num, move->student.mclass, move->student.name);
			Sleep(100);
			printf("��ѧ: %-10d\t Ӣ��: %-10d\t ���ģ�%-10d\t\n", move->student.score.match, move->student.score.english, move->student.score.chinese);
			Sleep(100);
			printf("------------------------------------------------------------\n");
			Sleep(100);
		}
		move = move->next;
	}
	system("pause");
}

//�޸��ܱ�
void sreviseconfidential(Node* head, int Num) {

	Node* move = head->next;
	while (move != NULL) {
		if (move->student.num == Num) {
			printf("------------------------------------------------------------\n");
			printf("ԭ�ܱ����⣺%s\n",move->student.question);
			printf("ԭ�ܱ��𰸣�%s\n", move->student.answer);
			printf("------------------------------------------------------------\n");
			printf("�������ܱ����⣺\n");
			scanf("%100s", move->student.question);
			scanf("%*[^\n]%*c");

			printf("�������ܱ���:\n");
			scanf("%100s", move->student.answer);
			scanf("%*[^\n]%*c");

			fileNode(head);
			printf("�޸ĳɹ�\n");

			system("pause");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�ѧ��\n");
	system("pause");
}

//�޸�����
void srevisemypassword(Node* head, int Num) {

	Node* move = head->next;
	while (move != NULL) {
		if (move->student.num == Num) {

			printf("������������:\n");
			scanf("%10s", move->student.password);
			scanf("%*[^\n]%*c");

			fileNode(head);
			printf("�޸ĳɹ�\n");

			system("pause");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�ѧ��\n");
	system("pause");
}