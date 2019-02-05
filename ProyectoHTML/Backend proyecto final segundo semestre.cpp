#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;

struct DatosUsuario{
       char Name[100];      //Contiene el nombre de la persona
       long long int ID;      //Contiene la cedula de la persona
       char User[100];       //Contiene el nombre de usuario con el que se vá a ingresar
       char password[100];        //Contiene la contraseña con la que el usuario va a ingresar
};

//--------------------------------------------------//
//ESTAS SON LAS FIRMAS DE LAS FUNCIONES DEL PROGRAMA//
//--------------------------------------------------//

void Escribir();
void IngresarDatos(DatosUsuario &datosDelUsuario);
void RegistroUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado);

//---------------------------//
//AQUI TERMINAN LAS FIRMAS XD//
//---------------------------//

//FUNCION PRINCIPAL
int main()
{
    struct DatosUsuario datosDelUsuario;        //Variable que referencia la estructura con los datos del usuario.
    bool estaRegistrado = false;        //Contiene la verificacion si el usuario está registrado o no.
    
    RegistroUsuario(datosDelUsuario, estaRegistrado);        //Registra al usuario si no lo está, si lo está, pide los datos para loguearse
    
    
    Escribir();      //Realiza la maquetacion de la vista.
    //Lectura();
    system("PAUSE");
    return 0;
}

//Registra al usuario si no lo está, si lo está, pide los datos para loguearse
void RegistroUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado){
     
     //Valida si el usuario está registrado
     if(!estaRegistrado){
          //ALMACENA TODOS LOS DATOS NECESARIOS PARA EL REGISTRO EN LA ESTRUCTURA DatosUsuario
          cout<<"Ingrese su nombre completo= ";
          fflush(stdin);
          gets(datosDelUsuario.Name);
          cout<<"\n"<<endl;
          cout<<"Ingrese su numero de cedula= ";
          cin>>datosDelUsuario.ID;
          cout<<"\n"<<endl;
          cout<<"Ingrese el usuario que desea= ";
          fflush(stdin);
          gets(datosDelUsuario.User);
          cout<<"\n"<<endl;
          cout<<"Ingrese la contraseña que desea= ";
          fflush(stdin);
          gets(datosDelUsuario.password);
          
          system("cls");
          //Con esta parte confirmamos siquedan guardados los datos.
          cout<<datosDelUsuario.Name<<endl;
          cout<<datosDelUsuario.ID<<endl;
          cout<<datosDelUsuario.User<<endl;
          cout<<datosDelUsuario.password<<endl;
          //Si pilla, si quedan guardados xD.
          
          estaRegistrado = true;
     }else{
          IngresarDatos(datosDelUsuario);         //INGRESA LOS DATOS SI YA ESTÁ REGISTRADO.
     }
}

//Funcion que pide los datos de usuario para poder ingresar.
void IngresarDatos(DatosUsuario &datosDelUsuario){
     
}

//Funcion que realiza la maquetacion de la vista.
void Escribir(){
    ofstream archivoHTML;     //Contiene el archivo HTML de la vista
    
    archivoHTML.open("Frontend proyecto final segundo semestre.html", ios::out);     //Abre el archivo HTML
    if(archivoHTML.fail()){
        cout<<"No se pudo leer el archivo, error fatal";
        exit(1);
    }
    
    archivoHTML<<"<!doctype html>";
    
    archivoHTML<<"<html lang='es'>";
    
    archivoHTML<<"<head>";
    
	archivoHTML<<"<title>Proyecto final programacion 2 Andrés Manuel Prieto Álvarez & Cristian Andrés Grajales Perez</title>";
    archivoHTML<<"<meta charset='utf-8''>";
    archivoHTML<<"<link rel='shortcut icon' type='/imagex-icon' href='icon.png'>";
    archivoHTML<<"<link rel='stylesheet' href='jQuery/Plugins_jQuery/fancybox/v_3.5.1/jquery_FancyBox.3.5.1.css'>";
    archivoHTML<<"<link rel='stylesheet' type='text/css' href='frontend para proyecto final del segundo semestre.css'>";
    archivoHTML<<"<script src='jQuery/jquery-3.3.1.min.js' type='text/javascript'></script>";
    archivoHTML<<"<script src='jQuery/Plugins_jQuery/jquery-easing_plugin_v1.3.js' type='text/javascript'></script>";
    //archivo<<"<script src='jQuery/Plugins_jQuery/fancybox/v_3.5.1/jquery_FancyBox.3.5.1.js type='text/javascript></script>";
    archivoHTML<<"<script>$(document).ready(function() {$('#banner').hide();$('#fecha_llegada').click(function(e){$('#banner').fadeIn(2000);e.preventDefault();return false;})});</script>";
	archivoHTML<<"</head>";
    
    archivoHTML<<"<body>";
    
	archivoHTML<<"<header>";
    
    archivoHTML<<"<div id='search_div'>";
    archivoHTML<<"<input type='text' placeholder='Buscar' name='Buscar' id='search'>";
    archivoHTML<<"<input type='button' value='Buscar' id='button_buscar'>";
    archivoHTML<<"</div>";
    
	archivoHTML<<"<div id='dates'>";
    archivoHTML<<"<input type='button' value='Fecha de llegada'>";
    archivoHTML<<"<input type='button' value='Fecha de salida'>";
    archivoHTML<<"<input type='button' value='Menu'>";
    archivoHTML<<"</div";
    
	archivoHTML<<"</header>";
    
    archivoHTML<<"<section class='main'>";
    
    for(int i=0;i<5;i++){
    	archivoHTML<<"<div class='galeria'>";
	    archivoHTML<<"<img src='cancun.jpg' alt='imagen'>";
	    archivoHTML<<"<div>";
	    archivoHTML<<"<h2 class='refence'><a href='https://goo.gl/maps/hxJcrHy1dYt' class='reference' target='_blank'>Hotel Occidental Costa de Cancun</a></h2>";
	    archivoHTML<<"</div>";
	    archivoHTML<<"</div>";
	}
    
    archivoHTML<<"</section>";
    
	archivoHTML<<"</body>";
    archivoHTML<<"</html>";
    
    archivoHTML.close();
}
