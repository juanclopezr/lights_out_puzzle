/*
 * max7219.h
 *
 *  Created on: Oct 20, 2016
 *      Author: irana
 */

#ifndef MAX7219_H_
#define MAX7219_H_

#define ADDR_NO_OP 0x00 // Direccion 0, representa la no operacion de la matriz
#define ADDR_DIG_0 0x01 // Direccion 1, representa la habilitacion para mandar el dato a la primera fila de la matriz
#define ADDR_DIG_1 0x02 // Direccion 2, representa la habilitacion para mandar el dato a la segunda fila de la matriz
#define ADDR_DIG_2 0x03 // Direccion 3, representa la habilitacion para mandar el dato a la tercera fila de la matriz
#define ADDR_DIG_3 0x04 // Direccion 4, representa la habilitacion para mandar el dato a la cuarta fila de la matriz
#define ADDR_DIG_4 0x05 // Direccion 5, representa la habilitacion para mandar el dato a la quinta fila de la matriz
#define ADDR_DIG_5 0x06 // Direccion 6, representa la habilitacion para mandar el dato a la sexta fila de la matriz
#define ADDR_DIG_6 0x07 // Direccion 7, representa la habilitacion para mandar el dato a la septima fila de la matriz
#define ADDR_DIG_7 0x08 // Direccion 8, representa la habilitacion para mandar el dato a la octaba fila de la matriz
#define ADDR_DECODE_MODE 0x09 // Direccion 9, representa la forma de decodificacion de los datos
#define ADDR_INTENSITY 0x0A // Direccion 10, representa la configuracion de la intensidad de encendido de los leds
#define ADDR_SCAN_LIMIT 0x0B // Direccion 11, representa la cantidad de leds habilitados para encender en una fila
#define ADDR_SHUTDOWN 0x0C // Direccion 12, representa el modo de conexion de los leds
#define ADDR_DISPLAY_TEST 0x0F // Direccion 13, representa em modo de operacion de la matriz

// Dato de configuracion para Direccion 9
#define NO_DECODE_7_0 			0x00
#define CODE_B_0_NO_DECODE_7_1 		0x01
#define CODE_B_3_0_NO_DECODE_7_4 	0x0F
#define CODE_B_7_0 0xFF

//Datos de configuracion para Direccion 10
#define INTENSITY_1_32 0x00
#define INTENSITY_3_32 0x01
#define INTENSITY_5_32 0x02
#define INTENSITY_7_32 0x03
#define INTENSITY_9_32 0x04
#define INTENSITY_11_32 0x05
#define INTENSITY_13_32 0x06
#define INTENSITY_15_32 0x07
#define INTENSITY_17_32 0x08
#define INTENSITY_19_32 0x09
#define INTENSITY_21_32 0x0A
#define INTENSITY_23_32 0x0B
#define INTENSITY_25_32 0x0C
#define INTENSITY_27_32 0x0D
#define INTENSITY_29_32 0x0E
#define INTENSITY_31_32 0x0F

//Datos de configuracion para Direccion 11
#define DIS_DIG_0 0x00
#define DIS_DIG_0_1 0x01
#define DIS_DIG_0_2 0x02
#define DIS_DIG_0_3 0x03
#define DIS_DIG_0_4 0x04
#define DIS_DIG_0_5 0x05
#define DIS_DIG_0_6 0x06
#define DIS_DIG_0_7 0x07

//Datos de configuracion para Direccion 12
#define SHUTDOWN_MODE 0x00
#define NORMAL_OPERATION 0x01

//Datos de configuracion para Direccion 13
#define NORMAL_OPETAION_MODE 0x00
#define DISPLAY_TEST_MODE 0x01

//Direcciones de salida en el GPIO
#define PIN_CLK_IDX 	0U //pin 0
#define PIN_CS_IDX 	1U //pin 1
#define PIN_DIN_IDX 	2U //pin 2


int OutputHigh_Din(int Portlog);


int Outputlow_Din(int Portlog);


int Outputlow_clk(int Portlog);

int OutputHigh_clk(int Portlog);


int Outputlow_cs(int Portlog);


int OutputHigh_cs(int Portlog);

int max7219_int (int datalog);

int max7219_senbit (int portlog,char bitvalue);

int  sen_2_byte_info(int portlog, char address, char data);














#endif /* MAX7219_H_ */
