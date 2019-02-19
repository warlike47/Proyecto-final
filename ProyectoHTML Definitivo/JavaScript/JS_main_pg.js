$(document).ready(function() {
	var look_for;

	var llegada='no especificado', salida='no especificado';
	var dia_llegada=1, dia_salida=0;

	var wifi=false, refrigaracion=false, parqueadero=false, gimnasio=false, restaurante=false;
	var piscina=false, spa=false, sauna=false, recepcion_24_hrs=false, piso_casa=false;

	$('#banner_fecha').hide();
	$('#banner_menu').hide();
	$('#more_options').hide();
	$('.comments').hide();
	$('#message').hide();
	$('#autores').hide();

	$('#fecha').click(function(e){
		$('#banner_fecha').fadeIn(2000);
		e.preventDefault();
		return false;
	})
	$('#banner_fecha').mouseleave(function(e){
		$('#banner_fecha').hide(2000);
		e.preventDefault();
		return false;
	})

	$('#menu').click(function(e){
		$('#banner_menu').fadeIn(2000);
		e.preventDefault();
		return false;
	})
	$('#banner_menu').mouseleave(function(e){
		$('#banner_menu').hide(2000);
		e.preventDefault();
		return false;
	})

	$('#more').click(function(e){
		$('#more_options').fadeIn(2000);
		e.preventDefault();
		return false;
	})
	$('#more_options').mouseleave(function(e){
		$('#more_options').hide(2000);
		e.preventDefault();
		return false;
	})

	$('#tersm_y_conditions').click(function() {
		$('#tersm_y_conditions').css({'background':'#4FC9E6','width':'40%'});
		$('#tersm_y_conditions').attr('value','Has acetado nuestros treminos y condiciones');
		$('#facturar').css({'background':'#4FC9E6'});
		$('#enviar_factura').attr('href','Facturar.html');
		$('#enviar_factura').attr('target','_blank');
		$('#message').replaceWith("<cite id='message'>Ya puedes facturar</cite>");
	})

	$('#facturar').click(function(){
		$('#message').fadeIn();
	})

	$('#show_autors').click(function(e){
		$('#autores').fadeIn(2000);
		e.preventDefault();
		return false;
	})
	$('#autores').mouseleave(function(e){
		$('#autores').hide(2000);
		e.preventDefault();
		return false;
	})
});

	function buscador() {
		look_for=document.getElementById('search').value;
		return look_for;
	}

	function enviar_mes(eleccion, salida_lledada){
		if(salida_lledada==1){
			if(eleccion==1){llegada='enero';}
			if(eleccion==2){llegada='febrero';}
			if(eleccion==3){llegada='marzo';}
			if(eleccion==4){llegada='abril';}
			if(eleccion==5){llegada='mayo';}
			if(eleccion==6){llegada='junio';}
			if(eleccion==7){llegada='julio';}
			if(eleccion==8){llegada='agosto';}
			if(eleccion==9){llegada='septiembre';}
			if(eleccion==10){llegada='octubre';}
			if(eleccion==11){llegada='noviembre';}
			if(eleccion==12){llegada='diciembre';}
		}else{
			if(salida_lledada==0){
				if(eleccion==1){salida='enero';}
				if(eleccion==2){salida='febrero';}
				if(eleccion==3){salida='marzo';}
				if(eleccion==4){salida='abril';}
				if(eleccion==5){salida='mayo';}
				if(eleccion==6){salida='junio';}
				if(eleccion==7){salida='julio';}
				if(eleccion==8){salida='agosto';}
				if(eleccion==9){salida='septiembre';}
				if(eleccion==10){salida='octubre';}
				if(eleccion==11){salida='noviembre';}
				if(eleccion==12){salida='diciembre';}
			}
		}
	}

	function sacar_mes_de_llegada(){return llegada;}
	function sacar_mes_de_salida(){return salida;}

	function enviar_dia(eleccion, salida_lledada) {
		if(salida_lledada==1){dia_llegada=parseFloat(eleccion);}
		if(salida_lledada==0){dia_salida=parseFloat(eleccion);}
	}

	function sacar_dia_de_llegada(){return dia_llegada;}
	function sacar_dia_de_salida(){return dia_salida;}

	function seleccionado(eleccion_de_adicionales) {
		if(eleccion_de_adicionales==1){wifi=true;}
		if(eleccion_de_adicionales==2){refrigaracion=true;}
		if(eleccion_de_adicionales==3){parqueadero=true;}
		if(eleccion_de_adicionales==4){gimnasio=true;}
		if(eleccion_de_adicionales==5){restaurante=true;}
		if(eleccion_de_adicionales==6){piscina=true;}
		if(eleccion_de_adicionales==7){spa=true;}
		if(eleccion_de_adicionales==8){sauna=true;}
		if(eleccion_de_adicionales==9){recepcion_24_hrs=true;}
		if(eleccion_de_adicionales==10){piso_casa=true;}
	}

	function adicion_wifi(){return wifi;}
	function adicion_wifi(){return refrigaracion;}
	function adicion_wifi(){return parqueadero;}
	function adicion_wifi(){return gimnasio;}
	function adicion_wifi(){return restaurante;}
	function adicion_wifi(){return piscina;}
	function adicion_wifi(){return spa;}
	function adicion_wifi(){return sauna;}
	function adicion_wifi(){return recepcion_24_hrs;}
	function adicion_wifi(){return piso_casa;}


	function enviar_compra(price){return parseFloat(price);}

	function mostrar(id_click, id_banner){
		$(id_click).click(function(e){
			$(id_banner).fadeIn(2000);
			e.preventDefault();
			return false;
		})
		$(id_banner).mouseleave(function(e){
			$(id_banner).hide(2000);
			e.preventDefault();
			return false;
		})
	}