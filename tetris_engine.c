/*
 * tetris_engine.c
 *
 *  Created on: 19 Ara 2018
 *      Author: Tolga
 */

#include "stm32f4xx_hal.h"
#include "stdlib.h"
#include "tetris_engine.h"
#include "tol_tft.h"
#include "Tahoma10x11.h"
#include "Tahoma18x16.h"


tetrisTypeDef tetris_reg;

char txt[20];

void tetris_genel_ayar(void){

	tetris_reg.oyun_bitti=0;
	tetris_reg.blok_renk=1;
	tetris_reg.blok_no=0;
	tetris_reg.blok_yon=1;
	tetris_reg.blok_no_sonraki=1;
	tetris_reg.blok_renk_sonraki=2;
	tetris_reg.blok_yon_sonraki=2;
	tetris_reg.oyun_hiz=300;
	tetris_reg.oyun_seviye=1;
	tetris_reg.hiz_sayici=0;
	tetris_reg.blok_adet=1;
	tetris_reg.puan=0;
	tetris_reg.bos_kutu_renk=0b1111011111011110;
	tetris_reg.kutu_piksel=15;
	tetris_reg.kutu_satir=10;
	tetris_reg.kutu_sutun=20;
	tetris_reg.satir_sayici=0;
	tetris_reg.sutun_sayici=0;

	tetris_blok_yap(tetris_reg.blok_no,tetris_reg.blok_yon,tetris_reg.blok_renk,0);
	tetris_blok_yap(tetris_reg.blok_no_sonraki,tetris_reg.blok_yon_sonraki,tetris_reg.blok_renk_sonraki,1);
	tetris_ilk_blok_dose();
}

void tetris_harita_dose(void){

	uint16_t x=10,y=10,say=0,renk=0;	// x ve y ekran kullanım şekline göre değişebilir

		for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
			if(tetris_reg.tetris_harita[i]==0){
				tft_ili9325_dolukare(x,x+tetris_reg.kutu_piksel,y,y+tetris_reg.kutu_piksel,tetris_reg.bos_kutu_renk);
				tft_ili9325_boskare(x,x+tetris_reg.kutu_piksel,y,y+tetris_reg.kutu_piksel,1,renk_siyah);
				tft_ili9325_boskare(x+(tetris_reg.kutu_piksel/5),x+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/5),y+(tetris_reg.kutu_piksel/5),y+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/5),1,renk_siyah);
			}else{
				if(tetris_reg.tetris_harita[i]==1 || tetris_reg.tetris_harita[i]==11) renk=renk_mavi;
				if(tetris_reg.tetris_harita[i]==2 || tetris_reg.tetris_harita[i]==12) renk=renk_koyuyesil;
				if(tetris_reg.tetris_harita[i]==3 || tetris_reg.tetris_harita[i]==13) renk=renk_kirmizi;
				if(tetris_reg.tetris_harita[i]==4 || tetris_reg.tetris_harita[i]==14) renk=renk_sari;
				if(tetris_reg.tetris_harita[i]==5 || tetris_reg.tetris_harita[i]==15) renk=renk_mor;
				//if(tetris_reg.tetris_harita[i]==6 || tetris_reg.tetris_harita[i]==16) renk=renk_kahverengi;
				tft_ili9325_dolukare(x,x+tetris_reg.kutu_piksel,y,y+tetris_reg.kutu_piksel,renk);
				tft_ili9325_boskare(x,x+tetris_reg.kutu_piksel,y,y+tetris_reg.kutu_piksel,2,renk_siyah);
				//tft_ili9325_boskare(x+(tetris_reg.kutu_piksel/5),x+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/5),y+(tetris_reg.kutu_piksel/5),y+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/5),1,renk_koyugri);
			}
			x=x+tetris_reg.kutu_piksel;
			say++;
			if(say==tetris_reg.kutu_satir){
				say=0;
				x=10;
				y=y+tetris_reg.kutu_piksel;
			}
		}

}

