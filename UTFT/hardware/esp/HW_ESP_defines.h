// *** Hardwarespecific defines ***
#ifdef ESP8266
  #define cbi(reg, bitmask) GPOC = bitmask
  #define sbi(reg, bitmask) GPOS = bitmask
#endif

#ifdef ESP32
  #define cbi(reg, bitmask) *reg &= ~bitmask
  #define sbi(reg, bitmask) *reg |= bitmask
  #ifndef USE_ARDUINO
    #include <soc/gpio_reg.h>
    #include "driver/gpio.h"
    #include <freertos/FreeRTOS.h>
    #include <freertos/task.h>
    #define LOW 0
    #define HIGH 1
    #define digitalPinToPort(pin)       (((pin)>31)?1:0)
    #define digitalPinToBitMask(pin)    (1UL << (((pin)>31)?((pin)-32):(pin)))
    #define digitalPinToTimer(pin)      (0)
    #define OUTPUT GPIO_MODE_OUTPUT
    #define INPUT GPIO_MODE_INPUT
    #define pinMode(p, m) gpio_pad_select_gpio((gpio_num_t)p); gpio_set_direction((gpio_num_t)p, m)
    #define digitalWrite(p, v) gpio_set_level((gpio_num_t)p, v)
    #define delay(x) vTaskDelay(x / portTICK_PERIOD_MS)
    #define portOutputRegister(port)    ((volatile uint32_t*)((port)?GPIO_OUT1_REG:GPIO_OUT_REG))
  #endif
#endif

#define pulse_high(reg, bitmask) sbi(reg, bitmask); cbi(reg, bitmask);
#define pulse_low(reg, bitmask) cbi(reg, bitmask); sbi(reg, bitmask);

#define cport(port, data) port &= data
#define sport(port, data) port |= data

#define swap(type, i, j) {type t = i; i = j; j = t;}

#define fontbyte(x) pgm_read_byte(&cfont.font[x])

#define regtype volatile uint32_t
#define regsize uint32_t
#define bitmapdatatype unsigned short*
