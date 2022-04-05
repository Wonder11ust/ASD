#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
int top=0,maxStack= 5,i;
char dataStack[5][100];

int isEmpty(){
	if(top == 0){
		return 1;
	}else{
		return 0;
	}
}

int isFull(){
		if(top >= maxStack){
		return 1;
	}else{
		return 0;
	}
}

void displayStack(){
	if(isEmpty()){ //cek data kosong
		printf("Data kosong\n");
	}else{
		for(i = top;i>0;i--){
			printf("data = %s",dataStack[i-1]);
		}
	}
}

void pushStack(){
	char data[100];
	
	if(isFull()){
		printf("Data sudah penuh\n");
	}else{
		printf("Masukkan Data : "); scanf("	%[^\n]",&data);
		strcpy(dataStack[top],data);
		top++;
		printf("data berhasil dimasukkan");
	}
}

void popStack(){
	if(isEmpty()){
		printf("Data Kosong\n");
	}else{
		strcpy(dataStack[top-1],"");
		top--;
		printf("data berhasil dihapus");
	}
}

void peekStack(){
	int posisi,index;
	if(isEmpty()){
		printf("data kosong\n");
	}else{
		displayStack();
		printf("Masukkan Posisi Data: "); scanf("%d", &posisi);
		if(posisi > top){
			printf("Posisi melampaui data");
		}else{
			index = top;
			for(i = 0;i<posisi;i++){
				index--;
			}
			printf("Posisi ke = %d adalah %s",posisi,dataStack[index]);
		}
	}
}

void countStack(){
	printf("Jumlah data adalah sebanyak %d", top);
}

void changeStack(){
	char dataPengganti[100];
		int posisi,index;
	if(isEmpty()){
		printf("data kosong\n");
	}else{
		displayStack();
		printf("Masukkan Posisi Data: "); scanf("%d", &posisi);
		printf("Masukkan Data pengganti :"); scanf("	%[^\n]",dataPengganti);
		if(posisi > top){
			printf("Posisi melampaui data");
		}else{
			index = top;
			for(i = 0;i<posisi;i++){
				index--;
			}
			strcpy(dataStack[index],dataPengganti);
			printf("Posisi ke = %d adalah %s",posisi,dataStack[index]);
		}
	}
}

void destroyStack(){
	if(isEmpty()){
		printf("Data Stack sudah kosong\n");
	}else{
		for(i = top;i>0;i--){
			strcpy(dataStack[i-1],"");
			top--;
		}
		printf("data berhasil di reset");
	}
}

int main(){
	
	//stack
	//Stack -> tumpukan -> LIFO(last in First Out)
	//Display stack, push stack, pop stack, peekk stack,Change data stack,count stack,destroy stack
	int pilihan;
	do{

	
	printf("MENU STACK \n");
	printf("========================\n");
	printf("1.Lihat Data (Display Stack)\n");
	printf("2.Tambah Data (Push Stack)\n");
	printf("3.Hapus Data (pop Stack)\n");
	printf("4.Lihat Data berdasarkan posisi (Peek Stack)\n");
	printf("5.Ubah Data (Change Stack)\n");
	printf("6.Menghitung Data (Count Stack)\n");
	printf("7.Reset Data (Destroy Stack)\n");
	printf("8.Exit \n");
	printf("Masukkan pilihan:"); scanf("%d",&pilihan);
	switch(pilihan){
		case 1:system("cls"); displayStack(); getch();break;
		case 2:system("cls"); pushStack(); getch();break;
		case 3:system("cls"); popStack(); getch();break;
		case 4:system("cls"); peekStack(); getch();break;
		case 5:system("cls"); changeStack(); getch();break;
		case 6:system("cls"); countStack(); getch();break;
		case 7:system("cls"); destroyStack(); getch();break;
		case 8:exit(EXIT_SUCCESS);  break;
		default: printf("Pilihan salah!!\n");
	}
	
}while(pilihan!=9);
return 0;
}