void tetris_blok_dose(void){

	uint16_t x=180,y=100,say=0,renk=0;	// x ve y ekran kullanım şekline göre değişebilir

	tetris_blok_yap(tetris_reg.blok_no_sonraki,tetris_reg.blok_yon_sonraki,tetris_reg.blok_renk_sonraki,1);
	//tetris_ilk_blok_dose();

	if(tetris_reg.blok_renk_sonraki==1) renk=renk_mavi;
	if(tetris_reg.blok_renk_sonraki==2) renk=renk_koyuyesil;
	if(tetris_reg.blok_renk_sonraki==3) renk=renk_kirmizi;
	if(tetris_reg.blok_renk_sonraki==4) renk=renk_sari;
	if(tetris_reg.blok_renk_sonraki==5) renk=renk_mor;
	//if(tetris_reg.blok_renk_sonraki==6) renk=renk_kahverengi;

	for(uint16_t i=0;i<16;i++){
		if(tetris_reg.blok_sonraki[i]==0){
			tft_ili9325_dolukare(x,x+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/3),y,y+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/3),tetris_reg.bos_kutu_renk);
			tft_ili9325_boskare(x,x+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/3),y,y+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/3),1,renk_siyah);
		}else{
			tft_ili9325_dolukare(x,x+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/3),y,y+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/3),renk);
			tft_ili9325_boskare(x,x+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/3),y,y+tetris_reg.kutu_piksel-(tetris_reg.kutu_piksel/3),1,renk_siyah);
		}
		x=x+tetris_reg.kutu_piksel-5;
		say++;
		if(say==4){
			say=0;
			x=180;
			y=y+tetris_reg.kutu_piksel-5;
		}
	}

}

void tetris_ilk_blok_dose(void){
	uint16_t yar=0,say=0;

	// oluşturulan bloku haritaya döşer
	tetris_reg.satir_sayici=tetris_reg.kutu_satir/3;
	tetris_reg.sutun_sayici=1;
	tetris_reg.yer_sayici=((tetris_reg.sutun_sayici*tetris_reg.kutu_satir)+tetris_reg.satir_sayici)-tetris_reg.kutu_satir;
	for(int i=0;i<16;i++){
		tetris_reg.tetris_harita[say+yar+(tetris_reg.kutu_satir/3)]=tetris_reg.blok[i];
		say++;
		if(say==4){
			say=0;
			yar=yar+tetris_reg.kutu_satir;
		}
	}

}

