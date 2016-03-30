#ifndef FIGURE_H
#define FIGURE_H

#include "Option.hpp"

class Figure {
private:
	int x, y, z, t;
	Option fig_opt;

public:
	Figure();
	Figure(int x1, int y1, int z1, int t1);

	int getX() {return x;};
	int getY() {return y;};
	int getZ() {return z;};
	int getT() {return t;};

	void set_option(int col, int epaisseur, bool remp, int rot, double opacite);
	void setOption(Option opt) { fig_opt= opt; };
};

#endif
