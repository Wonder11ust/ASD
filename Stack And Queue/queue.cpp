#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct{
    int data[MAX];
    int head;
    int tail;

}queue;

queue antri;

int isFull()
{
    if(antri.tail == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if(antri.tail == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void awal()
{
    antri.head = antri.tail = -1;
}

void enqueue(int data)
{
    if(isEmpty()==1)
    {
        antri.head = antri.tail = 0;
        antri.data[antri.tail] = data;
        printf("%d Masuk\n\n", antri.data[antri.tail]);
    }
    else if(isFull()==0)
    {
        antri.tail++;
        antri.data[antri.tail] = data;
        printf("%d Masuk\n\n", antri.data[antri.tail]);
    }
}
int dequeue()
{
    int d = antri.data[antri.head];
    for(int i = antri.head;i<=antri.tail-1;i++)
    {
        antri.data[i] = antri.data[i+1];
    }
    antri.tail--;
    return d;
}
void tampil()
{
    if(isEmpty()==0)
    {
        for(int i = antri.head;i<=antri.tail;i++)
        {
            printf("%d\t", antri.data[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Antrian Kosong!\n");
    }
}
void hapus()
{
    antri.head = antri.tail = -1;
    printf("Data dalam antrian telah dibuang!\n");
}
int main()
{
    int pilihan,data;
    awal();
    do
    {
    printf("1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Lihat isi Antrian");
    printf("\n4. Hapus isi Antrian");
    printf("\n5. Keluar");
    printf("\nPilihan Anda : ");
    scanf("%d", &pilihan);
    switch(pilihan)
    {
        case 1:
        printf("Data = ");scanf("%d", &data);
        enqueue(data);
        break;

        case 2:
        printf("Data yang keluar : %d\n", dequeue());
        break;

        case 3:
        tampil();
        break;

        case 4:
        hapus();
        break;

        case 5:
        exit(0);
        break;

        default:
        printf("Pilih yang bener bang!\n");
        break;
    }
    }
    while(pilihan != 5);

}
