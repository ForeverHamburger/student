#include "studentsystem.h"

//����������ļ�������Ա��
void mfileNode(mNode* head) {
	FILE* fp = fopen("./manNode.txt", "w");
	if (fp == NULL) {
		printf("δ�ҵ��ļ�\n");
		return;
	}
	mNode* move = head->next;
	while (move != NULL) {
		if (fwrite(&move->man, sizeof(Man), 1, fp) != 1) {
			printf("д��ʧ��\n");
			return;
		}
		move = move->next;
	}
	Sleep(1000);
	printf("д��ɹ�\n");
	fclose(fp);
}

//���ļ���ȡ(����Ա)
void mloadStudent(mNode* head) {
	//���ļ�
	FILE* fp = fopen("./manNode.txt", "r");
	if (fp == NULL) {
		printf("δ�ҵ��ļ�,������ȡ\n");
		return;
	}

	//����һ�����
	mNode* new = (mNode*)malloc(sizeof(mNode));
	new->next = NULL;
	mNode* move = head;
	while (fread(&new->man, sizeof(Man), 1, fp) == 1) {
		move->next = new;
		move = new;

		new = (mNode*)malloc(sizeof(mNode));
		new->next = NULL;
	}
	free(new);
	//���ඨ��һ��new��Ҫ�����ͷŵ�
	//�ر��ļ�
	fclose(fp);

	//printf("��ȡ�ɹ�\n");

}


void mMenu() {
	printf("---Student Information Management System---\n");
	printf("--\t         Manager model\t\t --\n");
	printf("--\t  0.�˳� \t\t         --\n");
	printf("--\t  1.�鿴����ѡ��\t         --\n");
	printf("--\t  2.�����ʦ��\t\t\t --\n");
	printf("--\t  3.�����˺����� \t\t --\n");
	printf("--\t  4.ɾ���˺����� \t\t --\n");
	printf("--\t  5.�޸��˺�����\t\t --\n");
	printf("--\t  6.�����˺�����\t\t --\n");
	printf("--\t  7.¼�������˺�����\t         --\n");
	printf("--\t  8.��������˺�����\t         --\n");
	printf("--\t  9.�ֶ�����¼��ѧ����Ϣ         --\n");
	printf("--\t  10.������һ�� \t         --\n");
	printf("-------------------------------------------\n");
}

