#include "iostream"
#include "cstdlib"
#include "math.h"
#include "string"
#include "windows.h"
using namespace std;

struct Func {
     float A;
     float B;
     float C;
     float delta;
     float X1;
     float X2;
     string status;
};

struct Func me[10];

void  armazenar(int lin, float v1,float v2,float v3)
{
      me[lin].A = v1;
      me[lin].B = v2;
      me[lin].C = v3;
      
}

double lerA() 
{
   float A = 0;
   while(A == 0)
   {
   system("cls");
   cout << "Digite valor do coeficiente A da equação de segundo grau, diferente de 0: \n"; cin >> A;
   return A;
   }      
}

double lerB() 
{
   float B;
   system("cls");
   cout << "Digite valor do coeficiente B da equação de segundo grau: \n"; cin >> B;
   return B;      
}

double lerC() 
{
  float C;
   system("cls");
   cout << "Digite valor do coeficiente C da equação de segundo grau: \n"; cin >> C;
   return C;      
}

void CalMed(int lin)
{
    float t, l, s, d, q;
    float comp = 0;
    
    cout << "Calculando o Delta e as Raízes...Aguarde...";
    Sleep(1000);
    
    for (int i = 0; i <= lin; i++)
    {
    	float x1 = 0, x2 = 0;
    	t = me[i].A;
    	s = me[i].B;
    	l = me[i].C;
    	
    	d = (s * s) + (-4 * t * l);
    	
    	me[i].delta = d;
    	
    	q = sqrt(d);
    	
    	if (d == comp)
    	{
    		me[i].status = "Tem duas raízes iguais";
    		x1 = (s + q) / (2 * t);
    		x2 = (s - q) / (2 * t);
		}
		
		if (d < comp)
    	{
    		me[i].status = "Não tem raíz";
		}
		
		if (d > comp)
    	{
    		me[i].status = "Tem duas raízes diferentes";
    		x1 = (s + q) / (2 * t);
    		x2 = (s - q) / (2 * t);
		}
         
        me[i].X1 = x1;
        me[i].X2 = x2;
        
    }  
}

void Exibir(int lin)
{
     system("cls");
     for (int i=0; i <= lin; i++)
     {
          cout << "\nValor do primeiro coeficiente: " << me[i].A << " - Valor do segundo coeficiente: " << me[i].B << " - Valor do terceiro coeficiente: " << me[i].C << " - Valor do Delta: " << me[i].delta << " - Status: " << me[i].status << " - Valor da primeira raíz: " << me[i].X1 << " - Valor da segunda raíz: " << me[i].X2 << endl;
     } 
     system("pause");
}

int menu()
{
	     int tecla;
         system("cls");
         cout << "\n**Cálculo das raízes de uma equação do segundo grau**\n";
	     cout << "\n**Tela Inicial**\n";
         cout << "\n1 - Inserir coeficientes";
         cout << "\n2 - Realizar Cálculos";
         cout << "\n3 - Exibir Resultados";
         cout << "\n4 - Sair \n" << endl;
         cin >> tecla;
		  
return tecla;}

int main()
{
         setlocale(LC_ALL,"Portuguese");
	     int tecla = 0, linha = -1;
	     float A1, B1, C1;
	     while (tecla != 4)
	     {
         tecla = menu();
		  
           switch(tecla)
           {
              case 1:
                   {
                        A1 = lerA();
                        B1 = lerB();
                        C1 = lerC();
                      
                        linha = linha + 1;
                        armazenar(linha, A1, B1, C1);
                        break;   
                   }
                 
              case 2:
                   {
                       if (linha >= 0)
                       {
                          CalMed(linha);  
                          break;        
                       }                
                   }
            
              case 3:
                   {
                      if (linha >= 0)
                      {
                        Exibir(linha);
                        break;          
                      }        
                   }
           } 
		} 
return 0; 
}

