#include "board.h"
#include "LPC845.h"

// Etiqueta para el LED azul
#define LED_BLUE	1

/*
 * @brief Application entry point.
*/
int main(void) {
    // Inicializacion
    BOARD_InitBootClocks();
    // Estructura de configuracion para salida
    gpio_pin_config_t out_config = { kGPIO_DigitalOutput, 1 };
    // Habilito el clock del GPIO 1
    GPIO_PortInit(GPIO, 1);
    // Configuro el Pin 0 del GPIO 1 como salida
    GPIO_PinInit(GPIO, 1, LED_BLUE, &out_config);

    while(1) {
        // Niego el estado del LED
        GPIO_PinWrite(GPIO, 1, LED_BLUE, !GPIO_PinRead(GPIO, 1 LED_BLUE));
        // Demora
        for(uint32_t i = 0; i < 1000000; i++);
    }
    return 0;
}