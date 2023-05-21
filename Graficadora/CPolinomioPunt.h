//---------------------------------------------------------------------------

#ifndef CPolinomioPuntH
#define CPolinomioPuntH
//---------------------------------------------------------------------------
#endif
#include <fstream>
#include <iostream>
#include<math.h>
using namespace std;
 struct Nodo {
	int Coef;
	int	Exp;
	Nodo *sig;
};
class PolinomioP{
	private:
		int nt;
		Nodo *PtrPoli;

	public:
		void Crea();
		bool EsCero();
		void Ponertermino(int coef,int exp);
		int Grado();
		int Coeficiente(int exp);
		void Sumar(PolinomioP,PolinomioP,PolinomioP&);
		void Restar(PolinomioP,PolinomioP,PolinomioP&);
		void Multiplicar(PolinomioP,PolinomioP,PolinomioP&);
		int  Existe(int exp);
		void Mostrar();
		int numero_terminos();
		float Tabulacion(float valor);
		float Elevado(float base,int exp);
		int Exponente(int coef);
		float Area(int a, int b);
		void Derivada();

};
