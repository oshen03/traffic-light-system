// LED pin tika ardiuno board ekata ghanna oni widiha
//LED Outputs from uno board
#define TRAFFIC_RED 2
#define TRAFFIC_YELLOW 3
#define TRAFFIC_GREEN 4
#define PEDESTRIAN_RED 5
#define PEDESTRIAN_GREEN 6

// Millis kiyanne delay ekata
unsigned long previousMillis = 0;
const long interval = 1000; // milisecond dahak kiyanne thappara ekai
int count = -1; //-1 patan gaththe naththan hariyata sync wenne nh
//count is starting from -1 for proper syncronization

void setup() {
  // Led walata current denna me tika liyanna
  //initialization of LEDs 
  pinMode(TRAFFIC_RED, OUTPUT);
  pinMode(TRAFFIC_YELLOW, OUTPUT);
  pinMode(TRAFFIC_GREEN, OUTPUT);
  pinMode(PEDESTRIAN_RED, OUTPUT);
  pinMode(PEDESTRIAN_GREEN, OUTPUT);
  
  // LOW kalama LED off wenawa
  //Off stage of LEDs
  digitalWrite(TRAFFIC_RED, LOW);
  digitalWrite(TRAFFIC_YELLOW, LOW);
  digitalWrite(TRAFFIC_GREEN, LOW);
  digitalWrite(PEDESTRIAN_RED, LOW);
  digitalWrite(PEDESTRIAN_GREEN, LOW);
}

void loop() {
  unsigned long currentMillis = millis();//Delay function eka dannath puluwath eth eka set wenne nh
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    count = (count + 1) % 16;
    
    // Traffic Green wenakota Pedestrian eka Red 
    //pedestrian crossing is red when the traffic light is green
    if (count <= 6) {
      digitalWrite(TRAFFIC_GREEN, HIGH);
      digitalWrite(TRAFFIC_YELLOW, LOW);
      digitalWrite(TRAFFIC_RED, LOW);
      digitalWrite(PEDESTRIAN_RED, HIGH);
      digitalWrite(PEDESTRIAN_GREEN, LOW);
    }
    
    // Traffic Yellow weddith Pedestrian eka Red 
    //pedestrian crossing is stil red even if the traffic light is yellow
    else if (count <= 9) {
      digitalWrite(TRAFFIC_GREEN, LOW);
      digitalWrite(TRAFFIC_YELLOW, HIGH);
      digitalWrite(TRAFFIC_RED, LOW);
      digitalWrite(PEDESTRIAN_RED, HIGH);
      digitalWrite(PEDESTRIAN_GREEN, LOW);
    }
    
    // Traffic Red weddi Pedestrian Green wenna oni
    //pedestrian crossing is green when the traffic light is red
    else {
      digitalWrite(TRAFFIC_GREEN, LOW);
      digitalWrite(TRAFFIC_YELLOW, LOW);
      digitalWrite(TRAFFIC_RED, HIGH);
      digitalWrite(PEDESTRIAN_RED, LOW);
      digitalWrite(PEDESTRIAN_GREEN, HIGH);
    }
  }
}
