/*
 * max7219.c
 *
 *  Created on: Oct 20, 2016
 *      Author: irana
 */
/*
 * max7219.c
 *
 *  Created on: Oct 20, 2016
 *      Author: irana
 */
#include "max7219.h"
#include <stdio.h>
#include <unistd.h>
#include "io.h"
#include "system.h"
#include "altera_up_avalon_parallel_port.h"

//Porlog: palbra que relaciona salida del GPIO 32 bits
//adress: Direccion de escritura para configuracion o dato 8 bits
// data:  Informacion a enviar para la direccion (adress) seleccionda 8 bits


int OutputHigh_Din(int Portlog) // Salida en alto por el pin DIN enmascarado en  los 32 pines del GPIO
{
Portlog = Portlog | (1<<PIN_DIN_IDX);

IOWR(PARALLEL_PORT_0_BASE, ALT_UP_PARALLEL_PORT_DATA, Portlog); // funcion de la libreria io.h que permite escribir en la direccion del GPIO (PARALLEL_PORT_0_BASE), la informacion Portlog, ALT_UP_PARALLEL_PORT_DATA es parametro de dicha libreria.
return (Portlog);
}


int Outputlow_Din(int Portlog)// Salida en bajo por el pin DIN enmascarado en  los 32 pines del GPIO
{
Portlog = Portlog & ~(1<<PIN_DIN_IDX);

IOWR(PARALLEL_PORT_0_BASE, ALT_UP_PARALLEL_PORT_DATA, Portlog);
return (Portlog);
}



int Outputlow_clk(int Portlog)
{
Portlog = Portlog & ~(1<<PIN_CLK_IDX);

IOWR(PARALLEL_PORT_0_BASE, ALT_UP_PARALLEL_PORT_DATA, Portlog);
return (Portlog);
}


int OutputHigh_clk(int Portlog)
{
Portlog = Portlog | (1<<PIN_CLK_IDX);

IOWR(PARALLEL_PORT_0_BASE, ALT_UP_PARALLEL_PORT_DATA, Portlog);
return (Portlog);
}


int Outputlow_cs(int Portlog)
{
Portlog = Portlog & ~(1<<PIN_CS_IDX);

IOWR(PARALLEL_PORT_0_BASE, ALT_UP_PARALLEL_PORT_DATA, Portlog);

return (Portlog);
}
int OutputHigh_cs(int Portlog)
{
Portlog = Portlog | (1<<PIN_CS_IDX);

IOWR(PARALLEL_PORT_0_BASE, ALT_UP_PARALLEL_PORT_DATA, Portlog);

return (Portlog);
}



int max7219_int (int datalog) //Condiciones iniciales para empezar comunicacion.
{
datalog= Outputlow_clk(datalog);
datalog= Outputlow_Din(datalog);
datalog= OutputHigh_cs(datalog);
return (datalog);
}

int max7219_senbit (int portlog,char bitvalue) //Envio de informacion por pin DIN
{
if(bitvalue==1)
	{
	portlog=OutputHigh_Din(portlog);
	}
else
{
	portlog=Outputlow_Din(portlog);
}
	usleep(1);
	OutputHigh_clk(portlog); // Comportamiento de señal de Clock que determina el envio de informacion (1 bit).
	usleep(1);
	Outputlow_clk(portlog);

	return portlog;
}

int  sen_2_byte_info(int portlog, char address, char data)//Envio de palabra de 16 bits, en la cual se encuentra la direccion y dato correspondiente
{
	char i;
	Outputlow_cs(portlog);

	for (i=0;i<8;i++)
	{
		if ((address & (1<<(7-i))) != 0)
		{
			max7219_senbit(portlog,1);
		}
		else
		{
			max7219_senbit(portlog,0);
		}
	}
	for (i=0;i<8;i++)
		{
			if ((data & (1<<(7-i))) != 0)
			{
				max7219_senbit(portlog,1);
			}
			else
			{
				max7219_senbit(portlog,0);
			}

		}
	OutputHigh_cs(portlog);
	usleep(1);
	return portlog;
}




