#include "board.h"
#include "LPC845.h"

// Etiqueta para el pulsador USER
#define USER_BTN	4
//Etiqueta Digito A de luz
#define DIGITO 8
#define DIGITA 9
//Etiqueta segmento 1 de luz
#define A 10
#define B 11
#define C 6
#define D 14
#define E 0
#define F 13
#define G 15

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
    GPIO_PinInit(GPIO, 0, A , &out_config);
    GPIO_PinInit(GPIO, 0, B , &out_config);
    GPIO_PinInit(GPIO, 0, C , &out_config);
    GPIO_PinInit(GPIO, 0, D , &out_config);
    GPIO_PinInit(GPIO, 0, E , &out_config);
    GPIO_PinInit(GPIO, 0, F , &out_config);
    GPIO_PinInit(GPIO, 0, G , &out_config);


    GPIO_PinWrite(GPIO, 0, DIGITA, 0);
    GPIO_PinWrite(GPIO, 0, DIGITO, 0);

    while(1) {

    	// Verifico el estado del pulsador (tiene pull-up)
    	while (!GPIO_PinRead(GPIO, 0, USER_BTN)) {
    		GPIO_PinWrite(GPIO, 0, F, 1);
			GPIO_PinWrite(GPIO, 0, A, 0);
			for (uint32_t i = 0; i <1000000; i++);
			GPIO_PinWrite(GPIO, 0, A, 1);
			GPIO_PinWrite(GPIO, 0, B, 0);
			for (uint32_t i = 0; i <1000000; i++)
			GPIO_PinWrite(GPIO, 0, B, 1);
			GPIO_PinWrite(GPIO, 0, C, 0);
			for (uint32_t i = 0; i <1000000; i++)
			GPIO_PinWrite(GPIO, 0, C, 1);
			GPIO_PinWrite(GPIO, 0, D, 0);
			for (uint32_t i = 0; i <1000000; i++)
			GPIO_PinWrite(GPIO, 0, D, 1);
			GPIO_PinWrite(GPIO, 0, E, 0);
			for (uint32_t i = 0; i <1000000; i++)
			GPIO_PinWrite(GPIO, 0, E, 1);
			GPIO_PinWrite(GPIO, 0, F, 0);
			for (uint32_t i = 0; i <1000000; i++)
			GPIO_PinWrite(GPIO, 0, F, 1);
			GPIO_PinWrite(GPIO, 0, G, 0);
    	}
    }

    return 0;
}
