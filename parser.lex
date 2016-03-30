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
variable  		([a-z]|[A-Z])
rectangle		(r|R)(e|E)(c|C)(t|T)(a|A)(n|N)(g|G)(l|L)(e|E)
cercle			(c|C)(e|E)(r|R)(c|C)(l|L)(e|E)
ligne			(l|L)(i|I)(g|G)(n|N)(e|E)
nom_forme		(rectangle|cercle|ligne)
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

{nom_forme}				{ std::cout << "nom_forme reconnue !" << std::endl; return(NOM_FORME); }

{couleur}				{ std::cout << "couleur reconnue !" << std::endl; return(COULEUR);
						}

{remplissage}			{ std::cout << "remplissage reconnue !" << std::endl; return(REMPLISSAGE);}

"="   return(EGAL);
","	  return(VIRGULE);
"°"	  return(DEGRE);

"("   return(PARENTHESE_OUVRANTE);
")"   return(PARENTHESE_FERMANTE);

"couleur" { std::cout << "couleur trouvee" << std::endl; return(MOT_COULEUR);}
"rotation" { std::cout << "rotation trouvee" << std::endl; return(MOT_ROTATION);}
"remplissage" { std::cout << "remplissage trouvee" << std::endl; return(MOT_REMPLISSAGE);}
"epaisseur" { std::cout << "epaisseur trouvee" << std::endl; return(MOT_EPAISSEUR);}
"opacite" { std::cout << "opacite trouvee" << std::endl; return(MOT_OPACITE);}

"\n"  return(FIN);
