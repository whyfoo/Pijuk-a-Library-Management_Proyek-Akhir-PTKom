//=====================================================================================// includes
#include <stdio.h> 											//header i/o
#include <windows.h>
#include <string.h> 										//header system(cls), getch(), etc

//=====================================================================================// prototype setiap fungsi
void header();
void header_help();
void header_menu();
void add_contact();
void search_contact();
void delete_contact();
void delete_all();
void view_all_contact();
void help();
void help_add_contact();
void help_search_contact();
void help_delete_contact();
void help_delete_all();
void help_view_all_contact();
void printd(char* x, int y);
void arrow(int urutan,int posisi);
//=====================================================================================// main
int main()
{
	system("COLOR 5E");
	Sleep(50);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                         ");
	printd("MyCon Phonebook Initializing...",30);
	Sleep(900);
	menu();
	
}

//=====================================================================================// void header
void header()
{
	printf("\t\t\t\n");
    printf("\t\t\t                                                            \n");
    printf("\t\t\t                                                            \n");
    printf("\t\t\t                	  MyCon Phonebook GG		              \n");
    printf("\t\t\t                                                            \n");
    printf("\t\t\t                                                            \n");
    printf("\t\t\t    ============================================================\n\n");
}

//=====================================================================================// void header_help
void header_menu()
{
	printf("\t\t\t\t      =================================\n");
    printf("\t\t\t\t      |           Main Menu           |\n");
    printf("\t\t\t\t      =================================\n\n");
}

//=====================================================================================// void header_help
void header_help()
{
	printf("\t\t\t\t================================\n");
    printf("\t\t\t\t|       Menu Pertolongan        |\n");
    printf("\t\t\t\t================================\n\n");
}

//=====================================================================================// menu
int menu()
{	
	int i,j;
	int key=0;
	int posisi=1;
    header();												
	while(key!=13){
	system("cls");
	header();
    printf("\n\t\t\t\t\t  ==============================\n");
    arrow(1,posisi);printf("1. Daftar Kontak\n");
	arrow(2,posisi);printf("2. Tambah Kontak\n");
	arrow(3,posisi);printf("3. Hapus Kontak\n");
	arrow(4,posisi);printf("4. Pencarian\n");
	arrow(5,posisi);printf("5. Hapus Semua\n");
	arrow(6,posisi);printf("6. Pertolongan\n");
	arrow(7,posisi);printf("7. Exit\n");
    printf("\t\t\t\t\t  ==============================\n");
    key=getch();
  if(key == 80 && posisi != 7){
    posisi++;
  }
else if(key == 72 && posisi !=1){
  posisi--;
}
else if(key ==72 && posisi ==1){
  posisi =7;
}
else if(key ==80 && posisi ==7){
  posisi =1;
}
else if(key ==27){
  exit(0);
}

else{
  posisi=posisi;}}
if(posisi==1){
  view_all_contact();
}
if(posisi==2){
  add_contact();
}
if(posisi==3){
  delete_contact();
}
if(posisi==4){
  search_contact();
  }
if(posisi==5){
  delete_all();
  }
if(posisi==6){
  help();
  }
if(posisi==7){
  exit(0);
  }    

}

//=====================================================================================// void add_contact
void add_contact()
{
    FILE *fp;												
    fp=fopen("contacts.csv","a");							
    system("cls");											
    header();												
    char name_first[100];
	char mob[100];
	char group[100];
    printf("\t\t\t\t==============================\n");		
    printf("\t\t\t\t|         Tambah Kontak        |\n");
    printf("\t\t\t\t==============================\n\n");
    printf("\t\t\t\tNama		: ");						
    scanf("%s",name_first);
    printf("\t\t\t\tMobile No.	: ");
    scanf("%s",mob);
    printf("\t\t\t\tGroup 		: ");
    scanf("%s",group);
    fprintf(fp,"%s,%s,%s,\n",name_first,mob,group); 	
    fclose(fp);
    printf("\n\n\t\t\t\tSukses Menambahkan..");
    printf("\n\n\n\n\t\t\t\t");
    system("pause");
    menu();
}

//=====================================================================================// void search_contact
void search_contact()
{
	system("cls");
    FILE *a;
    a=fopen("contacts.csv","r");
    header();
    printf("\t\t\t\t=============================\n");
    printf("\t\t\t\t|         Pencarian         |\n");
    printf("\t\t\t\t=============================\n");
	int flag=0;
  char entry[100];
  char buf[100];
  char *temp;
  char *temp1;
  char *temp2;
  char name[100][30];
  char number[100][30];
  char group[100][30];
  int i = 0; int j = 0;
  printf("\t\t\t\tMasukkan Nama : ");
  scanf("%s", entry);
  printf("\n\t\t\t\tHasil untuk %s:\n", entry);
  while (fgets(buf, 1000, a)) {
    temp= strtok(buf, ",");
    strcpy(name[i], temp);
    temp1 = strtok(NULL, ",");
    strcpy(number[i], temp1);
    temp2 = strtok(NULL, ",");
    strcpy(group[i], temp2);
    i++;
	}
	for (j = 0; j < i; j++) {
    if (strcmp(entry,name[j])==0){
    	printf("\n\t\t\t\tEntry kontak nomer %d\n",j+1);
        printf("\n\t\t\t\tName		: %s\n",name[j]);
        printf("\t\t\t\tMobile no. 	: %s\n",number[j]);
        printf("\t\t\t\tGrouping 	: %s\n",group[j]);
        flag=1;
		}
	}
	
	if (!flag){printf("\n\t\t\t\t Kontak tidak ditemukan untuk keyword %s", entry);
	}
	
	fclose(a);
    printf("\n\n\n\n\t\t\t\t\t");
    system("pause");
    menu();
}



