#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "Delay.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"



u8 * itoa(u32 val, u32 base){

	static u8 buf[32] = {0};

	u32 i = 30;

	for(; val && i ; --i, val /= base)

		buf[i] = "0123456789abcdef"[val % base];

	return &buf[i+1];

}







void LCD_voidInitalize (void)
{
	
  delay_ms(40);
  LCD_voidWriteCmd(0b00111000);
  delay_ms(1);
  LCD_voidWriteCmd(0b00001111);
  delay_ms(1);
  LCD_voidWriteCmd(0b00000001);
  delay_ms(2);
	
	
}	




 void LCD_voidWriteCmd(u8 Copy_u8Command)
{

	DIO_u8SetPinValue (RS_PIN  , COMMAND_MODE );
    DIO_u8SetPinValue (RW_PIN  , LCD_u8_WRITE ); 
    DIO_u8SetPinValue (	d0 ,  get_bit(Copy_u8Command,0)  );
	DIO_u8SetPinValue (	d1 ,  get_bit(Copy_u8Command,1)  );
	DIO_u8SetPinValue (	d2 ,  get_bit(Copy_u8Command,2)   );
	DIO_u8SetPinValue (	d3 ,  get_bit(Copy_u8Command,3)   );
	DIO_u8SetPinValue (	d4 ,  get_bit(Copy_u8Command,4)   );
	DIO_u8SetPinValue (	d5 ,  get_bit(Copy_u8Command,5)   );
	DIO_u8SetPinValue (	d6 ,  get_bit(Copy_u8Command,6)   );
	DIO_u8SetPinValue (	d7 ,  get_bit(Copy_u8Command,7)   );
	DIO_u8SetPinValue  (E_PIN,ENABLE);
	delay_ms(2);
	DIO_u8SetPinValue   (E_PIN,DISENABLE);
	

	
}


 void  LCD_VoidWritechar(u8 Copy_u8Data)
{
	

	DIO_u8SetPinValue (RS_PIN  , DATA_MODE );
    DIO_u8SetPinValue (RW_PIN  , LCD_u8_WRITE ); 

    DIO_u8SetPinValue (	d0 ,  get_bit(Copy_u8Data,0)    );
	DIO_u8SetPinValue (	d1 ,  get_bit(Copy_u8Data,1)  );
	DIO_u8SetPinValue (	d2 ,  get_bit(Copy_u8Data,2)   );
	DIO_u8SetPinValue (	d3 ,  get_bit(Copy_u8Data,3)   );
	DIO_u8SetPinValue (	d4 ,  get_bit(Copy_u8Data,4)    );
	DIO_u8SetPinValue (	d5 ,  get_bit(Copy_u8Data,5)   );
	DIO_u8SetPinValue (	d6 ,  get_bit(Copy_u8Data,6)   );
	DIO_u8SetPinValue (	d7 ,  get_bit(Copy_u8Data,7)   );


	DIO_u8SetPinValue  (E_PIN,ENABLE);
	delay_ms(1);
	DIO_u8SetPinValue  (E_PIN,DISENABLE);
	
	
	
	
}






u8 LCD_u8Write (u8 *Copy_u8Data , u8 Copy_XPos , u8 Copy_YPos)
{
	u8 Local_u8Result = 0;

	if ( (Copy_XPos < LCD_u8_Col_Num) && (Copy_YPos < LCD_u8_Row_Num))
	{

         u8 Local_u8DdramADD=  Copy_XPos + ( Copy_YPos * 0x40);
		  Local_u8DdramADD =  Local_u8DdramADD | 0x80;
		  LCD_voidWriteCmd( Local_u8DdramADD);
		  while (*Copy_u8Data != '\0')
		  {
			  if ( Local_u8DdramADD == 0x90)
			  {
				  Local_u8DdramADD = 0xC0;
				  LCD_voidWriteCmd(Local_u8DdramADD);
				  
			  }	  
			  else if (Local_u8DdramADD== 0xD0)
			  {
				   Local_u8DdramADD = 0x80;
				   LCD_voidWriteCmd(Local_u8DdramADD);
			  }  
			  LCD_VoidWritechar(*Copy_u8Data);
			  Copy_u8Data ++;
			  Local_u8DdramADD++;
		  }	  
		  
	}
	else
	{
		  Local_u8Result = 1;
	}
	
	return Local_u8Result;
}
	
void LCD_writeintegar ( u32 Copy_nb ,u8 Copy_XPos,u8 Copy_YPos )
{
	if (Copy_nb == 0)
	{
		LCD_u8Write ("0", Copy_XPos , Copy_YPos);
	}else
	{
	u8 * buff  ;
	buff =itoa (Copy_nb,10);
	LCD_u8Write (buff , Copy_XPos , Copy_YPos);
	}

}
