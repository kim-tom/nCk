#include<stdio.h>
#include <stdlib.h>
#define N 5
#define K 3
//written recursively
void nCk(int n, int k,int *a){
  static int b[K];
  int index=K-k, i;
  if(k==0){
    for(i=0;i<K;i++){
      printf("%d",b[i]);
      if(i<K-1) printf(",");
    }
    printf("\n");
  }else if(n==k){
    b[index]=a[0];
    nCk(n-1,k-1,a+1);
  }else{
    b[index]=a[0];
    nCk(n-1,k-1,a+1);

    nCk(n-1,k,a+1);
  }
}
//written with for loop
void nCk_loop(int *a){
  int i,j,k;
   for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
      for(k=j+1;k<N;k++){
        printf("%d,%d,%d\n",a[i],a[j],a[k] );
      }
    }
  }
}
int main(int argc, char *argv[]){
  int a[N]={0, 1, 2, 3, 4};

  printf("for loop\n");
  nCk_loop(a);
  printf("recrusively\n");
  nCk(N,K,a);
  return EXIT_SUCCESS;
}
