#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kvlib.h"

HashTable Htable = {NULL};//�ؽ����̺��� �������� ����
// �� ��� �Լ��� ������ 0, ���н� ���� ������ �����ڵ带 �����Ѵ�.
 
// �־��� key�� �̿��Ͽ� data�� ã��, buf�� �����Ͽ� ���Ͻ��� �ش�.
int kvget(char *key, char *buf)
{
	pNode cur;//�̵��ϸ� ���� ���� ����ü ������ 
	int tablekey = key[0];//tablekey�� ���� ���� 
	int compare;//�񱳰� ������ ���� ����

	cur = Htable.Table[tablekey];//cur�� table[tablekey] �ּ� �Է� 
		
	while(cur)//cur�� NULL�̵ɶ����� �ݺ� 
	{
		compare = strcmp(key, cur->key);//key�� ����� key ��
		
		if(compare < 0)//����� key���� root����� key������ ������ 
		{
			cur = cur->left;//���ʳ��� �̵�
		}
		else if(compare > 0)//����� key���� root����� key������ Ŭ�� 
		{
			cur = cur->right;//������ ���� �̵�
		}
		else//���� ������
		{
			strcpy(buf, cur->data);//����� data�� buf�� ����
			return 0;
		}
	}

	if(cur == NULL)//ã������ ���� ������
	{
		strset(buf,'\0');//���� �ʱ�ȭ
 		return 1;
 	}
}

// �־��� key�� data�� �̿��Ͽ� kv store�� �����Ѵ�. 
// �̹� key�� �����ϴ� ��� �����. 
int kvput(char *key, char *data)
{
	int TableKey = key[0];//tablekey�� ���� 
	pNode NewNode = (pNode)malloc(sizeof(Node));//���ο� ���� ���� ����ü �����Ҵ�
	int compare;//key�� �񱳰�� ���庯��
	pNode Pre_Root, Root;//������ ���� ��� ������
	int key_size = strlen(key);//key�� �������� 
	int data_size = strlen(data);//data�� �������� 

	NewNode->key = (char*)malloc(sizeof(char)*key_size+1);//����� key�� key+1 ũ�⸸ŭ �����Ҵ�
	NewNode->data = (char*)malloc(sizeof(char)*data_size+1);//����� data�� data+1 ũ�⸸ŭ �����Ҵ�
	
	strcpy(NewNode->key, key);//key�� ����
	strcpy(NewNode->data, data);//data�� ����
	NewNode->key[key_size] = '\0';//���ڿ��� �������� �ι��� �߰�
	NewNode->data[data_size] = '\0';//���ڿ��� �������� �ι��� �߰�
	NewNode->left = NULL;//�¿� ��������� �ʱ�ȭ
	NewNode->right = NULL;
	
	if(Htable.Table[TableKey] == NULL)//table�� ���� �ϳ��������� 
	{
		Htable.Table[TableKey] = NewNode;//table�� ���ο� ����ü ���� 
		return 0;
	}
	else//table�� ���� �����ҋ� 
	{
		Root = Htable.Table[TableKey];//����Ʈ�� ������ġ ����
		
		while(1)
		{
			if(Root == NULL)//��尡 ������
			{ 
				if(compare < 0)//��������� key������ ������
					Pre_Root->left = NewNode;//��������� ���ʿ� ����
				else//��������� key������ Ŭ��
					Pre_Root->right = NewNode;//��������� �����ʿ� ����
			
				return 0;
			}
		
			compare = strcmp(NewNode->key, Root->key);//������ ����� key�� ��
			if(compare < 0)//�� ����� key���� ����� key������ ������ 
			{
				Pre_Root = Root;//������� �̵�
				Root = Root->left;//��� �������� �̵�
			}
			else if(compare > 0)//�� ����� key���� ����� key������ Ŭ�� 
			{
				Pre_Root = Root;//������� �̵�
				Root = Root->right;//��� ���������� �̵�
			}
			else//�� ����� key���� �̹� �����ҋ�
			{
				Root->data = (char*)realloc(Root->data, sizeof(char)*data_size+1);//������� data+1 ���̸�ŭ �絿���Ҵ�
				strcpy(Root->data, NewNode->data);//������� data�� ��忡 ����
				Root->data[data_size] = '\0';//���ڿ��� �������� �ι��� �߰� 
				free(NewNode);//����� �����Ҵ� ����
				return 0;
			}
		}
	}
	
	return 1;
}

