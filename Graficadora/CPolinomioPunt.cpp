//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPolinomioPunt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iostream>
#include <string>
#include <new>
#include <fstream>
#include<stdio.h>
#include <math.h>
using namespace std;
void PolinomioP::Crea(){
	PtrPoli=NULL;
	nt=0;
}
bool PolinomioP::EsCero(){
	bool res=false;
	if (nt==0){
		res=true;
	}
	return res;
}
void PolinomioP::Ponertermino(int coef,int exp){
  Nodo *lug=NULL;
  Nodo *aux=PtrPoli;
  Nodo *ant;
  while (aux!=NULL){
	 if (aux->Exp==exp) {
		 lug=aux;
		 aux=NULL;
	 }else{
          ant=aux;
		  aux=aux->sig;
     }
  }
  if (lug==NULL) {
	  Nodo *nuevo=new Nodo;
	  nuevo->Coef=coef;
	  nuevo->Exp=exp;
	  nuevo->sig=PtrPoli;
	  PtrPoli=nuevo;
	  nt=nt+1;

  }else{
	 lug->Coef=lug->Coef + coef;
	 if (lug->Coef==0) {
		  if (lug==PtrPoli) {
			 PtrPoli=PtrPoli->sig;
			 delete(lug);
			 nt=nt-1;
		  }else{
			  ant->sig=lug->sig;
			  delete(lug);
			  nt=nt-1;
		  }
	 }
  }
}
int PolinomioP::Grado(){
Nodo *aux;int may=0;
	if (!EsCero()) {
		 aux=PtrPoli;
		 may=aux->Exp;
		 while (aux!=NULL){
		   if (aux->Exp>may) {
			  may=aux->Exp;
		   }
		   aux=aux->sig;
		 }
	  return may;

	}else{
		cout<<"Grado: EL POLINOMIO ES CERO"<<endl;
		return NULL;
	}
}
int PolinomioP::Coeficiente(int exp){
Nodo *aux;
   if (EsCero()) {
	  cout<<"EL POLINOMIO ES CERO"<<endl;
	  return NULL;
   }else{
	   if (!(exp>=0 && exp<=Grado())) {
			 cout<<"Coeficiente: EL EXPONENTE NO ESTA EN EL POLINOMIO"<<endl;
			 return NULL;
	   }else{
		  aux=PtrPoli;
		  while(aux!=NULL) {
			  if (aux->Exp==exp) {
				  return aux->Coef;
			  }
			 aux=aux->sig;
		  }
          cout<<"Coeficiente: EL EXPONENTE NO ESTA EN EL POLINOMIO"<<endl;
		  return NULL;
       }
   }
}
float PolinomioP::Elevado(float base,int exp){
		return exp==0?1:(base*Elevado(base,exp-1));
}

int  PolinomioP::Exponente(int nroter){
	int c=0; Nodo *aux;
	 if (EsCero()) {
		cout<<"Exponente: POlINOMIO ES CERO"<<endl;
		return NULL;
	 }else{
		 aux=PtrPoli;
		 while (aux!=NULL)
		 {    c++;
			 if (c==nroter) {
			   return aux->Exp;
			 }
			 aux=aux->sig;
		 }
		cout<<"Exponente: NO EXISTE ESE NUMERO DE TERMINO"<<endl;
		return NULL;
     }
}
 void PolinomioP::Sumar(PolinomioP P1,PolinomioP P2, PolinomioP &P3)
{ Nodo *aux1=P1.PtrPoli;
  Nodo *aux2=P2.PtrPoli;
  int i=0;
  int k=0;
  int ex;int co;

		 while (aux1!=NULL){
			i=i+1;
			ex=P1.Exponente(i);
			co=P1.Coeficiente(ex);
			P3.Ponertermino(co,ex);
			aux1=aux1->sig;
		 }

		 while (aux2!=NULL){
			 k=k+1;
			ex=P2.Exponente(k);
			co=P2.Coeficiente(ex);
			P3.Ponertermino(co,ex);
			aux2=aux2->sig;
		 }

}