void tetris_ekran_dose(void){	// bu kısım opsiyonel ekran tipine veya kullanım şekline göre değiştirebilirsin

	tft_ili9325_dolukare(0,239,0,319,renk_beyaz);
	tft_ili9325_boskare(5,165,5,315,4,renk_siyah);
	tft_ili9325_yaziyaztum(173,15,"STM32",Tahoma18x16,renk_kirmizi,renk_beyaz);
	tft_ili9325_yaziyaztum(170,35,"TETRIS",Tahoma18x16,renk_kirmizi,renk_beyaz);
	tft_ili9325_yataycizgi(170,60,65,renk_siyah);
	tft_ili9325_yaziyaztum(173,75,"SONRA",Tahoma18x16,renk_mavi,renk_beyaz);
	tetris_blok_dose();
	itoa(tetris_reg.blok_adet,txt,10);
	tft_ili9325_yaziyaztum(195,150,txt,Tahoma18x16,renk_mavi,renk_beyaz);
	tft_ili9325_yataycizgi(170,175,65,renk_siyah);
	tft_ili9325_yaziyaztum(180,195,"PUAN",Tahoma18x16,renk_mavi,renk_beyaz);
	itoa(tetris_reg.puan,txt,10);
	tft_ili9325_yaziyaztum(180,225,txt,Tahoma18x16,renk_mavi,renk_beyaz);
	tft_ili9325_yataycizgi(170,250,65,renk_siyah);
	tft_ili9325_yaziyaztum(172,260,"SEVİYE",Tahoma18x16,renk_mavi,renk_beyaz);
	itoa(tetris_reg.oyun_seviye,txt,10);
	tft_ili9325_yaziyaztum(190,280,txt,Tahoma18x16,renk_mavi,renk_beyaz);
	tetris_harita_dose();

}
/*	hatanın 99 olması yüzeye tek satırlık bir parçanın oturmuş olma ihtimaline karşılık eklenmiştir.
	blok alt fonksyonunda taramalar en alt satırın bir satır yukarısından yapılır
	dolayısıyla en alt satırdaki tek satırlık parça göz ardı edilir
	bu durumda fonksyon 99 hata dönüşü yapar ki code kitlenmesin.
*/
uint8_t tetris_blok_alt(void){
	uint8_t hata=99;

	for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
		tetris_reg.yedek_harita[i]=tetris_reg.tetris_harita[i];
	}
	for(uint16_t i=(tetris_reg.kutu_satir*tetris_reg.kutu_sutun)-tetris_reg.kutu_satir-1;i>0;i--){
		if(tetris_reg.yedek_harita[i]!=0){
			if(tetris_reg.yedek_harita[i]>0 && tetris_reg.yedek_harita[i]<10){
				if(tetris_reg.yedek_harita[i+tetris_reg.kutu_satir]==0){
					tetris_reg.yedek_harita[i+tetris_reg.kutu_satir]=tetris_reg.yedek_harita[i];
					tetris_reg.yedek_harita[i]=0;
					hata=0;
				}else{
					hata=1;
					break;
				}
			}
		}
	}
	if(hata==0){
		for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
			tetris_reg.tetris_harita[i]=tetris_reg.yedek_harita[i];
		}
		tetris_reg.sutun_sayici++;
		tetris_reg.yer_sayici=((tetris_reg.sutun_sayici*tetris_reg.kutu_satir)+tetris_reg.satir_sayici)-tetris_reg.kutu_satir;
	}
	if(hata==1 || hata==99){
		for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
			if(tetris_reg.tetris_harita[i]!=0){
				if(tetris_reg.tetris_harita[i]>0 && tetris_reg.tetris_harita[i]<10){
					tetris_reg.tetris_harita[i]=tetris_reg.tetris_harita[i]+10;
				}
			}
		}
	}
	return hata;

}

uint8_t tetris_blok_sag(void){
	uint8_t hata=0;
	uint16_t kalan=0;

	for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
		tetris_reg.yedek_harita[i]=tetris_reg.tetris_harita[i];
	}
	for(uint16_t i=(tetris_reg.kutu_satir*tetris_reg.kutu_sutun);i>0;i--){
		if(tetris_reg.yedek_harita[i]!=0){
			if(tetris_reg.yedek_harita[i]>0 && tetris_reg.yedek_harita[i]<10){
				kalan=(i+1) % tetris_reg.kutu_satir;
				if(kalan==0){
					hata=1;
					break;
				}
				if(tetris_reg.yedek_harita[i+1]==0){
					tetris_reg.yedek_harita[i+1]=tetris_reg.yedek_harita[i];
					tetris_reg.yedek_harita[i]=0;
				}else{
					hata=1;
					break;
				}
			}
		}
	}
	if(hata==0){
		for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
			tetris_reg.tetris_harita[i]=tetris_reg.yedek_harita[i];
		}
		tetris_reg.satir_sayici++;
		if(tetris_reg.satir_sayici >= tetris_reg.kutu_satir-4){
			tetris_reg.satir_sayici=tetris_reg.kutu_satir-4;
		}
		tetris_reg.yer_sayici=((tetris_reg.sutun_sayici*tetris_reg.kutu_satir)+tetris_reg.satir_sayici)-tetris_reg.kutu_satir;

	}
	return hata;

}

