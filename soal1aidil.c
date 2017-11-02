#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main()
{
       key_t key = 1234;
        int *setok, masuk, jumlah;
        char inputan[100];
        char barang[6][100]={"M4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
        int shmid = shmget(key, 6*sizeof(int), IPC_CREAT | 0666);
        setok = (int*) shmat(shmid, NULL, 0);
        printf("BUAT PEMBELI HEHE\n\n");
        while(1) {
            printf("Mau ngapain bang?\n 1. Lihat Stok Senjata     2. Beli Senjata\n");
            printf("Inputan anda: "); scanf("%d",&masuk);
            if(masuk==1) {
                for(int i=0;i<6;i++) {
                    printf("Stok %s : %d\n",barang[i],setok[i]);
                }
            }
	}
        shmdt(setok);
        shmctl(shmid, IPC_RMID, NULL);
}
