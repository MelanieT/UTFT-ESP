	case S6D02A1:		
        // Extended command mode on
		LCD_Write_COM(0xf0);
		LCD_Write_DATA(0x5a);
		LCD_Write_DATA(0x5a);

        // Extended command 3 (should this be 0xa5?)
		LCD_Write_COM(0xfc);
		LCD_Write_DATA(0x5a);
		LCD_Write_DATA(0x5a);

        // Gamma set
		LCD_Write_COM(0x26);
		LCD_Write_DATA(0x01);

        // Positive Gamma control
		LCD_Write_COM(0xfa);
		LCD_Write_DATA(0x02);
		LCD_Write_DATA(0x1f);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x10);
		LCD_Write_DATA(0x22);
		LCD_Write_DATA(0x30);
		LCD_Write_DATA(0x38);
		LCD_Write_DATA(0x3A);
		LCD_Write_DATA(0x3A);
		LCD_Write_DATA(0x3A);
		LCD_Write_DATA(0x3A);
		LCD_Write_DATA(0x3A);
		LCD_Write_DATA(0x3d);
		LCD_Write_DATA(0x02);
		LCD_Write_DATA(0x01);

        // Negative Gamma control
		LCD_Write_COM(0xfb);
		LCD_Write_DATA(0x21);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x02);
		LCD_Write_DATA(0x04);
		LCD_Write_DATA(0x07);
		LCD_Write_DATA(0x0a);
		LCD_Write_DATA(0x0b);
		LCD_Write_DATA(0x0c);
		LCD_Write_DATA(0x0c);
		LCD_Write_DATA(0x16);
		LCD_Write_DATA(0x1e);
		LCD_Write_DATA(0x30);
		LCD_Write_DATA(0x3f);
		LCD_Write_DATA(0x01);
		LCD_Write_DATA(0x02);

		// Analog test, set power and frequencies
		LCD_Write_COM(0xfd);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x17);
		LCD_Write_DATA(0x10);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x01);
		LCD_Write_DATA(0x01);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x1f);
		LCD_Write_DATA(0x1f);

        // Power CTL
		LCD_Write_COM(0xf4);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3f);
		LCD_Write_DATA(0x3f);
		LCD_Write_DATA(0x07);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3C);
		LCD_Write_DATA(0x36);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3C);
		LCD_Write_DATA(0x36);
		LCD_Write_DATA(0x00);

        // Comms voltages control
		LCD_Write_COM(0xf5);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x70);//39
		LCD_Write_DATA(0x66);//3a
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x6d);//38
		LCD_Write_DATA(0x66);//38
		LCD_Write_DATA(0x06);

        // Source clock and power
		LCD_Write_COM(0xf6);
		LCD_Write_DATA(0x02);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3f);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x02);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x06);
		LCD_Write_DATA(0x01);
		LCD_Write_DATA(0x00);

        // Display timing control
		LCD_Write_COM(0xf2);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x01);//04
		LCD_Write_DATA(0x03);
		LCD_Write_DATA(0x08);
		LCD_Write_DATA(0x08);
		LCD_Write_DATA(0x04);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x01);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x04);
		LCD_Write_DATA(0x08);
		LCD_Write_DATA(0x08);

        // Panel timing control
		LCD_Write_COM(0xf8);
		LCD_Write_DATA(0x11);//66

        // Interface control
		LCD_Write_COM(0xf7);
		LCD_Write_DATA(0xc8);
		LCD_Write_DATA(0x20);
        if (init_flags & 2) // Invert clock polarity, needed for mega328 SPI
            LCD_Write_DATA(0x20);
        else
            LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);

        // Stop boosters and clocks
		LCD_Write_COM(0xf3);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);

        // Sleep off
		LCD_Write_COM(0x11);
		delay(50);

        // Start boosters and clocks
		LCD_Write_COM(0xf3);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x01);
		delay(50);
		LCD_Write_COM(0xf3);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x03);
		delay(50);
		LCD_Write_COM(0xf3);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x07);
		delay(50);
		LCD_Write_COM(0xf3);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x0f);
		delay(50);

        // Power control, again
		LCD_Write_COM(0xf4);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x04);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3f);
		LCD_Write_DATA(0x3f);
		LCD_Write_DATA(0x07);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3C);
		LCD_Write_DATA(0x36);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3C);
		LCD_Write_DATA(0x36);
		LCD_Write_DATA(0x00);
		delay(50);

        // Start boosters and clocks
		LCD_Write_COM(0xf3);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x1f);
		delay(50);
		LCD_Write_COM(0xf3);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x7f);
		delay(50);
		LCD_Write_COM(0xf3);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0xff);
		delay(50);

		// Analog test, set power and frequencies
		LCD_Write_COM(0xfd);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x17);
		LCD_Write_DATA(0x10);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x01);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x16);
		LCD_Write_DATA(0x16);

        // More power control
		LCD_Write_COM(0xf4);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x09);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3f);
		LCD_Write_DATA(0x3f);
		LCD_Write_DATA(0x07);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3C);
		LCD_Write_DATA(0x36);
		LCD_Write_DATA(0x00);
		LCD_Write_DATA(0x3C);
		LCD_Write_DATA(0x36);
		LCD_Write_DATA(0x00);

		/////////////initializing sequence/////////////

        // Memory data access control
		LCD_Write_COM( 0x36);   
        if (init_flags & 1) // Flip display as some models scan upside down
            LCD_Write_DATA( 0xc8); 
        else
            LCD_Write_DATA( 0x08); 

        // Disable TE output
		LCD_Write_COM(0x35);
		LCD_Write_DATA(0x00);

        // Interface pixel format
		LCD_Write_COM(0x3a);
		LCD_Write_DATA(0x05);


		/////////////////gamma setting sequence/////////

		delay(150);	

        // Display on 
		LCD_Write_COM(0x29);

        // Memory write
		LCD_Write_COM(0x2c);
		break;
