#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "RTClib.h"
// On an arduino UNO:       A4(SDA), A5(SCL)
RTC_DS3231 rtc;

char days[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);


void setup() {
  Serial.begin(115200); //시리얼 모니터 시작

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //OLED 시작

  if (! rtc.begin()) {
    Serial.println("Could not find RTC! Check circuit."); //rtc를 찾지 못했을때 출력
    while (1);
  }

  rtc.adjust(DateTime(__DATE__, __TIME__)); //RTC에 현재시간 넣어주기
  display.clearDisplay(); //화면 클리어
  display.setTextColor(WHITE);  //글씨 색 정하기
  display.setTextSize(2); //글씨크기
  display.setCursor(0, 5);  //글씨 좌표
  display.print("NONAMED"); //글씨 출력
  display.setCursor(0, 30);
  display.print("1414 ljy");
  display.display();
  delay(5000); //위에 글씨들을 5초간 보여준다
}

void loop() {
  DateTime now = rtc.now();
  display.clearDisplay();
  //display.setTextSize(3); //글씨 크기 정하기
  //display.setCursor(90, 25); //글씨 위치 정하기
  //display.println(now.second(), DEC); //글씨 출력
  //display.setTextSize(3);
  //display.setCursor(75, 25);
  //display.println(":");
  //display.setTextSize(3);
  //display.setCursor(30, 25);
  //display.println(":");
  //display.setTextSize(3);
  //display.setCursor(45, 25);
  //display.println(now.minute(), DEC);
  //display.setTextSize(3);
  //display.setCursor(0, 25);
  //display.println(now.hour(), DEC);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(now.year(), DEC);
  display.setTextSize(1);
  display.setCursor(67, 53);
  display.print(days[now.dayOfTheWeek()]);
  display.setTextSize(1);
  display.setCursor(26, 0);
  display.println("-");
  display.setTextSize(1);
  display.setCursor(34, 0);
  display.println(now.month(), DEC);
  display.setTextSize(1);
  display.setCursor(48, 0);
  display.println("-");
  display.setTextSize(1); 
  display.setCursor(56, 0);
  display.println(now.day(), DEC);
  display.display();
}
