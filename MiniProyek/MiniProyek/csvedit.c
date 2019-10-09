#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  FILE *a;
  a = fopen("countries.csv", "r");
  char buf[100];
  char *temp;
  char name[100][30];
  int number[100], group[100];
  int i = 0;

  while (fgets(buf, 1000, a)) {
    temp = strtok(buf, ",");
    number[i] = strtok(NULL, ",");
    group[i] = atoi(strtok(NULL, ","));
    strcpy(name[i], temp);
    i++;
  }
  printf("%d\n", i);
  //for (i = 0; i <= 2; i++) {
  //  printf("%d %s %s %d\n", i, name[i], number[i], group[i]);
  }
  fclose(a);
  return 0;
}
// r = read
// w = write
// a = append
//fprintf(fpointer, "This; test");

