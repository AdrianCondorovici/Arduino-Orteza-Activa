//Definim pinii
#define en 2
#define pinM1_PWM 3
#define pinM1_S 4
#define pinM2_PWM 5
#define pinM2_S 7
#define pinM3_PWM 6
#define pinM3_S 8
#define pinM4_PWM 9
#define pinM4_S 12
#define pinS1 A0
#define pinS2 A1
#define pinS3 A3
#define pinS4 A4
const int pragL_s1 = 400;
const int pragU_s1 = 750;
const int pragL_s2 = 400;
const int pragU_s2 = 650;
const int pragL_s3 = 400;
const int pragU_s3 = 700;

const int pragL_s4 = 400;
const int pragU_s4 = 850;
const int valPWM = 255; //Viteza de executie
int valS1, valS2, valS3, valS4;
void setup() {
 Serial.begin(9600);

 //Setarea pinilor
 pinMode(en, OUTPUT);
 pinMode(pinM1_PWM, OUTPUT);
 pinMode(pinM1_S, OUTPUT);
 pinMode(pinM2_PWM, OUTPUT);
 pinMode(pinM2_S, OUTPUT);
 pinMode(pinM3_PWM, OUTPUT);
 pinMode(pinM3_S, OUTPUT);
 pinMode(pinM4_PWM, OUTPUT);
 pinMode(pinM4_S, OUTPUT);
 //Setari initiale
 analogWrite(pinM1_PWM, 0);
 digitalWrite(pinM1_S, LOW);
 analogWrite(pinM2_PWM, 0);
 digitalWrite(pinM2_S, LOW);
 analogWrite(pinM3_PWM, 0);
 digitalWrite(pinM3_S, LOW);
 analogWrite(pinM4_PWM, 0);
 digitalWrite(pinM4_S, LOW);
 digitalWrite(en, HIGH);
}
void loop() {
 citeste();
 transmite();
 comandaD1();
 comandaD2();
 comandaD3();
 comandaD4();
}
void citeste(){
 valS1 = analogRead(pinS1);
 valS2 = analogRead(pinS2);
 valS3 = analogRead(pinS3);
 valS4 = analogRead(pinS4);
}

void comandaD1(){
 //valoarea este sub pragul inferior
 if (valS1 < pragL_s1){
 digitalWrite(pinM1_S, HIGH);
 analogWrite(pinM1_PWM, 255 - valPWM);
 }
 //valoarea este intre praguri
 if (valS1 >= pragL_s1 && valS1 < pragU_s1){
 digitalWrite(pinM1_S, LOW);
 analogWrite(pinM1_PWM, 0);
 }
 //valoarea este peste pragul superior
 if (valS1 >= pragU_s1){
 digitalWrite(pinM1_S, LOW);
 analogWrite(pinM1_PWM, valPWM);
 }
}
void comandaD2(){
 //valoarea este sub pragul inferior
 if (valS2 < pragL_s2){
 digitalWrite(pinM2_S, HIGH);
 analogWrite(pinM2_PWM, 255 - valPWM);
}
 //valoarea este intre praguri
 if (valS2 >= pragL_s2 && valS2 < pragU_s2){
 digitalWrite(pinM2_S, LOW);
 analogWrite(pinM2_PWM, 0);
}
 //valoarea este peste pragul superior
 if (valS2 >= pragU_s2){
 digitalWrite(pinM2_S, LOW);
 analogWrite(pinM2_PWM, valPWM);
 }
}
void comandaD3(){
 //valoarea este sub pragul inferior
 if (valS3 < pragL_s3){
 digitalWrite(pinM3_S, HIGH);
 analogWrite(pinM3_PWM, 255 - valPWM);
 }
 //valoarea este intre praguri
 if (valS3 >= pragL_s3 && valS3 < pragU_s3){
 digitalWrite(pinM3_S, LOW);
 analogWrite(pinM3_PWM, 0);
 }


 //valoarea este peste pragul superior
 if (valS3 >= pragU_s3){
 digitalWrite(pinM3_S, LOW);
 analogWrite(pinM3_PWM, valPWM);
 }
}
void comandaD4(){
 //valoarea este sub pragul inferior
 if (valS4 < pragL_s4){
 digitalWrite(pinM4_S, HIGH);
 analogWrite(pinM4_PWM, 255 - valPWM);
 }
 //valoarea este intre praguri
 if (valS4 >= pragL_s4 && valS4 < pragU_s4){
 digitalWrite(pinM4_S, LOW);
 analogWrite(pinM4_PWM, 0);
 }
 //valoarea este peste pragul superior
 if (valS4 >= pragU_s4){
 digitalWrite(pinM4_S, LOW);
 analogWrite(pinM4_PWM, valPWM);
 }
}
void transmite(){
 Serial.print(valS1);
 Serial.print('\t');
 Serial.print(valS2);
 Serial.print('\t');
 Serial.print(valS3);
 Serial.print('\t');
 Serial.print(valS4);
 Serial.print('\t');
 Serial.print(pragL_s2);
 Serial.print('\t');
 Serial.println(pragU_s2);

}