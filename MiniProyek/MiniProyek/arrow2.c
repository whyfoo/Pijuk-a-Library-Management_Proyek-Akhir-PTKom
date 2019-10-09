#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void arrow(int urutan,int posisi);
int duduk[10][10]= {{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};

int main(){
 int i,j;
  int key=0;
  int posisi=1;
  system("COLOR 70");


while(key!=13){
system("cls");
 printf("\033[1;33m");
printf("BELI TIKET\n\n");
printf("\033[0m");
fflush(stdin);
arrow(1,posisi);printf("1. Beli Tiket\n");
arrow(2,posisi);printf("2. Beli Tiket\n");
arrow(3,posisi);printf("3. Beli Tiket\n");
arrow(4,posisi);printf("4. Beli Tiket\n");

key=getch();
  if(key == 80 && posisi != 4){
    posisi++;
  }
else if(key == 72 && posisi !=1){
  posisi--;
}
else if(key ==72 && posisi ==1){
  posisi =4;
}
else if(key ==80 && posisi ==4){
  posisi =1;
}

else{
  posisi=posisi;}}
if(posisi==1){
  system("cls");
    printf("Anda Akan Membeli TIket");
}
if(posisi==2){
  system("cls");
  printf("Anda Melihat Resensi Film...");
}
if(posisi==3){
  system("cls");
  printf("Anda Melihat Coming Soon...");
}
if(posisi==4){
  system("cls");
  printf("Anda Melihat Now Playing...");}}


void arrow(int urutan,int posisi){

 if(urutan==posisi){
  printf("\033[1;34m");

  }
    else{
       printf("\033[0m");
  }

}
