#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct TodosUsuarios{
       string NombresUsuarios[100];
       long long int CedulasUsuarios[100];
       string UsersUsuarios[100];
       string ContrasUsuarios[100];       
};

struct TodosAdministradores{
      string NombresAdministradores[100];
      long long int CedulasAdministradores[100];
      string UsersAdministradores[100];
      string ContrasAdministradores[100]; 
};

struct DatosUsuario{
       struct TodosUsuarios todosLosUsuarios;
       int cantUsuarios;
       char Name[100];      //Contiene el nombre de la persona
       long long int ID;      //Contiene la cedula de la persona
       char User[100];       //Contiene el nombre de usuario con el que se vá a ingresar
       char password[100];        //Contiene la contraseña con la que el usuario va a ingresar
};

struct DatosAdministrador{
      struct TodosAdministradores todosLosAdmin;
      int cantAdministradores;
      char NameAdmin[100];      //Contiene el nombre de el administrador
      long long int IDAdmin;      //Contiene la cedula de el administrador
      char UserAdmin[100];       //Contiene el nombre de usuario con el que se va a ingresar como administrador
      char passwordAdmin[100];        //Contiene la contraseña con la que el usuario va a ingresar como administrador
};



//--------------------------------------------------//
//ESTAS SON LAS FIRMAS DE LAS FUNCIONES DEL PROGRAMA//
//--------------------------------------------------//

void Escribir();
void IngresarDatos(DatosUsuario &datosDelUsuario);
void RegistroUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);
void RegistroAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado, DatosUsuario &datosDelUsuario);
void MenuPrincipal(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);
void DefineTipoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);



void MuestraDatosUsuarios(DatosUsuario &datosDelUsuario, bool &estaRegistrado);
void MuestraDatosAdmins(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado);
//---------------------------//
//AQUI TERMINAN LAS FIRMAS XD//
//---------------------------//

//FUNCION PRINCIPAL
int main()
{
    struct DatosUsuario datosDelUsuario;        //Variable que referencia la estructura con los datos del usuario.
    struct DatosAdministrador datosDelAdministrador;       //Variable que referencia la estructura con los datos del administrador
    bool estaRegistrado = false;        //Contiene la verificacion si el usuario está registrado o no.
    system("color 4B");
    
    Escribir();      //Realiza la maquetacion de la vista.
    MenuPrincipal(datosDelUsuario, estaRegistrado, datosDelAdministrador);
    //RegistroUsuario(datosDelUsuario, estaRegistrado);        //Registra al usuario si no lo está, si lo está, pide los datos para loguearse
    //RegistroUsuario(datosDelUsuario, estaRegistrado);
    
    //Lectura();
    system("PAUSE");
    return 0;
}

//El menu que se inicia al comienzo de el programa
void MenuPrincipal(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador){
     
     int op = 1;       //Es la opcion que va a tomar el usuario
     datosDelUsuario.cantUsuarios = 0;
     datosDelAdministrador.cantAdministradores = 0;
     
     //Se ejecuta si op es diferente de 0
     while(op != 0){
          system("cls");
          //Muestra las opciones que se pueden ejecutar
          cout<<"Ingrese 1 para registrarte"<<endl;
          cout<<"Ingrese 2 para buscar un hotel"<<endl;
          cout<<"Ingrese 3 para mostrar todos los usuarios corrientes"<<endl;
          cout<<"Ingrese 4 para mostrar todos los Administradores"<<endl;
          cin>>op;       //Guarda el valor de la opcion que se ejecutará
          
          switch(op){
               case 1:
                   //Ejecuta el registro o logea al usuario dependiendo de si está registrado o no
                   DefineTipoUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);
                   system("pause");
                   break;
               case 2:
                   system("start Frontend_proyecto_final_segundo_semestre.html");
                   system("start https://www.trivago.com.co/?aDateRange%5Barr%5D=2019-02-13");
                   system("pause");
                   break;
               case 3:
                    MuestraDatosUsuarios(datosDelUsuario, estaRegistrado);
                    system("pause");
                    break;
               case 4:
                    MuestraDatosAdmins(datosDelAdministrador, estaRegistrado);
                    system("pause");
                    break;
          }
     }
}

void MuestraDatosAdmins(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado){
     for(int i = 0; i < datosDelAdministrador.cantAdministradores; i++){
          cout<<"ADMINISTRADOR "<<i+1<<endl;
          cout<<"CEDULA= "<<datosDelAdministrador.todosLosAdmin.CedulasAdministradores[i]<<endl;
          cout<<"CONTRASEÑA= "<<datosDelAdministrador.todosLosAdmin.ContrasAdministradores[i]<<endl;
          cout<<"NOMBRE= "<<datosDelAdministrador.todosLosAdmin.NombresAdministradores[i]<<endl;
          cout<<"USUARIO= "<<datosDelAdministrador.todosLosAdmin.UsersAdministradores[i]<<endl;
          cout<<endl;      
     }
}

