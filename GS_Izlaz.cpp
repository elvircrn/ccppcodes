#include "GlavnoStanje.h"

void GlavnoStanje::Izlaz()
{
	IzbrisiFBO();	

	ObrisiMapu();

	for(int i=0; i<shaderi.size(); i++)
		delete shaderi[i];
	shaderi.clear();	
	for(int i=0; i<projektili.size(); i++)
		delete projektili[i];
	projektili.clear();
	for(int i=0; i<mobovi.size(); i++)	
		delete mobovi[i];	
	mobovi.clear();	
	for(int i=0; i<explozije.size(); i++)
		delete explozije[i];
	explozije.clear();
	for(int i=0; i<stvari.size(); i++)
		delete stvari[i];
	stvari.clear();
	for(int i=0; i<triggeri.size(); i++)
		delete triggeri[i];
	triggeri.clear();
	for(int i=0; i<cestice.size(); i++)
		delete cestice[i];
	cestice.clear();
	for(int i=0; i<zvukovi.size(); i++)	
	{
		zvukovi[i]->Stop();
		delete zvukovi[i];
	}
	zvukovi.clear();
	for(int i=0; i<svjetla.size(); i++)
		delete svjetla[i];
	svjetla.clear();	

	delete uim;

	for(int i=0; i<poruke.size(); i++)
		delete poruke[i];
	poruke.clear();
	fontovi.clear();	

	muzika.Stop();	

	delete kamera;
	
	mz->Brisi();
	mt->Brisi();	
	
	delete mz;
	delete mt;	
}

ManagerTextura* GlavnoStanje::DajMT()
{
	return mt;
}