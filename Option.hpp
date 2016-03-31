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

	int get_col() const { return col;};
	int get_epaisseur() const { return epaisseur;};
	bool get_remp() const {return remp;};
	double get_rot() const { return rot;};
	bool get_opacite() const { return opacite;};

	void set_col(int color);
	void set_epaisseur(int ep);
	void set_remp(bool r);
	void set_rot(int ro);
	void set_opacite(double o);

};

#endif
