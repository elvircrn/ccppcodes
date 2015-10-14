#include "MinigunMob1.h"
#include "GlavnoStanje.h"
#include "MinigunProjektil.h"

void MinigunMob1::Init(Vec2 poz, GlavnoStanje* stanje, unsigned char** mapa)
{
	Mob::Init(poz,stanje,mapa);

	dim.x=64;
	dim.y=64;
	
	maxbrzina=250;	
	brzinaPunjenja=750;	
	domet=512;

	hp=35;
	textura=stanje->DajMT()->DajTexturu("mob1Diffuse.tga")->id;
	texturaN=stanje->DajMT()->DajTexturu("mob1Normal.tga")->id;
	texturaG=stanje->DajMT()->DajTexturu("mob3Glow.tga")->id;		
}
void MinigunMob1::Update(float deltaT)
{
	Mob::Update(deltaT);
	Pucanje(new MinigunProjektil(),deltaT);	
	Vec2 smjer;
	smjer=stanje->DajIgraca()->DajSredinu()-poz-Vec2(dim.x/2, dim.y/2);
	if(smjer.Duljina()<300)
	{
		brzina-=100*deltaT;
		if(brzina<0)
			brzina=0;
	}
	else
	{
		brzina+=100*deltaT;
		if(brzina>maxbrzina)
			brzina=maxbrzina;
	}
}
void MinigunMob1::Render(unsigned char stil)
{
	Mob::Render(stil);
}
void MinigunMob1::Pucanje(Projektil* p, float deltaT)
{	
	Mob::Pucanje(p,deltaT);	
}
void MinigunMob1::Unisti()
{
	sf::Sound* z = stanje->DodajZvuk(new sf::Sound(), stanje->DajMZ()->DajZvuk("Zvukovi/explozija1.wav"));		
	z->Play();	
	Mob::Unisti();
}
void MinigunMob1::PrimiStetu(Projektil* projektil)
{
	Mob::PrimiStetu(projektil);
}