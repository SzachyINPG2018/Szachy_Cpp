/*
 * kolorki.h
 *
 *  Created on: 22.05.2018
 *      Author: Mariusz
 */

#ifndef KOLORKI_KOLORKI_H_
#define KOLORKI_KOLORKI_H_

#include <windows.h>
#include <string>


//#define


/* Wybierz kolor wed逝g poni窺zego kodu:
    *
    * Pierwszy znak odpowiada za kolor t豉 pod tekstem, drugi za kolor tekstu
    *
    * Kolory podstawowe
    *
    * 0 - czerwony
    * 1 - zielony
    * 2 - niebieski
    * 3 - czerwony + zielony = pomara鎍zowy
    * 4 - czerwony + niebieski = fioletowy
    * 5 - zielony + niebieski = 鄴速y
    * 6 - czerwony + zielony + niebieski = bia造
    *
    * Kolory jaskrawe
    *
    * 7 - czerwony jaskrawy
    * 8 - zielony jaskrawy
    * 9 - niebieski jaskrawy
    * A - czerwony jaskrawy + zielony jaskrawy = pomara鎍zowy
    * B - czerwony jaskrawy + niebieski jasrkawy = fioletowy jaskrawy
    * C - zielony jaskrawy + niebieski jaskrawy = 鄴速y jaskrawy
    * D - czerwony jaskrawy + zielony jaskrawy + niebieski jaskrawy = bia造 jaskrawy
    *
    * E - czarny

    */

void SetColor(std::string number);

#endif /* KOLORKI_KOLORKI_H_ */
