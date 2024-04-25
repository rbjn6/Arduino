//**Programme pour un robot arduino afin de lui permmettre d'avancer, de reculer, de tourner et d'agir en fonctoion de son environement.**



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
void avancer()  //Fonction pour avancer tout droit à la vitesse maximale
{
  digitalWrite(moteurG, LOW);  //Initialisation du sens de rotation du moteur gauche (ici vers l'avant)
  digitalWrite(brakeG, LOW);   // Enclenchement ou non du frein du moteur gauche ( ici non enclenché)
  analogWrite(3,255);          //Initialisation de la vitesse de rotation du moteur Gauche (ici au max :255)
  digitalWrite(moteurD, LOW);  //Initialisation du sens de rotation du moteur droit (ici vers l'avant)
  digitalWrite(brakeD, LOW);   // Enclenchement ou non du frein du moteur droit ( ici non enclenché)
  analogWrite(11,255);         //Initialisation de la vitesse de rotation du moteur Droit (ici au max : 255)
}

void gauche()  //Fonction pour tourner à gauche en avançant
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, HIGH);
  analogWrite(3,0);
  digitalWrite(moteurD, LOW);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}
void droite()  //Fonction pour tourner à droite en avançant
{
  digitalWrite(moteurG, LOW);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, HIGH);
  analogWrite(11,0);
}
void reculer()  //Fonction pour reculer tout droit à la vitesse maximale
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}
void reculerG()  //Fonction pour tourner à gauche en reculant
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, HIGH);
  analogWrite(3,0);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}
void obstacleG()  //Fonction pour faire 1/4 de demi tour à gauche en reculant 
{
  reculerG();
  delay(300);
}
void reculerD()  //Fonction pour tourner à droite en reculant
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, HIGH);
  analogWrite(11,0);
}
void obstacleD()  //Fonction pour faire 1/4 de demi tour à droite en reculant 
{
  reculerD();
  delay(300);
}
//------------------FONCTIONS POUR LES DEPLACEMENTS SUR PLACE------------------
void arreter()  //Fonction pour mettre le vehicule à l'arrêt
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, HIGH);
  analogWrite(3,0);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, HIGH);
  analogWrite(11,0);
}
void pivoterGauche()  //Fonction pour pivoter à gauche tout en restant au même endroit 
{
  digitalWrite(moteurG, HIGH);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, LOW);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);
}
void pivoterDroite()  //Fonction pour pivoter à droiter tout en restant au même endroit 
{
  digitalWrite(moteurG, LOW);
  digitalWrite(brakeG, LOW);
  analogWrite(3,255);
  digitalWrite(moteurD, HIGH);
  digitalWrite(brakeD, LOW);
  analogWrite(11,255);

}
void pivoterGauche25()  //Fonction pour pivoter de 1/4 de tour à gauche tout en restant au même endroit 
{
  pivoterGauche();
  delay(180);
}
void pivoterGauche50()  //Fonction pour pivoter de 180° à gauche tout en restant au même endroit 
{
  pivoterGauche();
  delay(360);
}
void pivoterGauche100()  //Fonction pour pivoter de 360° à gauche tout en restant au même endroit 
{
  pivoterGauche();
  delay(720);
}
void pivoterDroite25()  //Fonction pour pivoter de 1/4 de tour à Droite tout en restant au même endroit 
{
  pivoterDroite();
  delay(180);
}
void pivoterDroite50()  //Fonction pour pivoter de 180° à droite tout en restant au même endroit 
{
  pivoterDroite();
  delay(360);
}
void pivoterDroite100()  //Fonction pour pivoter de 360° à gauche tout en restant au même endroit 
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

