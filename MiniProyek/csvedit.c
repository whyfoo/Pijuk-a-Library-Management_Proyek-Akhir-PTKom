#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  FILE *a;
  a = fopen("countries.csv", "r");
  char buf[1000];
  char *temp;
  char *name[2000][30];
  int num[2000];
  char *group[2000];
  int i = 0;

  while (fgets(buf, 1000, a)) {
    temp = strtok(buf, ",");
    num[i] = atoi(strtok(NULL, ","));
    group[i] = atoi(strtok(NULL, ","));
    strcpy(name[i], temp);
    i++;
  }
  printf("%d\n", i);
  for (i = 0; i <= 3; i++) {
    printf("%d %s %d %s \n", i, name[i], num[i], group[i]);
  }
  fclose(a);
  return 0;
}
// r = read
// w = write
// a = append
//fprintf(fpointer, "This; test");
