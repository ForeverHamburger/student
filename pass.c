#include "studentsystem.h"




void passMenu() {
	printf("---Student Information Management System---\n");
	printf("--           logon  model\t\t --\n");
	printf("--      0.Զ��˳��� \t\t         --\n");
	printf("--      1.���������ӵ���ս��\t         --\n");
	printf("--      2.����ң�����Ա����\t\t --\n");
	printf("-------------------------------------------\n");
}
void helpMenu() {
	printf("---Student Information Management System---\n");
	printf("--           help  model \t\t --\n");
	printf("--      \t0.Զ��˳��� \t         --\n");
	printf("--      \t1.����ע�ᣡ�� \t         --\n");
	printf("--      \t2.�����޸ģ��� \t         --\n");
	printf("--      \t3.�����һأ��� \t         --\n");
	printf("-------------------------------------------\n");
}
void helping(Node* head, nNode* nhead, mNode* mhead) {
	while (1) {
		system("cls");
		loadStudent(head);
		mloadStudent(mhead);
		nloadStudent(nhead);
		helpMenu();
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
			helpMenu();
		}
		scanf("%*[^\n]%*c");
		switch (c) {
		case 1://����ע��
			passWordrevise(head,mhead,nhead);
			break;
		case 2://�����޸�
			passWordrevise(head, mhead, nhead);
			break;
		case 3://�����һ�
			passWordretrieval(nhead, head, mhead);
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

void passing(Node* head, nNode* nhead, mNode* mhead) {
	char account[11] = { '\0' };
	char password[11] = { '\0' };
	printf("�������˺�:\n");
	scanf("%10s", account);
	scanf("%*[^\n]%*c");
	printf("����������:\n");
	scanf("%10s", password);
	scanf("%*[^\n]%*c");
	printf("���ڵ�¼��......\n");
	Sleep(1000);
	system("cls");

	if (account[0] == 'G' || account[0] == 'T') {
		mNode* move = mhead;
		while (move != NULL) {
			if (!strcmp(move->man.account, account)) {
				if (!strcmp(move->man.password, password)) {

					if (account[0] == 'T') {
						printf("��ʦ��ã���ӭʹ�ñ�ϵͳ\n");
						if (strcmp(move->man.question, "����ԭ����") == 0 && strcmp(move->man.answer, "��Ԫ�����") == 0) {
							printf("��ʦ��ã����ε�¼������ܱ�\n");
							system("pause");
							treviseconfidential(mhead, move->man.account);
						}
						system("pause");
						Teachers(head,  nhead, mhead, move->man.account, move->man.mclass, move->man.name);
						return;
					}
					else if (account[0] == 'G') {
						printf("����Ա��ã���ӭʹ�ñ�ϵͳ\n");
						system("pause");
						Manager(head,nhead, mhead, move->man.account);
						return;
					}
				}
				else {
					printf("�������Ŷ������������\n");
					system("pause");
					return;
				}
			}
			move = move->next;
		
		}
		printf("���˺Ų�����,������ѡ��\n");
		system("pause");
	}
	else if (account[0] == 'S') {
		Node* move = head;
		while (move != NULL) {

			if (!strcmp(move->student.account, account)) {
				if (!strcmp(move->student.password, password)) {
					printf("ͬѧ��ã���ӭʹ�ñ�ϵͳ\n");
					system("pause");
					if (strcmp(move->student.question, "����ԭ����") == 0 && strcmp(move->student.answer, "��Ԫ�����") == 0) {
						printf("ͬѧ��ã����ε�¼������ܱ�\n");
						system("pause");
						sreviseconfidential(head, move->student.num);
					}
					Students(head, nhead, move->student.mclass, move->student.num, move->student.account, move->student.name);
					return;
				}
				else {
					printf("�������Ŷ������������\n");
					system("pause");
					return;
				}
			}
			move = move->next;
		}
		printf("���˺Ų�����,������ѡ��\n");
		system("pause");
	}
	else {
		printf("�˺Ÿ�ʽ������������\"G\", \"T\"��\"S\"��ͷ���˺�\n");
		system("pause");
		return;
	}
}

void PASS(Node* head, nNode* nhead, mNode* mhead) {

	while (1) {
		system("cls");
		loadStudent(head);
		mloadStudent(mhead);
		nloadStudent(nhead);
		passMenu();
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
			passMenu();
		}
		scanf("%*[^\n]%*c");
		switch (c) {
		case 1://��¼
			passing(head,nhead,mhead);
			break;
		case 2://����
			helping(head,nhead,mhead);
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


//����������ļ�
void nfileNode(nNode* nhead) {
	FILE* fp = fopen("./helpNode.txt", "w");
	if (fp == NULL) {
		printf("δ�ҵ�ѧ���ļ�\n");
		return;
	}
	nNode* move = nhead->next;
	while (move != NULL) {
		if (fwrite(&move->con, sizeof(Con), 1, fp) != 1) {
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
void nloadStudent(nNode* nhead) {
	//���ļ�
	FILE* fp = fopen("./helpNode.txt", "r");
	if (fp == NULL) {
		printf("--\t δ�ҵ������ļ�,������ȡ\t --\n");
		return;
	}

	//����һ�����
	nNode* new = (nNode*)malloc(sizeof(nNode));
	new->next = NULL;
	nNode* move = nhead;
	while (fread(&new->con, sizeof(Con), 1, fp) == 1) {
		move->next = new;
		move = new;

		new = (nNode*)malloc(sizeof(nNode));
		new->next = NULL;
	}
	free(new);
	//���ඨ��һ��new��Ҫ�����ͷŵ�
	//�ر��ļ�
	fclose(fp);

	//printf("��ȡ�ɹ�\n");

}




//����ע��

//�����޸�
void passWordrevise(Node* head, mNode* mhead, nNode* nhead) {

	printf("1��ѧ���˺������޸�\n");
	printf("2����ʦ�˺������޸�\n");
	printf("��ѡ��:\n");

	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ���������ѡ��\n");

	}
	scanf("%*[^\n]%*c");
	switch (c) {
	case 1:
		spassWordretrieval(nhead,head);
		break;
	case 2:
		tpassWordretrieval(nhead, mhead);
		break;
	default:
		printf("�޴˷��񣬽����ز˵�\n");
		system("pause");
		break;
	}

}
//�����޸�ѧ��
void spassWordrevise(nNode* nhead,Node*head) {

	char question[100] = { '\0' };
	char answer[100] = { '\0' };
	char Account[11] = { '\0' };
	char Password[11] = { '\0' };
	int flag = 0;
	nNode* pre = (nNode*)malloc(sizeof(nNode));
	pre->con.chose = 2;
	pre->con.over = 0;
	pre->next = NULL;
	//�ݴ�
	printf("������Ҫ����������˺ţ�\n");
	scanf("%10s", Account);
	scanf("%*[^\n]%*c");
	if (Account[0] != 'S') {
		free(pre);
		printf("��ѧ���˻�\n");
		system("pause");
		return;
	}
	printf("������Ҫ����������˺ŵ����룺\n");
	scanf("%10s", Password);
	scanf("%*[^\n]%*c");

	Node* move = head;
	while (move != NULL) {
		if (!strcmp(move->student.account,Account)) {
			if (!strcmp(move->student.password, Password)) {
				pre->con.num = move->student.num;
				strcpy(pre->con.name, move->student.name);
				strcpy(pre->con.account,Account);
				strcpy(pre->con.mclass, move->student.mclass);
				flag = 1;
			}
		}
		move = move->next;
	}

	if (flag) {

		nNode* cur = nhead;
		while (cur->next != NULL) {

			cur = cur->next;
		}//�ҵ����ڵ�

		printf("���������֮������룺\n");
		scanf("%10s", pre->con.newPassword);
		scanf("%*[^\n]%*c");
		printf("���ڼ���\n");
		cur->next = pre;
		nfileNode(nhead);
		system("pause");
	}
	else {
		free(pre);
		printf("�˺Ż���������޷��޸�\n");
		system("pause");
	}
}
//�����޸�ѧ������
void dospassWordrevise(Node* head,char*account,char*newpassword) {
	Node* move = head;
	printf("�޸���\n");
	Sleep(100);
	while (move != NULL) {
		if (!strcmp(move->student.account, account)) {
			strcpy(move->student.password, newpassword);
			fileNode(head);
			printf("�޸����\n");
			system("pause");
		}
		move = move->next;
	}
}
//�����޸���ʦ
void tpassWordrevise(nNode* nhead, mNode* mhead) {

	char question[100] = { '\0' };
	char answer[100] = { '\0' };
	char Account[11] = { '\0' };
	char Password[11] = { '\0' };
	int flag = 0;
	nNode* pre = (nNode*)malloc(sizeof(nNode));
	pre->con.chose = 2;
	pre->con.over = 0;
	pre->next = NULL;
	//�ݴ�
	printf("������Ҫ����������˺ţ�\n");
	scanf("%10s", Account);
	scanf("%*[^\n]%*c");
	if (Account[0] != 'T') {
		free(pre);
		printf("����ʦ�˻�\n");
		system("pause");
		return;
	}
	printf("������Ҫ����������˺ŵ����룺\n");
	scanf("%10s", Password);
	scanf("%*[^\n]%*c");

	mNode* move = mhead;
	while (move != NULL) {
		if (!strcmp(move->man.account, Account)) {
			if (!strcmp(move->man.password, Password)) {
				pre->con.num = 0;
				strcpy(pre->con.name, move->man.name);
				strcpy(pre->con.account, Account);
				strcpy(pre->con.mclass, move->man.mclass);
				pre->con.num = 0;
				flag = 1;
			}
		}
		move = move->next;
	}

	if (flag) {

		nNode* cur = nhead;
		while (cur->next != NULL) {

			cur = cur->next;
		}//�ҵ����ڵ�

		printf("���������֮������룺\n");
		scanf("%10s", pre->con.newPassword);
		scanf("%*[^\n]%*c");
		printf("���ڼ���\n");
		cur->next = pre;
		nfileNode(nhead);
		system("pause");
	}
	else {
		free(pre);
		printf("�˺Ż���������޷��޸�\n");
		system("pause");
	}
}
//�����޸���ʦ����
void dotpassWordrevise(mNode* mhead, char* account, char* newpassword) {
	mNode* move = mhead;
	printf("�޸���\n");
	Sleep(100);
	while (move != NULL) {
		if (!strcmp(move->man.account, account)) {
			strcpy(move->man.password, newpassword);
			mfileNode(mhead);
			printf("�޸����\n");
			system("pause");
		}
		move = move->next;
	}
}
//�����޸Ķ�ȡ
void readpassWordrevise(nNode* nhead, Node* head, mNode* mhead) {

	if (nhead->next == NULL) {
		printf("���������޸�����\n");
		system("pause");
		return;
	}
	int a = 0;
	nNode* move = nhead->next;

	while (move != NULL) {
		if (move->con.chose == 2) {
			a++;
			printf("�����޸����� %d:\n\n", a);

			printf("ѧ��Ϊ��%d\n", move->con.num);
			printf("ѧ��Ϊ0,������ʦ�˺�\n");
			Sleep(100);
			printf("�˺�Ϊ��%s\n", move->con.account);
			Sleep(100);
			printf("����Ϊ��%s\n", move->con.name);
			Sleep(100);
			printf("�༶Ϊ��%s\n", move->con.mclass);
			Sleep(100);
			printf("����֮�������:%s\n", move->con.newPassword);
			Sleep(100);
			printf("------------------------------------------------------------\n");
			Sleep(100);
			if (move->con.over == 1) {
				printf("(����ɸô���)\n");
			}
			else{
				printf("�Ƿ�ͬ������� \n");
				printf("1ͬ�⣬2�ܾ�\n");
				int c;
				while (scanf("%d", &c) != 1)
				{
					scanf("%*[^\n]%*c");
					printf("����Ƿ���������ѡ��\n");

				}
				scanf("%*[^\n]%*c");
				switch (c) {
				case 1:
					if (move->con.num != 0)
					{
						move->con.over = 1;
						nfileNode(nhead);
						dospassWordrevise(head, move->con.account, move->con.newPassword);
					}
					else
					{
						move->con.over = 1;
						nfileNode(nhead);
						dotpassWordrevise(head, move->con.account, move->con.newPassword);
					}
					break;
				case 2:
					break;
				default:
					printf("�޴˷���Ĭ�Ͼܾ�\n");
					system("pause");
					break;
				}
			}
			ndelete(nhead, move->con.account);
		}
		move = move->next;
	}
	printf("------------------------------------------------------------\n");
	printf("û�������޸���������������İ�\n");
	system("pause");
}

//�����һ�
void passWordretrieval(nNode* nhead, Node* head, mNode* mhead) {
	printf("1��ѧ���˺������һ�\n");
	printf("2����ʦ�˺������һ�\n");
	printf("��ѡ��:\n");

	int c;
	while (scanf("%d", &c) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ���������ѡ��\n");

	}
	scanf("%*[^\n]%*c");
	switch (c) {
	case 1:
		spassWordretrieval(nhead, head);
		break;
	case 2:
		tpassWordretrieval(nhead, mhead);
		break;
	default:
		printf("�޴˷��񣬽����ز˵�\n");
		system("pause");
		break;
	}
}
//�����һ�ѧ��
void spassWordretrieval(nNode* nhead, Node* head) {

	char question[100] = { '\0' };
	char answer[100] = { '\0' };
	char Account[11] = { '\0' };
	int flag = 0;
	nNode* pre = (nNode*)malloc(sizeof(nNode));
	pre->con.chose = 3;
	pre->con.over = 0;
	pre->next = NULL;
	//�ݴ�
	printf("������Ҫ�һ�������˺ţ�\n");
	scanf("%10s", Account);
	scanf("%*[^\n]%*c");
	if (Account[0] != 'S') {
		free(pre);
		printf("��ѧ���˻�\n");
		system("pause");
		return;
	}
	printf("�������ܱ����⣺\n");
	scanf("%100s", question);
	scanf("%*[^\n]%*c");

	printf("�������ܱ���:\n");
	scanf("%100s", answer);
	scanf("%*[^\n]%*c");
	char phonenum[101] = { '\0' };
	printf("������绰����:\n");
	scanf("%100s", phonenum);
	scanf("%*[^\n]%*c");

	Node* move = head;
	while (move != NULL) {
		if (!strcmp(move->student.account, Account)) {
			if (!strcmp(move->student.question, question) && !strcmp(move->student.answer, answer))
			{
				strcpy(pre->con.phonenum, phonenum);
				pre->con.num = move->student.num;
				strcpy(pre->con.name, move->student.name);
				strcpy(pre->con.account, Account);
				strcpy(pre->con.mclass, move->student.mclass);
				flag = 1;

			}
		}
		move = move->next;
	}

	if (flag) {

		nNode* cur = nhead;
		while (cur->next != NULL) {

			cur = cur->next;
		}//�ҵ����ڵ�

		printf("���ڼ���\n");
		cur->next = pre;
		nfileNode(nhead);
		printf("�������ύ\n");
		system("pause");
	}
	else {
		free(pre);
		printf("�ܱ������޷��޸�\n");
		system("pause");
	}
}
//�����һ���ʦ
void tpassWordretrieval(nNode* nhead, mNode* mhead) {

	char question[100] = { '\0' };
	char answer[100] = { '\0' };
	char Account[11] = { '\0' };
	int flag = 0;
	nNode* pre = (nNode*)malloc(sizeof(nNode));
	pre->con.chose = 3;
	pre->con.over = 0;
	pre->next = NULL;
	//�ݴ�
	printf("������Ҫ�һ�������˺ţ�\n");
	scanf("%10s", Account);
	scanf("%*[^\n]%*c");
	if (Account[0] != 'T') {
		free(pre);
		printf("����ʦ�˻�\n");
		system("pause");
		return;
	}	


	printf("�������ܱ����⣺\n");
	scanf("%100s", question);
	scanf("%*[^\n]%*c");

	printf("�������ܱ���:\n");
	scanf("%100s", answer);
	scanf("%*[^\n]%*c");
	char phonenum[101] = { '\0' };
	printf("������绰����:\n");
	scanf("%100s", phonenum);
	scanf("%*[^\n]%*c");


	mNode* move = mhead;
	while (move != NULL) {
		if (!strcmp(move->man.account, Account)) {
			if (!strcmp(move->man.question, question) && !strcmp(move->man.answer, answer))
			{
				strcpy(pre->con.phonenum, phonenum);
				pre->con.num = 0;
				strcpy(pre->con.name, move->man.name);
				strcpy(pre->con.account, Account);
				strcpy(pre->con.mclass, move->man.mclass);
				flag = 1;

			}
		}
		move = move->next;
	}
	if (flag) {

		nNode* cur = nhead;
		while (cur->next != NULL) {

			cur = cur->next;
		}//�ҵ����ڵ�
		printf("���ڼ���\n");
		cur->next = pre;
		nfileNode(nhead);
		printf("�������ύ\n");
		system("pause");
	}
	else {
		free(pre);
		printf("�ܱ������޷��޸�\n");
		system("pause");
		return;
	}
}
//�����һض�ȡ
void readpassWordretrieval(nNode* nhead) {

	if (nhead->next == NULL) {
		printf("���������һ�����\n");
		system("pause");
		return;
	}
	int a = 0;
	nNode* move = nhead->next;

	while (move != NULL) {
		if (move->con.chose == 3) {
			a++;
			printf("�����һ����� %d:\n\n", a);

			printf("ѧ��Ϊ��%d\n", move->con.num);
			printf("ѧ��Ϊ0,������ʦ�˺�\n");
			Sleep(100);
			printf("�˺�Ϊ��%s\n", move->con.account);
			Sleep(100);
			printf("����Ϊ��%s\n", move->con.name);
			Sleep(100);
			printf("�༶Ϊ��%s\n", move->con.mclass);
			Sleep(100);
			printf("------------------------------------------------------------\n");
			Sleep(100);
			if (move->con.over == 1) {
				printf("������ɸô��죩\n");
			}
			else
			{
				printf("�Ƿ�ͬ������� \n");
				printf("1ͬ�⣬2�ܾ�\n");
				int c;
				while (scanf("%d", &c) != 1)
				{
					scanf("%*[^\n]%*c");
					printf("����Ƿ���������ѡ��\n");

				}
				scanf("%*[^\n]%*c");
				switch (c) {
				case 1:
					move->con.over = 1;
					nfileNode(nhead);
					printf("���µ�:%s,��֪�Է�����\n", move->con.phonenum);
					break;
				case 2:
					break;
				default:
					printf("�޴˷���Ĭ�Ͼܾ�\n");
					system("pause");
					break;
				}
			}
			ndelete(nhead, move->con.account);

		}
		move = move->next;
	}
	printf("------------------------------------------------------------\n");
	printf("û�������һ���������������İ�\n");
	system("pause");

}


//�ɼ�����
void GradeAppeals(nNode* nhead, char* mclass, int num, char* account,char*name) {

	nNode* pre = (nNode*)malloc(sizeof(nNode));
	pre->con.chose = 4;
	pre->con.over = 0;
	pre->next = NULL;
	//�ݴ�
	strcpy(pre->con.name, name);
	strcpy(pre->con.account, account);
	strcpy(pre->con.mclass, mclass);
	pre->con.num = num;

	printf("������Ҫ����ǰ�ĳɼ�����ѧ��Ӣ����ģ�\n");
	scanf("%d%d%d", &pre->con.icomplaint[1], &pre->con.icomplaint[2], &pre->con.icomplaint[3]);
	scanf("%*[^\n]%*c");

	printf("������Ҫ���ĺ�ĳɼ�����ѧ��Ӣ����ģ�\n");
	scanf("%d%d%d", &pre->con.icomplaint[4], &pre->con.icomplaint[5], &pre->con.icomplaint[6]);
	scanf("%*[^\n]%*c");

	printf("��������������\n");
	scanf("%999s",pre->con.ccomplaint);
	scanf("%*[^\n]%*c");

	nNode* cur = nhead;
	while (cur->next != NULL) {

		cur = cur->next;
	}//�ҵ����ڵ�

	printf("���ڼ���\n");

	cur->next = pre;

	nfileNode(nhead);
	printf("�������ύ\n");
	system("pause");

}
//�ɼ����߶�ȡ
void readGradeAppeals(nNode* nhead,Node* head) {

		if (nhead->next == NULL) {
			printf("��������\n");
			system("pause");
			return;
		}
		int a = 0;
		nNode* move = nhead->next;

		while (move != NULL) {
			if(move->con.chose==4){
				a++;
				printf("���� %d:\n\n", a);

				printf("ѧ��Ϊ��%d\n", move->con.num);
				Sleep(100);
				printf("�˺�Ϊ��%s\n", move->con.account);
				Sleep(100);
				printf("����Ϊ��%s\n", move->con.name);
				Sleep(100);
				printf("�༶Ϊ��%s\n", move->con.mclass);
				Sleep(100);
				printf("����ǰ�ĳɼ�����ѧ��Ӣ����ģ�\n");
				printf("��ѧ��%-10d\t Ӣ�%-10d\t ���ģ�%-10d\t \n", move->con.icomplaint[1], move->con.icomplaint[2], move->con.icomplaint[3]);
				Sleep(100);
				printf("���ĺ�ĳɼ�����ѧ��Ӣ����ģ�\n");
				printf("��ѧ��%-10d\t Ӣ�%-10d\t ���ģ�%-10d\t \n", move->con.icomplaint[4], move->con.icomplaint[5], move->con.icomplaint[6]);
				Sleep(100);
				printf("�������ɣ�%s\n", move->con.ccomplaint);
				Sleep(100);
				printf("------------------------------------------------------------\n");
				Sleep(100);
				if (move->con.over == 1) {
					printf("������ɸô��죩\n");
					
				}
				else{
					printf("�Ƿ�ͬ������� \n");
					printf("1ͬ�⣬2�ܾ�\n");
					int c;
					while (scanf("%d", &c) != 1)
					{
						scanf("%*[^\n]%*c");
						printf("����Ƿ���������ѡ��\n");

					}
					scanf("%*[^\n]%*c");
					switch (c) {
					case 1:
						move->con.over = 1;
						nfileNode(nhead);
						doGradeAppeals(head, move->con.icomplaint[4], move->con.icomplaint[5], move->con.icomplaint[6], move->con.account);

						break;
					case 2:
						break;
					default:
						printf("�޴˷���Ĭ�Ͼܾ�\n");
						system("pause");
						break;
					}
				}
				ndelete(nhead, move->con.account);
			}
			move = move->next;
		}
		printf("------------------------------------------------------------\n");
		printf("û����������������İ�\n");
		system("pause");
}
//�ɼ����߲���
void doGradeAppeals(Node* head, int match, int english,int chinese,char*account) {
	Node* move = head;
	printf("�޸���\n");
	Sleep(100);
	while (move != NULL) {
		if (!strcmp(move->student.account, account)) {
			move->student.score.match=match;
			move->student.score.english=english;
			move->student.score.chinese=chinese;

			fileNode(head);
			printf("�޸����\n");

			system("pause");

		}
		move = move->next;
	}

}

//���³ɼ���
void Update(nNode* nhead, char* account,char*mclass, char* name) {

	nNode* pre = (nNode*)malloc(sizeof(nNode));
	pre->con.chose = 5;
	pre->con.over =0;
	pre->next = NULL;
	//�ݴ�
	pre->con.num = 0;


	strcpy(pre->con.name, name);
	strcpy(pre->con.account, account);
	strcpy(pre->con.mclass, mclass);

	printf("��������Ҫ���߹���Ա�Ļ�\n");
	scanf("%*[^\n]%*c");
	scanf("%999s", pre->con.ccomplaint);
	scanf("%*[^\n]%*c");

	nNode* cur = nhead;
	while (cur->next != NULL) {

		cur = cur->next;
	}//�ҵ����ڵ�

	printf("���ڼ���\n");

	cur->next = pre;

	nfileNode(nhead);
	printf("�������ύ\n");
	system("pause");
}
//���³ɼ����ȡ
void readUpdate(nNode* nhead) {
	if (nhead->next == NULL) {
		printf("���޸��³ɼ�������\n");
		system("pause");
		return;
	}
	int a = 0;
	nNode* move = nhead->next;

	while (move != NULL) {
		if (move->con.chose == 5) {
			a++;
			printf("���³ɼ������� %d:\n\n", a);

			printf("�˺�Ϊ��%s\n", move->con.account);
			Sleep(100);
			printf("����Ϊ��%s\n", move->con.name);
			Sleep(100);
			printf("�༶Ϊ��%s\n", move->con.mclass);
			Sleep(100);
			printf("��Ҫ˵�Ļ���%s\n", move->con.ccomplaint);
			Sleep(100);
			printf("------------------------------------------------------------\n");
			if (move->con.over == 1) {
				printf("������ɸô��죩\n");
			}
			else
			{
				move->con.over = 1;
				nfileNode(nhead);
			}
			ndelete(nhead, move->con.account);
		}
		move = move->next;
	}
	printf("------------------------------------------------------------\n");
	printf("û�и�����������������İ�\n");
	system("pause");

}

//ɾ����������
void ndeleteStudent(nNode * nhead, char* Account) {
	nNode* move = nhead;
	while (move->next != NULL) {
		if (!strcmp(move->next->con.account, Account)) {
			nNode* ret = move->next;
			move->next = ret->next;
			free(ret);
			ret = NULL;
			nfileNode(nhead);
			printf("�ô�����ɾ��\n");
			system("pause");

			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�\n");
	system("pause");
}
//
void ndelete(nNode* nhead, char*account) {
	printf("------------------------------------------------------------\n");
	printf("�Ƿ�ɾ�������룺\n");
	printf("1ɾ����2����\n");
	int d;
	while (scanf("%d", &d) != 1)
	{
		scanf("%*[^\n]%*c");
		printf("����Ƿ���������ѡ��\n");

	}
	scanf("%*[^\n]%*c");
	switch (d) {
	case 1:
		ndeleteStudent(nhead,account);
		break;
	case 2:
		break;
	default:
		printf("�޴˷���Ĭ�ϱ���\n");
		system("pause");
		break;
	}
}