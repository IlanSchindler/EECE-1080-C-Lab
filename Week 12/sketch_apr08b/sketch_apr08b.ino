// Zumo general prereqs
#include <Wire.h>
#include <Zumo32U4.h>

// Global definitions
#define NUM_SENSORS 3
#define XY_ACCELERATION_THRESHOLD 2400  // for detection of contact (~16000 = magnitude of acceleration due to gravity)

Zumo32U4ButtonA buttonA;
Zumo32U4Buzzer buzzer;

// For the LCD config and OP
Zumo32U4LCD lcd;

// For the Line Sensor
Zumo32U4LineSensors lineSensors;
uint16_t line_sensor_values[NUM_SENSORS];

// For the proximity sensors
Zumo32U4ProximitySensors proxSensors;

// For the motor control
Zumo32U4Motors motors;

// For the motor encoders
Zumo32U4Encoders encoders;

// For the accelerometer
LSM303 compass;
L3G gyro;

// Function Prototype section:
/* LCD display function 
 *  INPUT: Two string, str1 prints on line 1 & str2 prints onto line 2.
 *  RETURN: void
 */
void lcdDisplay(String str1, String str2);

/* Line Sensor update function
 *  INPUT:  uint16_t threshold, used as a value to test against for a line
 *  RETURN: bool indicating if a line is present 
 *  GLOBAL: line_sensor_values[] values 
 */
bool updateLineSensors(uint16_t threshold);

/* Line Sensor update function
 *  INPUT:  uint16_t threshold, used as a value to test against for a line
 *  RETURN: bool indicating if a line is present 
 *  GLOBAL: line_sensor_values[] values 
 */
bool updateLineSensors(uint16_t threshold);

void setup() {
  // Setup the some basics
  Serial.begin(115200);
  Wire.begin();
  
  // Task #1: Print both members names onto the LCD screen.
  lcdDisplay("Cameron","Rishabh");

  // Initialize the QRT sensor array
  lineSensors.initThreeSensors();

  // Initialize the proximity sensor cluster
  proxSensors.initThreeSensors();

  // Setup the compass and gyro
  if (!compass.init())
  {
    // Failed to detect the compass.
    ledRed(1);
    while(1)
    {
      Serial.println(F("Failed to detect the compass."));
      delay(100);
    }
  }

  compass.enableDefault();

  if (!gyro.init())
  {
    // Failed to detect the gyro.
    ledRed(1);
    while(1)
    {
      Serial.println(F("Failed to detect gyro."));
      delay(100);
    }
  }

  gyro.enableDefault();

  // Press the "A" button to start
  buttonA.waitForButton(); // Wait indefinitely for the user to press the A button

  // Buzz on start
  buzzer.playFrequency(440, 200, 15);

  // 
  
}

void loop() {
    /* Step #1: Gather the line_sensor_values[] and determine if a line is present */
    bool edge = updateLineSensors(1000);            // 1000 is the preset threshold for the edge. Is this the best value?
    uint16_t left_sensor = line_sensor_values[0];   // Grab the left sensor
    uint16_t middle_sensor = line_sensor_values[1]; // Grab the middle sensor value
    uint16_t right_sensor = line_sensor_values[2];  // Grab the right sensor values

    /* Step #2: Gather the proximity sensor values and determine if a another robot is in sight. */
    proxSensors.read();
    int prox_left_front = proxSensors.countsFrontWithLeftLeds();
    int prox_right_front = proxSensors.countsFrontWithRightLeds();
    int prox_left = proxSensors.countsLeftWithLeftLeds();
    int prox_right = proxSensors.countsRightWithRightLeds();
    //Serial.println(prox_left_front);
    //Serial.println(prox_right_front);
    //Serial.println(prox_left);
    //Serial.println(prox_right);

    /* Step #3: Update the counts for the encoders */
    int16_t countsLeft = encoders.getCountsLeft();
    int16_t countsRight = encoders.getCountsRight();
    //Serial.println(countsLeft);
    //Serial.println(countsRight);

    /* Step #4: Read the compass and gyro readings */
    compass.read();
    gyro.read();
    int16_t gyro_x = gyro.g.x;
    int16_t gyro_y = gyro.g.y;
    int16_t gyro_z = gyro.g.z;
    //Serial.println(gyro_x);
    //Serial.println(gyro_y);
    //Serial.println(gyro_z);
    //Serial.println(compass.a.x);
    //Serial.println(compass.a.y);
    //Serial.println(compass.a.z);
    //Serial.println(compass.m.x);
    //Serial.println(compass.m.y);
    //Serial.println(compass.m.z);
    

    // Check for an edge first
    if(edge) {
      //Serial.println("Detected an edge!");          // Debug
      if(left_sensor > right_sensor) {
        motors.setSpeeds(300,-300);
        delay(50);
        //Serial.println("Turning right!");           // Debug
      }
      else {
        motors.setSpeeds(-300,300);
        delay(50);
        //Serial.println("Turning left!");            // Debug
      }
    }
    else {
      if(prox_right > 5) {
        motors.setSpeeds(-100,100);
        //Serial.println("Prox left!");            // Debug
      }
      else if(prox_left > 5) {
        motors.setSpeeds(100,-100);
        //Serial.println("Prox right!");           // Debug
      }
      else if(prox_left_front > 4 || prox_right_front > 4
      ){
        motors.setSpeeds(400,400);
        //Serial.println("Prox straight!");        // Debug
      }
      
    }
}

/* LCD display function */
void lcdDisplay(String str1, String str2) {
  
  // Clear the screen
  lcd.clear();

  // Print string number 1
  lcd.print(str1);

  // Go to the next line
  lcd.gotoXY(0, 1);

  // Print string number 1
  lcd.print(str2);
}

/* Line Sensor update function */
bool updateLineSensors(uint16_t threshold) {
  // Update the line_sensor_values
  lineSensors.read(line_sensor_values);

  // See if any of the sesnors are above the threshold
  if(line_sensor_values[0] >= threshold || line_sensor_values[1] >= threshold || line_sensor_values[2] >= threshold) {
    return true;
  }
  else {
    return false;
  }
}
