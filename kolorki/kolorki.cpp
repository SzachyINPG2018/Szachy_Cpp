/*
 * kolorki.c
 *
 *  Created on: 22.05.2018
 *      Author: Mariusz
 */

#include "kolorki.h"

void SetColor(std::string number)
{

    int color = 0;
    HANDLE hOut;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);


    switch (number[0]) {

    case '0':

        color += 0x40;
        break;

    case '1':

        color += 0x20;
        break;

    case '2':

        color += 0x10;
        break;

    case '3':

        color += 0x60;
        break;

    case '4':

        color += 0x50;
        break;

    case '5':

        color += 0x30;
        break;

    case '6':

        color += 0x70;
        break;

    case '7':

        color += 0xC0;
        break;

    case '8':

        color += 0xA0;
        break;

    case '9':

        color += 0x90;
        break;

    case 'A':

        color += 0xE0;
        break;

    case 'B':

        color += 0xD0;
        break;

    case 'C':

        color += 0xB0;
        break;

    case 'D':

        color += 0xF0;
        break;

    }

    switch (number[1]) {

    case '0':

        color += 0x4;
        break;

    case '1':

        color += 0x2;
        break;

    case '2':

        color += 0x1;
        break;

    case '3':

        color += 0x6;
        break;

    case '4':

        color += 0x5;
        break;

    case '5':

        color += 0x3;
        break;

    case '6':

        color += 0x7;
        break;

    case '7':

        color += 0xC;
        break;

    case '8':

        color += 0xA;
        break;

    case '9':

        color += 0x9;
        break;

    case 'A':

        color += 0xE;
        break;

    case 'B':

        color += 0xD;
        break;

    case 'C':

        color += 0xB;
        break;

    case 'D':

        color += 0xF;
        break;

    }

    SetConsoleTextAttribute(hOut, color);

}

