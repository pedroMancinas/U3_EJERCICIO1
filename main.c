//Pedro Mancinas Hernandez
// Ejercicio 9 realizado

/**********************************************************
 * FileName:        main.c
 * Dependencies:    msp.h, stdint.h
 * Processor:       MSP432
 * Board:           MSP432P401R
 * Program version: CCS V10 TI
 * Company:         TecNM /IT Chihuahua
 * Description:     ACCESO A MEMORIA DE REGISTROS DE PERIFERICO GPIO CON "ESTRUCTURAS_V2"
 * Authors:         ALFREDO CHACON
 * Updated:         03/2021
 * Nota: no se están usando las estructuras definidas en los sorucefiles dados por el BSP de TI, Aqui se declran las estructuras
 *       los punteros declarados se incializan con las direcciones de memoria de los registros de los perifericos en cuestión
 * Created on: 6 oct. 2021
 * updated: 20/11/2021
 **************************************************/

/************************************************************************************************
 * * Copyright (C) 2021 by Alfredo Chacon - TecNM /IT Chihuahua
 *
 * Se permite la redistribución, modificación o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/
/************************************************
  HEADER FILES
 ************************************************/

#include<stdint.h>
#include "msp.h"
#include "DRIVERS\BSP.h"

void main(void)
{

    /************************************************
              DECLARACION DE VARIABLES
     ************************************************/
    uint32_t i;
    uint8_t bandera = 0;

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;           // DETIENE EL TIMER DEL WATCHDOG
    /************************************************
        CONFIGURACION DE GPIO
    ************************************************/

    void Gpio_init2021();//Ejercicio 9


    while(1)
    {

        if ( Gpio_Pin_in(BOTON2) != 1)                // ENTRA AL PRESIONAR EL SWITCH DEL PUERTO P2.3 (CUANDO ESTA EN BAJO)
                {
                GPIO_setPinBajo(PUERTO1, LEDROJO);
                    if(bandera == FALSE)
                        {
                            bandera = TRUE;                                 //BANDERA EN ALTO
                            while (bandera==TRUE){
                                GPIO_setPinBajo(PUERTO2, LEDAZUL);    //APAGA BLUE
                                GPIO_setPinAlto(PUERTO2, LEDROJO);    //ENCIENDE RED
                                for(i=RETARDO; i>0 ;i--);
                                GPIO_setPinBajo(PUERTO2, LEDROJO);    //APAGA RED
                                GPIO_setPinAlto(PUERTO2, LEDVERDE);    //ENCIENDE GREEN
                                for(i=RETARDO; i>0 ;i--);
                                GPIO_setPinBajo(PUERTO2, LEDVERDE);    //APAGA GREEN
                                GPIO_setPinAlto(PUERTO2, LEDAZUL);    //ENCIENDE BLUE
                                for(i=RETARDO; i>0 ;i--);
                             if ( Gpio_Pin_in(BOTON2) != 1) bandera=FALSE;    // ENTRA CUANDO PRESIONAMOS BOTON DE P1.4
                             while( Gpio_Pin_in(BOTON2) != 1);                //MIENTRAS ESTE PRESIONADO EL BOTON
                            }
                        }
                 GPIO_setPinBajo(PUERTO2, LEDROJO | LEDVERDE |LEDAZUL);  //APAGA TODOS
                }
        for(i=RETARDO; i>0 ;i--);

    }

}

