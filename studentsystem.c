#include "studentsystem.h"

void Initialization(mNode* mhead) {
    mNode* pre = (mNode*)malloc(sizeof(mNode));
    pre->next = NULL;

    strcpy(pre->man.name, "admanager");
    strcpy(pre->man.mclass, "man");
    strcpy(pre->man.account, "G20040125");
    strcpy(pre->man.password, "12345678");
    if (mhead->next == NULL) {
        mhead->next = pre;
        printf("�����ڹ���Ա�˺ţ������\n");
    }
    else {
        mNode* cur = mhead;
        int exist = 0; // �Ƿ��Ѿ����ڹ���Ա�˺ŵı�־λ
        while (cur != NULL) {
            if (strcmp(pre->man.account, cur->man.account) == 0) {
                // ����Ѿ����ڹ���Ա�˺ţ����޸�ԭ�нڵ���˺���Ϣ
                strcpy(cur->man.name, "admanager");
                strcpy(cur->man.mclass, "man");
                strcpy(cur->man.password, "12345678");
                exist = 1;
            }
            cur = cur->next;
        }


        if (!exist) {
            // ��������ڹ���Ա�˺ţ����½ڵ���ӵ�����ĩβ
            pre->next=mhead->next;
            mhead->next = pre;

            printf("���������߹���Ա�˺ţ������\n");

        }
    }

    mfileNode(mhead);
    // �������������Ը�����Ҫ�������
    free(pre); // �ͷ�Ԥ�ȷ�����ڴ�ռ�
}

int main() {
    //system("chcp 65001");fubern
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	mNode* mhead = (mNode*)malloc(sizeof(mNode));
	mhead->next = NULL;
    nNode* nhead = (nNode*)malloc(sizeof(nNode));
    nhead->next = NULL;

    mloadStudent(mhead);
	Initialization(mhead);	
    //Manager(head, nhead, mhead, '0');
	PASS(head, nhead, mhead);
    free(head);
    free(nhead);
    free(mhead);
	return 0;
}
