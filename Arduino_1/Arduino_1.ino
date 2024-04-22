//____________DECLARATION DES VARIABLES EN LIEN AVEC LES MOTEURS____________
const int moteurG=12;
const int brakeG=9;

const int moteurD=13;
const int brakeD=8;

//-----------DECLARATION DES VARIABLES EN LIEN AVEC LES MOUSTACHES-----------
const int Moustache=1;

//----------------SETUP----------------
void setup() {
  //Setup Channel G
  pinMode(moteurG, OUTPUT); //Initiates Motor Channel G pin
  pinMode(brakeG, OUTPUT); //Initiates Brake Channel G pin

  //Setup Channel D
  pinMode(moteurD, OUTPUT); //Initiates Motor Channel D pin
  pinMode(brakeG, OUTPUT);  //Initiates Brake Channel D pin
}

//------------------FONCTIONS POUR LES MOTEURS------------------
void avancer()
{
  digitalWrite(moteurG, LOW);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, LOW);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}

void gauche()
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, HIGH);
  analogWrite(3,0);
  digitalWrite(moteurD, LOW);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}
void droite()
{
  digitalWrite(moteurG, LOW);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, HIGH);
  analogWrite(11,0);
}
void reculer()
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}
void arreter()
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, HIGH);
  analogWrite(3,0);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, HIGH);
  analogWrite(11,0);
}
void pivoterGauche()
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, LOW);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}
void pivoterDroite()
{
  digitalWrite(moteurG, LOW);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);

}
void pivoterGauche25()
{
  pivoterGauche();
  delay(900);
}
void pivoterGauche50()
{
  pivoterGauche();
  delay(1800);
}
void pivoterGauche100()
{
  pivoterGauche();
  delay(3600);
}
void pivoterDroite25()
{
  pivoterDroite();
  delay(900);
}
void pivoterDroite50()
{
  pivoterDroite();
  delay(1800);
}
void pivoterDroite100()
{
  pivoterDroite();
  delay(3600);
}

//---------------BOUCLE---------------
void loop() {
  pivoterGauche100();
  arreter();
  delay(500);

}

}
