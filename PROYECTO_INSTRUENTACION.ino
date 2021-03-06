float volt_analog;
int pin_rojo1 = 3;
int pin_rojo2 = 5;
int pin_amarillo1 = 6;
int pin_amarillo2 = 9;
int pin_verde1 = 10;
int pin_verde2 = 11;
float volt_analog_v;
float Volumen_maximo=5.403e-3; //Volumen del recipiente

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pin_rojo1, OUTPUT);
pinMode(pin_rojo2, OUTPUT);
pinMode(pin_amarillo1, OUTPUT);
pinMode(pin_amarillo2, OUTPUT);
pinMode(pin_verde1, OUTPUT);
pinMode(pin_verde2, OUTPUT);
pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
volt_analog = analogRead (A0);
volt_analog_v = (volt_analog*5)/1023;
float altura = 0.033*volt_analog_v;
float Volumen=(volt_analog_v*Volumen_maximo)/5;
Serial.print("Altura/Volumen: ");
Serial.print(altura, 7);
Serial.print("m");
Serial.print(" / ");
Serial.print(Volumen,7);
Serial.println("m^3");

//Serial.println(volt_analog_v);
if (volt_analog_v <= 0){
  analogWrite(pin_rojo1, HIGH);
  analogWrite(pin_rojo2, LOW);
  analogWrite(pin_amarillo1, LOW);
  analogWrite(pin_amarillo2, LOW);  
  analogWrite(pin_verde1, LOW);
  analogWrite(pin_verde2, LOW);  
  delay(1000);
}
if (0 < volt_analog_v && volt_analog_v <=0.833){
  analogWrite(pin_rojo1, HIGH);
  analogWrite(pin_rojo2, HIGH);
  analogWrite(pin_amarillo1, LOW);
  analogWrite(pin_amarillo2, LOW);  
  analogWrite(pin_verde1, LOW);
  analogWrite(pin_verde2, LOW);  
  delay(1000);
}
if (0.833 < volt_analog_v && volt_analog_v < 1.67){
  analogWrite(pin_rojo1, HIGH);
  analogWrite(pin_rojo2, HIGH);
  analogWrite(pin_amarillo1, HIGH);
  analogWrite(pin_amarillo2, LOW);  
  analogWrite(pin_verde1, LOW);
  analogWrite(pin_verde2, LOW);  
  delay(1000);
}
if (1.67 < volt_analog_v && volt_analog_v < 2.499){
  analogWrite(pin_rojo1, HIGH);
  analogWrite(pin_rojo2, HIGH);
  analogWrite(pin_amarillo1, HIGH);
  analogWrite(pin_amarillo2, HIGH);  
  analogWrite(pin_verde1, LOW);
  analogWrite(pin_verde2, LOW);
  delay(1000);
}
if (2.499 < volt_analog_v && volt_analog_v <= 3.332){
  analogWrite(pin_rojo1, HIGH);
  analogWrite(pin_rojo2, HIGH);
  analogWrite(pin_amarillo1, HIGH);
  analogWrite(pin_amarillo2, HIGH);  
  analogWrite(pin_verde1, HIGH);
  analogWrite(pin_verde2, LOW);
  delay(1000);
}
if (3.334 < volt_analog_v && volt_analog_v < 5){
  analogWrite(pin_rojo1, HIGH);
  analogWrite(pin_rojo2, HIGH);
  analogWrite(pin_amarillo1, HIGH);
  analogWrite(pin_amarillo2, HIGH);  
  analogWrite(pin_verde1, HIGH);
  analogWrite(pin_verde2, HIGH);
  delay(1000);
}
}
