%option nounput
%option yylineno

%{
#include <iostream>
#include <string>

#include "Figure.hpp"
#include "Option.hpp"
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Ligne.hpp"

#include "global.h"

#include "parser.tab.hpp"

extern "C" int yylex(void);
%}


blancs    		[ \t]+

chiffre   		[0-9]
entier    		{chiffre}+
variable  		_([a-z]|[A-Z])
rectangle		(r|R)(e|E)(c|C)(t|T)(a|A)(n|N)(g|G)(l|L)(e|E)
cercle			(c|C)(e|E)(r|R)(c|C)(l|L)(e|E)
ligne			(l|L)(i|I)(g|G)(n|N)(e|E)
nom_forme		({rectangle}|{cercle}|{ligne})
couleur	  		(rouge|vert|bleu|jaune|noir|blanc|gris)
remplissage	 	(vide|plein)

%%

{blancs}  { /* On ignore */ }

(?i:true) {yylval.valeur_numerique=1; return (NOMBRE);}
(?i:false) {yylval.valeur_numerique=0; return (NOMBRE);}

"fin" return(END);

{variable}				{yylval.indice_table_symboles=yytext[0];
							return(VARIABLE);
						}
{entier}				{std::cout << "NOMBRE" << std::endl; return(NOMBRE);}
{nom_forme}				{ std::cout << "NOM_FORME" << std::endl; return(NOM_FORME); }

{couleur}				{ std::cout << "COULEUR" << std::endl; return(COULEUR);
						}

{remplissage}			{ std::cout << "REMPLISSAGE" << std::endl; return(REMPLISSAGE);}

"="   {std::cout << "=" << std::endl; return(EGAL);}
","	  {std::cout << "," << std::endl; return(VIRGULE);}
"°"	  {std::cout << "°" << std::endl; return(DEGRE);}
"%"	  {std::cout << "%" << std::endl; return(POURCENT);}


"("   {std::cout << "(" << std::endl; return(PARENTHESE_OUVRANTE);}
")"   {std::cout << ")" << std::endl; return(PARENTHESE_FERMANTE);}
"{"	  {std::cout << "{" << std::endl; return(ACCOLADE_OUVRANTE);}
"}"	  {std::cout << "}" << std::endl; return(ACCOLADE_FERMANTE);}

"couleur" { std::cout << "mot couleur trouve" << std::endl; return(MOT_COULEUR);}
"rotation" { std::cout << "mot rotation trouve" << std::endl; return(MOT_ROTATION);}
"remplissage" { std::cout << "mot remplissage trouve" << std::endl; return(MOT_REMPLISSAGE);}
"epaisseur" { std::cout << "mot epaisseur trouve" << std::endl; return(MOT_EPAISSEUR);}
"opacite" { std::cout << "mot opacite trouve" << std::endl; return(MOT_OPACITE);}

"\n"  return(FIN);