void Manager( Node* head, nNode* nhead,mNode* mhead,char*account ) {
	while (1) {

		system("cls");

		loadStudent(head);
		mloadStudent(mhead);
		nloadStudent(nhead);
		mMenu();
		int c;
		while (scanf("%d", &c) != 1)
		{
			scanf("%*[^\n]%*c");
			printf("����Ƿ�������������\n");
			system("pause");
			system("cls");
			loadStudent(head);
			mloadStudent(mhead);
			nloadStudent(nhead);
			mMenu();
		}
		scanf("%*[^\n]%*c");

		switch (c) {
		case 1://�鿴����ѡ��/ע��/�޸�/�һ�/����/���³ɼ���
			printf("���ڽ������ҳ��\n");
			Sleep(1000);
			Viewagency(head, mhead, nhead);
			break;
		case 2://�����ʦ��
			printf("���ڽ����ʦ��\n");
			Sleep(1000);
			Teachers(head, nhead, mhead, account, "man", "admanager");
			break;
		case 3://�����˺�����
			ainputAccount(mhead, head);
			break;
		case 4://ɾ���˺�����
			adeleteAccount(mhead, head);
			break;
		case 5://�޸��˺�����
			areviseAccount(mhead, head);
			break;
		case 6://�����˺�����
			afindAccount(mhead, head);
			break;
		case 7://¼�������˺�����
			mloadStudent(mhead);
			loadStudent(head);
			system("pause");
			break;
		case 8://��������˺�����
			sprintfStdent(head);
			mprintfStdent(mhead);
			break;
		case 9://�ֶ�����¼��ѧ����Ϣ
			reviseStudent(head);
			break;
		case 10://������һ��
			return;
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

//�鿴����ѡ��/ע��/�޸�/�һ�/����/���³ɼ���
//�����ʦ��

//�����˺�����
//ɾ���˺�����
//�޸��˺�����
//����
void ainputAccount(mNode* mhead, Node* head) {
	printf("����ѧ���˺�������1��������ʦ���߹���Ա�˺�������2\n");
	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ�������������\n");
	}
	scanf("%*[^\n]%*c");

	switch (c) {
	case 1:
		sinputAccount(head);
		break;
	case 2:
		minputAccount(mhead);
		break;
	default:
		printf("�޴˷��񣬽����ز˵�\n");
		break;
	}
}
void minputAccount(mNode* mhead) {
	mNode* pre = (mNode*)malloc(sizeof(mNode));
	pre->next = NULL;
	//�ݴ�
	char a = getchar();
	char c = '\0';
	while (c != 'T' && c != 'G'){
		printf("ѡ����˺�����ʦ���ǹ���Ա��TΪ��ʦ��GΪ����Ա��\n");

		scanf("%c", &c);
		scanf("%*[^\n]%*c");

		if (c == 'T') {
			printf("�������˺����ڰ༶\n");
			scanf("%63s", pre->man.mclass);
			scanf("%*[^\n]%*c");
		}
		else if (c == 'G') {
			char* m = "man";
			strcpy(pre->man.mclass , m);
		}
	} 
	strcpy(pre->man.question, "����ԭ����");
	strcpy(pre->man.answer, "��Ԫ�����");

	
	pre->man.account[0] = c;

	printf("������������\n");
	scanf("%19s", pre->man.name);
	scanf("%*[^\n]%*c");

	printf("�������˺�(����������ĸ)��\n");
	scanf("%9s", &(pre->man.account[1]));
	scanf("%*[^\n]%*c");

	printf("���������룺\n");
	scanf("%10s", pre->man.password);
	scanf("%*[^\n]%*c");


	mNode* cur = mhead;
	while (cur->next != NULL) {
		if (!strcmp(pre->man.account, cur->man.account)) {
			printf("�˺��ظ����������������\n");
			free(pre);
			system("pause");
			return;
		}
		cur = cur->next;
	}//�ҵ����ڵ�

	
	printf("�������......\n");
	cur->next = pre;

	mfileNode(mhead);
	free(pre);
	system("pause");
}
void sinputAccount(Node*head) {

	//�ݴ�
	int Num=0;
	printf("������Ҫ�����˺ŵ�ѧ��ѧ��\n");
	while (scanf("%d", Num) != 1) {
		scanf("%*[^\n]%*c");
		printf("���������������ȷ��ѧ��\n");
	}
	scanf("%*[^\n]%*c");
	getchar();
	Node* move = head;
	int flag = 0;
	while (move != NULL) {
		if (move->student.num == Num) {
			flag = 1;
			move->student.account[0] = 'S';
			printf("�������˺�(����������ĸ)\n");
			scanf("%9s", &(move->student.account[1]));
			scanf("%*[^\n]%*c");

			printf("����������\n");
			scanf("%10s", move->student.password);
			scanf("%*[^\n]%*c");
			break;
		}
		move = move->next;
	}
	if (!flag) {
		printf("��ѧ��������\n");
		system("pause");
		return;
	}

	Node* cur = head;
	while (cur->next != NULL) {
		if (!strcmp(move->student.account, cur->student.account)) {
			printf("�˺��ظ����������������\n");

			system("pause");
			return;
		}
		cur = cur->next;
	}//�ҵ����ڵ�
	printf("�������......\n");
	fileNode(head);

	system("pause");
}

//ɾ��
void adeleteAccount(mNode* mhead, Node* head) {
	printf("ɾ��ѧ���˺�������1��ɾ����ʦ���߹���Ա�˺�������2\n");
	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ�������������\n");
	}
	scanf("%*[^\n]%*c");

	switch (c) {
	case 1:
		sdeleteAccount(head);
		break;
	case 2:
		mdeleteAccount(mhead);
		break;
	default:
		printf("�޴˷��񣬽����ز˵�\n");
		system("pause");
		break;
	}
}
void mdeleteAccount(mNode* mhead) {
	if (mhead->next == NULL) {
		printf("�����˺�\n");
		system("pause");
		return;
	}

	printf("������Ҫɾ�����˺�(��������ĸ):");
	char Account[11];
	scanf("%10s", Account);
	scanf("%*[^\n]%*c");

	mNode* move = mhead;
	while (move->next != NULL) {
		if (!strcmp(move->next->man.account,Account )) {
			mNode* ret = move->next;
			move->next = ret->next;
			free(ret);
			ret = NULL;
			mfileNode(mhead);
			printf("���˺���ɾ��\n");
			system("pause");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�\n");
	system("pause");
}
void sdeleteAccount(Node* head) {
	if (head->next == NULL) {
		printf("�����˺�\n");
		system("pause");
		return;
	}

	printf("������Ҫɾ�����˺�(��������ĸ):");
	char Account[11];
	scanf("%10s", Account);
	scanf("%*[^\n]%*c");

	Node* move = head;
	while (move->next != NULL) {
		if (!strcmp(move->next->student.account, Account)) {
			Node* ret = move->next;
			move->next = ret->next;
			free(ret);
			ret = NULL;
			fileNode(head);
			printf("���˺���ɾ��\n");
			system("pause");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�\n");
	system("pause");
}
////�޸�
void areviseAccount(mNode* mhead, Node* head) {
	printf("�޸�ѧ���˺�������1���޸���ʦ���߹���Ա�˺�������2\n");
	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ�������������\n");
	}
	scanf("%*[^\n]%*c");

	switch (c) {
	case 1:
		sreviseAccount(head);
		break;
	case 2:
		mreviseAccount(mhead);
		break;
	default:
		printf("�޴˷��񣬽����ز˵�\n");
		break;
	}
}
void mreviseAccount(mNode* mhead) {
	printf("������Ҫ�޸ĵ��˺�(��������ĸ):\n");
	char Account[11];
	scanf("%10s", Account);
	scanf("%*[^\n]%*c");
	printf("�����޸���\n");
	mNode* move = mhead->next;
	while (move != NULL) {
		if (!strcmp(move->man.account, Account)) {
			char c = '\0';
			while (c != 'T' && c != 'G') {
				printf("ѡ����˺�����ʦ���ǹ���Ա��TΪ��ʦ��GΪ����Ա��\n");
				scanf(" %c", &c);
				scanf("%*[^\n]%*c");
				strcpy(move->man.mclass , "man");
				if (c == 'T') {
					printf("�������˺����ڰ༶\n");
					scanf("%63s", move->man.mclass);
					scanf("%*[^\n]%*c");
				}
			}
			move->man.account[0] = c;
			printf("����������\n");
			scanf("%10s", move->man.name);
			scanf("%*[^\n]%*c");

			char newAccount[11];
			memset(newAccount, '\0', sizeof(newAccount));
			newAccount[0] = c;
			printf("�������˺�(����������ĸ)\n");
			scanf("%9s", &newAccount[1]);
			scanf("%*[^\n]%*c");
			mNode* check = mhead->next;
			while (check != NULL) {
				if (strcmp(check->man.account, move->man.account) && !strcmp(check->man.account, newAccount)) {
					printf("�µ��˺��Ѿ����ڣ�����������\n");
					memset(newAccount, '\0', sizeof(newAccount));
					newAccount[0] = c;
					scanf("%9s", &newAccount[1]);
					scanf("%*[^\n]%*c");
					check = mhead;
				}
				else {
					check = check->next;
				}
			}
			strcpy(move->man.account, newAccount);
			printf("����������:\n");
			scanf("%9s", move->man.password);
			scanf("%*[^\n]%*c");

			mfileNode(mhead);
			printf("�޸ĳɹ�\n");

			system("pause");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�\n");
	system("pause");
}

void sreviseAccount(Node* head) {
	printf("������Ҫ�޸ĵ��˺�(��������ĸ):\n");
	char Account[11];
	scanf("%10s", &Account);
	scanf("%*[^\n]%*c");
	printf("�����޸���\n");
	Node* move = head->next;
	while (move != NULL) {
		if (!strcmp(move->student.account, Account)) {

			printf("�������˺����ڰ༶\n");
			scanf("%63s", move->student.mclass);
			scanf("%*[^\n]%*c");
			printf("����������\n");
			scanf("%19s", move->student.name);
			scanf("%*[^\n]%*c");

			char newAccount[11];
			memset(newAccount, '\0', sizeof(newAccount));
			newAccount[0] = 'S';
			printf("�������˺�(����������ĸ)\n");
			scanf("%9s", &newAccount[1]);
			scanf("%*[^\n]%*c");
			Node* check = head->next;
			while (check != NULL) {
				if (strcmp(check->student.account, move->student.account) && !strcmp(check->student.account, newAccount)) {
					printf("�µ��˺��Ѿ����ڣ�����������\n");
					memset(newAccount, '\0', sizeof(newAccount));
					newAccount[0] = 'S';
					scanf("%9s", &newAccount[1]);
					scanf("%*[^\n]%*c");
					check = head;
				}
				else {
					check = check->next;
				}
			}
			strcpy(move->student.account, newAccount);
			printf("����������:\n");
			scanf("%10s", move->student.password);
			scanf("%*[^\n]%*c");

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
//�����˺�����
void afindAccount(mNode* mhead, Node* head) {
	printf("����ѧ���˺�������1��������ʦ���߹���Ա�˺�������2\n");
	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ�������������\n");
	}
	scanf("%*[^\n]%*c");

	switch (c) {
	case 1:
		sfindAccount(head);
		break;
	case 2:
		mfindAccount(mhead);
		break;
	default:
		printf("�޴˷��񣬽����ز˵�\n");
		break;
	}
}

void mfindAccount(mNode* mhead) {

	printf("������Ҫ���ҵ��˺�(��������ĸ):\n");
	char Account[11];
	scanf("%10s", Account);
	scanf("%*[^\n]%*c");
	mNode* move = mhead;
	while (move->next != NULL) {
		if (!strcmp(move->man.account, Account)) {
			printf("����Ϊ��%s\n", move->man.name);
			Sleep(100);
			printf("�˺�Ϊ��%s\n", move->man.account);
			Sleep(100);
			printf("����Ϊ��%s\n", move->man.password);
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

void sfindAccount(Node* head) {

	printf("������Ҫ���ҵ��˺�(��������ĸ):\n");
	char Account[10];
	scanf("%10s", Account);
	scanf("%*[^\n]%*c");
	Node* move = head;
	while (move->next != NULL) {
		if (!strcmp(move->student.account, Account)) {
			printf("����Ϊ��%s\n", move->student.name);
			Sleep(100);
			printf("�˺�Ϊ��%s\n", move->student.account);
			Sleep(100);
			printf("����Ϊ��%s\n", move->student.password);
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

//¼�������˺�����

//��������˺�����
void mprintfStdent(mNode* mhead) {
	if (mhead->next == NULL) {
		printf("����\n");
		system("pause");
		return;
	}
	int a = 0;
	mNode* move = mhead->next;

	while (move != NULL) {

		a++;
		printf("�˺�%d:\n\n", a);
		printf("����Ϊ��%s\n", move->man.name);
		Sleep(100);
		printf("�༶Ϊ��%s\n", move->man.mclass);
		Sleep(100);
		printf("�˺�Ϊ��%s\n", move->man.account);
		Sleep(100);
		printf("����Ϊ��%s\n", move->man.password);
		Sleep(100);
		printf("------------------------------------------------------------\n");
		Sleep(100);
		move = move->next;
	}
	system("pause");

}

void sprintfStdent(Node* head) {
	if (head->next == NULL) {
		printf("����ѧ��\n");
		system("pause");
		return;
	}
	int a = 0;
	Node* move = head->next;

	while (move != NULL) {

		a++;
		printf("ѧ���˺�%d:\n\n", a);		
		printf("ѧ��Ϊ��%d\n", move->student.num);
		Sleep(100);
		printf("����Ϊ��%s\n", move->student.name);
		Sleep(100);
		printf("�༶Ϊ��%s\n", move->student.mclass);
		Sleep(100);
		printf("�˺�Ϊ��%s\n", move->student.account);
		Sleep(100);
		printf("����Ϊ��%s\n", move->student.password);
		Sleep(100);
		printf("------------------------------------------------------------\n");
		Sleep(100);
		move = move->next;
	}
	system("pause");

}
//�ֶ�����¼��ѧ����Ϣ




void agencyMenu() {
	printf("---Student Information Management System---\n");
	printf("--           agency  model\t\t--\n");
	printf("--      0.Զ��˳��� \t\t         --\n");
	printf("--      1.����ע�ᣡ�� \t\t         --\n");
	printf("--      2.�����޸ģ��� \t\t         --\n");
	printf("--      3.�����һأ��� \t\t         --\n");
	printf("--      4.�ɼ����ߣ��� \t\t         --\n");
	printf("--      5.���³ɼ��⣡ \t\t         --\n");
	printf("-------------------------------------------\n");
}
//�鿴����
void Viewagency(Node* head, mNode* mhead, nNode* nhead) {
	while (1) {
		system("cls");
		loadStudent(head);
		mloadStudent(mhead);
		nloadStudent(nhead);
		agencyMenu();
		int c;
		while (scanf("%d", &c) != 1)
		{
			scanf("%*[^\n]%*c");
			printf("����Ƿ�������������\n");
			system("pause");
			system("cls");
			loadStudent(head);
			mloadStudent(mhead);
			nloadStudent(nhead);
			agencyMenu();
		}
		scanf("%*[^\n]%*c");
		switch (c) {
		case 1://����ע��
			readpassWordrevise(nhead, head, mhead);
			break;
		case 2://�����޸�
			readpassWordrevise(nhead, head, mhead);
			break;
		case 3://�����һ�
			readpassWordretrieval(nhead);
			break;
		case 4://�ɼ�����
			readGradeAppeals(nhead, head);
			break;
		case 5://���Ѹ���
			readUpdate(nhead);
			break;
		case 0://�˳�
			return;
			break;
		default:
			printf("�޴�ѡ�����ѡ���\n");
			system("pause");
			break;
		}

	}
}