#include <Arduino.h>
#include "Maix_Speech_Recognition.h"
#include "voice_model.h"
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define PIN_SDA 31
#define PIN_SCL 30

//U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // Adafruit Feather ESP8266/32u4 Boards + FeatherWing OLED

SpeechRecognizer rec;

void setup() 
{
    rec.begin();
    delay(1000);
    Serial.begin(115200);
    /*
    Serial.println("start rec...");
    if( rec.record(0, 0) == 0) //keyword_num, model_num 
    {    
        Serial.println("done rec...");
      rec.print_model(0, 0);
    }
    else
    { 
        Serial.println("rec failed");
    }
    */
    //while(1) {};

    Wire.begin();
    //Serial.begin(9600);
    pinMode(PIN_LED_BLUE, OUTPUT);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_RED, OUTPUT);
    digitalWrite(PIN_LED_BLUE, HIGH);
    digitalWrite(PIN_LED_GREEN, HIGH);
    digitalWrite(PIN_LED_RED, HIGH);

    //u8g2.begin();

    Serial.println("init model...");
    rec.addVoiceModel(0, 0, odin_0, frm_num_odin_0); 
    rec.addVoiceModel(0, 1, odin_1, frm_num_odin_1); 
    rec.addVoiceModel(0, 2, odin_2, frm_num_odin_2); 
    rec.addVoiceModel(0, 3, odin_3, frm_num_odin_3); 
    rec.addVoiceModel(1, 0, dva_0, frm_num_dva_0);     
    rec.addVoiceModel(1, 1, dva_1, frm_num_dva_1);     
    rec.addVoiceModel(1, 2, dva_2, frm_num_dva_2);     
    rec.addVoiceModel(1, 3, dva_3, frm_num_dva_3);     
    rec.addVoiceModel(2, 0, tri_0, frm_num_tri_0);   
    rec.addVoiceModel(2, 1, tri_1, frm_num_tri_1);   
    rec.addVoiceModel(2, 2, tri_2, frm_num_tri_2);   
    rec.addVoiceModel(2, 3, tri_3, frm_num_tri_3);    
    Serial.println("init model ok!");
}

void loop() 
{
    int res;
    res = rec.recognize();
    Serial.printf("res : %d ", res);
    if (res <= 0)
    {
        Serial.println("recognize failed.");
    }

    // u8g2.clearBuffer();					// clear the internal memory
    // u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
    // u8g2.setCursor(0, 10);
    // u8g2.print(millis());
    // u8g2.sendBuffer();					// transfer internal memory to the display

    Serial.println(millis());
    digitalWrite(PIN_LED_BLUE, LOW);
    delay(500);
    digitalWrite(PIN_LED_BLUE, HIGH);
    delay(500);

/*
    Serial.println ("I2C scanner. Scanning ...");
    byte count = 0;

    for (byte i = 8; i < 120; i++)
    {
        Wire.beginTransmission (i);
        if (Wire.endTransmission () == 0)
        {
            Serial.print ("Found address: ");
            Serial.print (i, DEC);
            Serial.print (" (0x");
            Serial.print (i, HEX);
            Serial.println (")");
            count++;
            //delay (1);  // maybe unneeded?
        } // end of good response
    } // end of for loop
    Serial.println ("Done.");
    Serial.print ("Found ");
    Serial.print (count, DEC);
    Serial.println (" device(s).");
    */
// put your main code here, to run repeatedly:
}