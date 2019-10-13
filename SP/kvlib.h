#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node* pNode;//��� ����ü ������ ����
typedef struct Node//��� ����ü ���� 
{
	char *key;
	char *data;
	pNode left;
	pNode right;
}Node; 

typedef struct Hashtable//hashtable ����ü ���� 
{
	pNode Table[256];
}HashTable;

int kvget(char *key, char *buf);
int kvput(char *key, char *data);
int kvdel(char *key);
int kvopen();
int kvclose();
void  Print_Node(FILE* kvkey, FILE* kvdata, FILE* kvsize, pNode Root);
