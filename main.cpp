#include "IntGrande.h"

void menu(int,int);
int main(){
    int a,b;
    cout << "\nBienvenido\n";
    cout << "\nPorfavor, digite el primer número: ";
    cin >> a;
    cout << "\nPorfavor, digite el segundo número: ";
    cin >> b;
    menu(a,b);
    
    cout << "\n\n";
    return 0;
};

void menu(int a,int b){
    int op;
    cout<<"\n\nDigite la operación que desea realizar: \n";
    cout<<"\n1. Suma";
    cout<<"\n2. Resta";
    cout<<"\n3. Multiplicacion";
    cout<<"\n4. Division\n\n";
    cout<<"R/: ";cin>>op;
    switch(op){
        case 1:
            if(a > 0 && b > 0){
                IntGrande n1(a);IntGrande n2(b);
                cout << a << " + " << b << " = " << n1+n2;
            }
            else if(a < 0 && b > 0){
                int a1 = -a;
                IntGrande n1(a1);IntGrande n2(b);
                cout << a << " + " << b << " = " << n2-n1;
            }
            else if(a > 0 && b < 0){
                int b1 = -b;
                IntGrande n1(a);IntGrande n2(b1);
                cout << a << " + (" << b << ") = " << n1-n2;
            }
            else if(a < 0 && b < 0){
                int a1 = -a; int a2 = -b; 
                IntGrande n1(a1);IntGrande n2(a2);
                cout << a << " + (" << b <<") = -" << n1+n2; 
            }
        case 2:
            if(a > 0 && b > 0){
                IntGrande n1(a);IntGrande n2(b);
                cout << a << " - " << b << " = " << n1-n2;
            }
            else if(a < 0 && b > 0){
                int a1 = -a;
                IntGrande n1(a1);IntGrande n2(b);
                cout << a << " - " << b << " = -" << n1+n2;
            }
            else if(a > 0 && b < 0){
                int b1 = -b;
                IntGrande n1(a);IntGrande n2(b1);
                cout << a << " - (" << b << ") = " << n1+n2;
            }
            else if(a < 0 && b < 0){
                int a1 = -a; int a2 = -b; 
                IntGrande n1(a1);IntGrande n2(a2);
                cout << a << " - (" << b <<") = " << n2-n1; 
            }
        case 3:
            if(a > 0 && b > 0){
                IntGrande n1(a);IntGrande n2(b);
                cout << a << " * " << b << " = " << n1*n2;
            }
            else if(a < 0 && b > 0){
                int a1 = -a;
                IntGrande n1(a1);IntGrande n2(b);
                cout << a << " * " << b << " = -" << n1*n2;
            }
            else if(a > 0 && b < 0){
                int b1 = -b;
                IntGrande n1(a);IntGrande n2(b1);
                cout << a << " * (" << b << ") = -" << n1*n2;
            }
            else if(a < 0 && b < 0){
                int a1 = -a; int a2 = -b; 
                IntGrande n1(a1);IntGrande n2(a2);
                cout << a << " * (" << b <<") = " << n2*n1; 
            }
        case 4:
            if(a > 0 && b > 0){
                IntGrande n1(a);IntGrande n2(b);
                if(a < b)
                    cout << a << " / " << b << " = 0";
                else
                    cout << a << " / " << b << " = " << n1/n2;
            }
            else if(a < 0 && b > 0){
                int a1 = -a;
                IntGrande n1(a1);IntGrande n2(b);
                if(a1 < b)
                    cout << a << " / " << b << " = 0";
                else 
                    cout << a << " / " << b << " = -" << n1/n2;
            }
            else if(a > 0 && b < 0){
                int b1 = -b;
                IntGrande n1(a);IntGrande n2(b1);
                if(a < b1)
                    cout << a << " / " << b << " = 0";
                else  
                    cout << a << " / (" << b << ") = -" << n1/n2;
            }
            else if(a < 0 && b < 0){
                int a1 = -a; int a2 = -b;
                IntGrande n1(a1);IntGrande n2(a2);
                if(a1 < a2)
                    cout << a << " / (" << b << ") = 0";
                else
                    cout << a << " / (" << b <<") = " << n1/n2; 
            }
    }
}
 