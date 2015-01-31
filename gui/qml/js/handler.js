var userComponent = null;
var users = [];
function init() {
	console.log("Starting ... ");
	userComponent = Qt.createComponent("../user.qml");
	if(userComponent.status != Component.Ready)
		if( userComponent.status == Component.Error)
	        console.debug("Error:"+ userComponent.errorString() );
	app.load('data');
}

function add(name){
	console.log("Adding : " + name);
	name = name.trim();
	if(name != ''){
		app.addName(name);
	}
}

function showUsers(){
	console.log("Showing users");
	// Cleaning existing 
	for(var i = 0; i < users.length; i++)
		if(users[i] != null)
			users[i].destroy();
	users = [];
	for(var i in app.users) {
		var d = userComponent.createObject(content);
		d.num = app.users[i].num;
		d.name = app.users[i].name;
		users.push(d);
	}
	app.save('data');
}