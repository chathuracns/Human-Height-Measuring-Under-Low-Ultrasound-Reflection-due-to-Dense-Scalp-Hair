#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 OLED = Adafruit_SSD1306(128, 64, &Wire);

bool first = true;
bool ditected = false;
float initial = 0.0;
float something = 0.0;
const int trigPin = 6;  // Trig pin of the ultrasonic sensor
const int echoPin = 7;  // Echo pin of the ultrasonic sensor
long duration = 0;
float Prevdistance = 0.0;
float distance = 0.0;
int count = 1;
int count1 = 1;
int count2 = 1;
int count3 = 1;
int count1pro = 1;
int count2pro = 1;
float clustr1 = 250.0;
float clustr2 = 0.0;
float clustr1pro = 0.0;
float clustr2pro = 0.0;
float var = 0.0;
float happy = 2.5;
float minimum = 250.0;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  // Triggering the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reading the echo duration
  duration = pulseIn(echoPin, HIGH);
  Prevdistance = distance;
  distance = duration * 0.034725 / 2;
  //Serial.print(distance);

  // Serial.print(" ");


  if (first == true) {
    if (distance < 250 && distance > 150) {
      initial = (initial * (count - 1) + distance) / count;
      count = count + 1;
      //Serial.print(distance);
      //Serial.println("initializing");
      OLED.clearDisplay();
      OLED.setTextColor(WHITE);

      OLED.setTextSize(2);
      OLED.setCursor(33, 20);
      OLED.print(initial);
      OLED.display();
      if (count == 50) {
        count = 1;
        first = false;
        //initial = 196;
        OLED.clearDisplay();
        OLED.display();
      }
    }
    delay(100);
  } else {
    if (ditected == false) {
      if (abs(initial - distance) > 100) {
        something = (something * (count - 1) + something) / count;
        count = count + 1;
        //Serial.print(distance);
        //Serial.println("something");
        if (abs(initial - something) > 10 && count > 2) {  //#############################################
          count = 1;
          something = 0;
          ditected = true;
          clustr1 = initial;
          clustr1pro = initial;
        }
        delay(100);
      } else if (abs(initial - distance) < 10) {
        //Serial.print(distance);
        //Serial.println("nothing");
        count = 1;
        delay(2000);
      } else {
        //Serial.print(distance);
        //Serial.println("lts see");
        delay(500);
      }
    }


    else {
      //Serial.println("detected");
      if (250.0 < distance || abs(Prevdistance - distance) > 5) {
        //Serial.print(distance);
        //Serial.print("/");
        count3 = count3 + 1;
      } else if (abs(clustr1 - distance) < abs(distance - clustr2)) {
        clustr1 = (clustr1 * (count1 - 1) + distance) / count1;
        count1 = count1 + 1;
        //Serial.print(distance);
        //Serial.print(",");
        if (abs(clustr1 - distance) < 6) {
          clustr1pro = (clustr1pro * ((count1pro - 1) + 50) + distance) / (count1pro + 50);
          //Serial.print(distance);
          //Serial.print(",");
          count1pro = count1pro + 1;
        }
      } else {
        clustr2 = (clustr2 * (count2 - 1) + distance) / count2;
        count2 = count2 + 1;
        var = (var * (count2 - 1) + abs(clustr2 - distance)) / count2;
        //Serial.print(distance);
        //Serial.print("  ");
        if (abs(clustr2 - distance) < 2) {
          clustr2pro = (clustr2pro * (count2pro - 1) + distance) / count2pro;
          count2pro = count2pro + 1;
          //Serial.print(distance);
          //Serial.print(" ");
        }
      }
      if(minimum > distance){
        minimum = distance;
      }
      
      if (var < 0.5) {
        happy = 0;
      } else if (var < 5) {
        happy = 4.5;
      } else {
        happy = 6.5;
      }
      OLED.clearDisplay();
      OLED.setTextColor(WHITE);

      OLED.setTextSize(2);
      OLED.setCursor(90, 0);
      OLED.print(count);

      OLED.setTextSize(1);
      OLED.setCursor(50, 0);
      OLED.print(clustr1);

      OLED.setTextSize(2);
      OLED.setCursor(50, 26);
      OLED.print((float)count2pro / count2 * 100);

      OLED.setTextSize(2);
      OLED.setCursor(60, 50);
      OLED.print(var);

      /*OLED.setTextSize(1);
      OLED.setCursor(63, 0);
      OLED.print(count1);*/

      OLED.setTextSize(1);
      OLED.setCursor(1, 6);
      OLED.print(initial - minimum );
      
      OLED.setTextSize(1);
      OLED.setCursor(1, 26);
      OLED.print(initial - clustr2pro );
      
      OLED.setTextSize(1);
      OLED.setCursor(1, 46);
      OLED.print(initial - clustr2);

      
      /*OLED.setTextSize(1);
      OLED.setCursor(90, 50);
      OLED.print(initial);*/

      /*OLED.setTextSize(1);
      OLED.setCursor(80, 50);
      OLED.print(clustr2pro);*/

      OLED.display();

      if ((count1 > 5 && count2pro > 30) || count1 > 1000 || count2 > 100) {

        //Serial.print("first: ");
        //Serial.print(first);
        //Serial.print(", detected: ");
        //Serial.print(ditected);
        //Serial.print(", initial: ");
        //Serial.print(initial);
        //Serial.print(", something: "); Serial.print(something);
        //Serial.print(", Prevduration: "); Serial.print(Prevduration);
        //Serial.print(", duration: "); Serial.print(duration);
        //Serial.print(", ----distance: ");
        //Serial.print(distance);
        //Serial.print(", count: "); Serial.print(count);
        //Serial.print("------, count1: ");
        //Serial.print(count1);
        //Serial.print(", count1pro: ");
        //Serial.print(count1pro);
        //Serial.print(",---- count2: ");
        //Serial.print(count2);
        //Serial.print(", count2pro: ");
        //Serial.print(count2pro);
        //Serial.print("------, clustr1: ");
        //Serial.print(clustr1);
        //Serial.print(", clustr1pro: ");
        //Serial.print(clustr1pro);
        //Serial.print(",---- clustr2: ");
        //Serial.print(clustr2);
        //Serial.print(", clustr2pro:");
        //Serial.println(clustr2pro);
        //Serial.print("200cm error percentage: ");
        //Serial.println((float)count1pro / count1 * 100);
        //Serial.print("40cm error percentage: ");
        Serial.println(initial);
        Serial.println(initial - minimum );
        Serial.println(initial - clustr2pro );
        Serial.println(initial - clustr2 );
        Serial.println((float)count2pro / count2 * 100);
        Serial.println(count3);
        Serial.println(var);
        //Serial.println(var/count) ;
        delay(10000);
        OLED.clearDisplay();
        OLED.display();
        delay(3000);
        count = 1;
        count1 = 1;
        count2 = 1;
        count3 = 1;
        count1pro = 1;
        count2pro = 1;
        duration = 0;
        Prevdistance = 0;
        clustr1 = 0;
        clustr2 = 0;
        clustr1pro = 0;
        clustr2pro = 0;
        var = 0;
        ditected = false;
        happy = 2.5;
        minimum = 250;
      }

      if (count == 100) {
        //Serial.println("000");
        //Serial.println(var/count) ;
        delay(0);
        //count = 1;
      }
      //Serial.println("##");
      count = count + 1;
      delay(10 );//+ 5*pow(-1,count)  );
    }
  }
}