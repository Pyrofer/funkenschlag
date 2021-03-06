#ifndef PSX_lib_h
#define PSX_lib_h


#include <avr/io.h>
#include <util/delay.h>

#define PSX_SPI	PORTB
#define PSX_DAT PB2 // brown wire from pad to avr
#define PSX_CLK PB3 // blue wire from avr to pad
#define PSX_COM PB4 // orange wire from avr to pad
#define PSX_ATT PORTD
#define PSX_ATN PD7 // yellow wire from avr to pad



//Half a clock cycle; 10µs seems to be about right
#define CTRL_CLK        10

//These are our button constants
#define PSB_SELECT      0x0001
#define PSB_L3          0x0002
#define PSB_R3          0x0004
#define PSB_START       0x0008
#define PSB_PAD_UP      0x0010
#define PSB_PAD_RIGHT   0x0020
#define PSB_PAD_DOWN    0x0040
#define PSB_PAD_LEFT    0x0080
#define PSB_L2          0x0100
#define PSB_R2          0x0200
#define PSB_L1          0x0400
#define PSB_R1          0x0800
#define PSB_TRIANGLE    0x1000
#define PSB_CIRCLE      0x2000
#define PSB_CROSS       0x4000
#define PSB_SQUARE      0x8000

//These are stick values
#define PSS_RX 5
#define PSS_RY 6
#define PSS_LX 7
#define PSS_LY 8

/* quickly return pad values for interrupt transmission */
int16_t ps2_get(uint8_t n);
/* routine to query the pad and put values into array ready for TX */
void ps2_query(void);
/* Initialize the controller, specifying which port and pins to use for each connection.
 * We extrapolate the DDR register from the PORT register for each connection.
 */
void psx_init(volatile uint8_t *data_port, uint8_t data_pin,
        volatile uint8_t *clock_port, uint8_t clock_pin,
        volatile uint8_t *command_port, uint8_t command_pin,
        volatile uint8_t *attention_port, uint8_t attention_pin);
        
/* Returns the current state of all 16 buttons */
uint16_t psx_buttons(void);
      
/* Returns non-zero if the given button is pressed. */
uint8_t psx_button(uint16_t);

/* Returns the value of the given analog stick (0-255) */
uint8_t psx_stick(unsigned int);

/* Updates the current value of the game pad. */
void psx_read_gamepad(void);

#endif
