/***************************************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA
                                                                                                                          */
/*DATE     : 3 MARCH 2019                                                                                                                             */
/*VERSION  : V01                                                                                                                                    */
/***************************************************************************************************************************************************/
/* DESCRIPTION                                                                                                                                       */
/*------------                                                                                                                                       */
/* this file defines the APIs corresponding to LCD                                                                                                    */
/*****************************************************************************************************************************************************/
#ifndef LCD_interface_h
#define LCD_interface_h
#define LCD_u8_READ                  1
#define LCD_u8_WRITE                 0

#define LCD_u8_Data                  1
#define LCD_u8_Command               0
#define DATA_MODE                    1
#define COMMAND_MODE                 0
#define ENABLE                       1
#define DISENABLE                    0
#define MODE4BIT                     4
#define MODE8BIT                     8
void LCD_voidInitalize (void);
u8   LCD_u8Write (u8 *Copy_u8Data , u8 Copy_XPos , u8 Copy_YPos);
void LCD_writeintegar ( u32 Copy_nb ,u8 Copy_XPos,u8 Copy_YPos );

#endif