uint8_t tetris_blok_sol(void){
	uint8_t hata=0;
	uint16_t kalan=0;

	for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
		tetris_reg.yedek_harita[i]=tetris_reg.tetris_harita[i];
	}
	for(uint16_t i=0;i<(tetris_reg.kutu_satir*tetris_reg.kutu_sutun);i++){

		if(tetris_reg.yedek_harita[i]!=0){
			if(tetris_reg.yedek_harita[i]>0 && tetris_reg.yedek_harita[i]<10){
				kalan=i % tetris_reg.kutu_satir;
				if(kalan==0){
					hata=1;
					break;
				}
				if(tetris_reg.yedek_harita[i-1]==0){
					tetris_reg.yedek_harita[i-1]=tetris_reg.yedek_harita[i];
					tetris_reg.yedek_harita[i]=0;
				}else{
					hata=1;
					break;
				}
			}
		}

	}
	if(hata==0){
		for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
			tetris_reg.tetris_harita[i]=tetris_reg.yedek_harita[i];
		}
		tetris_reg.satir_sayici--;
		if(tetris_reg.satir_sayici==0 || tetris_reg.satir_sayici>=250){
			tetris_reg.satir_sayici=0;
		}
		tetris_reg.yer_sayici=((tetris_reg.sutun_sayici*tetris_reg.kutu_satir)+tetris_reg.satir_sayici)-tetris_reg.kutu_satir;
	}
	return hata;

}
uint8_t tetris_blok_donme(void){
	uint8_t hata=0;
	uint16_t yar=0,say=0;

	tetris_blok_yap(tetris_reg.blok_no,tetris_reg.blok_yon,tetris_reg.blok_renk,0);

	for(int i=0;i<16;i++){
		if(tetris_reg.tetris_harita[say+yar+(tetris_reg.yer_sayici)]>10){
			hata=1;
			break;
		}
		say++;
		if(say==4){
			say=0;
			yar=yar+tetris_reg.kutu_satir;
		}
	}

	if(hata==1){
		tetris_reg.blok_yon--;
		if(tetris_reg.blok_yon==0) tetris_reg.blok_yon=4;
		tetris_blok_yap(tetris_reg.blok_no,tetris_reg.blok_yon,tetris_reg.blok_renk,0);
	}
	if(hata==0){
		yar=0;
		say=0;
		for(int i=0;i<16;i++){
			tetris_reg.tetris_harita[say+yar+(tetris_reg.yer_sayici)]=0;
			tetris_reg.tetris_harita[say+yar+(tetris_reg.yer_sayici)]=tetris_reg.blok[i];
			say++;
			if(say==4){
				say=0;
				yar=yar+tetris_reg.kutu_satir;
			}
		}
	}

	return hata;

}

uint8_t tetris_blok_patlama_kontrol(void){
	uint8_t sonuc=0,kalan=0,kaydir=0;
	uint16_t sayici=0;

	for(uint16_t i=(tetris_reg.kutu_satir*tetris_reg.kutu_sutun);i>0;i--){
		kalan=(i+1) % tetris_reg.kutu_satir;
		if(kalan==0) sayici=0;
		if(tetris_reg.tetris_harita[i]>10){
			sayici++;
		}else{
			sayici=0;
		}
		if(sayici==tetris_reg.kutu_satir){
			for(uint16_t x=i;x<i+tetris_reg.kutu_satir;x++){
				tetris_reg.tetris_harita[x]=0;
			}
			sonuc=1;
			kaydir=1;
			if(tetris_reg.blok_adet>100){
				tetris_reg.puan_carpan=tetris_reg.blok_adet/100;
			}else{
				tetris_reg.puan_carpan=1;
			}
			tetris_reg.puan=tetris_reg.puan+(tetris_reg.kutu_satir*tetris_reg.puan_carpan);
			patlama_sesi();
			tetris_ekran_dose();
		}
		if(kaydir==1){
			tetris_reg.tetris_harita[i+tetris_reg.kutu_satir-1]=tetris_reg.tetris_harita[i-1];
		}
	}

	return sonuc;

}

void tetris_oyun_bitti_kontrol(void){

	for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
		if(tetris_reg.tetris_harita[i]!=0){
			if(i<tetris_reg.kutu_satir*4){
				tetris_reg.oyun_bitti=1;
				break;
			}
		}
	}
}

