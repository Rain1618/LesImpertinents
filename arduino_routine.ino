const int temperature_pin_a = A0;
const int smoke_pin_a = A1;
const int humidity_pin_a = A2;
const int gas_pin_a = A3;

const int motor_pin_d = 3;
const int button_pin_d = 4;

const int LOW_SPEED = 100;
const int HIGH_SPEED = 200;

bool fireActive = false; 

void setup() {
  Serial.begin(9600);
  pinMode(motor_pin_d, OUTPUT);
  pinMode(button_pin_d, INPUT_PULLUP); 
}

void loop() {
  if (fireActive) {
    delay(500);
    return;
  }

  if (1) {  // Check if there’s data to read
    byte cam_input = Serial.read();
    Serial.print("The cam input is: ");
    Serial.println(cam_input);

    int temperature_value = analogRead(temperature_pin_a);
    Serial.print("Temperature: ");
    Serial.print(temperature_value);
    Serial.println(" °C");

    int smoke_value = analogRead(smoke_pin_a);
    Serial.print("Smoke Sensor Value: ");
    Serial.println(smoke_value);

    int humidity_value = analogRead(humidity_pin_a);
    Serial.print("Humidity Sensor Value: ");
    Serial.println(humidity_value);

    int gas_value = analogRead(gas_pin_a);
    Serial.print("Gas Sensor Value: ");
    Serial.println(gas_value);

    if ((temperature_value < 265 && smoke_value > 700) || cam_input == 1) {
      Serial.println("🔥 FIRE DETECTED 🔥");
      fireActive = true;          
      extinguishFire();
      fireActive = false;           
    }
  }
  
  delay(2000);
}

void extinguishFire() {
  analogWrite(motor_pin_d, HIGH_SPEED); 

  Serial.println("Sprinkler ON");

  while (true) {
    int button_state = digitalRead(button_pin_d);
    if (button_state == LOW) { 
      break;
    }
    delay(100); 
  }

  analogWrite(motor_pin_d, 0);
  Serial.println("Sprinkler OFF");
}