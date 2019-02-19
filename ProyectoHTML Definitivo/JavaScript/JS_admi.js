$(document).ready(function() {
	$(".aditamento").hide();
	$("#send_extra").hide();
})
	/*var dirr= new Blob([], {type:type});
	var ubication= new Blob([], {type:type});
	var dirr_img= new Blob([], {type:type});
	var hotel_price= new Blob([], {type:type}); 
	var num_star= new Blob([], {type:type});
	var room_type_1= new Blob([], {type:type});
	var room_type_2= new Blob([], {type:type});
	var room_type_3= new Blob([], {type:type});*/

	var a_wf=0, a_prqdr=0, a_gmns=0, a_rstrnt=0, a_pscn=0, a_sp=0, a_sn=0;
	var valor_wifi, valor_parqueadero, valor_gym, valor_restaurante, valor_piscina, valor_sap, valor_sauna;

	function take_dates() {
		/*
		var aux=document.getElementById('name_hotel').value;
		var hotel= new Blob([aux], {type:"txt"});
		alert(window.navigator.msSaveOrOpenBlob(hotel, "hotel.txt"));
		*/

		hotel=document.getElementById('name_hotel').value;
		dirr=document.getElementById('url').value;
		ubication=document.getElementById('ubi').value;
		dirr_img=document.getElementById('url_img').value;
		hotel_price=parseFloat(document.getElementById('price').value);
		num_star=parseFloat(document.getElementById('stars').value);
		room_type_1=parseFloat(document.getElementById('individuals_rooms').value);
		room_type_2=parseFloat(document.getElementById('doble_rooms').value);
		room_type_3=parseFloat(document.getElementById('familiar_rooms').value);
	}

	function take_additions() {
		$('#avion').hide(2000);
		$("#send_extra").fadeIn(1500);
		$('#aditamentos').css({'position':'absolute','top':'5%','right':'3%'});
		if($('#wifi').prop('checked')){a_wf=1;$("#valor_wifi").fadeIn();}else{a_wf=0;$("#valor_wifi").hide();}
		if($('#parqueadero').prop('checked')){a_prqdr=1;$("#valor_parqueadero").fadeIn();}else{a_prqdr=0;$("#valor_parqueadero").hide();}
		if($('#gimnasio').prop('checked')){a_gmns=1;$("#valor_gym").fadeIn();}else{a_gmns=0;$("#valor_gym").hide();}
		if($('#restaurante').prop('checked')){a_rstrnt=1;$("#valor_restaurante").fadeIn();}else{a_rstrnt=0;$("#valor_restaurante").hide();}
		if($('#piscina').prop('checked')){a_pscn=1;$("#valor_piscina").fadeIn();}else{a_pscn=0;$("#valor_piscina").hide();}
		if($('#spa').prop('checked')){a_sp=1;$("#valor_sap").fadeIn();}else{a_sp=0;$("#valor_sap").hide();}
		if($('#sauna').prop('checked')){a_sn=1;$("#valor_sauna").fadeIn();}else{a_sn=0;$("#valor_sauna").hide();}
	}

	function send_additions() {
		valor_wifi=document.getElementById('valor_wifi').value;
		valor_valor_wifi=document.getElementById('valor_valor_wifi').value;
		valor_valor_parqueadero=document.getElementById('valor_valor_parqueadero').value;
		valor_valor_gym=document.getElementById('valor_valor_gym').value;
		valor_valor_restaurante=document.getElementById('valor_valor_restaurante').value;
		valor_valor_piscina=document.getElementById('valor_valor_piscina').value;
		valor_valor_sap=document.getElementById('valor_valor_sap').value;
		valor_valor_sauna=document.getElementById('valor_valor_sauna').value;
	}

	function nombre_del_hotel() {return hotel;}
	function val_url() {return dirr;}
	function place() {return ubication;}
	function val_url_img() {return dirr_img;}
	function precio() {return hotel_price;}
	function numero_de_estrellas() {return num_star;}
	function numero_de_habitaciones_individuales() {return room_type_1;}
	function numero_de_habitaciones_dobles() {return room_type_2;}
	function numero_de_habitaciones_familiares() {return room_type_3;}

	function val_wifi() {return valor_wifi;}
	function val_valor_wifi() {return valor_valor_wifi;}
	function val_valor_parqueadero() {return valor_valor_parqueadero;}
	function val_valor_gym() {return valor_valor_gym;}
	function val_valor_restaurante() {return valor_valor_restaurante;}
	function val_valor_piscina() {return valor_valor_piscina;}
	function val_valor_sap() {return valor_valor_sap;}
	function val_valor_sauna() {return valor_valor_sauna;}

	function look_for_wifi() {return a_wf;}
	function look_for_parqueadero() {return a_prqdr;}
	function look_for_gimnasio() {return a_gmns;}
	function look_for_restaurante() {return a_rstrnt;}
	function look_for_piscina() {return a_pscn;}
	function look_for_spa() {return a_sp;}
	function look_for_sauna() {return a_sn;}