#ifndef COLORLINUX_H
#define COLORLINUX_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

//ColorText


#define DefaultColor 			"\033[39m"
#define WhiteText 				"\033[m"
#define WhiteTextBold 		    "\033[1m"
#define BlackText 				"\033[30m"
#define BlackTextBold 		    "\033[1;30m"
#define RedText 				"\033[31m"
#define RedTextBold 			"\033[1;31m"
#define GreenText 				"\033[32m"
#define GreenTextBold 		    "\033[1;32m"
#define OrangeText 				"\033[33m"
#define YellowText 				"\033[2;33m"
#define YellowTextBold 		    "\033[1;33m"
#define BlueText 				"\033[34m"
#define BlueTextBold 			"\033[1;34m"
#define MagentaText 			"\033[35m"
#define MagentaTextBold 	    "\033[1;35m"
#define CyanText 				"\033[36m"
#define CyanTextBold 			"\033[1;36m"
#define GreyText 				"\033[37m"
#define GreyTextBold 			"\033[1;37m"

//Color Background

#define BlackBG 				  "\033[40m"
#define RedBG 					  "\033[41m"
#define GreenBG 				  "\033[42m"
#define YellowBG 				  "\033[43m"
#define BlueBG 					  "\033[44m"
#define MagentaBG 			      "\033[45m"
#define CyanBG 					  "\033[46m"
#define GreyBG 					  "\033[47m"
#define DefaultBG 			      "\033[49m"

//Atributes

#define AtributeNone 			"\033[0m"
#define AtributeBold 			"\033[1m"
#define AtributeNormalColorSet 	"\033[2m"
#define AtributeUnderline 	    "\033[4m"
#define AtributeBlink 			"\033[5m"
#define AtributeReverse 		    "\033[7m"

//Cancel

#define NormalIntensive 	    "\033[22m"
#define CancelUnderline 	    "\033[24m"
#define CancelBlink 			"\033[25m"
#define CancelReverse 		    "\033[27m"

//Cursor

//???

#endif //COLORLINUX_H