void PolinomioP::Restar(PolinomioP P1,PolinomioP P2, PolinomioP &P3)
{ Nodo *aux1=P1.PtrPoli;
  Nodo *aux2=P2.PtrPoli;
  int i=0;
  int k=0;
  int ex;int co;

		 while (aux1!=NULL){
			i=i+1;
			ex=P1.Exponente(i);
			co=P1.Coeficiente(ex);
			P3.Ponertermino(co,ex);
			aux1=aux1->sig;
		 }

		 while (aux2!=NULL){
			 k=k+1;
			ex=P2.Exponente(k);
			co=P2.Coeficiente(ex)*(-1);
			P3.Ponertermino(co,ex);
			aux2=aux2->sig;
		 }
}
void PolinomioP::Multiplicar(PolinomioP P1,PolinomioP P2, PolinomioP &P3)
{ Nodo *aux1;
  Nodo *aux2;
  int i=0; int ex1; int ex2; int ex3;
  int k=0; int co1;  int co2; int co3;
	 if (!P1.EsCero() && !P2.EsCero()) {
		aux2=P2.PtrPoli;
		  while (aux2!=NULL)  {
			   i++;
			   ex1= P2.Exponente(i);
			   co1= P2.Coeficiente(ex1);

			   aux1=P1.PtrPoli;
			   k=0;
			   while (aux1!=NULL){
				 k++;
				 ex2= P1.Exponente(k);
				 co2=P1.Coeficiente(ex2);
				 ex3= ex1+ex2;
				 co3=co1*co2;
				 P3.Ponertermino(co3,ex3);
				 aux1=aux1->sig;
			   }

			   aux2=aux2->sig;
		  }

	 }else{
		 cout<<"UN POLINOMIO ES CERO"<<endl;
	 }
}

void PolinomioP::Mostrar()
{
  Nodo *aux;
  int i=1;
  if (EsCero()) {
	 cout<<"Mostrar: EL POLINOMIO ES CERO"<<endl;
  } else{
	  aux=PtrPoli;
	  while (i<=numero_terminos()){
		 if (i!=numero_terminos()) {
		  cout<<aux->Coef<<"x"<<aux->Exp<<"+";
		  aux=aux->sig;
		  i++;
		 }else{
			 cout<<aux->Coef<<"x"<<aux->Exp<<endl;
			 i++;
         }

	  }
	  cout<<endl;
  }
}
float PolinomioP::Tabulacion(float x){
 float y=0;
 int exp,coef,i;
  for (i=1;i<=numero_terminos();i++){
	exp=Exponente(i);
	coef=Coeficiente(exp);
	 if (x!=0){
	  y=y+coef*(pow(x,exp));
	}
  }
 return y;
}

float PolinomioP::Area(int a,int b){
 float area=0,x=a,y=0;
  while (x<=b){
   y=Tabulacion(x);
	if (y<0){
	  y=y*-1;
	}
   area=area+(y*0.00001);
   x=x+0.00001;
  }
 return area;
}

void PolinomioP::Derivada()
{   Nodo *ant;
	Nodo *aux=PtrPoli;
	while (aux!=NULL){
	   aux->Coef=(aux->Coef)*(aux->Exp);
	   aux->Exp=(aux->Exp)-1;

		  if (aux->Coef==0) {
			  if (aux==PtrPoli) {
				   PtrPoli=PtrPoli->sig;
				   delete(aux);
				   aux=PtrPoli;
				   nt=nt-1;
			  }else{
				  ant->sig=aux->sig;
				  delete(aux);
				  aux=ant->sig;
              }
		  }else{
			  ant=aux;
			  aux=aux->sig;
          }
	}
}
int PolinomioP::numero_terminos(){
 return nt;
}
