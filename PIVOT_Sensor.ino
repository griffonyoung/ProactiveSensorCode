const int CO_RL = 10 // needs to be calibrated
const int CO_R0 = 0 // determined during calibration

const int CH4_R5k =10 // needs calibrated
const int CH4_R3k = 10 //determined during calibration

void setup() {
  Serial.begin(115200); // Initialize serial communication

  pinMode(IO33, INPUT); //Carbon monoxide 
  pinMode(IO27, INPUT); //Methane 
  pinMode(IO32, INPUT); //Propane
  pinMode(IO35, INPUT); //Temperature
}

void loop() {
  float Tvoltage = analogRead(IO35); // Read the analog input
  float COvoltage = analogRead(IO33);

  float temp = (voltage - 0.5) * 100; //converts signal to temp in C

  Serial.print("Temp: ");
  Serial.print(temp, 2);
  Serial.println(" Celsius");

  float CO_Rratio = (5-COvoltage)/COvoltage * CO_RL / CO_RO; //converts signal to resistance ratio
  float COppm = log10(CO_Rratio/20.207659640165)/(-0.65275800920155); //converts ratio to ppm

  Serial.print("CO: ");
  Serial.print(COppm, 1);
  Serial.println(" ppm");



  
  delay(200); // Small delay to avoid flooding the serial monitor
}
