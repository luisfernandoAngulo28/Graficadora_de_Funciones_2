//---------------------------------------------------------------------------

#ifndef CGraficoClassH
#define CGraficoClassH
//---------------------------------------------------------------------------
#endif

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "CPolinomioPunt.h"
using namespace std;

class Cgrafico {
	private:
	 int Cx,Cy;  // Coordenadas X e Y
	 int Upuntos; // Unidades de puntos
	 float Dx;    // Incremento en X
	 void DibujarPunto(TForm *pantalla, float x, float y, int color); // Dibuja un punto en la pantalla
	 double Fx (float x);  // Calcula el valor de la funci�n en un punto dado
	 PolinomioP P;  // Objeto polinomio para almacenar t�rminos
	public:
	 Cgrafico();  // Constructor de la clase
	 void DibujarEje(TForm *paint);  // Dibuja los ejes X e Y en la pantalla
	 void Crear(int Cx, int Cy, int VUp,float Dx); // Configura los par�metros iniciales
	 void DefinirEje(int Cx1, int Cy2);  // Define el punto de origen del sistema de coordenadas
	 void DefinirUPuntos(int VUp); // Define la escala de unidades de puntos
	 void GraficarFuncion(TForm *, int a, int b);// Grafica la funci�n en un rango dado
	 void Insertar_termino(int coef, int exp); // Inserta un t�rmino en el polinomio
	 void MostrarPol(TLabel *); // Muestra el polinomio en una etiqueta de texto
	 void MostrarArea(TLabel *);  // Muestra el �rea calculada en una etiqueta de texto
	 float CalcularArea(int a, int b);  // Calcula el �rea bajo la curva en un rango dado
};
