#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#define decn;
void decision ()
{
	Digital();

	switch (DigVal)
	{
	case 0b000:
	decn='-';
	break;
	case 0b010:
	decn='I';
	break;
	case 0b011:
	decn='R';
	break;
	case 0b101:
	decn='T';
	break;
	case 0b110:
	decn='L';
	break;
	case 0b111:
	decn='+';
	break;
	}
}