void tetris_oyun_bitti_animasyon(void){

	uint8_t say=10;
	for(uint16_t i=0;i<((tetris_reg.kutu_satir*tetris_reg.kutu_sutun)/2+1);i++){
		say++;
		if(say==16) say=11;
		tetris_reg.tetris_harita[i]=say;
		tetris_reg.tetris_harita[(tetris_reg.kutu_satir*tetris_reg.kutu_sutun)-i]=say;
		kucuk_ses();
		tetris_harita_dose();
	}

	tft_ili9325_dolukare(20,150,40,270,renk_beyaz);
	tft_ili9325_boskare(20,150,40,270,2,renk_kizil);
	tft_ili9325_yaziyaz(40,80,"OYUN  BİTTİ",Tahoma18x16,renk_kirmizi);
	tft_ili9325_yaziyaz(30,150,"PUAN:",Tahoma18x16,renk_mavi);
	itoa(tetris_reg.puan,txt,10);
	tft_ili9325_yaziyaz(100,150,txt,Tahoma18x16,renk_mavi);
	HAL_Delay(2500);

}

void tetris_hareket(uint8_t hareket, uint8_t yon){

	if(hareket==1){		// blok alt hareket bölümü
		if(tetris_blok_alt()==0){		// blok zemine değmedi
			tetris_harita_dose();
		}else{							// blok zemine oturdu
			while(tetris_blok_patlama_kontrol()){
				HAL_Delay(150);
				tetris_reg.hiz_sayici++;
				if(tetris_reg.hiz_sayici==5){	// her patlayan 5 blokta oyun hizinı 10ms hizlandırır.
					tetris_reg.hiz_sayici=0;
					tetris_reg.oyun_hiz=tetris_reg.oyun_hiz-10;
					tetris_reg.oyun_seviye++;
				}
			}
			tetris_oyun_bitti_kontrol();
			if(tetris_reg.oyun_bitti==0){
				tetris_reg.blok_adet++;
				tetris_reg.blok_no=tetris_reg.blok_no_sonraki;
				tetris_reg.blok_renk=tetris_reg.blok_renk_sonraki;
				tetris_reg.blok_yon=tetris_reg.blok_yon_sonraki;
				tetris_reg.blok_no_sonraki=tetris_reg.s_b_s;
				tetris_reg.blok_renk_sonraki=tetris_reg.s_r_s;
				tetris_reg.blok_yon_sonraki=tetris_reg.s_y_s;
				tetris_blok_yap(tetris_reg.blok_no,tetris_reg.blok_yon,tetris_reg.blok_renk,0);
				tetris_blok_yap(tetris_reg.blok_no_sonraki,tetris_reg.blok_yon_sonraki,tetris_reg.blok_renk_sonraki,1);
				tetris_ilk_blok_dose();
				tetris_ekran_dose();
				HAL_Delay(500); // yeni blok ekrana geldiğinde bir süre hiç birşey yapmadan bekleme yapması iyidir
			}else{
				hata_sesi();
				HAL_Delay(1000);
				tetris_oyun_bitti_animasyon();
				for(uint16_t i=0;i<tetris_reg.kutu_satir*tetris_reg.kutu_sutun;i++){
					tetris_reg.yedek_harita[i]=0;
					tetris_reg.tetris_harita[i]=0;
				}
				tetris_reg.blok_adet=1;
				tetris_reg.oyun_hiz=300;
				tetris_reg.puan=0;
				tetris_reg.hiz_sayici=0;
				tetris_reg.oyun_seviye=1;
				tetris_blok_yap(tetris_reg.blok_no,tetris_reg.blok_yon,tetris_reg.blok_renk,0);
				tetris_blok_yap(tetris_reg.blok_no_sonraki,tetris_reg.blok_yon_sonraki,tetris_reg.blok_renk_sonraki,1);
				tetris_ilk_blok_dose();
				//tetris_ekran_dose();
				basla_bekleme();
			}
		}
	}

	if(hareket==2){		// blok sag hareket bölümü
		if(tetris_blok_sag()==0){		// blok duvara çarpmadı
			tetris_harita_dose();
		}
	}

	if(hareket==3){		// blok sol hareket bölümü
		if(tetris_blok_sol()==0){		// blok duvara çarpmadı
			tetris_harita_dose();
		}
	}
	if(hareket==4){		// blok çevir
		if(tetris_blok_donme()==0){
			tetris_harita_dose();
		}
	}



}

