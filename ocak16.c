#include <stdio.h>
#include <stdlib.h>

void ikiBoyutluDiziyiYazdir(int **dizi, int satir, int sutun);
void rastgeleGemiOlustur(int **dizi, int satir, int sutun);
int main() {
	
	
	
	srand(time(0));
	int satirSayisi, sutunSayisi;
	
	printf("Amiral batti oyunu icin 2 boyutlu alan buyuklugu tanimlayin (ornek: 10 14 yazdiginizda 10x14'luk bir alan olustursun.)");
	scanf("%d%d",&satirSayisi, &sutunSayisi);
	int i;
	int **oyunAlani;
	oyunAlani = (int **)calloc(satirSayisi, sizeof(int*));
	for(i=0; i<satirSayisi; i++){
		oyunAlani[i] = (int*)calloc(sutunSayisi, sizeof(int));
	}
	
	ikiBoyutluDiziyiYazdir(oyunAlani, satirSayisi, sutunSayisi);
	
	
	return 0;
}


void rastgeleGemiOlustur(int **dizi, int satir, int sutun){
	do {
		int gemi_satir_indexi = rand()%(satir - 1) + 1;
		int gemi_sutun_indexi = rand()%(sutun - 2) +1;
		
		if(dizi[gemi_satir_indexi][gemi_sutun_indexi] == 0 &&
		dizi[gemi_satir_indexi - 1][gemi_sutun_indexi]== 0 &&
		dizi[gemi_satir_indexi][gemi_sutun_indexi - 1] == 0 &&
		dizi[gemi_satir_indexi][gemi_sutun_indexi + 1] == 0){
			
			dizi[gemi_satir_indexi][gemi_sutun_indexi] = 1;
			dizi[gemi_satir_indexi - 1][gemi_sutun_indexi] = 1;
			dizi[gemi_satir_indexi][gemi_sutun_indexi - 1] = 1;
			dizi[gemi_satir_indexi][gemi_sutun_indexi + 1] = 1;
			break;
			
		}
	}while(1);
}



void ikiBoyutluDiziyiYazdir(int **dizi, int satir, int sutun){
	int i,j;
	for(i=0; i<satir;i++){
		for(j=0; j<sutun;j++){
			printf("%d",dizi[i][j]);
		}
		printf("\n");
	}
	printf("**********\n");
}
