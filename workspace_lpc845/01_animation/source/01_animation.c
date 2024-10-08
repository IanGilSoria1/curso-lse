#include "board.h"
#include "LPC845.h"

// Etiqueta para el pulsador USER
#define USER_BTN	4
//Etiqueta Digito A de luz
#define DIGITO 8
#define DIGITA 9
//Etiqueta segmento 1 de luz
#define SEGMENTA 11
#define SEGMENTE 10
#define SEGMENTI 6
#define SEGMENTO 14
#define SEGMENTU 0
#define SEGMENTAA 13
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
    GPIO_PinInit(GPIO, 0, DIGITA , &out_config);
    //Configuro el pin 8,9,10,11,12,13,14 y 15 como salida
    GPIO_PinInit(GPIO, 0, SEGMENTA , &out_config);
    GPIO_PinInit(GPIO, 0, SEGMENTE , &out_config);
    GPIO_PinInit(GPIO, 0, SEGMENTI , &out_config);
    GPIO_PinInit(GPIO, 0, SEGMENTO , &out_config);
    GPIO_PinInit(GPIO, 0, SEGMENTU , &out_config);
    GPIO_PinInit(GPIO, 0, SEGMENTAA , &out_config);
    GPIO_PinInit(GPIO, 0, SEGMENTEE , &out_config);

    while(1) {

    	// Verifico el estado del pulsador (tiene pull-up)
    	while (!GPIO_PinRead(GPIO, 0, USER_BTN)) {
			GPIO_PinWrite(GPIO, 0, DIGITO, 0);
			GPIO_PinWrite(GPIO, 0, DIGITA, 0);
			GPIO_PinWrite(GPIO, 0, SEGMENTA, 0);
			for (uint32_t i = 0; i <100000; i++);
			GPIO_PinWrite(GPIO, 0, SEGMENTA, 1);
			GPIO_PinWrite(GPIO, 0, SEGMENTE, 0);
			for (uint32_t i = 0; i <100000; i++)
			GPIO_PinWrite(GPIO, 0, SEGMENTE, 1);
			GPIO_PinWrite(GPIO, 0, SEGMENTI, 0);
			for (uint32_t i = 0; i <100000; i++)
			GPIO_PinWrite(GPIO, 0, SEGMENTI, 1);
			GPIO_PinWrite(GPIO, 0, SEGMENTO, 0);
			for (uint32_t i = 0; i <100000; i++)
			GPIO_PinWrite(GPIO, 0, SEGMENTO, 1);
			GPIO_PinWrite(GPIO, 0, SEGMENTU, 0);
			for (uint32_t i = 0; i <100000; i++)
			GPIO_PinWrite(GPIO, 0, SEGMENTU, 1);
			GPIO_PinWrite(GPIO, 0, SEGMENTAA, 0);
			for (uint32_t i = 0; i <100000; i++)
			GPIO_PinWrite(GPIO, 0, SEGMENTAA, 1);
			GPIO_PinWrite(GPIO, 0, SEGMENTEE, 0);
			for (uint32_t i = 0; i <100000; i++);
			GPIO_PinWrite(GPIO, 0, SEGMENTEE, 1);
    	}

		// Apago el segmento de manera secuenciada
		GPIO_PinWrite(GPIO, 0, DIGITO, 1);
		GPIO_PinWrite(GPIO, 0, DIGITA, 1);
		GPIO_PinWrite(GPIO, 0, SEGMENTA, 1);
		GPIO_PinWrite(GPIO, 0, SEGMENTE, 1);
		GPIO_PinWrite(GPIO, 0, SEGMENTI, 1);
		GPIO_PinWrite(GPIO, 0, SEGMENTO, 1);
		GPIO_PinWrite(GPIO, 0, SEGMENTU, 1);
		GPIO_PinWrite(GPIO, 0, SEGMENTAA, 1);
		GPIO_PinWrite(GPIO, 0, SEGMENTEE, 1);
		for (uint32_t i = 0; i <100000; i++);
}

    return 0;
}
