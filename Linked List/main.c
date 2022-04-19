#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<conio.h>
#include<string.h>



struct mahasiswa{
    char nama [30], nim [10], fakultas [30], jurusan [30];
    float ipk;
    struct mahasiswa *next;
}*head = NULL, *tail, *current;
//head => pointer yang menyimpan alamat data pertama
//tail => pointer yang menyimpan alamat data terakhir
//current => pointer yang digunakan sebagai temporary variabel

void LihatData(){
    if(head == NULL){
        printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        current = head;
        int i = 1;
        while(current != NULL){
            printf("Data ke - %i\n", i);
            printf("Nama     : %s\n", current->nama);
            printf("NIM      : %s\n", current->nim);
            printf("Fakultas : %s\n", current->fakultas);
            printf("Jurusan  : %s\n", current->jurusan);
            printf("IPK     : %f\n", current->ipk);
            current = current->next;
            printf("\n");
            i++;
        }
        i = 1;
    }
    printf("\n");
}

struct mahasiswa *addData(char nama [], char nim [],char fakultas [],char jurusan [],float ipk){
    struct mahasiswa *newData = (struct mahasiswa*) malloc(sizeof(struct mahasiswa));
    strcpy(newData->nama, nama);
    strcpy(newData->nim, nim);
    strcpy(newData->fakultas, fakultas);
    strcpy(newData->jurusan, jurusan);
    newData->ipk = ipk;
    newData->next = NULL;
    return newData;
}

void TambahData(){
    char nama [30], nim [10], fakultas [30], jurusan [30];
    float ipk;
    
	printf("NIM      : ");fflush(stdin);gets(nim);
    printf("Nama     : ");fflush(stdin);gets(nama);
    printf("Fakultas : ");fflush(stdin);gets(fakultas);
    printf("Jurusan  : ");fflush(stdin);gets(jurusan);
    printf("IPK     : ");scanf("%f", &ipk);

    struct mahasiswa *curr = head;
    if(head == NULL){
        struct mahasiswa *temp1 = addData(nama, nim, fakultas, jurusan,ipk);
        head = temp1;
    }
    else{
        while (curr){
            if (strcmp(nim, curr->nim)==0){
                printf("data sama\n");
                return;
            }
            else if (curr->next == NULL){
                struct mahasiswa *temp1 = addData(nama, nim, fakultas, jurusan,ipk);
                curr->next = temp1;
                break;
            }
            curr = curr->next;
        }
    }
	printf("\nData berhasil diinput");
	count++;
}

void editData(){
    if(head==NULL){
        printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        current = head;

        char nim [10];
        printf("Cari NIM yang mau diedit : ");scanf("%s", &nim);

        while (current != NULL) {
            if (strcmp(current->nim, nim)==0){
                printf("Nama     : %s\n", current->nama);
                printf("NIM      : %s\n", current->nim);
                printf("Fakultas : %s\n", current->fakultas);
                printf("Jurusan     : %s\n", current->jurusan);
                printf("IPK     : %f\n\n", current->ipk);

                printf("EDIT DATA\n");
                char jurusanBaru[30];
                printf("Jurusan baru : ");fflush(stdin);gets(jurusanBaru);
                strcpy(current->jurusan, jurusanBaru);

                printf("\nData berhasil diedit");
                break;
            }else if(current == NULL || current->next==NULL){
                printf("\nData tidak ada");
            }
            current = current->next;
         
        }
    }
}

void deleteData(){
	int i;
    if (head == NULL){
        printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        struct mahasiswa *temp = head;
        current = head;

        char nim [10];
        printf("Cari NIM yang mau dihapus : ");scanf("%s", &nim);

        //cari posisi index data yang mau dihapus
        int index = 0;
        while (current != NULL) {
            if (strcmp(current->nim, nim)==0){
                break;
            }
            index++;
            current = current->next;
        }


        if (index == 0){
            head = temp->next;
            free(temp);
            printf("\nData berhasil dihapus");
        }else{

            //nyari dan mindahin posisi temp ke data yang mau dicari
            for (i=0; temp!=NULL && i<index-1; i++){
                temp = temp->next;
            }

            if (temp == NULL || temp->next == NULL){
                printf("\nData tidak ada");
            }else{
                struct mahasiswa *next = temp->next->next;

                free(temp->next);
                temp->next = next;
                printf("\nData berhasil dihapus");
            }
        }
    }
}

void cariData()
{
	    if(head==NULL){
        printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        current = head;

        char nim [10];
        printf("Masukkan NIM yang mau dicari : ");scanf("%s", &nim);

        while (current != NULL) {
            if (strcmp(current->nim, nim)==0){
                printf("Nama     : %s\n", current->nama);
                printf("NIM      : %s\n", current->nim);
                printf("Fakultas : %s\n", current->fakultas);
                printf("Jurusan     : %s\n", current->jurusan);
                printf("IPK     : %f\n\n", current->ipk);

               
                break;
            }else if(current == NULL || current->next==NULL){
                printf("\nData tidak ada");
            }
            current = current->next;
        }
    }
}

void sortingData()
{
    struct mahasiswa  *curr = head;
    struct mahasiswa *index = NULL;
    struct mahasiswa *tmp = current;
    float temp;

    if (head==NULL){
        printf("data tidak tersedia");

    }
    else {
        while (curr!= NULL){
            index = current ->next;
        
            while (index!=NULL){
                if (curr->ipk > index->ipk){
                    temp = tmp;
                    tmp = index;
                    index = temp;
                }
                index = index->next;
            }
            curr= curr->next;
        }
    }
}

int main()
{
    //LINKED LIST => tipe data yang dapat menampung banyak data

    /*
    int angka[5] => [0][1][2][][] => 5X

    linked list => add 1 data => [] => 1X
    linked list => add 1 data => [][] => 2X
    linked list => add 1 data => [][][] => 3x
    */

    char menu;
    do{
        printf("MENU KAMPUS\n");
               printf("count:%d\n",count);
        printf("1. Lihat Data\n");
        printf("2. Tambah Data\n");
        printf("3. Edit Data\n");
        printf("4. Hapus Data\n");
        printf("5. Keluar\n");
        printf("6.Cari Data\n");
        printf("7.Sorting Data\n");
        printf("Pilihan : \n");scanf(" %c", &menu);
 
        switch(menu){
            case '1' : LihatData();break;
            case '2' : TambahData();break;
            case '3' : editData();break;
            case '4' : deleteData();break;
            case '5' : break;
            case '6' : cariData(); break;
            case '7' : sortingData();break;
            default : printf("Inputan Salah\n\n");break;
        }
        getch();
        system("cls");
    }while(menu != '5');

    return 0;
}
