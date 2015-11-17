#pragma once
#include "Arduino.h"
#include "IM920.h"

IM920::IM920(uint8_t busy_pin): busy_pin(busy_pin){
    Serial.begin(19200);
    pinMode(busy_pin, INPUT);
}

void IM920::setWritable(boolean status){
	waitBusy();
	if(status){
		Serial.print("ENWR¥r¥n");
	}else{
		Serial.print("DSWR¥r¥n");
	}
	skipToLF();
}

uint16_t IM920::readID(){
	waitBusy();
	uint16_t id = serial4num();
	skipToLF();
	return id;
}

void IM920::setNodeNum(uint8_t nodeNum){
	waitBusy();
	Serial.print("STNN ");
	Serial.print(nodeNum, HEX);
	Serial.print("¥r¥n");
	skipToLF();
}

uint8_t IM920::readNodeNum(){
	waitBusy();
	uint8_t nodeNum = serial2num();
	skipToLF();
	return nodeNum;
}

void IM920::setTxID(uint16_t id){
	waitBusy();
	Serial.print("SRID ");
	Serial.print(id, HEX);
	Serial.print("¥r¥n");
	skipToLF();
}

uint16_t* IM920::readTxID(){
	waitBusy();
	//TODO
	return 0;
}

void IM920::eraseTxID(){
	waitBusy();
	Serial.print("ERID¥r¥n");
	skipToLF();
}

void IM920::setCH(uint8_t ch){
	waitBusy();
	Serial.print("STCH ");
	Serial.print(ch, DEC);
	skipToLF();
}

uint8_t IM920::readCH(){
	waitBusy();
	Serial.print("RDCH");
	uint8_t ch = serial2num();
	skipToLF();
	return ch;
}

void IM920::sendData(uint8_t* data, size_t len){
	waitBusy();
	Serial.print("TXDA ");
	for(size_t i=0; i<len; ++i){
		Serial.print(data[i], HEX);
	}
	Serial.print("¥r¥n");
	skipToLF();
}

uint8_t IM920::readRSSI(){
	waitBusy();
	Serial.print("RDRS¥r¥n");
	uint8_t rssi = serial2num();
	skipToLF();
	return rssi;
}

void IM920::setPower(uint8_t pwr){
	waitBusy();
	Serial.print("STPO ");
	Serial.print(pwr, HEX);
	Serial.print("¥r¥n");
	skipToLF();
}
uint8_t IM920::readPower(){
	waitBusy();
	Serial.print("RDPO¥r¥n");
	uint8_t pwr = serial2num();
	skipToLF();
	return pwr;
}
void IM920::setRate(uint8_t rate){
	waitBusy();
	Serial.print("STRT ");
	Serial.print(rate, DEC);
	Serial.print("¥r¥n");
	skipToLF();
}
uint8_t IM920::readRate(){
	waitBusy();
	Serial.print("RDRT¥r¥n");
	uint8_t rate = serial2num();
	skipToLF();
	return rate;
}
void IM920::setBaud(uint8_t baud){
	waitBusy();
	//TODO
}
void IM920::setSleep(boolean status){
	waitBusy();
	if(status){
		Serial.print("DSRX¥r¥n");
	}else{
		Serial.print("ENRX¥r¥n");
	}
	skipToLF();
}
void IM920::reboot(){
	waitBusy();
	Serial.print("SRST¥r¥n");
	skipToLF();
}
void IM920::reset(){
	waitBusy();
	Serial.print("PCLR¥r¥n");
	skipToLF();
}

void IM920::skipToLF(){
	while(Serial.read() != '¥n');
}

void IM920::waitNbyte(uint8_t n){
	while(Serial.available() < n);
}

uint8_t IM920::serial2num(){
	waitNbyte(2);
	uint8_t id2 = char2num(Serial.read());
	uint8_t id1 = char2num(Serial.read());
	return id2<<4 + id1;
}

uint16_t IM920::serial4num(){
	waitNbyte(4);
	uint16_t id4 = char2num(Serial.read());
	uint16_t id3 = char2num(Serial.read());
	uint16_t id2 = char2num(Serial.read());
	uint16_t id1 = char2num(Serial.read());
	return id4<<12 + id3<<8 + id2<<4 + id1;
}

uint8_t IM920::char2num(uint8_t c){
	if(c<48) return 0;
	if(c<=57) return c-48;
	if(c<65) return 0;
	if(c<=70) return c-55;
	return 0;
}

void IM920::waitBusy(){
	while(digitalRead(busy_pin));
}
