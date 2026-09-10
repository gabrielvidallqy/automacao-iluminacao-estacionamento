#include <Adafruit_NeoPixel.h>

// =====================================================
// CONFIGURAÇÃO DOS NEOPIXELS
// =====================================================

#define PIN_FITA_1 10
#define PIN_FITA_2 8
#define PIN_FITA_3 9

#define LEDS_FITA_1 10
#define LEDS_FITA_2 12
#define LEDS_FITA_3 12


// =====================================================
// CONFIGURAÇÃO DOS SENSORES
// =====================================================

#define SENSOR_1 2
#define SENSOR_2 3
#define SENSOR_3 4
#define SENSOR_4 5
#define SENSOR_5 6


// =====================================================
// TEMPO
// =====================================================

// 2 minutos = 120000 milissegundos

unsigned long TEMPO_LIGADO = 120000;


// Para testar rapidamente no Tinkercad:
//
// 10 segundos = 10000
// 30 segundos = 30000
// 1 minuto    = 60000
// 2 minutos   = 120000


// =====================================================
// CRIAÇÃO DOS NEOPIXELS
// =====================================================

Adafruit_NeoPixel fita1(
  LEDS_FITA_1,
  PIN_FITA_1,
  NEO_GRB + NEO_KHZ800
);

Adafruit_NeoPixel fita2(
  LEDS_FITA_2,
  PIN_FITA_2,
  NEO_GRB + NEO_KHZ800
);

Adafruit_NeoPixel fita3(
  LEDS_FITA_3,
  PIN_FITA_3,
  NEO_GRB + NEO_KHZ800
);


// =====================================================
// VARIÁVEIS DO TEMPORIZADOR
// =====================================================

unsigned long ultimaDeteccao = 0;

bool sistemaLigado = false;


// =====================================================
// LIGAR TODAS AS FITAS
// =====================================================

void ligarTodas()
{
  // Fita 1
  for (int i = 0; i < LEDS_FITA_1; i++)
  {
    fita1.setPixelColor(i, fita1.Color(255, 255, 255));
  }


  // Fita 2
  for (int i = 0; i < LEDS_FITA_2; i++)
  {
    fita2.setPixelColor(i, fita2.Color(255, 255, 255));
  }


  // Fita 3
  for (int i = 0; i < LEDS_FITA_3; i++)
  {
    fita3.setPixelColor(i, fita3.Color(255, 255, 255));
  }


  // Envia os dados para as fitas
  fita1.show();
  fita2.show();
  fita3.show();


  sistemaLigado = true;
}


// =====================================================
// DESLIGAR TODAS AS FITAS
// =====================================================

void desligarTodas()
{
  fita1.clear();
  fita2.clear();
  fita3.clear();

  fita1.show();
  fita2.show();
  fita3.show();

  sistemaLigado = false;

  Serial.println("Fitas desligadas.");
}


// =====================================================
// SETUP
// =====================================================

void setup()
{
  Serial.begin(9600);


  // ---------------------------------------------------
  // SENSORES
  // ---------------------------------------------------

  pinMode(SENSOR_1, INPUT);
  pinMode(SENSOR_2, INPUT);
  pinMode(SENSOR_3, INPUT);
  pinMode(SENSOR_4, INPUT);
  pinMode(SENSOR_5, INPUT);


  // ---------------------------------------------------
  // INICIALIZA OS NEOPIXELS
  // ---------------------------------------------------

  fita1.begin();
  fita2.begin();
  fita3.begin();


  // Brilho
  fita1.setBrightness(180);
  fita2.setBrightness(180);
  fita3.setBrightness(180);


  // Começar apagado
  desligarTodas();


  Serial.println("================================");
  Serial.println("SISTEMA INICIADO");
  Serial.println("================================");
  Serial.println("Qualquer sensor liga as 3 fitas.");
  Serial.println("Tempo: 2 minutos");
}


// =====================================================
// LOOP
// =====================================================

void loop()
{
  unsigned long agora = millis();

  bool movimento = false;


  // ===================================================
  // SENSOR 1
  // ===================================================

  if (digitalRead(SENSOR_1) == HIGH)
  {
    movimento = true;
    Serial.println("Sensor 1 detectou movimento.");
  }


  // ===================================================
  // SENSOR 2
  // ===================================================

  if (digitalRead(SENSOR_2) == HIGH)
  {
    movimento = true;
    Serial.println("Sensor 2 detectou movimento.");
  }


  // ===================================================
  // SENSOR 3
  // ===================================================

  if (digitalRead(SENSOR_3) == HIGH)
  {
    movimento = true;
    Serial.println("Sensor 3 detectou movimento.");
  }


  // ===================================================
  // SENSOR 4
  // ===================================================

  if (digitalRead(SENSOR_4) == HIGH)
  {
    movimento = true;
    Serial.println("Sensor 4 detectou movimento.");
  }


  // ===================================================
  // SENSOR 5
  // ===================================================

  if (digitalRead(SENSOR_5) == HIGH)
  {
    movimento = true;
    Serial.println("Sensor 5 detectou movimento.");
  }


  // ===================================================
  // QUALQUER SENSOR DETECTOU
  // ===================================================

  if (movimento == true)
  {
    // Liga as 3 fitas
    ligarTodas();


    // Reinicia o temporizador
    ultimaDeteccao = agora;


    Serial.println("TODAS AS FITAS LIGADAS.");
    Serial.println("Temporizador reiniciado.");
  }


  // ===================================================
  // VERIFICA O TEMPORIZADOR
  // ===================================================

  if (sistemaLigado == true)
  {
    if (agora - ultimaDeteccao >= TEMPO_LIGADO)
    {
      desligarTodas();
    }
  }


  delay(50);
}
