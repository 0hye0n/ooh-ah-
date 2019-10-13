#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kvlib.h"

HashTable Htable = {NULL};//해시테이블을 전역으로 선언
// 각 모든 함수는 성공시 0, 실패시 각자 정의한 에러코드를 리턴한다.
 
// 주어진 key를 이용하여 data를 찾고, buf에 저장하여 리턴시켜 준다.
int kvget(char *key, char *buf)
{
	pNode cur;//이동하며 값을 비교할 구조체 포인터 
	int tablekey = key[0];//tablekey를 위한 변수 
	int compare;//비교값 저장을 위한 변수

	cur = Htable.Table[tablekey];//cur에 table[tablekey] 주소 입력 
		
	while(cur)//cur가 NULL이될때까지 반복 
	{
		compare = strcmp(key, cur->key);//key와 노드의 key 비교
		
		if(compare < 0)//노드의 key값이 root노드의 key값보다 작을때 
		{
			cur = cur->left;//왼쪽노드로 이동
		}
		else if(compare > 0)//노드의 key값이 root노드의 key값보다 클때 
		{
			cur = cur->right;//오른쪽 노드로 이동
		}
		else//값이 같을때
		{
			strcpy(buf, cur->data);//노드의 data를 buf에 복사
			return 0;
		}
	}

	if(cur == NULL)//찾으려는 값이 없을때
	{
		strset(buf,'\0');//버퍼 초기화
 		return 1;
 	}
}

// 주어진 key와 data를 이용하여 kv store에 저장한다. 
// 이미 key가 존재하는 경우 덮어쓴다. 
int kvput(char *key, char *data)
{
	int TableKey = key[0];//tablekey값 연산 
	pNode NewNode = (pNode)malloc(sizeof(Node));//새로운 값을 넣을 구조체 동적할당
	int compare;//key값 비교결과 저장변수
	pNode Pre_Root, Root;//삽입을 위한 노드 포인터
	int key_size = strlen(key);//key의 길이저장 
	int data_size = strlen(data);//data의 길이저장 

	NewNode->key = (char*)malloc(sizeof(char)*key_size+1);//노드의 key에 key+1 크기만큼 동적할당
	NewNode->data = (char*)malloc(sizeof(char)*data_size+1);//노드의 data에 data+1 크기만큼 동적할당
	
	strcpy(NewNode->key, key);//key값 복사
	strcpy(NewNode->data, data);//data값 복사
	NewNode->key[key_size] = '\0';//문자열의 마지막에 널문자 추가
	NewNode->data[data_size] = '\0';//문자열의 마지막에 널문자 추가
	NewNode->left = NULL;//좌우 노드포인터 초기화
	NewNode->right = NULL;
	
	if(Htable.Table[TableKey] == NULL)//table에 값이 하나도없을때 
	{
		Htable.Table[TableKey] = NewNode;//table에 새로운 구조체 연결 
		return 0;
	}
	else//table에 값이 존재할떄 
	{
		Root = Htable.Table[TableKey];//이진트리 시작위치 지정
		
		while(1)
		{
			if(Root == NULL)//노드가 없을떄
			{ 
				if(compare < 0)//이전노드의 key값보다 작을떄
					Pre_Root->left = NewNode;//이전노드의 왼쪽에 연결
				else//이전노드의 key값보다 클떄
					Pre_Root->right = NewNode;//이전노드의 오른쪽에 연결
			
				return 0;
			}
		
			compare = strcmp(NewNode->key, Root->key);//새노드와 노드의 key값 비교
			if(compare < 0)//새 노드의 key값이 노드의 key값보다 작을때 
			{
				Pre_Root = Root;//이전노드 이동
				Root = Root->left;//노드 왼쪽으로 이동
			}
			else if(compare > 0)//새 노드의 key값이 노드의 key값보다 클때 
			{
				Pre_Root = Root;//이전노드 이동
				Root = Root->right;//노드 오른쪽으로 이동
			}
			else//새 노드의 key값이 이미 존재할떄
			{
				Root->data = (char*)realloc(Root->data, sizeof(char)*data_size+1);//새노드의 data+1 길이만큼 재동적할당
				strcpy(Root->data, NewNode->data);//새노드의 data를 노드에 복사
				Root->data[data_size] = '\0';//문자열의 마지막에 널문자 추가 
				free(NewNode);//새노드 동적할당 해제
				return 0;
			}
		}
	}
	
	return 1;
}

