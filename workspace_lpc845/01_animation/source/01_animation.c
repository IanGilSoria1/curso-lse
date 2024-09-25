#include "board.h"
#include "LPC845.h"

// Etiqueta para el pulsador USER
#define USER_BTN	4
//Etiqueta Digito A de luz
#define DIGITO 8
//Etiqueta segmento 1 de luz
#define SEGMENTA 9
#define SEGMENTE 10
#define SEGMENTI 11
#define SEGMENTO 12
#define SEGMENTU 13
#define SEGMENTAA 14
#define SEGMENTEE 15

/*
 * @brief   Application entry point.
*/
int main(void) {

	// Inicializacion
    BOARD_InitBootClocks();
    GPIO_PortInit(GPIO, 0);

    // Estructura de configuracion para salida
    gpio_pin_config_t out_config = { kGPIO_DigitalOutput, 1 };
    // Estructura de configuracion para entrada
    gpio_pin_config_t in_config = { kGPIO_DigitalInput };
    // Habilito el puerto 0

    //Habilito segmento "a"
    // Configuro el pin 4 como entrada
    GPIO_PinInit(GPIO, 0, USER_BTN , &in_config);
    //Configuro el pin 8 como saida
    GPIO_PinInit(GPIO, 0, DIGITO , &out_config);
    //Configuro el pin 8 como saida
    GPIO_PinInit(GPIO, 0, SEGMENTA , &out_config);

    while(1) {

    	// Verifico el estado del pulsador (tiene pull-up)
    	if(!GPIO_PinRead(GPIO, 0, USER_BTN)) {
    		// Prendo el segmento (anodo comun)
    		GPIO_PinWrite(GPIO, 0, DIGITO, 0);
    		GPIO_PinWrite(GPIO, 0, SEGMENTA, 0);


    	}
    	else {
    		// Apago el segmento de manera secuenciada
    		GPIO_PinWrite(GPIO, 0, DIGITO, 1);
    		GPIO_PinWrite(GPIO, 0, SEGMENTA, 1);

    	}
    }

    return 0;
}
