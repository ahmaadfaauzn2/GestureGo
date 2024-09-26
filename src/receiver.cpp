#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define enA 9  
#define in1 2
#define in2 3
#define enB 10   
#define in3 4
#define in4 5

RF24 radio(7,8); // CE, CSN
const byte address[6] = "00001";
char receivedData[32] = "";
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int joystick[2];
int z0 = 3000;
int zstop = 13000;
int y0 = 10000;

//Deklarasi library dan pin


// Deklarasi untuk menggerakan motor driver dari data yang didapat

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
 
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void loop() {
 
  if (radio.available()) {   // If the NRF240L01 module received data
	 
	radio.read( joystick, sizeof(joystick) );

	radio.read(&receivedData, sizeof(receivedData));
    
	AcX = joystick[0];
	AcY = joystick[1];


//Konversi data gyro sensor mpu6050 ke moto driver untuk menentukan arah gerakan robot

if(AcX<-6000){  	//Forward
    
	Serial.print("	Forward	");
	digitalWrite(enA, HIGH);
	digitalWrite(enB, HIGH);
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  }
  else if(AcX>6000){  //BACK
    
	Serial.print("	BACK	");
	digitalWrite(enA, HIGH);
	digitalWrite(enB, HIGH);
	digitalWrite(in2, HIGH);
	digitalWrite(in1, LOW);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);
  }

  else if(AcY<-6000 ){    	///LEFT
    
	Serial.print("	LEFT	");
	digitalWrite(enA, HIGH);
	digitalWrite(enB, HIGH);
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
  }
  else if(AcY>6000){    	//RIGHT
    
	Serial.print("	RIGHT	");
	digitalWrite(enA, HIGH);
	digitalWrite(enB, HIGH);
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
  }

else if(AcX<6000 && AcX>-6000 && AcX<6000 && AcX>-6000 ) 
{  //Stop
	Serial.print("	Stop   ");
	digitalWrite(enA, LOW);
	digitalWrite(enB, LOW);
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  }
//  Membuat motor driver berhenti



  }
}

//Koneksi antara nrf dan melakukan penerimaan data lalu diterjemahkan dari sensor mpu6050 ke motor driver

// OUTPUT
//-----------------------------

	// Serial.print("AcX :");
	// Serial.print(AcX);
	// Serial.print("	");
	// Serial.print("AcY :");
	// Serial.print(AcY);

	// delay(300);
//-----------------------------



