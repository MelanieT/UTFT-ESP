#ifdef USE_ARDUINO
#include <SPI.h>
#else
#include <driver/spi_master.h>
#include <soc/spi_reg.h>
#endif

#ifndef USE_ARDUINO
spi_device_handle_t disp_spi;
regtype *PP_CS;
regsize PB_CS;

char *dtostrf (double val, signed char width, unsigned char prec, char *sout) {
    char fmt[20];
    sprintf(fmt, "%%%d.%df", width, prec);
    sprintf(sout, fmt, val);
    return sout;
}

extern "C" {
static void disp_cs_on_cb(spi_transaction_t *trans)
{
    cbi(PP_CS, PB_CS);
    //gpio_set_level(PIN_NUM_CS, 0);
}

static void disp_cs_off_cb(spi_transaction_t *trans)
{
    sbi(PP_CS, PB_CS);
    //gpio_set_level(PIN_NUM_CS, 1);
}
}

#endif

// *** Hardwarespecific functions ***
void UTFT::_hw_special_init (  ) {
    if ( hwSPI ) {
#ifdef USE_ARDUINO
        SPI.begin (  );
        SPI.setClockDivider ( SPI_CLOCK_DIV4 );
        SPI.setBitOrder ( MSBFIRST );
        SPI.setDataMode ( SPI_MODE0 );
#else
        PP_CS = P_CS;
        PB_CS = B_CS;

		spi_bus_config_t buscfg;
		memset(&buscfg, 0, sizeof(buscfg));
		buscfg.miso_io_num = GPIO_NUM_12;
		buscfg.mosi_io_num = GPIO_NUM_13;
		buscfg.sclk_io_num = GPIO_NUM_14;
		buscfg.quadwp_io_num = -1;
		buscfg.quadhd_io_num = -1;
		buscfg.max_transfer_sz = 6 * 1024;

		//Initialize the SPI bus
		int ret = spi_bus_initialize(HSPI_HOST, &buscfg, 1);
		ESP_ERROR_CHECK(ret);

		spi_device_interface_config_t devcfg;
		memset(&devcfg, 0, sizeof(devcfg));
		devcfg.clock_speed_hz = 30000000;                //Clock out at 30 MHz
		devcfg.mode = 0;                                 //SPI mode 0
		devcfg.spics_io_num = -1;
		devcfg.queue_size = 1;
		devcfg.pre_cb = disp_cs_on_cb;
		devcfg.post_cb = disp_cs_off_cb;

		//Attach the LCD to the SPI bus
		ret = spi_bus_add_device(HSPI_HOST, &devcfg, &disp_spi);
		ESP_ERROR_CHECK(ret);
#endif
    }
}

void UTFT::LCD_Writ_Bus ( char VH, char VL, byte mode ) {
    if ( hwSPI ) {
        if ( VH == 1 ) {
            sbi ( P_RS, B_RS );
        } else {
            cbi ( P_RS, B_RS );
        }
#ifdef USE_ARDUINO
        SPI.write ( VL );
#else
		esp_err_t ret;

		spi_transaction_t t;

		memset(&t, 0, sizeof(t));       //Zero out the transaction
		t.length = 8;                 //Len is in bytes, transaction length is in bits.
		t.tx_buffer = &VL;

		ret = spi_device_transmit(disp_spi, &t);  //Transmit!

		assert(ret == ESP_OK);            //Should have had no issues.

#endif
        return;
    }

    switch ( mode ) {
    case 1:
        if ( display_serial_mode == SERIAL_4PIN ) {
            if ( VH == 1 )
                sbi ( P_SDA, B_SDA );
            else
                cbi ( P_SDA, B_SDA );
            pulse_low ( P_SCL, B_SCL );
        } else {
            if ( VH == 1 )
                sbi ( P_RS, B_RS );
            else
                cbi ( P_RS, B_RS );
        }

        if ( VL & 0x80 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x40 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x20 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x10 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x08 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x04 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x02 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        if ( VL & 0x01 )
            sbi ( P_SDA, B_SDA );
        else
            cbi ( P_SDA, B_SDA );
        pulse_low ( P_SCL, B_SCL );
        break;
    default:
        break;
    }
}

void UTFT::_set_direction_registers ( byte mode ) {
}

void UTFT::_fast_fill_16 ( int ch, int cl, long pix ) {
}

void UTFT::_fast_fill_8 ( int ch, long pix ) {
}

void UTFT::_convert_float ( char *buf, double num, int width, byte prec ) {
  dtostrf ( num, width, prec, buf );
}
