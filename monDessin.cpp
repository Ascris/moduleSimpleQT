#include "monDessin.h"
#include <sstream>
#include <iostream>
using namespace std;

extern void trace(const char*);

monDessin::monDessin(QWidget * parent, Qt::WindowFlags flags)
:QWidget(parent,flags)
{

}

monDessin::~monDessin()
{

}


void monDessin::paintEvent(QPaintEvent *)
{
QPainter p(this);
QPen pe;

std::cout << "Dans PaintEvent 1!" << std::endl;

std::vector<Figure>::iterator it;
int i= 0;
for(it= liste_fig.begin(); it != liste_fig.end(); ++it){
	std::cout << "Figure : " << i << std::endl;
	int id_fig= getIdFigure(i);
	switch(id_fig){
	case 0:
		{
		int rx= (*it).getX();
		int ry= (*it).getY();
		int rz= (*it).getZ();
		int rt= (*it).getT();

		std::cout << "Coordonnees du rectangle = " << rx << " - " << ry << " - " << rz << " - " << rt << std::endl;

		std::cout << "rectangle detecte !" << std::endl;
		pe.setWidth((*it).getOption().get_epaisseur());
		p.setBrush(QColor(255,0,0));
		pe.setBrush(QColor(255,0,0));
		p.setPen(pe);
		
		p.drawRect(QRect(rx,ry,rz,rt));
		}
		break;
	case 1:
		{
		int rx= (*it).getX();
		int ry= (*it).getY();
		int rz= (*it).getZ();
		int rt= (*it).getT();

		std::cout << "Coordonnees du cercle = " << rx << " - " << ry << " - " << rz << " - " << rt << std::endl;

		std::cout << "cercle detecte !" << std::endl;
		pe.setWidth((*it).getOption().get_epaisseur());
		p.setBrush(QColor(0,255,0));
		pe.setBrush(QColor(0,255,0));
		p.setPen(pe);
		
		p.drawEllipse(QRect(rx,ry,rz,rt));
		}
		break;

	default:	
	{
		int rx= (*it).getX();
		int ry= (*it).getY();
		int rz= (*it).getZ();
		int rt= (*it).getT();

		std::cout << "Coordonnees de la ligne = " << rx << " - " << ry << " - " << rz << " - " << rt << std::endl;

		std::cout << "ligne detectee !" << std::endl;
		pe.setWidth((*it).getOption().get_epaisseur());
		p.setBrush(QColor(0,0,255));
		pe.setBrush(QColor(0,0,255));
		p.setPen(pe);
		
		p.drawLine(QLine(rx,ry,rz,rt));
		}
		break;
	}

	++i;
}
pe.setWidth(5);
p.setBrush(QColor(255,0,0));
pe.setBrush(QColor(255,0,0));
p.setPen(pe);
p.drawRect(QRect(10,15,20,25));
p.rotate(45);
p.setOpacity(0.5);

}


