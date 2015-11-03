var socket = io.connect('http://localhost:3000'); // On se connecte au socket du serveur pour avoir les informations en temps r�el
var sock = io.connect('http://localhost:3080');


// Si le socket nous informe qu'il y a une notification qui se nomme UserState, il executera le callback. 
socket.on('UserState', function (data) {
    // nous ins�rons dans la span la valeur envoy�e par le socket
    $('.connected-number').text(data);
});
socket.on('emit_from_server', function (data) {
    $('.message').text(data);
});