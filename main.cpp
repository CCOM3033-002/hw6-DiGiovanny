/*
HW6 - Figuras en 3D
Giovanny Rodriguez Rivera
801-24-2694
Colaboraciones: ChatGPT
-Lo utilize para aclarar dudas acerca y resolver errores que se desplegaban en el terminal
https://chatgpt.com/share/67e9bcc6-2578-8006-be08-a3abf767c58b
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Prototipo de funciones
void volumen(double, double);
void area(double, double);
void volumen(double);
void area(double);
void volumen(double, double, double);
void area(double, double, double);

int main() {
    //Declara variables
    char opcion_figura, opcion_calcular;
    double radio, altura, ancho, longitud;
    
    //Establecer que los numeros se desplieguen con solo dos espacios decimales
    cout << setprecision(2) << fixed;
    
    //Desplegar el proposito y pedir la figura
    cout << "Este programa calcula el volumen y el área de la supercicie de tres figuras.\n Escriba la letra de la figura que desea escoger:" << "\na. Cilindro\nb. Esfera\nc. Prisma rectangular" << "\nSelección: ";
    cin >> opcion_figura;
    
    //Input Validation
    while (opcion_figura != 'a' && opcion_figura != 'b' && opcion_figura != 'c'){
        cout << "ERROR: Valor entrado no es válido.\nIngrese la letra de la figura que desea escoger: ";
        cin >> opcion_figura;
    }
    
    //Pedir el calculo que se quiere realizar
    cout << endl << "Escriba la letra de la opción que desea escoger:" << "\na. Volumen\nb. Área de la superficia\nSelección: ";
    cin >> opcion_calcular;
    
    //Input Validation
    while (opcion_calcular != 'a' && opcion_calcular != 'b'){
        cout << "ERROR: Valor entrado no es válido.\n Ingrese la letra de la opcion que desea escoger: ";
        cin >> opcion_calcular;
    }
    
    //Se creo un menu con switch para poder manejar las opciones escogidas por el usuario
    //El usuario entra los datos necesarios para llevar a cabo el calculo que quiere realizar dependiendo de la figura escogida
    //En cada switch case hay un while loop que hace que el usurio vuelva a escribir los datos si alguno de ellos es negativo
    switch(opcion_figura){
        case 'a':{
            cout << "\nEntre el radio: ";
            cin >> radio;
            cout << "Entre la altura: ";
            cin >> altura;
            while (radio < 0 || altura < 0){
                cout << "\nERROR: Un valor entrado es negativo.\nIngrese solo valores positivos ";
                cout << "\nEntre el radio: ";
                cin >> radio;
                cout << "Entre la altura: ";
                cin >> altura;
            }
            if (opcion_calcular == 'a'){
                volumen(radio, altura);
            }
            else{
                area(radio, altura);
            }
            break;
        } 
        case 'b':{
            cout << "\nEntre el radio: ";
            cin >> radio;
            while (radio < 0){
                cout << "\nERROR: El valor entrado es negativo.\nIngrese solo valores positivos ";
                cout << "\nEntre el radio: ";
                cin >> radio;
            }
            if (opcion_calcular == 'a'){
                volumen(radio);
            }
            else{
                area(radio);
            }
            break;
        } 
        case 'c':{
            cout << "\nEntre la longitud: ";
            cin >> longitud;
            cout << "Entre el ancho: ";
            cin >> ancho;
            cout << "Entre la altura: ";
            cin >> altura;
            while (altura < 0 || longitud < 0 || ancho < 0){
                cout << "\nERROR: Un valor entrado es negativo.\nIngrese solo valores positivos ";
                cout << "\nEntre la longitud: ";
                cin >> longitud;
                cout << "Entre el ancho: ";
                cin >> ancho;
                cout << "Entre la altura: ";
                cin >> altura;
            }
            if (opcion_calcular == 'a'){
                volumen(longitud, ancho, altura);
            }
            else{
                area(longitud, ancho, altura);
            }
            break; 
        }
            
    }
    return 0;
}

//FUNCIONES PARA CILINDRO
//La primera devuelve el volumen, mientras que la segunda devuelve el area de superficie   
void volumen(double radio, double altura){
    double volumen;
    volumen = 3.14 * pow(radio, 2) * altura;
    cout << "El volumen del cilindro es: " << volumen;
}
void area(double radio, double altura){ 
    double superficie;
    superficie = 2 * 3.14 * radio * altura + 2 * 3.14 * pow(radio, 2);
    cout << "El área de la superficie del cilindro es: " << superficie;
}

//FUNCIONES PARA ESFERA
//La primera devuelve el volumen, mientras que la segunda devuelve el area de superficie    
void volumen(double radio){
    double volumen;
    volumen = 4.0 / 3.0 * 3.14 * pow(radio, 3);
    cout << "El volumen de la esfera es: " << volumen;
}
void area(double radio){ 
    double superficie;
    superficie = 4 * 3.14 * pow(radio, 2);
    cout << "El área de la superficie de la esfera es: " << superficie;
}

//FUNCIONES PARA PRISMA RECTANGULAR
//La primera devuelve el volumen, mientras que la segunda devuelve el area de superficie   
void volumen(double longitud, double ancho, double altura){
    double volumen;
    volumen = longitud * ancho * altura;
    cout << "El volumen del prisma rectangular es: " << volumen;
}
void area(double longitud, double ancho, double altura){ 
    double superficie;
    superficie = 2 * (longitud * ancho + ancho * altura + longitud * altura);
    cout << "El área de la superficie del prisma rectangular es: " << superficie;
}