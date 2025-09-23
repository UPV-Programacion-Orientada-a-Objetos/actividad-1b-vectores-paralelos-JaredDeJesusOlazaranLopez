#include <iostream>
#include <string>
#include <thread>

using namespace std;

int codigo;
int indice;
int pmc=0;
string npmc;
int id[10]={101,102,103,104,105,106,107,108,109,110};
string nombre[10]={"Martillo de bola    ",
                   "Destornillador      ",
                   "Cinta metrica       ",
                   "Llave inglesa       ",
                   "Taladro inalambrico ",
                   "Sierra circular     ",
                   "Caja de herramientas",
                   "Tijeras             ",
                   "Tornillos           ",
                   "Clavos              "
                };
int stock[10]={50,100,45,65,90,34,78,98,120,150};
float precio[10]={15.00,8.75,20.00,25.99,100.00,1350.00,200.00,50.00,5.00,5.00};

void consultarProducto();
//void actualizarInventario();
//void generarReporte();
//void productoMasCaro();

int main() {

    

    cout<<"Hola, bienvenido a la ferreteria 'El martillo'"<<endl;

    while(true){
        cout<<"Que accion desea realizar?"<<endl;

        cout<<"1.- Consultar productos"<<endl;
        cout<<"2.- Actualizar inventario"<<endl;
        cout<<"3.- Generar reporte completo"<<endl;
        cout<<"4.- Encontrar el producto mas caro"<<endl;
        cout<<"5.- Salir"<<endl;
        int opcion;
        cin>>opcion;

        switch(opcion){
            case 1:
            consultarProducto();
            break;
            case 2:
            //actualizarInventario();
            break;
            case 3:
            //generarReporte();
            break;
            case 4:
            //productoMasCaro();
            break;
            case 5:
            cout<<"Gracias por usar el sistema de la ferreteria 'El martillo'"<<endl;
            return 0;
            break;
            default:
            cout<<"Opcion no valida, intente de nuevo"<<endl;
            break;
        }
    }
    return 0;
}

void consultarProducto(){
    cout << "Ingresa el codigo del producto a consultar: " << endl;
    cin >> codigo;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Por favor ingrese un codigo valido." << endl;
        cout<<"Redirigiendo al menu principal..."<<endl;
        this_thread::sleep_for(chrono::seconds(2));
        system("clear");
        return;
    }
    for(int i=0;i<10;i++){
        if(codigo==id[i]){
            indice=i;
        }
    }
    if(codigo!=id[indice]){
        cout<<"El codigo ingresado no existe, intente de nuevo"<<endl;
        cout<<"Redirigiendo al menu principal..."<<endl;
        this_thread::sleep_for(chrono::seconds(2));
        return;
    }
    cout<<"Codigo: "<<id[indice]<<endl;
    cout<<"Nombre: "<<nombre[indice]<<endl;
    cout<<"Stock: "<<stock[indice]<<endl;
    cout<<"Precio: $"<<precio[indice]<<endl;
    cout<<"Redirigiendo al menu principal..."<<endl;
    this_thread::sleep_for(chrono::seconds(5));
}