// 주어진 key를 이용하여 key와 data를 삭제한다. 
int kvdel(char *key)
{
 	pNode parent, node, root;//삭제노드와 삭제노드의 부모노드의 주소를 받을 포인터 
	pNode succ, succ_parent, child; //삭제때 위치를 받을 포인터 
	int compare, tablekey = key[0];//key비교값 저장을 위한 변수와 table번호
	parent = NULL;//노드추기화
	root = Htable.Table[tablekey];//이진트리 시작위치
	node = root;//삭제할 노드를 가리킬 포인터
	

	while(node != NULL)//Target값을 가진 Node를 찾는다 
	{//삭제노드가 NULL이거나 삭제노드 값이 Target값과 같으면 while문 종료 
    	compare = strcmp(key,node->key);//key값 비교
    	
		if(compare == 0)//키값이 같을때 현제노드가 삭제노드
    		break;
    	
    	parent = node;//부모 노드는 현제 비교노드 
    	
    	if(compare < 0)//삭제 노드의 값이 target값보다 클때 
			node = node->left; //삭제노드는 왼쪽 자식 노드가 된다 
    	else node = node->right; //삭제노드는 오른쪽 자식 노드가 된다 
	} 
	
	if(node == NULL) //삭제노드 값이 NULL이면 Target값과 일치한 노드가 없으므로 종료 
	{ 
    	return 1; 
	} 
   
	if((node->left == NULL) && (node->right == NULL)) //삭제노드의 자식노드가 하나도 없을때 
	{ 
    	if(parent != NULL) //삭제노드의 부모노드가 NULL이 아닐때(삭제노드가 root노드가 아닐때) 
    	{ 
        	if(parent->left == node) //삭제노드가 부모노드의 왼쪽 자식일때 
        		parent->left = NULL;//부모노드의 왼쪽주소 NULL 
        	else
				parent->right = NULL;//부모노드의 오른쪽주소 NULL 
    	} 
    	else//삭제노드가 root노드일떄 
			Htable.Table[tablekey] = NULL;
	} 
	else if((node->left == NULL) || (node->right == NULL))//삭제노드의 자식노드가 1개일때 
	{ 
    	if(node->left != NULL)//삭제노드의 왼쪽 자식이 있을떄 
			child = node->left; 
    	else//삭제노드의 오른쪽 자식이 있을떄 
			child = node->right; 
    	if(parent != NULL)//삭제노드의 부모노드가 NULL이 아닐때(삭제노드가 root노드가 아닐때) 
    	{ 
        	if(parent->left == node)//삭제노드가 부모노드의 왼쪽 자식일때 
        		parent->left = child;//자식노드를 부모노드의 왼쪽으로 붙인다 
        	else//삭제노드가 부모노드의 오른쪽 자식일때 
				parent->right = child;//자식노드를 부모노드의 오른쪽으로 붙인다  
    	} 
    	else//삭제노드가 root노드일때 
			Htable.Table[tablekey] = child;//자식노드가 root노드가 된다. 
	} 
	else//삭제노드의 자식이 2개일때 
	{ 
    	succ_parent = node;//대체부모노드는 삭제노드 
    	succ = node->left; //대체노드는 삭제노드의 left 
    	
		while(succ->right != NULL) //삭제노드값의 바로 아래값을 찾는다. 
    	{ //대체노드의 right이 존재할때 
        	succ_parent = succ; //대체부모노드는 대체노드 
        	succ = succ->right; //대체노드는 대체노드의 right 
    	}
    	

    	if(root == node)//삭제노드가 이진트리의 루트노드일떄
    	{
    		if(succ_parent == root)//대체부모노드가 루트노드일떄 
    		{
                Htable.Table[tablekey] = succ;//대체노드는 이진트리 시작노드
    			succ->right = node->right;//대체노드의 오른쪽에 삭제노드의 오른쪽 연결	
            }
            else
            { 
    		    Htable.Table[tablekey] = succ;//대체노드는 이진트리 시작노드
    		    succ_parent->right = succ->left;//대체부모노드의 right는 대체노드의 rigit 
                succ->left = node->left;//대체노드의 왼쪽에 삭제노드의 왼쪽 연결
                succ->right = node->right;//대체노드의 오른쪽에 삭제노드의 오른쪽 연결
            }
		}
		else//삭제노드가 이진트리의 루트노드가 아닐때
		{
			if(succ==node->left)//대체노드가 삭제노드의 왼쪽자식일떄
			{
                succ->right = node->right;//대체노드의 오른쪽에 삭제노드의 오른쪽 연결
                if(parent->left == node)//삭제노드가 그 부모노드의 왼쪽자식일때
                    parent->left = succ;//대체노드를 왼쪽에 연결
                else//오른쪽 자식일떄
                    parent->right = succ;//대체노드를 오른쪽에 연결
            }
            else//대체노드가 삭제노드때의 왼쪽자식이 아닐때
            {
                succ_parent->right = succ->left;//대체노드의 왼쪽자식을 대체부모노드에 연결 
			    succ->left = node->left;//삭제노드의 왼쪽자식를 대체노드에 연결
    		    succ->right = node->right;//삭제노드의 오른쪽자식을 대체노드에 연결
    		    if(parent->left == node)//삭제노드가 그 부모노드의 왼쪽자식일때
                    parent->left = succ;//대체노드를 왼쪽에 연결
                else//오른쪽 자식일떄
                    parent->right = succ;//대체노드를 오른쪽에 연결
            }
		}

	} 
	
	free(node); //삭제노드의 동적할당을 해제한다 
	return 0;
}