//FUNCION TEMPORAL QUE MUESTRA TODOS LOS USUARIOS DE LA BASE DE DATOS

void MuestraDatosUsuarios(DatosUsuario &datosDelUsuario, bool &estaRegistrado){
     
     for(int i = 0; i < datosDelUsuario.cantUsuarios; i++){
          cout<<"USUARIO "<<i+1<<endl;
          cout<<"CEDULA= "<<datosDelUsuario.todosLosUsuarios.CedulasUsuarios[i]<<endl;
          cout<<"CONTRASEÑA= "<<datosDelUsuario.todosLosUsuarios.ContrasUsuarios[i]<<endl;
          cout<<"NOMBRE= "<<datosDelUsuario.todosLosUsuarios.NombresUsuarios[i]<<endl;
          cout<<"USUARIO= "<<datosDelUsuario.todosLosUsuarios.UsersUsuarios[i]<<endl;      
          cout<<endl; 
     }
}

void DefineTipoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador){
     system("cls");
     int op = 1;
     
     while(op != 0){
         cout<<"Desea registrarse como administrador o como usuario corriente?"<<endl;
         cout<<"Ingrese 1 si quiere registrarse como administrador"<<endl;
         cout<<"Ingrese 2 si quiere registrarse como usuario corriente"<<endl;
         
         cin>>op;
         
         switch(op){
                case 1:
                     RegistroAdministrador(datosDelAdministrador, estaRegistrado, datosDelUsuario);
                     break;
                case 2:
                     RegistroUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);
                     break;           
         }           
     }
}

void RegistroAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado, DatosUsuario &datosDelUsuario){
     //Valida si el usuario está registrado
     if(!estaRegistrado){
          //ALMACENA TODOS LOS DATOS NECESARIOS PARA EL REGISTRO EN LA ESTRUCTURA DatosUsuario
          cout<<"Ingrese su nombre completo= ";
          fflush(stdin);
          gets(datosDelAdministrador.NameAdmin);
          cout<<"\n"<<endl;
          cout<<"Ingrese su numero de cedula= ";
          cin>>datosDelAdministrador.IDAdmin;
          cout<<"\n"<<endl;
          cout<<"Ingrese el usuario que desea= ";
          fflush(stdin);
          gets(datosDelAdministrador.UserAdmin);
          cout<<"\n"<<endl;
          cout<<"Ingrese la contraseña que desea= ";
          fflush(stdin);
          gets(datosDelAdministrador.passwordAdmin);
          
          int cantRepeticionesCedula = 0;
          int cantRepeticionesUser = 0;
          
          for(int i = 0; i < datosDelAdministrador.cantAdministradores; i++){
               if(datosDelAdministrador.IDAdmin == datosDelAdministrador.todosLosAdmin.CedulasAdministradores[i]){
                   cantRepeticionesCedula++;                        
               }
               if(datosDelAdministrador.UserAdmin == datosDelAdministrador.todosLosAdmin.UsersAdministradores[i]){
                   cantRepeticionesUser++;                    
               }
               for(int j = 0; j < datosDelUsuario.cantUsuarios; j++){
                     if(datosDelAdministrador.IDAdmin == datosDelUsuario.todosLosUsuarios.CedulasUsuarios[j]){
                         cantRepeticionesCedula++;                      
                     }
                     if(datosDelAdministrador.UserAdmin == datosDelUsuario.todosLosUsuarios.UsersUsuarios[j]){
                         cantRepeticionesUser++;                       
                     }
               }
          }
          
          if(cantRepeticionesCedula != 0){
              cantRepeticionesCedula = 0;
              cout<<"\nYa existe un usuario con esa cedula registrada\n"<<endl;
              RegistroAdministrador(datosDelAdministrador, estaRegistrado, datosDelUsuario);               
          }else{
                if(datosDelAdministrador.IDAdmin < 10000000 || datosDelAdministrador.IDAdmin > 2222222222){
                     cout<<"\nCedula no valida\n"<<endl;
                      RegistroAdministrador(datosDelAdministrador, estaRegistrado, datosDelUsuario); 
               }else{
                     if(cantRepeticionesUser != 0){
                          cantRepeticionesUser = 0;
                          cout<<"\nYa existe un usuario con ese usuario registrado\n"<<endl;
                           RegistroAdministrador(datosDelAdministrador, estaRegistrado, datosDelUsuario);   
                     }else{
                          datosDelAdministrador.todosLosAdmin.CedulasAdministradores[datosDelAdministrador.cantAdministradores] = datosDelAdministrador.IDAdmin;
                          datosDelAdministrador.todosLosAdmin.ContrasAdministradores[datosDelAdministrador.cantAdministradores] = datosDelAdministrador.passwordAdmin;
                          datosDelAdministrador.todosLosAdmin.NombresAdministradores[datosDelAdministrador.cantAdministradores] = datosDelAdministrador.NameAdmin;
                          datosDelAdministrador.todosLosAdmin.UsersAdministradores[datosDelAdministrador.cantAdministradores] = datosDelAdministrador.UserAdmin;
                          datosDelAdministrador.cantAdministradores++; 
                     }
               }
          }
          
          
          
          system("cls");
          //Con esta parte confirmamos siquedan guardados los datos.
          cout<<datosDelAdministrador.NameAdmin<<endl;
          cout<<datosDelAdministrador.IDAdmin<<endl;
          cout<<datosDelAdministrador.UserAdmin<<endl;
          cout<<datosDelAdministrador.passwordAdmin<<endl;
          //Si pilla, si quedan guardados xD.
          
          //estaRegistrado = true;
     }/*else{
          IngresarDatos(datosDelUsuario);         //INGRESA LOS DATOS SI YA ESTÁ REGISTRADO.
     }*/
}

