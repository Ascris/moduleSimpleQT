#include "parser.tab.cpp"
#include "monDessin.h"

#include <QtGui>
#include <QApplication>

#include <iostream>

using namespace std;

int main ( int argc , char ** argv )
{

FILE * fic = nullptr;
	
if(argc > 1) {
	fic = fopen(argv[1], "r");
	if(fic) yyin = fic;
}

QApplication app(argc,argv);
QMainWindow * w = new QMainWindow;
trace(w);
return app.exec();
}