// �־��� key�� �̿��Ͽ� key�� data�� �����Ѵ�. 
int kvdel(char *key)
{
 	pNode parent, node, root;//�������� ��������� �θ����� �ּҸ� ���� ������ 
	pNode succ, succ_parent, child; //������ ��ġ�� ���� ������ 
	int compare, tablekey = key[0];//key�񱳰� ������ ���� ������ table��ȣ
	parent = NULL;//����߱�ȭ
	root = Htable.Table[tablekey];//����Ʈ�� ������ġ
	node = root;//������ ��带 ����ų ������
	

	while(node != NULL)//Target���� ���� Node�� ã�´� 
	{//������尡 NULL�̰ų� ������� ���� Target���� ������ while�� ���� 
    	compare = strcmp(key,node->key);//key�� ��
    	
		if(compare == 0)//Ű���� ������ ������尡 �������
    		break;
    	
    	parent = node;//�θ� ���� ���� �񱳳�� 
    	
    	if(compare < 0)//���� ����� ���� target������ Ŭ�� 
			node = node->left; //�������� ���� �ڽ� ��尡 �ȴ� 
    	else node = node->right; //�������� ������ �ڽ� ��尡 �ȴ� 
	} 
	
	if(node == NULL) //������� ���� NULL�̸� Target���� ��ġ�� ��尡 �����Ƿ� ���� 
	{ 
    	return 1; 
	} 
   
	if((node->left == NULL) && (node->right == NULL)) //��������� �ڽĳ�尡 �ϳ��� ������ 
	{ 
    	if(parent != NULL) //��������� �θ��尡 NULL�� �ƴҶ�(������尡 root��尡 �ƴҶ�) 
    	{ 
        	if(parent->left == node) //������尡 �θ����� ���� �ڽ��϶� 
        		parent->left = NULL;//�θ����� �����ּ� NULL 
        	else
				parent->right = NULL;//�θ����� �������ּ� NULL 
    	} 
    	else//������尡 root����ϋ� 
			Htable.Table[tablekey] = NULL;
	} 
	else if((node->left == NULL) || (node->right == NULL))//��������� �ڽĳ�尡 1���϶� 
	{ 
    	if(node->left != NULL)//��������� ���� �ڽ��� ������ 
			child = node->left; 
    	else//��������� ������ �ڽ��� ������ 
			child = node->right; 
    	if(parent != NULL)//��������� �θ��尡 NULL�� �ƴҶ�(������尡 root��尡 �ƴҶ�) 
    	{ 
        	if(parent->left == node)//������尡 �θ����� ���� �ڽ��϶� 
        		parent->left = child;//�ڽĳ�带 �θ����� �������� ���δ� 
        	else//������尡 �θ����� ������ �ڽ��϶� 
				parent->right = child;//�ڽĳ�带 �θ����� ���������� ���δ�  
    	} 
    	else//������尡 root����϶� 
			Htable.Table[tablekey] = child;//�ڽĳ�尡 root��尡 �ȴ�. 
	} 
	else//��������� �ڽ��� 2���϶� 
	{ 
    	succ_parent = node;//��ü�θ���� ������� 
    	succ = node->left; //��ü���� ��������� left 
    	
		while(succ->right != NULL) //������尪�� �ٷ� �Ʒ����� ã�´�. 
    	{ //��ü����� right�� �����Ҷ� 
        	succ_parent = succ; //��ü�θ���� ��ü��� 
        	succ = succ->right; //��ü���� ��ü����� right 
    	}
    	

    	if(root == node)//������尡 ����Ʈ���� ��Ʈ����ϋ�
    	{
    		if(succ_parent == root)//��ü�θ��尡 ��Ʈ����ϋ� 
    		{
                Htable.Table[tablekey] = succ;//��ü���� ����Ʈ�� ���۳��
    			succ->right = node->right;//��ü����� �����ʿ� ��������� ������ ����	
            }
            else
            { 
    		    Htable.Table[tablekey] = succ;//��ü���� ����Ʈ�� ���۳��
    		    succ_parent->right = succ->left;//��ü�θ����� right�� ��ü����� rigit 
                succ->left = node->left;//��ü����� ���ʿ� ��������� ���� ����
                succ->right = node->right;//��ü����� �����ʿ� ��������� ������ ����
            }
		}
		else//������尡 ����Ʈ���� ��Ʈ��尡 �ƴҶ�
		{
			if(succ==node->left)//��ü��尡 ��������� �����ڽ��ϋ�
			{
                succ->right = node->right;//��ü����� �����ʿ� ��������� ������ ����
                if(parent->left == node)//������尡 �� �θ����� �����ڽ��϶�
                    parent->left = succ;//��ü��带 ���ʿ� ����
                else//������ �ڽ��ϋ�
                    parent->right = succ;//��ü��带 �����ʿ� ����
            }
            else//��ü��尡 ������嶧�� �����ڽ��� �ƴҶ�
            {
                succ_parent->right = succ->left;//��ü����� �����ڽ��� ��ü�θ��忡 ���� 
			    succ->left = node->left;//��������� �����ڽĸ� ��ü��忡 ����
    		    succ->right = node->right;//��������� �������ڽ��� ��ü��忡 ����
    		    if(parent->left == node)//������尡 �� �θ����� �����ڽ��϶�
                    parent->left = succ;//��ü��带 ���ʿ� ����
                else//������ �ڽ��ϋ�
                    parent->right = succ;//��ü��带 �����ʿ� ����
            }
		}

	} 
	
	free(node); //��������� �����Ҵ��� �����Ѵ� 
	return 0;
}

