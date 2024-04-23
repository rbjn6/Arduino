//**Programme afin de programmer un robot arduino et lui permmettre d'avancer, reculer, tourner et d'agir en fonctoion de son environement.**



//____________DECLARATION DES VARIABLES EN LIEN AVEC LES MOTEURS____________
const int moteurG=12;
const int brakeG=9;

const int moteurD=13;
const int brakeD=8;

//-----------DECLARATION DES VARIABLES EN LIEN AVEC LES MOUSTACHES-----------
const int moustache1=6;
const int moustache2=7;

//----------------SETUP----------------
void setup() {
  //Setup Channel G
  pinMode(moteurG, OUTPUT); //Initiates Motor Channel G pin
  pinMode(brakeG, OUTPUT); //Initiates Brake Channel G pin

  //Setup Channel D
  pinMode(moteurD, OUTPUT); //Initiates Motor Channel D pin
  pinMode(brakeG, OUTPUT);  //Initiates Brake Channel D pin

  //Setup Moustaches 
  pinMode(moustache1, INPUT_PULLUP);
  pinMode(moustache2, INPUT_PULLUP);

}

//------------------FONCTIONS POUR LES DEPLACEMENTS DE BASE------------------
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
void reculerG()
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, HIGH);
  analogWrite(3,0);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}
void obstacleG()
{
  reculerG();
  delay(300);
}
void reculerD()
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, HIGH);
  analogWrite(11,0);
}
void obstacleD()
{
  reculerD();
  delay(300);
}
//------------------FONCTIONS POUR LES DEPLACEMENTS SUR PLACE------------------
void arreter()
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, HIGH);
  analogWrite(3,0);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, HIGH);
  analogWrite(11,0);
}
void pivoterGauche() //pivoter a gauche en restant au meme endroit 
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, LOW);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}
void pivoterDroite() //pivoter a droite en restant au meme endroit 
{
  digitalWrite(moteurG, LOW);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);

}
void pivoterGauche25() // 1/4 de tour a gauche
{
  pivoterGauche();
  delay(180);
}
void pivoterGauche50() // 180 a gauche
{
  pivoterGauche();
  delay(360);
}
void pivoterGauche100() //  360 a gauche
{
  pivoterGauche();
  delay(720);
}
void pivoterDroite25() // 1/4 de tour a droite
{
  pivoterDroite();
  delay(180);
}
void pivoterDroite50() //180 a droite
{
  pivoterDroite();
  delay(360);
}
void pivoterDroite100() //360 a droite
{
  pivoterDroite();
  delay(720);
}


//---------------BOUCLE---------------
void loop() {

  if (digitalRead(moustache1)==LOW){
    obstacleG();
    }

  else if (digitalRead(moustache2)==LOW){
    obstacleD();
  }

  avancer();
}

