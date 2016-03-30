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

std::vector<Figure>::iterator it;
for(it= liste_fig.begin(); it != liste_fig.end(); ++it){
	std::cout << "Je parcours les figures !" << std::endl;
}
pe.setWidth(5);
p.setBrush(QColor(255,0,0));
pe.setBrush(QColor(255,0,0));
p.setPen(pe);
p.drawRect(QRect(10,15,20,25));
p.rotate(45);
p.setOpacity(0.5);

}


