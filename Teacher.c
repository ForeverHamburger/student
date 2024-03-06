#include "studentsystem.h"

void Teachers(Node* head, nNode* nhead,mNode* mhead,char*account, char* mclass,char*name) {
	while (1) {

		system("cls");
		loadStudent(head);
		mloadStudent(mhead);
		Menu1();

		int c;
		while (scanf("%d", &c)!= 1)
		{
			scanf("%*[^\n]%*c");
			printf("����Ƿ�������������\n");
			system("pause");
			system("cls");
			loadStudent(head);
			mloadStudent(mhead);
			Menu1();
		}
		scanf("%*[^\n]%*c");


		switch (c) {
		case 1://����
			inputStudent(head);
			break;
		case 2://ɾ��
			deleteStudent(head);
			break;
		case 3://�޸�
			reviseStudent(head);
			break;
		case 4://��ѯ
			findStudent(head);
			break;
		case 5://���
			printfStdent(head);
			break;
		case 6://����
			tfileNode(head);
			printf("�Ѿ����ص�\"D:/Tstudent.txt\"�ļ�����\n");
			system("pause");
			break;
		case 7://����
			essayStudent(head);
			break;
		case 8://����
			Update(nhead, account, mclass, name);
			break;
		case 9://����
			asortStudent(head);
			break;
			treviseconfidential(mhead,account);
		case 10://�޸�����
			trevisemypassword(mhead, account);
			break;
		case 11://������һ��
			return;
			break;
		case 0 ://�˳�
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

//����
void Clean() {
	system("pause");
	system("cls");
}

//������̶������ļ�
void tfileNode(Node* head) {
	FILE* fp = fopen("D:/Tstudent.txt", "w");
	if (fp == NULL) {
		printf("δ�ҵ�ѧ���ļ�\n");
		return;
	}
	Node* move = head->next;
	while (move != NULL) {
		if (fwrite(&move->student, sizeof(Stu), 1, fp) != 1) {
			printf("д��ʧ��\n");
			return;
		}
		move = move->next;
	}
	printf("д��ɹ�\n");
	system("pause");
	fclose(fp);

}


//����������ļ�
void fileNode(Node* head) {
	FILE* fp = fopen("./studentNode.txt", "w");
	if (fp == NULL) {
		printf("δ�ҵ�ѧ���ļ�\n");
		return;
	}
	Node* move = head->next;
	while (move != NULL) {
		if (fwrite(&move->student, sizeof(Stu), 1, fp) != 1) {
			printf("д��ʧ��\n");
			return;
		}
		move = move->next;
	}
	Sleep(1000);
	printf("д��ɹ�\n");
	fclose(fp);

}

//���ļ���ȡ
void loadStudent(Node* head) {
	//���ļ�
	FILE* fp = fopen("./studentNode.txt", "r");
	if (fp == NULL) {
		printf("--\t δ�ҵ�ѧ���ļ�,������ȡ\t --\n");
		return;
	}

	//����һ�����
	Node* new = (Node*)malloc(sizeof(Node));
	new->next = NULL;
	Node* move = head;
	while (fread(&new->student, sizeof(Stu), 1, fp) == 1) {
		move->next = new;
	move = new;

		new = (Node*)malloc(sizeof(Node));
		new->next = NULL;
	}
	free(new);
	//���ඨ��һ��new��Ҫ�����ͷŵ�
	//�ر��ļ�
	fclose(fp);

	//printf("��ȡ�ɹ�\n");

}


void Menu1() {

	printf("---Student Information Management System---\n");
	printf("--\t         teacher model\t\t --\n");
	printf("--\t  0.�˳� \t\t         --\n");
	printf("--\t  1.�����µ�ѧ����Ϣ\t         --\n");
	printf("--\t  2.ɾ��ѧ����Ϣ\t\t --\n");
	printf("--\t  3.�޸�ѧ����Ϣ \t\t --\n");
	printf("--\t  4.��ѯѧ����Ϣ \t\t --\n");
	printf("--\t  5.�������ɼ�\t\t --\n");
	printf("--\t  6.���ص��ļ���\t\t --\n");
	printf("--\t  7.�ɼ�����\t\t         --\n");
	printf("--\t  8.���ѹ���Ա���³ɼ�\t         --\n");
	printf("--\t  9.ѧ������ \t\t         --\n");
	printf("--\t  10.�޸�ԭ���� \t         --\n");
	printf("--\t  11.������һ�� \t         --\n");
	printf("-------------------------------------------\n");
}


//����
void inputStudent(Node* head) {
	Node* pre = (Node*)malloc(sizeof(Node));
	pre->next = NULL;
	//�ݴ�
	printf("������༶\n");
	scanf("%63s", pre->student.mclass);
	scanf("%*[^\n]%*c");

	printf("������ѧ��,����\n");
	scanf("%d %19s", &pre->student.num, pre->student.name);
	scanf("%*[^\n]%*c");

	Node* cur = head;
	while (cur->next != NULL) {
		if (pre->student.num == cur->student.num) {
			printf("ѧ���ظ����������������\n");
			free(pre);
			system("pause");
			return;
		}
		cur = cur->next;
	}//�ҵ����ڵ�

	printf("������ɼ���ѧ,Ӣ��,����:\n");
	scanf("%d%d%d",&pre->student.score.match, &pre->student.score.english, &pre->student.score.chinese);
	scanf("%*[^\n]%*c");
	while (pre->student.score.match > 100) {
		printf("---------------------------\n");
		printf("��ѧ���100�֣���ǰ�Ѿ�����Ŷ\n");
		printf("������ɼ���ѧ:\n");
		scanf("%d", &pre->student.score.match);
	}
	while (pre->student.score.english > 100) {
		printf("Ӣ�����100�֣���ǰ�Ѿ�����Ŷ\n");
		printf("������ɼ�Ӣ��:\n");
		scanf("%d", &pre->student.score.english);
	}
	while (pre->student.score.chinese > 100) {
		printf("�������100�֣���ǰ�Ѿ�����Ŷ\n");
		printf("������ɼ�����:\n");
		scanf("%d", &pre->student.score.chinese);
	}
	sprintf(pre->student.account, "S%d", pre->student.num);
	strcpy(pre->student.password, "00000000");

	strcpy(pre->student.question, "����ԭ����");
	strcpy(pre->student.answer, "��Ԫ�����");

	printf("�������......\n");
	//¼��

	
	//Node* moveLast(Node*head){
	// 	Node* cur = head;
	//  while (cur->next != NULL) {
	//	cur = cur->next;
	//  }
	// return cur;
	//}

	cur->next= pre;

	fileNode(head);
	system("pause");
}
//�޸��ܱ�
void treviseconfidential(mNode* mhead, char*account) {
	if (!strcmp('0', account)) {
		printf("����Ա��ݣ����ܱ�\n");
		return;
	}

	mNode* move = mhead->next;
	while (move != NULL) {
		if (!strcmp(move->man.account, account)) {
			printf("�������ܱ����⣺\n");
			scanf("%100s", move->man.question);
			scanf("%*[^\n]%*c");

			printf("�������ܱ���:\n");
			scanf("%100s", move->man.answer);
			scanf("%*[^\n]%*c");

			mfileNode(mhead);
			printf("�޸ĳɹ�\n");

			system("pause");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�ѧ��\n");
	system("pause");
}


//ɾ��
void deleteStudent(Node*head) {
	if (head->next == NULL) {
		printf("����ѧ��\n");
		system("pause");
		return;
	}

	printf("������ѧ��ѧ��:");
	int Num = 0;
	scanf("%d", &Num);
	scanf("%*[^\n]%*c");

	Node* move = head;
	while (move->next != NULL) {
		if (move->next->student.num == Num) {
			Node* ret = move->next;
			move->next = ret->next;
			free(ret);
			ret = NULL;
			fileNode(head);
			printf("ѧ��Ϊ%d��ѧ����ɾ��\n",Num);
			Clean();
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�\n");
	system("pause");
}

//�޸�
void reviseStudent(Node* head) {
	printf("������Ҫ�޸ĵ�ѧ����ѧ��:\n");
	int Num;
	scanf("%d", &Num);
	scanf("%*[^\n]%*c");
	Node* move = head->next;
	while (move != NULL) {
		if (move->student.num == Num) {
			printf("������༶\n");
			scanf("%63s", move->student.mclass);
			scanf("%*[^\n]%*c");

			printf("����������:\n");
			scanf("%19s", move->student.name);
			scanf("%*[^\n]%*c");

			printf("������ɼ���ѧ,Ӣ��,����:\n");
			scanf("%d%d%d", &move->student.score.match, &move->student.score.english, &move->student.score.chinese);
			scanf("%*[^\n]%*c");

			while (move->student.score.match > 100) {
				printf("��ѧ���100�֣���ǰ�Ѿ�����Ŷ\n");
				printf("������ɼ���ѧ:\n");
				scanf("%d", &move->student.score.match);
			}			
			while (move->student.score.english > 100) {
				printf("Ӣ�����100�֣���ǰ�Ѿ�����Ŷ\n");
				printf("������ɼ�Ӣ��:\n");
				scanf("%d", &move->student.score.english);
			}
			while (move->student.score.chinese > 100) {
				printf("�������100�֣���ǰ�Ѿ�����Ŷ\n");
				printf("������ɼ�����:\n");
				scanf("%d", &move->student.score.chinese);
			}

			fileNode(head);
			printf("�޸ĳɹ�\n");

			system("pause");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�\n");
	system("pause");
}

//���ң�ѧ�ţ�
void nfindStudent(Node* head) {

	printf("������Ҫ���ҵ�ѧ��ѧ�ţ�");
	int Num;
	scanf("%d", &Num);
	scanf("%*[^\n]%*c");
	Node* move = head;
	while (move!= NULL) {
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

//���ң�������
void mfindStudent(Node* head) {

	printf("������Ҫ���ҵ�ѧ��������");
	char name[20] = { '\0' };
	scanf("%19s", name);
	scanf("%*[^\n]%*c");
	Node* move = head;
	while (move != NULL) {
		if (!strcmp(move->student.name, name)) {
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

//��ѯ���ۺϣ�
void afindStudent(Node* head) {

	printf("������Ҫ���ҵ�ѧ�� ѧ�ź�������");
	char name[20] = { '\0' };
	int Num;
	scanf("%d%19s", &Num, name);
	scanf("%*[^\n]%*c");
	Node* move = head;
	while (move != NULL) {
		if (move->student.num == Num) {
			if (!strcmp(move->student.name, name)) {
				printf("ѧ�ţ�%-10d\t �༶��%-10s\t ������%-10s\t \n", move->student.num, move->student.mclass, move->student.name);
				Sleep(100);
				printf("��ѧ: %-10d\t Ӣ��: %-10d\t ���ģ� %-10d\t\n", move->student.score.match, move->student.score.english, move->student.score.chinese);
				Sleep(100);
				printf("------------------------------------------------------------\n");
				Sleep(100);
				system("pause");
				return;
			}

		}
		move = move->next;
	}

	printf("δ�ҵ�\n");
	system("pause");
}

//�ܲ���
void findStudent(Node* head){
	printf("1����ѧ�Ų�ѯ\n");
	printf("2����������ѯ\n");
	printf("3���ۺϲ�ѯ\n");
	printf("��ѡ��Ҫ���ҵķ�ʽ:\n");

	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ���������ѡ��\n");

	}
	scanf("%*[^\n]%*c");
	switch (c) {
	case 1:
		nfindStudent(head);
		break;
	case 2:
		mfindStudent(head);
		break;
	case 3:
		afindStudent(head);
		break;
	default:
		printf("�޴˷��񣬽����ز˵�\n");
		system("pause");
		break;
	}

}

//��ӡ
void printfStdent(Node* head) {
	if (head->next == NULL) {
		printf("����ѧ��\n");
		system("pause");
		return;
	}
	int a = 0;
	Node* move = head->next;

	while (move != NULL) {

		a++;
		printf("ѧ��%d:\n\n", a);

		printf("ѧ�ţ�%-10d\t �༶��%-10s\t ������%-10s\t \n", move->student.num, move->student.mclass, move->student.name);
		Sleep(100);
		printf("��ѧ: %-10d\t Ӣ��: %-10d\t ���ģ� %-10d\t\n", move->student.score.match, move->student.score.english, move->student.score.chinese);
		Sleep(100);
		printf("------------------------------------------------------------\n");
		Sleep(100);
		move = move->next;
	}
	system("pause");
}



//��������
void essayStudent(Node* head) {
	Node* move = head;

	char mclass[20];
	printf("������Ҫ�����İ༶��\n");
	scanf("%s", mclass);
	scanf("%*[^\n]%*c");

	int mgood = 0,egood = 0, cgood = 0;
	int mok = 0, eok = 0, cok = 0;
	double all = 0;
	while (move->next != NULL) {
		if (!strcmp(mclass, move->next->student.mclass))
		{
			all++;
			if (move->next->student.score.match >= 85) {
				mgood++;
			}
			else if (move->next->student.score.match >= 60 && move->next->student.score.match < 85) {
				mok++;
			}

			if (move->next->student.score.english >= 85) {
				egood++;
			}
			else if (move->next->student.score.english >= 60 && move->next->student.score.english < 85) {
				eok++;
			}

			if (move->next->student.score.chinese >= 85) {
				cgood++;
			}
			else if (move->next->student.score.chinese >= 60 && move->next->student.score.chinese < 85) {
				cok++;
			}
		}
		move = move->next;
	}
	if(all!=0){
		printf("ѧ����:%dλ\n", (int)all);
		printf("--------------------------------------------\n");
		Sleep(100);
		printf("--��ѧ�ɼ��ﵽ�����ѧ����:%dλ\n", mgood);
		printf("--ռȫ��ı���Ϊ:%lf%%\n\n", mgood / all * 100);
		Sleep(100);
		printf("--��ѧ�ɼ��ﵽ����δ�ﵽ�����ѧ����:%dλ\n", mok);
		printf("--ռȫ��ı���Ϊ:%lf%%\n", mok / all * 100);
		printf("--------------------------------------------\n");
		Sleep(100);

		printf("--Ӣ��ɼ��ﵽ�����ѧ����:%dλ\n", egood);
		printf("--ռȫ��ı���Ϊ:%lf%%\n\n", egood / all * 100);
		Sleep(100);
		printf("--Ӣ��ɼ��ﵽ����δ�ﵽ�����ѧ����:%dλ\n", eok);
		printf("--ռȫ��ı���Ϊ:%lf%%\n", eok / all * 100);
		printf("--------------------------------------------\n");
		Sleep(100);

		printf("--���ĳɼ��ﵽ�����ѧ����:%dλ\n", cgood);
		printf("--ռȫ��ı���Ϊ:%lf%%\n\n", cgood / all * 100);
		Sleep(100);
		printf("--���ĳɼ��ﵽ����δ�ﵽ�����ѧ����:%dλ\n", cok);
		printf("--ռȫ��ı���Ϊ:%lf%%\n", cok / all * 100);
		printf("--------------------------------------------\n");
		system("pause");
	}
	else {
		printf("û����¼����༶ѧ����ϢŶ\n");
		system("pause");
	}
}

void asortStudent(Node* head) {
	printf("1����С��������\n");
	printf("2���Ӵ�С����\n");
	printf("��ѡ��Ҫ����ķ���:\n");

	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ���������ѡ��\n");

	}
	scanf("%*[^\n]%*c");
	switch (c) {
	case 1:
		ssortStudent(head);
		break;
	case 2:
		jsortStudent(head);
		break;
	default:
		printf("�޴˷��񣬽����ز˵�\n");
		system("pause");
		break;
	}

}
//ѧ�����򣨴�С����
void ssortStudent(Node* head) {
	system("cls");
	Node* save = NULL;
	Node* move = NULL;
	if (head != NULL ) {
		printf("ע�⣡��ǰû��ѧ��\n");
		system("pause");
		return;
	}
	if(head->next == NULL){
		printf("ע�⣡��ǰѧ������Ҫ����\n");
		system("pause");
		return;
	}
	printf("��������ʲô����\n");
	printf("1����ѧ��\n");
	printf("2������ѧ�ɼ�\n");
	printf("3����Ӣ��ɼ�\n");
	printf("4�������ĳɼ�\n");
	printf("5������������\n");
	printf("6�����༶����\n");
	printf("��ѡ��Ҫ����ķ�ʽ:\n");
	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ���������ѡ��\n");

	}
	scanf("%*[^\n]%*c");
	switch (c) {
	case 1:
		for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
			for (move = head->next; move->next != save; move = move->next) {
				if (move->student.num > move->next->student.num) {
					Stu temp = move->student;
					move->student = move->next->student;
					move->next->student = temp;
				}
			}
			save = move;
		}
		fileNode(head);
		printfStdent(head);
		return;
		break;
	case 2:
		for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
			for (move = head->next; move->next != save; move = move->next) {
				if (move->student.score.match > move->next->student.score.match) {
					Stu temp = move->student;
					move->student = move->next->student;
					move->next->student = temp;
				}
			}
			save = move;
		}
		break;
	case 3:
		for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
			for (move = head->next; move->next != save; move = move->next) {
				if (move->student.score.english > move->next->student.score.english) {
					Stu temp = move->student;
					move->student = move->next->student;
					move->next->student = temp;
				}
			}
			save = move;
		}
		break;
	case 4:
		for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
			for (move = head->next; move->next != save; move = move->next) {
				if (move->student.score.chinese > move->next->student.score.chinese) {
					Stu temp = move->student;
					move->student = move->next->student;
					move->next->student = temp;
				}
			}
			save = move;
		}
		break;
	case 5:
		for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
			for (move = head->next; move->next != save; move = move->next) {
				if (strcmp(move->student.name, move->next->student.name) > 0) {
					Stu temp = move->student;
					move->student = move->next->student;
					move->next->student = temp;
				}
			}
			save = move;
		}
		break;
	case 6:
		for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
			for (move = head->next; move->next != save; move = move->next) {
				if (strcmp(move->student.mclass, move->next->student.mclass) > 0) {
					Stu temp = move->student;
					move->student = move->next->student;
					move->next->student = temp;
				}
			}
			save = move;
		}
		break;
	default:
		printf("�޴˷��񣬽����ز˵�\n");
		system("pause");
		break;
	}
	fileNode(head);
	printfStdent(head);
	return;
}

//ѧ�����򣨴Ӵ�С��
void jsortStudent(Node* head) {
	Node* save = NULL;
	Node* move = NULL;
	if (head != NULL) {
		printf("ע�⣡��ǰû��ѧ��\n");
		system("pause");
		return;
	}
	if (head->next == NULL) {
		printf("ע�⣡��ǰѧ������Ҫ����\n");
		system("pause");
		return;
	}
	printf("��������ʲô����\n");
	printf("1����ѧ��\n");
	printf("2������ѧ�ɼ�\n");
	printf("3����Ӣ��ɼ�\n");
	printf("4�������ĳɼ�\n");
	printf("5������������\n");
	printf("6�����༶����\n");
	printf("��ѡ��Ҫ����ķ�ʽ:\n");
	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ���������ѡ��\n");

	}
	scanf("%*[^\n]%*c");

		switch (c) {
		case 1:
			for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
				for (move = head->next; move->next != save; move = move->next) {
					if (move->student.num < move->next->student.num) {
						Stu temp = move->student;
						move->student = move->next->student;
						move->next->student = temp;
					}
				}
				save = move;
			}
			break;
		case 2:
			for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
				for (move = head->next; move->next != save; move = move->next) {
					if (move->student.score.match < move->next->student.score.match) {
						Stu temp = move->student;
						move->student = move->next->student;
						move->next->student = temp;
					}
				}
				save = move;
			}
			break;
		case 3:
			for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
				for (move = head->next; move->next != save; move = move->next) {
					if (move->student.score.english < move->next->student.score.english) {
						Stu temp = move->student;
						move->student = move->next->student;
						move->next->student = temp;
					}
				}
				save = move;
			}
			break;
		case 4:
			for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
				for (move = head->next; move->next != save; move = move->next) {
					if (move->student.score.chinese < move->next->student.score.chinese) {
						Stu temp = move->student;
						move->student = move->next->student;
						move->next->student = temp;
					}
				}
				save = move;
			}
			break;
		case 5:
			for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
				for (move = head->next; move->next != save; move = move->next) {
					if (strcmp(move->student.name, move->next->student.name) < 0) {
						Stu temp = move->student;
						move->student = move->next->student;
						move->next->student = temp;
					}
				}
				save = move;
			}
			break;
		case 6:
			for (Node* turn = head->next; turn->next != NULL; turn = turn->next) {
				for (move = head->next; move->next != save; move = move->next) {
					if (strcmp(move->student.mclass, move->next->student.mclass) < 0) {
						Stu temp = move->student;
						move->student = move->next->student;
						move->next->student = temp;
					}
				}
				save = move;
			}
			break;
		default:
			printf("�޴˷��񣬽����ز˵�\n");
			system("pause");
			break;
		}
		fileNode(head);
		printfStdent(head);
		return;
}

