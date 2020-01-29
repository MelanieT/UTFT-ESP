case ILI9486_480:
    //set the X coordinates
    LCD_Write_COM(0x2A);
    LCD_Write_DATA(x1 >> 8);                 //Set the horizontal starting point to the high octet
    LCD_Write_DATA(x1 & 0xff);                   //Set the horizontal starting point to the low octet
    LCD_Write_DATA(x2 >> 8); //Set the horizontal end to the high octet
    LCD_Write_DATA(x2 & 0xff);   //Set the horizontal end to the low octet

    //set the Y coordinates
    LCD_Write_COM(0x2B);
    LCD_Write_DATA(y1 >> 8);
    LCD_Write_DATA(y1 & 0xff );
    LCD_Write_DATA(y2 >> 8);
    LCD_Write_DATA(y2 & 0xff);
    LCD_Write_COM(0x2C);
    break;
