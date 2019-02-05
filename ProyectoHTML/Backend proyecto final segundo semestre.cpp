#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void Escribir(int suma);

using namespace std;

/*
void Lectura(){
     ifstream file;
     
     file.open("C:\Users\Cisco\Desktop\Pagesq\no c.html", ios::in);
     
     if(file.fail()){
         cout<<"No se pudo abrir el archivo"<<endl;
         exit(1);                
     }
     
}*/

int PideDatos(){
    int num1 = 4;
    int num2 = 6;
    
    return num1+num2;
}

int main()
{
    int suma;
    suma = PideDatos();
    Escribir(suma);
    //Lectura();
    system("PAUSE");
    return 0;
}

void Escribir(int suma){
    ofstream archivo;
    ifstream file;
    int xd = suma;
    
    archivo.open("Frontend proyecto final segundo semestre.html", ios::out);
    if(archivo.fail()){
        cout<<"No se pudo leer el archivo, error fatal";
        exit(1);
    }
    
    archivo<<"<!doctype html>";
    
    archivo<<"<html lang='es'>";
    
    archivo<<"<head>";
    
	archivo<<"<title>Proyecto final programacion 2 Andrés Manuel Prieto Álvarez & Cristian Andrés Grajales Perez</title>";
    archivo<<"<meta charset='utf-8''>";
    archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='icon.png'>";
    archivo<<"<link rel='stylesheet' href='jQuery/Plugins_jQuery/fancybox/v_3.5.1/jquery_FancyBox.3.5.1.css'>";
    archivo<<"<link rel='stylesheet' type='text/css' href='frontend para proyecto final del segundo semestre.css'>";
    archivo<<"<script src='jQuery/jquery-3.3.1.min.js' type='text/javascript'></script>";
    archivo<<"<script src='jQuery/Plugins_jQuery/jquery-easing_plugin_v1.3.js' type='text/javascript'></script>";
    //archivo<<"<script src='jQuery/Plugins_jQuery/fancybox/v_3.5.1/jquery_FancyBox.3.5.1.js type='text/javascript></script>";
    archivo<<"<script>$(document).ready(function() {$('#banner').hide();$('#fecha_llegada').click(function(e){$('#banner').fadeIn(2000);e.preventDefault();return false;})});</script>";
	archivo<<"</head>";
    
    archivo<<"<body>";
    
	archivo<<"<header>";
    
    archivo<<"<div id='search_div'>";
    archivo<<"<input type='text' placeholder='Buscar' name='Buscar' id='search'>";
    archivo<<"<input type='button' value='Buscar' id='button_buscar'>";
    archivo<<"</div>";
    
	archivo<<"<div id='dates'>";
    archivo<<"<input type='button' value='Fecha de llegada'>";
    archivo<<"<input type='button' value='Fecha de salida'>";
    archivo<<"<input type='button' value='Menu'>";
    archivo<<"</div";
    
	archivo<<"</header>";
    
    archivo<<"<section class='main'>";
    
    for(int i=0;i<5;i++){
    	archivo<<"<div class='galeria'>";
	    archivo<<"<img src='cancun.jpg' alt='imagen'>";
	    archivo<<"<div>";
	    archivo<<"<h2 class='refence'><a href='https://goo.gl/maps/hxJcrHy1dYt' class='reference' target='_blank'>Hotel Occidental Costa de Cancun</a></h2>";
	    archivo<<"</div>";
	    archivo<<"</div>";
	}
    
    archivo<<"</section>";
    
	archivo<<"</body>";
    archivo<<"</html>";
    
    archivo.close();
}