void delete_contact()
{
	system("cls");
    FILE *a;
    FILE *b;
    a=fopen("contacts.csv","r");
    header();
    printf("\t\t\t\t=============================\n");
    printf("\t\t\t\t|         Hapus		    |\n");
    printf("\t\t\t\t=============================\n");
	int flag=0;
	int tbd;
	int count=0;
  char entry[100];
  char buf[100];
  char *temp;
  char *temp1;
  char *temp2;
  char name[100][30];
  char number[100][30];
  char group[100][30];
  int i = 0; int j = 0;
  printf("\t\t\t\tMasukkan Nama : ");
  scanf("%s", entry);
  printf("\n\t\t\t\tHasil untuk %s:\n", entry);
  while (fgets(buf, 1000, a)) {
    temp= strtok(buf, ",");
    strcpy(name[i], temp);
    temp1 = strtok(NULL, ",");
    strcpy(number[i], temp1);
    temp2 = strtok(NULL, ",");
    strcpy(group[i], temp2);
    i++;
	}
	for (j = 0; j < i; j++) {
    if (strcmp(entry,name[j])==0){
    	printf("\n\t\t\t\tEntry kontak nomer %d\n",j+1);
        printf("\n\t\t\t\tName		: %s\n",name[j]);
        printf("\t\t\t\tMobile no. 	: %s\n",number[j]);
        printf("\t\t\t\tGroup	 	: %s\n",group[j]);
        flag=1;tbd=j;
		}
	}
	fclose(a);
    if (flag)
    {
	    printf("\n\t\t\t\tYakin menghapus kontak ini?[Y/N]");
	    switch(getch())
	    {
	    	case 'Y':
	    	case 'y':
	    		remove("contacts.csv");
			    b=fopen("contacts.csv","a+");
			    	for (j = 0; j < i; j++) {
			        	if (j!=tbd){
						fprintf(b,"%s,%s,%s,\n",name[j],number[j],group[j]);
			        	}
					}
			    fclose(b);
			    printf("\n\t\t\t\tDelete success!");
			    printf("\n\t\t\t\t");
    			system("pause");
    			menu();
			case 'n':
			case 'N':
				menu();
			default:
				printf("\n\t\t\t\tWrong input!");
				printf("\n\t\t\t\t");
    			system("pause");
				menu();
		}
	}
	else
    {
    	printf("\n\t\t\t\tNo data found!\n");
    	remove("temp.txt");
	}
    printf("\n\t\t\t\t");
    system("pause");
    menu();
}

//=====================================================================================// void delete_all
void delete_all()
{
	int size;
    FILE *fp;
    system("cls");
    header();
    printf("\t\t\t\t==============================\n");
    printf("\t\t\t\t|      Hapus Semua           |\n");
    printf("\t\t\t\t==============================\n\n");
   printf("\n\t\t\t\tYakin menghapus semua kontak?[Y/N]");
	switch(getch())
	    {
	    	case 'Y':
	    	case 'y':
	    		remove("contacts.csv");
			    printf("\n\t\t\t\tDelete success!");
			    printf("\n\t\t\t\t");
    			system("pause");
    			menu();
			case 'n':
			case 'N':
				menu();
			default:
				printf("\n\t\t\t\tWrong input!");
				printf("\n\t\t\t\t");
    			system("pause");
				menu();}
}

//=====================================================================================// void view_all_contact
void view_all_contact()
{
    FILE *a;
    a=fopen("contacts.csv","r");
    system("cls");
    header();
    printf("\t\t\t\t=============================\n");
    printf("\t\t\t\t|       Daftar Kontak       |\n");
    printf("\t\t\t\t=============================\n");
  char buf[100];
  char *temp;
  char *temp1;
  char *temp2;
  char name[100][30];
  char number[100][30];
  char group[100][30];
  int i = 0; int j = 0;
  
  while (fgets(buf, 1000, a)) {
    temp= strtok(buf, ",");
    strcpy(name[i], temp);
    temp1 = strtok(NULL, ",");
    strcpy(number[i], temp1);
    temp2 = strtok(NULL, ",");
    strcpy(group[i], temp2);
    i++;
	}
  for (j = 0; j < i; j++) {
    printf("\n\t\t\t\t\%d.",j+1);
        printf("\n\t\t\t\tName		: %s\n",name[j]);
        printf("\t\t\t\tMobile no. 	: %s\n",number[j]);
        printf("\t\t\t\tGroup		: %s\n",group[j]);
	}
	
	fclose(a);
    printf("\n\n\t\t\t\t\t");
    system("pause");
    menu();
}

