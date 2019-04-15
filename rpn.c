#include<stdio.h>
#include <stdlib.h>
#define DIGIT 4
void generate_rpn(int num, int exp){
  static char rpn[2*DIGIT];
  int index=exp+num;
  if(index==2*DIGIT-1){
    rpn[index]='\0';
    printf("%s\n",rpn);
  }else if(num-exp>=2){
    if(num!=4){
      rpn[index]='0';
      generate_rpn(num+1,exp);
    }
    rpn[index]='*';
    generate_rpn(num,exp+1);
    rpn[index]='/';
    generate_rpn(num,exp+1);
    rpn[index]='+';
    generate_rpn(num,exp+1);
    rpn[index]='-';
    generate_rpn(num,exp+1);
  }else{
    rpn[index]='0';
    generate_rpn(num+1,exp);
  }
}
int main(int argc, char *argv[]){
  generate_rpn(0,0);
  return EXIT_SUCCESS;
}
