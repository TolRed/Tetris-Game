/*
 * tetris_bloklar.c
 *
 *  Created on: 26 Ara 2018
 *      Author: Tolga
 */


#include "stm32f4xx_hal.h"
#include "stdlib.h"
#include "tetris_engine.h"
#include "tetris_bloklar.h"

tetrisTypeDef tetris_reg;


void tetris_blok_yap(uint8_t no, uint8_t yon ,uint8_t renk, uint8_t tip){


	if(tip==0){					// normal blok

		if(no==0){	// kare
			/*	----
			 * 	----
			 * 	-**-
			 * 	-**-
			 */
			if(yon==1){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
			}
			/*	----
			 * 	----
			 * 	-**-
			 * 	-**-
			 */
			if(yon==2){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
			}
			/*	----
			 * 	----
			 * 	-**-
			 * 	-**-
			 */
			if(yon==3){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
			}
			/*	----
			 * 	----
			 * 	-**-
			 * 	-**-
			 */
			if(yon==4){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
			}
		}
		if(no==1){	// çubuk
			/*	----
			 * 	----
			 * 	----
			 * 	****
			 */
			if(yon==1){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=0;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=renk;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=renk;
			}
			/*	-*--
			 * 	-*--
			 * 	-*--
			 * 	-*--
			 */
			if(yon==2){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=renk;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=renk;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=0;tetris_reg.blok[15]=0;
			}
			/*	----
			 * 	----
			 * 	----
			 * 	****
			 */
			if(yon==3){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=0;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=renk;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=renk;
			}
			/*	-*--
			 * 	-*--
			 * 	-*--
			 * 	-*--
			 */
			if(yon==4){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=renk;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=renk;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=0;tetris_reg.blok[15]=0;
			}
		}
		if(no==2){	// sol L
			/*	----
			 * 	----
			 * 	*---
			 * 	***-
			 */
			if(yon==1){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=renk;tetris_reg.blok[9]=0;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=renk;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
			}
			/*	----
			 * 	-**-
			 * 	-*--
			 * 	-*--
			 */
			if(yon==2){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=renk;tetris_reg.blok[6]=renk;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=0;tetris_reg.blok[15]=0;
			}
			/*	----
			 * 	----
			 * 	-***
			 * 	---*
			 */
			if(yon==3){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=renk;
				tetris_reg.blok[12]=0;tetris_reg.blok[13]=0;tetris_reg.blok[14]=0;tetris_reg.blok[15]=renk;
			}
			/*	----
			 * 	--*-
			 * 	--*-
			 * 	-**-
			 */
			if(yon==4){
				tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
				tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=renk;tetris_reg.blok[7]=0;
				tetris_reg.blok[8]=0;tetris_reg.blok[9]=0;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
				tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
			}
		}
		if(no==3){	// sol z
				/*	----
				 * 	----
				 * 	**--
				 * 	-**-
				 */
				if(yon==1){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=renk;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	--*-
				 * 	-**-
				 * 	-*--
				 */
				if(yon==2){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=renk;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=0;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	----
				 * 	**--
				 * 	-**-
				 */
				if(yon==3){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=renk;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	--*-
				 * 	-**-
				 * 	-*--
				 */
				if(yon==4){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=renk;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=0;tetris_reg.blok[15]=0;
				}
			}
			if(no==4){	// üçgen
				/*	----
				 * 	----
				 * 	-*--
				 * 	***-
				 */
				if(yon==1){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=renk;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	-*--
				 * 	-**-
				 * 	-*--
				 */
				if(yon==2){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=renk;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=0;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	----
				 * 	***-
				 * 	-*--
				 */
				if(yon==3){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=renk;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=0;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	--*-
				 * 	-**-
				 * 	--*-
				 */
				if(yon==4){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=renk;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=0;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
			}
			if(no==5){	// sağ L
				/*	----
				 * 	----
				 * 	---*
				 * 	-***
				 */
				if(yon==1){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=0;tetris_reg.blok[10]=0;tetris_reg.blok[11]=renk;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=renk;
				}
				/*	----
				 * 	-*--
				 * 	-*--
				 * 	-**-
				 */
				if(yon==2){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=renk;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=0;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	----
				 * 	-***
				 * 	-*--
				 */
				if(yon==3){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=renk;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=0;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	-**-
				 * 	--*-
				 * 	--*-
				 */
				if(yon==4){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=renk;tetris_reg.blok[6]=renk;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=0;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=0;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
			}
			if(no==6){	// sağ z
				/*	----
				 * 	----
				 * 	--**
				 * 	-**-
				 */
				if(yon==1){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=0;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=renk;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	-*--
				 * 	-**-
				 * 	--*-
				 */
				if(yon==2){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=renk;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=0;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	----
				 * 	--**
				 * 	-**-
				 */
				if(yon==3){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=0;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=0;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=renk;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=renk;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
				/*	----
				 * 	-*--
				 * 	-**-
				 * 	--*-
				 */
				if(yon==4){
					tetris_reg.blok[0]=0;tetris_reg.blok[1]=0;tetris_reg.blok[2]=0;tetris_reg.blok[3]=0;
					tetris_reg.blok[4]=0;tetris_reg.blok[5]=renk;tetris_reg.blok[6]=0;tetris_reg.blok[7]=0;
					tetris_reg.blok[8]=0;tetris_reg.blok[9]=renk;tetris_reg.blok[10]=renk;tetris_reg.blok[11]=0;
					tetris_reg.blok[12]=0;tetris_reg.blok[13]=0;tetris_reg.blok[14]=renk;tetris_reg.blok[15]=0;
				}
			}
	}else{						// sonraki blok

		if(no==0){	// kare
			/*	----
			 * 	----
			 * 	-**-
			 * 	-**-
			 */
			if(yon==1){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
			}
			/*	----
			 * 	----
			 * 	-**-
			 * 	-**-
			 */
			if(yon==2){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
			}
			/*	----
			 * 	----
			 * 	-**-
			 * 	-**-
			 */
			if(yon==3){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
			}
			/*	----
			 * 	----
			 * 	-**-
			 * 	-**-
			 */
			if(yon==4){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
			}
		}
		if(no==1){	// çubuk
			/*	----
			 * 	----
			 * 	----
			 * 	****
			 */
			if(yon==1){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=0;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=renk;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=renk;
			}
			/*	-*--
			 * 	-*--
			 * 	-*--
			 * 	-*--
			 */
			if(yon==2){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=renk;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=renk;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=0;tetris_reg.blok_sonraki[15]=0;
			}
			/*	----
			 * 	----
			 * 	----
			 * 	****
			 */
			if(yon==3){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=0;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=renk;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=renk;
			}
			/*	-*--
			 * 	-*--
			 * 	-*--
			 * 	-*--
			 */
			if(yon==4){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=renk;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=renk;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=0;tetris_reg.blok_sonraki[15]=0;
			}
		}
		if(no==2){	// sol L
			/*	----
			 * 	----
			 * 	*---
			 * 	***-
			 */
			if(yon==1){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=renk;tetris_reg.blok_sonraki[9]=0;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=renk;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
			}
			/*	----
			 * 	-**-
			 * 	-*--
			 * 	-*--
			 */
			if(yon==2){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=renk;tetris_reg.blok_sonraki[6]=renk;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=0;tetris_reg.blok_sonraki[15]=0;
			}
			/*	----
			 * 	----
			 * 	-***
			 * 	---*
			 */
			if(yon==3){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=renk;
				tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=0;tetris_reg.blok_sonraki[14]=0;tetris_reg.blok_sonraki[15]=renk;
			}
			/*	----
			 * 	--*-
			 * 	--*-
			 * 	-**-
			 */
			if(yon==4){
				tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
				tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=renk;tetris_reg.blok_sonraki[7]=0;
				tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=0;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
				tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
			}
		}
		if(no==3){	// sol z
				/*	----
				 * 	----
				 * 	**--
				 * 	-**-
				 */
				if(yon==1){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=renk;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	--*-
				 * 	-**-
				 * 	-*--
				 */
				if(yon==2){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=renk;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=0;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	----
				 * 	**--
				 * 	-**-
				 */
				if(yon==3){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=renk;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	--*-
				 * 	-**-
				 * 	-*--
				 */
				if(yon==4){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=renk;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=0;tetris_reg.blok_sonraki[15]=0;
				}
			}
			if(no==4){	// üçgen
				/*	----
				 * 	----
				 * 	-*--
				 * 	***-
				 */
				if(yon==1){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=renk;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	-*--
				 * 	-**-
				 * 	-*--
				 */
				if(yon==2){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=renk;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=0;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	----
				 * 	***-
				 * 	-*--
				 */
				if(yon==3){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=renk;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=0;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	--*-
				 * 	-**-
				 * 	--*-
				 */
				if(yon==4){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=renk;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=0;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
			}
			if(no==5){	// sağ L
				/*	----
				 * 	----
				 * 	---*
				 * 	-***
				 */
				if(yon==1){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=0;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=renk;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=renk;
				}
				/*	----
				 * 	-*--
				 * 	-*--
				 * 	-**-
				 */
				if(yon==2){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=renk;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=0;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	----
				 * 	-***
				 * 	-*--
				 */
				if(yon==3){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=renk;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=0;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	-**-
				 * 	--*-
				 * 	--*-
				 */
				if(yon==4){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=renk;tetris_reg.blok_sonraki[6]=renk;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=0;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=0;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
			}
			if(no==6){	// sağ z
				/*	----
				 * 	----
				 * 	--**
				 * 	-**-
				 */
				if(yon==1){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=0;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=renk;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	-*--
				 * 	-**-
				 * 	--*-
				 */
				if(yon==2){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=renk;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=0;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	----
				 * 	--**
				 * 	-**-
				 */
				if(yon==3){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=0;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=0;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=renk;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=renk;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
				/*	----
				 * 	-*--
				 * 	-**-
				 * 	--*-
				 */
				if(yon==4){
					tetris_reg.blok_sonraki[0]=0;tetris_reg.blok_sonraki[1]=0;tetris_reg.blok_sonraki[2]=0;tetris_reg.blok_sonraki[3]=0;
					tetris_reg.blok_sonraki[4]=0;tetris_reg.blok_sonraki[5]=renk;tetris_reg.blok_sonraki[6]=0;tetris_reg.blok_sonraki[7]=0;
					tetris_reg.blok_sonraki[8]=0;tetris_reg.blok_sonraki[9]=renk;tetris_reg.blok_sonraki[10]=renk;tetris_reg.blok_sonraki[11]=0;
					tetris_reg.blok_sonraki[12]=0;tetris_reg.blok_sonraki[13]=0;tetris_reg.blok_sonraki[14]=renk;tetris_reg.blok_sonraki[15]=0;
				}
			}

	}
}
