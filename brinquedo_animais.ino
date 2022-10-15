// Inclusão das Bibliotecas
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

//Inicia a serial para Módulo DFPlayer Mini e cria variável para controle do módulo
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

boolean run = false;
int botao = 0;
int sensor = 0;


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);

  
  // Comunicacao serial com o módulo
  mySoftwareSerial.begin(9600);
  
  // Inicializa a serial do Arduino
  Serial.begin(115200);
  
  // Verifica se o módulo está conectado e se cartão SD foi inserido
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini"));
  Serial.println(F("Inicializando módulo DFPlayer..."));
  if (!myDFPlayer.begin(mySoftwareSerial))
  {
    Serial.println(F("Não inicializado:"));
    Serial.println(F("- Verifique se módulo foi corretamente conectado ou"));
    Serial.println(F("- Insira um cartão SD"));
    while (true);
  }
  // Definições iniciais
  myDFPlayer.setTimeOut(500); //  Timeout serial 500ms
  myDFPlayer.volume(20);      //  Volume (de 0 até 30)
  myDFPlayer.EQ(0);           //  Equalização normal
  
  Serial.println();
  Serial.print("Número de arquivos no cartão: ");
  Serial.println(myDFPlayer.readFileCounts(DFPLAYER_DEVICE_SD)); 
  Serial.println();
  Serial.println(F("Módulo DFPlayer Mini inicializado corretamente!"));
}

void loop()
{

  sensor = digitalRead(3);
  botao = digitalRead(2);
  if(botao == HIGH)
  {
     digitalWrite(13,HIGH);
     delay(200);

     myDFPlayer.play(1);
     delay(2000);
     myDFPlayer.pause();

     digitalWrite(13, LOW);
     delay(200);

     digitalWrite(13,HIGH);
     delay(200);

      myDFPlayer.play(1);
     delay(2000);
     myDFPlayer.pause();

      digitalWrite(13, LOW);
     delay(200);

    }

  if(sensor == HIGH){
 
     digitalWrite(9,HIGH);
     delay(200);

     myDFPlayer.play(2);
     delay(2000);
     myDFPlayer.pause();

     digitalWrite(9, LOW);
     delay(200);

     digitalWrite(9,HIGH);
     delay(200);

     myDFPlayer.play(2);
     delay(2000);
     myDFPlayer.pause();

     digitalWrite(9, LOW);
     delay(200);
  }else{
    digitalWrite(9, LOW);
  }
  delay(10);
}