// kv store�� open�Ͽ� ������ key-data�� �ҷ��´�.
// ������ key-data�� ���ٸ� �����Ѵ�. 
int kvopen()
{
	int key_size, data_size;//size�� ���� ���� 
	FILE* kvkey = fopen("kvkey.txt","a+");//�б� ���� ���Ͽ���
	FILE* kvdata = fopen("kvdata.txt","a+");
	FILE* kvsize = fopen("kvsize.txt","a+"); 
	int TableKey;//tablekey�� ���� 
	pNode NewNode;//���ο� ���� ���� ���
	int compare;//key�� �񱳰�� ���庯��
	pNode Pre_Root, Root;//������ ���� ��� ������
	char key[4096];//key�� ���� ���� 
	strset(key,'\0');//key�ʱ�ȭ 
	
	while(fscanf(kvkey,"%s",key) != -1)//key���� NULL�� �ƴҶ� 
	{	
		fscanf(kvsize,"%d %d", &key_size, &data_size);//kvsize���� ������ ������ޱ�		
		NewNode = (pNode)malloc(sizeof(Node));//���ο� ���� ���� ����ü �����Ҵ�
		NewNode->key = (char*)malloc(sizeof(char)*key_size+1);//����� key�� keyũ�⸸ŭ �����Ҵ�
		NewNode->data = (char*)malloc(sizeof(char)*data_size+1);//����� data�� dataũ�⸸ŭ �����Ҵ�
		strcpy(NewNode->key,key);//�����Ҵ�� ��忡 key �ֱ� 
		fscanf(kvdata,"%s", NewNode->data);//�����Ҵ�� ��忡 data �ֱ� 
		NewNode->key[key_size] = '\0';//���ڿ��� �������� �ι��� �߰� 
		NewNode->data[data_size] = '\0';
		TableKey = NewNode->key[0];//�ؽ����̺��� Ű = key�� ù�ܾ� 
		NewNode->left = NULL;//�¿� ��������� �ʱ�ȭ
		NewNode->right = NULL;
	
		if(Htable.Table[TableKey] == NULL)//table�� ���� �ϳ��������� 
		{
			Htable.Table[TableKey] = NewNode;//table�� ���ο� ����ü ���� 
		}
		else//table�� ���� �����ҋ� 
		{
			Root = Htable.Table[TableKey];//����Ʈ�� ������ġ ����
		
			while(1)
			{
				if(Root == NULL)//��尡 ������
				{ 
					if(compare < 0)//��������� key������ ������
						Pre_Root->left = NewNode;//��������� ���ʿ� ����
					else//��������� key������ Ŭ��
						Pre_Root->right = NewNode;//��������� �����ʿ� ����
			
					break;
				}
		
				compare = strcmp(NewNode->key, Root->key);//������ ����� key�� ��
				if(compare < 0)//�� ����� key���� ����� key������ ������ 
				{
					Pre_Root = Root;//������� �̵�
					Root = Root->left;//��� �������� �̵�
				}
				else if(compare > 0)//�� ����� key���� ����� key������ Ŭ�� 
				{
					Pre_Root = Root;//������� �̵�
					Root = Root->right;//��� ���������� �̵�
				}
				else//�� ����� key���� �̹� �����ҋ�
				{
					Root->data = (char*)realloc(Root->data, sizeof(char)*data_size+1);//������� data���̸�ŭ �絿���Ҵ�
					strcpy(Root->data, NewNode->data);//������� data�� ��忡 ����
					Root->data[data_size] = '\0';
					free(NewNode);//����� �����Ҵ� ����
					break;
				}
			}
		}
	}

	fclose(kvkey);//������ ���� �ݱ� 
	fclose(kvdata);
	fclose(kvsize);
 	return 0;
}

