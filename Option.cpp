#include "Option.hpp"

Option::Option()
	:col(0), epaisseur(0), remp(true), rot(0), opacite(0.0), is_full(false)
{
}

Option::Option(int c, int e, bool r, int ro, double o)
	:col(c), epaisseur(e), remp(r), rot(ro), opacite(o), is_full(true)
{

}

Option::Option(const Option& op)
{
	col= op.col;
	epaisseur= op.epaisseur;
	remp= op.remp;
	rot= op.rot;
	opacite= op.opacite;
	is_full= true;
}

void Option::set_col(int color){
	col= color;
}

void Option::set_epaisseur(int e){
	epaisseur= e;
}

void Option::set_remp(bool r){
	remp= r;
}

void Option::set_rot(int ro){
	rot= ro;
}

void Option::set_opacite(double o){
	opacite= o;
}


