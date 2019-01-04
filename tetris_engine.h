/*
 * tetris_engine.h
 *
 *  Creaed on: 19 Ara 2018
 *      Author: Tolga
 */

#ifndef TETRIS_ENGINE_H_
#define TETRIS_ENGINE_H_

#ifdef __cplusplus
 extern "C" {
#endif


 typedef struct {

	 uint8_t 	blok_no;
	 uint8_t	blok_renk;
	 uint8_t	blok_yon;
	 uint8_t 	blok_no_sonraki;
	 uint8_t	blok_renk_sonraki;
	 uint8_t	blok_yon_sonraki;
	 uint8_t 	s_b_s;
	 uint8_t	s_r_s;
	 uint8_t	s_y_s;
	 uint8_t	kutu_piksel;
	 uint8_t	kutu_satir;
	 uint8_t 	kutu_sutun;
	 uint8_t	buton;
	 uint8_t	oyun_bitti;
	 uint8_t	puan_carpan;
	 uint8_t	hiz_sayici;
	 uint8_t	oyun_seviye;

	 uint16_t	oyun_hiz;
	 uint16_t 	puan;
	 uint16_t 	bos_kutu_renk;
	 uint16_t	blok_adet;
	 uint16_t 	satir_sayici;
	 uint16_t 	sutun_sayici;
	 uint16_t	yer_sayici;


	 uint8_t	blok[16];
	 uint8_t	blok_sonraki[16];
	 uint8_t	yedek_harita[500];	// max kutu sayısı 500 ile sınırlı dilersen arttırabilirsin
	 uint8_t	tetris_harita[500];	// max kutu sayısı 500 ile sınırlı dilersen arttırabilirsin

 }tetrisTypeDef;


//void tetris_blok_yap(uint8_t no, uint8_t renk, uint8_t tip);
void tetris_genel_ayar(void);
void tetris_harita_dose(void);
void tetris_blok_dose(void);
void tetris_ilk_blok_dose(void);
void tetris_ekran_dose(void);
uint8_t tetris_blok_alt(void);
uint8_t tetris_blok_sag(void);
uint8_t tetris_blok_sol(void);
uint8_t blok_patlama_kontrol(void);
void tetris_oyun_bitti_kontrol(void);
void tetris_oyun_bitti_animasyon(void);
void tetris_hareket(uint8_t hareket, uint8_t donus);



#ifdef __cplusplus
}
#endif

#endif /* TETRIS_ENGINE_H_ */