//��ʦ�޸�����
void trevisemypassword(mNode* mhead, char*Account) {

	mNode* move = mhead->next;
	while (move != NULL) {
		if (!strcmp(move->man.account,Account)) {

			printf("������������:\n");
			scanf("%10s", move->man.password);
			scanf("%*[^\n]%*c");

			mfileNode(mhead);
			printf("�޸ĳɹ�\n");

			system("pause");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ���ʦ\n");
	system("pause");
}

//void sortStudent(Node* head){}
//void Menu()
//{
//}
// 
//ָ������
void insertStudent(Node* head, int position) {
	Node* pre = (Node*)malloc(sizeof(Node));
	pre->next = NULL;

	// �ݴ�
	printf("������༶��\n");
	scanf("%63s", pre->student.mclass);
	scanf("%*[^\n]%*c");

	printf("������ѧ�ź�������\n");
	scanf("%d %19s", &pre->student.num, pre->student.name);
	scanf("%*[^\n]%*c");

	Node* cur = head;
	int count = 0;

	while (cur->next != NULL && count < position - 1) {
		cur = cur->next;
		count++;
	}

	if (count < position - 1) {
		printf("ָ��λ�ó��������ȣ��޷����롣\n");
		free(pre);
		return;
	}

	pre->next = cur->next;
	cur->next = pre;

	printf("���ݳɹ����뵽λ�� %d��\n", position);

	fileNode(head);
	system("pause");
}

