#include "UI_Prozor.h"
#include "UI_Menager.h"

UI_Prozor::UI_Prozor()
{
}
UI_Prozor::~UI_Prozor()
{
	for(int i=0; i<elementi.size(); i++)
		delete elementi[i];
	elementi.clear();
}
void UI_Prozor::Init(UI_Menager* m, Vec2 poz, Vec2 dim, string naziv)
{
	this->manager=manager;
	this->poz=poz;
	this->dim=dim;
	this->naziv=naziv;
}
void UI_Prozor::Update(float deltaT, Vec2 mis)
{
	if(podignut==true)
	{
		poz.x+=mis.x-misPrije.x;
		poz.y+=mis.y-misPrije.y;
		misPrije=mis;
	}
	for(int i=0; i<elementi.size(); i++)
		elementi[i]->Update(deltaT);
}
void UI_Prozor::Render()
{
	//TIJELO PROZORA
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glColor3f(0.0, 0.25, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(poz.x, poz.y);
	glVertex2f(poz.x+dim.x, poz.y);
	glVertex2f(poz.x+dim.x, poz.y+dim.y);
	glVertex2f(poz.x, poz.y+dim.y);
	glEnd();
	glDisable(GL_BLEND);

	//NASLOVNICA (TRAKA)
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0); glVertex2f(poz.x, poz.y);
	glColor3f(0.0, 1.0, 0.0); glVertex2f(poz.x+dim.x, poz.y);
	glColor3f(0.0, 0.0, 0.0); glVertex2f(poz.x+dim.x, poz.y+16);
	glColor3f(0.0, 0.0, 0.0); glVertex2f(poz.x, poz.y+16);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);

	for(int i=0; i<elementi.size(); i++)
		elementi[i]->Render();
}

void UI_Prozor::LijeviKlik(Vec2 mis)
{
	if(mis.x>=poz.x && mis.y>=poz.y
		&& mis.y<poz.y+16 && mis.x<poz.x+dim.x)
	{
			podignut=true;
			misPrije=mis;
	}
	for(int i=0; i<elementi.size(); i++)
		elementi[i]->LijeviKlik(mis);
}
void UI_Prozor::LijeviOtpust(Vec2 mis)
{
	podignut=false;
	for(int i=0; i<elementi.size(); i++)
		elementi[i]->LijeviOtpust(mis);
}
void UI_Prozor::DesniKlik(Vec2 mis)
{
	for(int i=0; i<elementi.size(); i++)
		elementi[i]->DesniKlik(mis);
}
void UI_Prozor::DesniOtpust(Vec2 mis)
{
	for(int i=0; i<elementi.size(); i++)
		elementi[i]->DesniOtpust(mis);
}

void UI_Prozor::DodajElement(UI_Element* e)
{
	elementi.push_back(e);
}
vector<UI_Element*> UI_Prozor::DajElemente()
{
	return elementi;
}

UI_Menager* UI_Prozor::DajMenagera()
{
	return manager;
}