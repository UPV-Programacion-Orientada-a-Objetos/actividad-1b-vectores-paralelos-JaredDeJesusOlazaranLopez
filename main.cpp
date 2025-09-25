#include <iostream>
#include <string>

using namespace std;

int codigo;
int limite=10;
int indice;
int pmc=0;
bool validar=true;
string npmc;
int id[100]={101,102,103,104,105,106,107,108,109,110};
string nombre[100]={"Martillo de bola",
                   "Destornillador",
                   "Cinta metrica",
                   "Llave inglesa",
                   "Taladro inalambrico",
                   "Sierra circular",
                   "Caja de herramientas",
                   "Tijeras",
                   "Tornillos",
                   "Clavos"
                };
int stock[100]={50,100,45,65,90,34,78,98,120,150};
float precio[100]={15.00,8.75,20.00,25.99,100.00,1350.00,200.00,50.00,5.00,5.00};

void consultarProducto();
void actualizarInventario();
void generarReporte();
void productoMasCaro();
void agregarProductos();
int main() {

    

    cout<<"Hola, bienvenido a la ferreteria 'El martillo'"<<endl;

    while(true){
        cout<<"Que accion desea realizar?"<<endl;
        
        cout<<"1.- Agregar articulo"<<endl;
        cout<<"2.- Consultar productos"<<endl;
        cout<<"3.- Actualizar inventario"<<endl;
        cout<<"4.- Generar reporte completo"<<endl;
        cout<<"5.- Encontrar el producto mas caro"<<endl;
        cout<<"6.- Salir"<<endl;
        int opcion;
        cin>>opcion;

        switch(opcion){
            case 1:
            agregarProductos();
            break;
            case 2:
            consultarProducto();
            break;
            case 3:
            actualizarInventario();
            break;
            case 4:
            generarReporte();
            break;
            case 5:
            productoMasCaro();
            break;
            case 6:
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

/*void conseguirIndice(){
    for(int i=0;i<100;i++){
        if(nombre[i].equals(null)){
            limite = i;
            break;
        }
    }
}*/

void validacion(){
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Por favor ingrese un codigo valido." << endl;
        return;
    }
}

void validacionWhile(){
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Por favor ingrese un numero valido." << endl;
        validar = true;
    }else{
        validar = false;
    }
}

void consultarProducto(){
    cout << "Ingresa el codigo del producto a consultar: " << endl;
    cin >> codigo;
    validacion();
    for(int i=0;i<limite;i++){
        if(codigo==id[i]){
            indice=i;
        }
    }
    if(codigo!=id[indice]){
        cout<<"El codigo ingresado no existe, intente de nuevo"<<endl;
        return;
    }
    cout<<"Codigo: "<<id[indice]<<endl;
    cout<<"Nombre: "<<nombre[indice]<<endl;
    cout<<"Stock: "<<stock[indice]<<endl;
    cout<<"Precio: $"<<precio[indice]<<endl;
}

void actualizarInventario(){
    cout<<"Ingresa el codigo del articulo a actualizar: ";
    cin>>codigo;

    validacion();
    for(int i=0;i<limite;i++){
        if(codigo==id[i]){
            indice=i;
        }
    }
    if(codigo!=id[indice]){
        cout<<"El codigo ingresado no existe, intente de nuevo"<<endl;
        return;
    }

    cout<<"Producto encontrado: " << nombre[indice]<<endl;
    do{
      cout<<"Ingrese el nuevo numero de stock, stock actual: "<< stock[indice]<<endl;
      cin>>stock[indice];
      validacionWhile();
    }while(validar==true);
    do{
      cout<<"Ingrese el nuevo precio, precio actual: $"<<precio[indice]<<endl;
      cin>>precio[indice];
      validacionWhile();
    }while(validar==true);
}

void generarReporte(){
     cout << "---------------Reporte de inventario---------------" << endl;
cout << "Codigo\t|\tNombre\t\t|\tStock\t|\tPrecio" << endl;
cout << "--------------------------------------------------------" << endl;
for (int i = 0; i <limite; i++) {
    cout << id[i] << "\t|\t" 
         << nombre[i] << "\t\t|\t" 
         << stock[i] << "\t|\t$"
         << precio[i] << endl;
}

}

void productoMasCaro(){
    for(int i=0;i<limite;i++){
        if(precio[i]>pmc){
            pmc=precio[i];
            npmc=nombre[i];
        }
    }
    cout<<"El producto mas caro es: "<<npmc<<", con un precio de: $"<<pmc<<endl;
}

void agregarProductos(){
    cout<<"Ingresa el nombre de tu producto: "<<endl;;
    cin>>nombre[limite];
    do{
      cout<<"Ingresa la cantidad de stock del producto"<<endl;
      cin>>stock[limite];
      validacionWhile();
    }while(validar==true);
    do{
      cout<<"Ingresa el precio para el producto: "<<endl;
      cin>>precio[limite];
      validacionWhile();
    }while(validar==true);
    id[limite]=id[limite-1]+1;
    limite++;
}