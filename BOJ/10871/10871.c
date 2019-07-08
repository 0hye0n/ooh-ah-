#include <stdio.h>

int main(void) {
   int size; // 주어질 개수
   int standardscore; //기준점수
   int A[10030];

   scanf("%d", &size); // 주어질 개수 입력
   scanf("%d", &standardscore); // 기준점수입력

    // 배열점수입력
   for (int i = 0; i < size; i++)
   {
      scanf("%d", &A[i]);
   }
    // 기준점수보다 낮은 점수 출력
   for (int j = 0; j < size; j++)
   {
      if (standardscore > A[j])
      {
         printf("%d ", A[j]);
      }
      else {
         continue;
      }
   }
   return 0;
}