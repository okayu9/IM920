#pragma once
#include "Arduino.h"

class IM920{
public:
	IM920(uint8_t busy_pin, void (*receive)(uint8_t node, uint16_t id, uint8_t rssi, uint8_t* data));
    void     setWritable(boolean);
    uint16_t readID();
    void     setNodeNum(uint8_t);
    uint8_t  readNodeNum();
    void     setTxID(uint16_t);
    uint16_t* readTxID();//TODO
    void     eraseTxID();
    void     setCH(uint8_t);
    uint8_t  readCH();
    void     sendData(uint8_t*);
    uint8_t  readRSSI();
    void     setPower(uint8_t);
    uint8_t  readPower();
    void     setRate(uint8_t);
    uint8_t  readRate();
    void     setBaud(uint8_t);//TODO
    void     setSleep(boolean);
    void     reboot();
    void     reset();
    boolean  check();
private:
	uint8_t busy_pin;
	void (*receive)(uint8_t node, uint16_t id, uint8_t rssi, uint8_t* data);
	void skipToLF();
	void waitNbyte(uint8_t);
	uint8_t char2num(uint8_t);
	uint8_t serial2num();
	uint16_t serial4num();
	void waitBusy();
};
