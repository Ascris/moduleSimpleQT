#include <vector>
#include <map>

typedef struct typegeneral
{
	double valeur_numerique;
	char indice_table_symboles;
	int entier;
	std::string texte;
	bool booleen;

	Figure figure;
	Option opt;

} typegeneral;

#define YYSTYPE typegeneral

extern YYSTYPE yylval;
