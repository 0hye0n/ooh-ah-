#include<bits/stdc++.h>
using namespace std;
int a, b;
int main(){
    scanf("%d %d", &a, &b);
    if(a>b)
    printf(">");
    else if(a<b)
    printf("<");
    else if(a==b)
    printf("==");
    return 0;
}