//Registra al usuario si no lo está, si lo está, pide los datos para loguearse
void RegistroUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador){
     
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
          
          int cantRepeticionesCedula = 0;
          int cantRepeticionesUser = 0;
          
          for(int i = 0; i < datosDelUsuario.cantUsuarios; i++){
               if(datosDelUsuario.ID == datosDelUsuario.todosLosUsuarios.CedulasUsuarios[i]){
                   cantRepeticionesCedula++;
               }
               if(datosDelUsuario.User == datosDelUsuario.todosLosUsuarios.UsersUsuarios[i]){
                   cantRepeticionesUser++;                    
               }
               for(int j = 0; j < datosDelAdministrador.cantAdministradores; j++){
                     if(datosDelUsuario.ID == datosDelAdministrador.todosLosAdmin.CedulasAdministradores[j]){
                         cantRepeticionesCedula++;                      
                     }
                     if(datosDelUsuario.User == datosDelAdministrador.todosLosAdmin.UsersAdministradores[j]){
                         cantRepeticionesUser++;                       
                     }
               }
          }
          
          if(cantRepeticionesCedula != 0){
              cantRepeticionesCedula = 0;
              cout<<"\nYa existe un usuario con esa cedula registrada\n"<<endl;
              RegistroUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);                
          }else{
                if(datosDelUsuario.ID < 10000000 || datosDelUsuario.ID > 2222222222){
                     cout<<"\nCedula no valida\n"<<endl;
                     RegistroUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);
               }else{
                     if(cantRepeticionesUser != 0){
                          cantRepeticionesUser = 0;
                          cout<<"\nYa existe un usuario con ese usuario registrado\n"<<endl;
                          RegistroUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);  
                     }else{
                          datosDelUsuario.todosLosUsuarios.CedulasUsuarios[datosDelUsuario.cantUsuarios] = datosDelUsuario.ID;
                          datosDelUsuario.todosLosUsuarios.ContrasUsuarios[datosDelUsuario.cantUsuarios] = datosDelUsuario.password;
                          datosDelUsuario.todosLosUsuarios.NombresUsuarios[datosDelUsuario.cantUsuarios] = datosDelUsuario.Name;
                          datosDelUsuario.todosLosUsuarios.UsersUsuarios[datosDelUsuario.cantUsuarios] = datosDelUsuario.User;
                          datosDelUsuario.cantUsuarios++; 
                     }
               }
          }
          
          
          
          system("cls");
          //Con esta parte confirmamos siquedan guardados los datos.
          cout<<datosDelUsuario.Name<<endl;
          cout<<datosDelUsuario.ID<<endl;
          cout<<datosDelUsuario.User<<endl;
          cout<<datosDelUsuario.password<<endl;
          //Si pilla, si quedan guardados xD.
          
          //estaRegistrado = true;
     }/*else{
          IngresarDatos(datosDelUsuario);         //INGRESA LOS DATOS SI YA ESTÁ REGISTRADO.
     }*/
}

//Funcion que pide los datos de usuario para poder ingresar.
void IngresarDatos(DatosUsuario &datosDelUsuario){
     
     cout<<"Ya tienes un usuario registrado.\n\n"<<endl;
     
     //Ingresa el usuario
     cout<<"Ingrese su usuario= "<<endl;
     char usuario[100];
     fflush(stdin);
     gets(usuario);
     //Ingresa la contraseña
     cout<<"Ingrese su contraseña= "<<endl;
     char contrasenia[100];
     fflush(stdin);
     gets(contrasenia);
     
     /*
     for(int i = 0; i < strlen(usuario); i++){
                  
     }*/
     if(usuario == datosDelUsuario.User){
            if(contrasenia == datosDelUsuario.password){
                   cout<<"\n\nLogeado correctamente!"<<endl;               
            }           
     }
     
}

//Funcion que realiza la maquetacion de la vista.
void Escribir(){
    ofstream archivoHTML;     //Contiene el archivo HTML de la vista
    
    archivoHTML.open("Frontend_proyecto_final_segundo_semestre.html", ios::out);     //Abre el archivo HTML
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
