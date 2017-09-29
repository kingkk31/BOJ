#include<stdio.h>

int main(){
   double  N, B, M;
   int year=0, num=0, i;
   while(scanf("%lf %lf %lf", &N, &B, &M )!=EOF){
      while(N<=M){
         N=N+N*(B*0.01);
         year++;
      }
      printf("%d\n", year);
      year=0;
   }

   return 0;
}