//=====================================================================================// void help
void help()
{
	int i,j;
	int key=0;
	int posisi=1;
    header();	
	system("cls");
	header();
	header_help();
    printf("\t\t\t\t");
    printd("Ada yang bisa dibantu ?",20);   
											
	while(key!=13){
	system("cls");
	header();
	header_help();
    printf("\t\t\t\t");
    printf("Ada yang bisa dibantu ?");
    printf("\n\t\t\t\t\t  ==============================\n");
    arrow(1,posisi);printf("1. Daftar Kontak\n");
	arrow(2,posisi);printf("2. Tambah Kontak\n");
	arrow(3,posisi);printf("3. Hapus Kontak\n");
	arrow(4,posisi);printf("4. Pencarian\n");
	arrow(5,posisi);printf("5. Hapus Semua\n");
	arrow(6,posisi);printf("6. Kembali ke menu\n");
    printf("\t\t\t\t\t  ==============================\n");
    key=getch();
  if(key == 80 && posisi != 6){
    posisi++;
  }
else if(key == 72 && posisi !=1){
  posisi--;
}
else if(key ==72 && posisi ==1){
  posisi =6;
}
else if(key ==80 && posisi ==6){
  posisi =1;
}
else if(key ==27){
  menu();
}

else{
  posisi=posisi;}}
if(posisi==1){
  help_view_all_contact();
}
if(posisi==2){
  help_add_contact();	
}
if(posisi==3){
  help_delete_contact();
}
if(posisi==4){
  help_search_contact();
  }
if(posisi==5){
  help_delete_all();
  }
if(posisi==6){
  menu();
  }
}

void help_add_contact()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini, kamu dapat menambahkan kontak dengan menginput data .",20);
	printf("\n\t\t\t\t");
	printd("Contoh : ",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Name		: Noname00",20);
	printf("\n\t\t\t\t");
	printd("Mobile No.	: 0822020928390",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Group		: Family",20);
	Sleep(500);
	printf("\n\n\t\t\t\t");
	printd("Note : Tidak bisa menggunakan spasi.",20);
	Sleep(500);
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

void help_search_contact()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini, kamu bisa mencari kontak yang tersimpan.",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Kamu dapat mencarinya dengan mengetikkan nama.",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Contoh : ",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Masukkan Nama : Noname00",20);
	Sleep(50);
	printf("\n\n\t\t\t\t");
	printf("Hasil untuk Noname00:");
	printf("\n\n\t\t\t\t");
	printf("Nama		: Noname00");
	printf("\n\t\t\t\t");
	printf("Mobile No.	: 082201928390");
	printf("\n\t\t\t\t");
	printf("Group		: Family");
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

void help_delete_contact()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini, kamu dapat menghapus kontak dengan",20);
	printf("\n\t\t\t\t");
	printd("keyword nama",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Contoh : ",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Masukkan Nama: Noname00",20);
	Sleep(50);
	printf("\n\n\t\t\t\t");
	printf("Nama		: Noname00");
	printf("\n\t\t\t\t");
	printf("Mobile No.	: 082201928390");
	printf("\n\t\t\t\t");
	printf("Group		: Family");
	printf("\n\t\t\t\t");
	printd("Apakah kamu yakin menghapus kontak ?[Y/N]",20);
	Sleep(500);
	printf("Y");
	Sleep(200);
	printf("\n\t\t\t\t");
	printf("Hapus Kontak Berhasil!");
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

void help_view_all_contact()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini kamu dapat melihat kontak yang tersimpan.",20);
	Sleep(200);
	printf("\n\t\t\t\t");
	printd("Kontak diurutkan berdasarkan waktu input.",20);
	Sleep(500);
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

void help_delete_all()
{
	system("cls");
	header();
	header_help();
	printf("\t\t\t\t");
	printd("Melalui pilihan ini, kamu dapat menghapus semua kontak",20);
	printf("\n\t\t\t\t");
	printd("Dengan konfirmasi Ya atau Tidak.",20);
	Sleep(500);
	printf("\n\n\t\t\t\t");
    system("pause");
	help();
}

//================================================================
void printd(char* x, int y)
{
	int i;
	for(i=0;i<strlen(x);i++)
	{
		printf("%c",x[i]);
		Sleep(y);
	}
}

void arrow(int urutan,int posisi){

	if(urutan==posisi){
		printf("\t\t\t\t       -=> ");
  }
    else{
       printf("\t\t\t\t\t   ");
  }
}
