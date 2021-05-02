#include <WiFi.h>
#include "DHT.h"
#include <HTTPClient.h>
#define DHTPIN 22     // DHT sensor pin
float h = 0;
float t = 0;
// Replace with your network credentials
const char* ssid     = "staffkktmpj";
const char* password = "5t@fFp!123";

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);
// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

void setup() {
  Serial.begin(115200);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
  dht.begin();
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
    h = dht.readHumidity();
    t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    h = random(60,78);
    t = random(28,31);
  }

  HTTPClient http;
  //send channel data with data reference name and data for example: temp=32
  //You can send multiple data separated by & for example: temp=32$hum=67
  //To request remote controllers data, send: ctrl=led1,led2(ref name)
  //dont forget to include api(api key) and id (device id)
  
  //Example url for channel data and controllers data both can be requested at the same http request url
  //replace API_KEY and DEVICE_ID with your own at io.circuits.my 
  //any api request will be using api.circuits.my
  String httpData = "http://10.73.99.82/iot/api.php?userid=M2ZDTDSY52&temperature=" + String(t) + "&humidity=" + String(h);

  String led1_value = ""; //payload value for led1
  String led2_value = ""; //payload value for led2
  
  http.begin(httpData); //Specify the URL
  int httpResponsCode = http.GET(); //Make the request
  if (httpResponsCode > 0) { //Check for the returning code
    
    String payload = http.getString();
    
    if (payload.indexOf("led1") != -1){
      led1_value = payload.substring(payload.indexOf("led1=")+5,payload.indexOf(",")); //capture and parse led1 value
      Serial.print("led1: ");
      Serial.println(led1_value);
      //control LED on pin 4
    if(led1_value.indexOf("ON") != -1)digitalWrite(4,HIGH);
    if(led1_value.indexOf("OFF") != -1)digitalWrite(4,LOW);
    }
    

    if (payload.indexOf("led2") != -1){
      led2_value = payload.substring(payload.indexOf("led2=")+5,payload.indexOf(",0")); //capture and parse led1 value
      //control LED on pin 2
      Serial.print("led2: ");
      Serial.println(led2_value);
    if(led2_value.indexOf("ON") != -1)digitalWrite(2,HIGH);
    if(led2_value.indexOf("OFF") != -1)digitalWrite(2,LOW);
    }

   
    Serial.println(httpResponsCode);
    Serial.println(payload);
  }

  else {
    Serial.println("Error on HTTP request");
  }

  http.end(); //Free the resources
  delay(3000);
}
