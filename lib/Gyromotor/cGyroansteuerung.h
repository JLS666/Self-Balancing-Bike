/*
* File: selfbalancingbike.h
* Autor: AB, ML
* Date: 14.08.2018  
* Sources: 
* Content: Eine Header-Datei um auf alle Konstanten, Variablen und Funktion definieren, die f�r unser Fahrrad ben�tigt werden
* ToDo: Aufgabe						Bearbeiter		fertig/in Bearbeitung
*		Headeraufbau designen		JS & ML 		in Bearbeitung
*/	

#pragma once


/*************************************
			Includes
*************************************/


#include "ESP32_Servo.h"
#include <EEPROM.h>

/*************************************
			Konstanten
*************************************/

//	Gyroansteuerung

#define Gyro1PWMPin 23
#define Gyro2PWMPin 19
#define StandadGyroAnlauf 15
#define maxLeistung 100
#define verboteneZahl 6666

class cGyroansteuerung
{
  private:
  unsigned int beschleunigung= StandadGyroAnlauf; //Zeit für 1% Schritt in ms
  char sollLeistung, istLeistung;
  bool motorfreigabe=false; //0=Keine Freigabe
  long vorigeZeit=millis();
  Servo Gyro; 
  //EEPROM von Byte 0 bis 100 //Soll Drehzahl in 1/s Speichern

  public:
  cGyroansteuerung(char GyroPWMPin);
  bool setLeistung(char pSollLeistung);
  bool anlaufen(); //return 1 wenn fertig !!Andreung in Diagramm
  bool setBeschleunigung(char pBeschleunigung); //Zahl in s bis Gyro komplet von 0 auf 100
  void setMotorfreigabe(bool pMotorfreigabe);
  bool setLookupDrehzahl(unsigned int pDrehzahl);
  void setMachNeLookup(int pMessDrehzahl); //1/min
};

