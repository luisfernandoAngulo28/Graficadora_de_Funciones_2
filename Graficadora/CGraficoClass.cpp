//---------------------------------------------------------------------------

#pragma hdrstop

#include "CGraficoClass.h"
#include <math.h>
#include <string>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Cgrafico::Cgrafico(){

}
void Cgrafico::Crear(int vcx, int vcy, int Vup, float dx){
 Cx=vcx;
 Cy=vcy;
 Upuntos=Vup;
 Dx=dx;
}
void Cgrafico::DibujarEje(TForm *pantalla){
	int lx = pantalla->Width;
	int ly = pantalla->Height;
	//this->Cx = lx/2;
	//this->Cy = ly/2;
	pantalla->Canvas->Pen->Width=2;
	pantalla->Canvas->MoveTo(Cx,0);
	pantalla->Canvas->LineTo(Cx,ly);
	pantalla->Canvas->MoveTo(0,Cy);
	pantalla->Canvas->LineTo(lx,Cy);
	int i;
	for (i = 0; i < lx; i=i+Upuntos) {
	  pantalla->Canvas->Pen->Width=2;
	  pantalla->Canvas->MoveTo(Cx+i,Cy-(Upuntos/2));
	  pantalla->Canvas->LineTo(Cx+i,Cy+(Upuntos/2));
	  pantalla->Canvas->MoveTo(Cx-i,Cy-(Upuntos/2));
	  pantalla->Canvas->LineTo(Cx-i,Cy+(Upuntos/2));
	}
	for (i = 0; i < ly; i=i+Upuntos) {
	  pantalla->Canvas->Pen->Width=2;
	  pantalla->Canvas->MoveTo(Cx-(Upuntos/2),Cy+i);
	  pantalla->Canvas->LineTo(Cx+(Upuntos/2),Cy+i);
	  pantalla->Canvas->MoveTo(Cx-(Upuntos/2),Cy-i);
	  pantalla->Canvas->LineTo(Cx+(Upuntos/2),Cy-i);
	}
}
void Cgrafico::DibujarPunto(TForm *pantalla, float x, float y, int color){
  float  vRx, vRy;
	vRx = Cx + (x*Upuntos);
	vRy = Cy - (y*Upuntos);
	pantalla->Canvas->Pixels[vRx][vRy] = clBlue;
}
double Cgrafico::Fx(float x){
 return P.Tabulacion(x);
}
void Cgrafico::GraficarFuncion(TForm *pantalla, int a, int b){
  float x,y;
 //DibujarEje(pantalla);
	x=a;
	while (x<=b){
	 y=Fx(x);
	 DibujarPunto(pantalla, x,y,clBlue);
	 x=x+Dx;
	}
}
void Cgrafico::Insertar_termino(int coef, int exp){
  P.Ponertermino(coef,exp);
}
void Cgrafico::MostrarPol(TLabel *pol){
  String cad="";
  for (int i =1; i<=P.numero_terminos() ; i++) {
		cad=IntToStr(P.Coeficiente(P.Exponente(i)))+"x^"+ IntToStr(P.Exponente(i))+"+"+cad;
  }
  cad="F(x)="+cad ;
  int aux=cad.Length();
  cad.Delete(aux,1);

  pol->Caption=cad;
}
void Cgrafico::DefinirEje(int x, int y)
{  Cx=x;
   Cy=y;
}
float Cgrafico::CalcularArea(int a, int b){
  return P.Area(a,b);
}
void Cgrafico::MostrarArea(TLabel *pol){
	String cad="";
	int a;
	int b;
	cad=StrToInt(P.Area(a,b));
}

