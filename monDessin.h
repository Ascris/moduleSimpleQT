#ifndef MONDESSIN_H
#define MONDESSIN_H

#include "Figure.hpp"

#include <QtGui>
#include <QMainWindow>

class monDessin:public QWidget
{
	Q_OBJECT

	private:
		std::vector<Figure> liste_fig;
		std::vector<int> which_figure;//0, 1 ou 2 pour rectangle, cercle ou ligne

	public:
		monDessin(QWidget * parent=0, Qt::WindowFlags flags=0);
		~monDessin();

		void setFigures(std::vector<Figure> liste){ liste_fig= liste;};
		void setWhichFigure(std::vector<int> which_fig){ which_figure= which_fig;};
		int getIdFigure(int indice) const { return which_figure[indice];};
		void paintEvent(QPaintEvent *);
		void draw() {update();}
};


#endif
