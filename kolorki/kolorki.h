/*
 * kolorki.h
 *  skrypy wykorzystany:
 *
 *  1 maja 2015
 *  Waszek Gadu�a
 *  https://forum.pasja-informatyki.pl/16505/czy-da-sie-zmienic-kolor-tekstu-w-konsoli-c-i-jak
 *
 */

#ifndef KOLORKI_KOLORKI_H_
#define KOLORKI_KOLORKI_H_

#include <windows.h>
#include <string>


//#define


/* Wybierz kolor wed�ug poni�szego kodu:
    *
    * Pierwszy znak odpowiada za kolor t�a pod tekstem, drugi za kolor tekstu
    *
    * Kolory podstawowe
    *
    * 0 - czerwony
    * 1 - zielony
    * 2 - niebieski
    * 3 - czerwony + zielony = pomara�czowy
    * 4 - czerwony + niebieski = fioletowy
    * 5 - zielony + niebieski = ��ty
    * 6 - czerwony + zielony + niebieski = bia�y
    *
    * Kolory jaskrawe
    *
    * 7 - czerwony jaskrawy
    * 8 - zielony jaskrawy
    * 9 - niebieski jaskrawy
    * A - czerwony jaskrawy + zielony jaskrawy = pomara�czowy
    * B - czerwony jaskrawy + niebieski jasrkawy = fioletowy jaskrawy
    * C - zielony jaskrawy + niebieski jaskrawy = ��ty jaskrawy
    * D - czerwony jaskrawy + zielony jaskrawy + niebieski jaskrawy = bia�y jaskrawy
    *
    * E - czarny

    */

void SetColor(std::string number);

#endif /* KOLORKI_KOLORKI_H_ */
