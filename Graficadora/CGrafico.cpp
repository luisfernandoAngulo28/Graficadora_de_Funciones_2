//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CGrafico.h"
#include "CGraficoClass.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Cgrafico g;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

   int cx = StrToInt(InputBox("Insertar Cx","Cx",""));
   int cy= StrToInt(InputBox("Insertar Cy","Cy",""));
   int up= StrToInt(InputBox("Insertar Dato","Upuntos",""));
   float dx= StrToFloat(InputBox("Insertar Dato","Dx",""));
   g.Crear(cx,cy,up,dx);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   int a = StrToInt(InputBox("Insertar Dato","Coeficiente",""));
   int b = StrToInt(InputBox("Insertar Dato","exponente",""));
  g.Insertar_termino(a,b);
  g.MostrarPol(Label1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   int x = StrToInt(InputBox("Insertar Eje X","Eje X",""));
   int y = StrToInt(InputBox("Insertar Eje Y","Eje Y",""));
   g.DefinirEje(x,y);
   g.DibujarEje(Form1);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
g.MostrarPol(Label1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
     Form1->Canvas->Refresh();
   //Form1->Canvas->Pen->Width=2;
   	//pantalla->Canvas->Pen->Width=2;
   //Form1->Canvas->MoveTo(vRx, vRy);
   //Form1->Canvas->LineTo(Cx,vRy);
   int a = StrToInt(InputBox("Insertar Dato","Inicio",""));
   int b = StrToInt(InputBox("Insertar Dato","Fin",""));
   g.GraficarFuncion(Form1, a,b);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
int a = StrToInt(InputBox("Insertar Dato","imite inferior",""));
   int b = StrToInt(InputBox("Insertar Dato","imite inferior",""));
   Edit1->Text=g.CalcularArea(a,b);
   g.MostrarArea(Label2);


   //float a=StrToFloat(Edit1->Text);
   //float b=StrToFloat(Edit2->Text);
   //float dx=StrToFloat(Edit1->Text);
   //Label2->Caption=g.MostrarArea(a,b,dx);

}
//---------------------------------------------------------------------------
