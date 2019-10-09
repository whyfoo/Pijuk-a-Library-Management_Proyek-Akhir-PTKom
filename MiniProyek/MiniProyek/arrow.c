#include <stdio.h> 											//header i/o
#include <windows.h> 

void arrow(int urutan,int posisi);


int main(){
	int i,j;
	int key=0;
	int posisi=1;


while(key!=13){
system("cls");
printf("\033[1;33m");
printf("BELI TIKET\n\n");
printf("\033[0m");
fflush(stdin);
arrow(1,posisi);printf("1. Daftar Kontak\n");
arrow(2,posisi);printf("2. Tambah Kontak\n");
arrow(3,posisi);printf("3. Hapus Kontak\n");
arrow(4,posisi);printf("4. Pencarian\n");
arrow(5,posisi);printf("5. Hapus Semua\n");
arrow(6,posisi);printf("6. Tolongan\n");
arrow(7,posisi);printf("7. Exit\n");

key=getch();
  if(key == 80 && posisi != 7){
    posisi++;
  }
else if(key == 72 && posisi !=1){
  posisi--;
}
else if(key ==72 && posisi ==1){
  posisi =4;
}
else if(key ==80 && posisi ==7){
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