// kv store�� close�Ѵ�. 
int kvclose()
{
	FILE* kvkey = fopen("kvkey.txt","w+");//������� txt���� ���� 
	FILE* kvdata = fopen("kvdata.txt","w+");
	FILE* kvsize = fopen("kvsize.txt","w+");
	int i;//for���� ���� ���� 

	if((kvkey==NULL) || (kvdata==NULL))//������ ������ ������ ���� 
		return 1;

	for(i = 1 ; i < 256 ; i++)//�ؽ����̺� ��ȸ 
	{
		Print_Node(kvkey, kvdata, kvsize, Htable.Table[i]);//�ؽ� ���̺���� ����Ʈ���� ��ȸ�Ͽ� ���Ͽ� ��� 
	}

	fclose(kvkey);//���� �ݱ� 
	fclose(kvdata);
	fclose(kvsize);
 	return 0;
}

void  Print_Node(FILE* kvkey, FILE* kvdata, FILE* kvsize, pNode Root)//����Ʈ���� ��ȸ�Ͽ� ���Ͽ� ��� 
{
	int key_size, data_size;//������ ���̸� ���� ���� 

	if(Root!=NULL)
	{
		key_size = strlen(Root->key);//key�� ���� ���� 
		data_size = strlen(Root->data);//data�� ���� ���� 
    	fprintf(kvsize,"%d %d\n", key_size, data_size);//kvsize�� key�� data���� ���� 
		fprintf(kvkey, "%s\n", Root->key);//kvstore�� key�� data���� 
		fprintf(kvdata, "%s\n", Root->data);
		Print_Node(kvkey, kvdata, kvsize, Root->left);//���� ���� ������ ����� �ö���鼭 ������ ��� ��� 
    	Print_Node(kvkey, kvdata, kvsize, Root->right); 
 	}
}