// kv store를 open하여 기존의 key-data를 불러온다.
// 기존의 key-data가 없다면 생성한다. 
int kvopen()
{
	int key_size, data_size;//size를 받을 변수 
	FILE* kvkey = fopen("kvkey.txt","a+");//읽기 모드로 파일오픈
	FILE* kvdata = fopen("kvdata.txt","a+");
	FILE* kvsize = fopen("kvsize.txt","a+"); 
	int TableKey;//tablekey값 연산 
	pNode NewNode;//새로운 값을 넣을 노드
	int compare;//key값 비교결과 저장변수
	pNode Pre_Root, Root;//삽입을 위한 노드 포인터
	char key[4096];//key를 받을 변수 
	strset(key,'\0');//key초기화 
	
	while(fscanf(kvkey,"%s",key) != -1)//key값이 NULL이 아닐때 
	{	
		fscanf(kvsize,"%d %d", &key_size, &data_size);//kvsize에서 데이터 사이즈받기		
		NewNode = (pNode)malloc(sizeof(Node));//새로운 값을 넣을 구조체 동적할당
		NewNode->key = (char*)malloc(sizeof(char)*key_size+1);//노드의 key에 key크기만큼 동적할당
		NewNode->data = (char*)malloc(sizeof(char)*data_size+1);//노드의 data에 data크기만큼 동적할당
		strcpy(NewNode->key,key);//동적할당된 노드에 key 넣기 
		fscanf(kvdata,"%s", NewNode->data);//동적할당된 노드에 data 넣기 
		NewNode->key[key_size] = '\0';//문자열의 마지막에 널문자 추가 
		NewNode->data[data_size] = '\0';
		TableKey = NewNode->key[0];//해쉬테이블의 키 = key의 첫단어 
		NewNode->left = NULL;//좌우 노드포인터 초기화
		NewNode->right = NULL;
	
		if(Htable.Table[TableKey] == NULL)//table에 값이 하나도없을때 
		{
			Htable.Table[TableKey] = NewNode;//table에 새로운 구조체 연결 
		}
		else//table에 값이 존재할떄 
		{
			Root = Htable.Table[TableKey];//이진트리 시작위치 지정
		
			while(1)
			{
				if(Root == NULL)//노드가 없을떄
				{ 
					if(compare < 0)//이전노드의 key값보다 작을떄
						Pre_Root->left = NewNode;//이전노드의 왼쪽에 연결
					else//이전노드의 key값보다 클떄
						Pre_Root->right = NewNode;//이전노드의 오른쪽에 연결
			
					break;
				}
		
				compare = strcmp(NewNode->key, Root->key);//새노드와 노드의 key값 비교
				if(compare < 0)//새 노드의 key값이 노드의 key값보다 작을때 
				{
					Pre_Root = Root;//이전노드 이동
					Root = Root->left;//노드 왼쪽으로 이동
				}
				else if(compare > 0)//새 노드의 key값이 노드의 key값보다 클때 
				{
					Pre_Root = Root;//이전노드 이동
					Root = Root->right;//노드 오른쪽으로 이동
				}
				else//새 노드의 key값이 이미 존재할떄
				{
					Root->data = (char*)realloc(Root->data, sizeof(char)*data_size+1);//새노드의 data길이만큼 재동적할당
					strcpy(Root->data, NewNode->data);//새노드의 data를 노드에 복사
					Root->data[data_size] = '\0';
					free(NewNode);//새노드 동적할당 해제
					break;
				}
			}
		}
	}

	fclose(kvkey);//열었던 파일 닫기 
	fclose(kvdata);
	fclose(kvsize);
 	return 0;
}

// kv store를 close한다. 
int kvclose()
{
	FILE* kvkey = fopen("kvkey.txt","w+");//쓰기모드로 txt파일 열기 
	FILE* kvdata = fopen("kvdata.txt","w+");
	FILE* kvsize = fopen("kvsize.txt","w+");
	int i;//for문을 위한 변수 

	if((kvkey==NULL) || (kvdata==NULL))//파일이 열리지 않으면 종료 
		return 1;

	for(i = 1 ; i < 256 ; i++)//해쉬테이블 순회 
	{
		Print_Node(kvkey, kvdata, kvsize, Htable.Table[i]);//해쉬 테이블안의 이진트리를 순회하여 파일에 출력 
	}

	fclose(kvkey);//파일 닫기 
	fclose(kvdata);
	fclose(kvsize);
 	return 0;
}

void  Print_Node(FILE* kvkey, FILE* kvdata, FILE* kvsize, pNode Root)//이진트리를 순회하여 파일에 출력 
{
	int key_size, data_size;//데이터 길이를 받을 변수 

	if(Root!=NULL)
	{
		key_size = strlen(Root->key);//key의 길이 저장 
		data_size = strlen(Root->data);//data의 길이 저장 
    	fprintf(kvsize,"%d %d\n", key_size, data_size);//kvsize에 key와 data길이 저장 
		fprintf(kvkey, "%s\n", Root->key);//kvstore에 key와 data저장 
		fprintf(kvdata, "%s\n", Root->data);
		Print_Node(kvkey, kvdata, kvsize, Root->left);//제일 왼쪽 노드부터 출력후 올라오면서 오른쪽 노드 출력 
    	Print_Node(kvkey, kvdata, kvsize, Root->right); 
 	}
}
