#ifndef OPTION_H
#define OPTION_H

class Option {
private:
	int col;
	int epaisseur;
	bool remp;
	int rot;
	double opacite;
	bool is_full;

public:
	Option();
	Option(int c, int e, bool r, int ro, double o);
	Option(const Option& op);

	bool isFull() { return is_full;};

	void set_col(int color);
	void set_epaisseur(int ep);
	void set_remp(bool r);
	void set_rot(int ro);
	void set_opacite(double o);

};

#endif
