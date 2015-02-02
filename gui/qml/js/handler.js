/*
Indicator : name, value, childs
Index : num, name, weight, value, parentId, borneFav, borneUnfav, 
Module : num, name, weight, value, parentId, childs
App : indicator, indexes, modules
	init()
	create(QString name)
	load(QString fileName)
	save(QString fileName)
	export(QString fileName)
	import(QString fileName)
	addIndex(QString name, int parentId, double weight, double value, double borneFav, double borneUnfav)
	editIndex(int id, QString name, double weight, double value, double borneFav, double borneUnfav)
	addModule(QString name, int parentId, double weight, double value)
	editModule(int id, QString name, double weight)
*/
var builder = null;
var blocks = [];
var action = null;

function init() {
	builder = Qt.createComponent("../Block.qml");
	if(builder.status != Component.Ready)
	    console.log("Error: " + builder.errorString());
	app.init();
}

function createIndicator(name){
	app.init();
	app.create(name);
}

function setAction(a){
	action = a;
}

function doAction(filename){
	switch(action){
		case 'save':
			saveIndicator(filename);
		break;
		case 'load':
			loadIndicator(filename);
		break;
	}
	action = null;
}

function saveIndicator(filename){
	console.log('saving ...');
	app.save(filename.toString().replace('file://', ''));
}

function loadIndicator(filename){
	console.log('loading ...');
	app.load(filename.toString().replace('file://', ''));
}

function addIndex(parentId, nameField, weightField, borneFField, borneUField, valueField){
	console.log('Adding an index ...');
	app.addIndex(nameField, parseInt(parentId), parseFloat(weightField), 
		parseFloat(valueField), parseFloat(borneFField), parseFloat(borneUField));
}

function submitIndex(parentId, num, nameField, weightField, borneFField, borneUField, valueField){
	if(num == -1)
		addIndex(parentId, nameField, weightField, borneFField, borneUField, valueField);
	else
		editIndex(num, nameField, weightField, borneFField, borneUField, valueField);
}

function clear(){
	for(var i in blocks)
		if(blocks[i] != null){
			blocks[i].visible = false;
			blocks[i].destroy();
		}
	blocks = [];
	content.visible = false;
	content.visible = true;
}

function makeIndicator(){
	var b = builder.createObject(content);
	b.x = (content.width - b.width) / 2;
	b.y = 5;
	b.withReduce = b.withClose = false;
	b.name = app.indicator.name;
	b.type = 'indicator';
	b.num = 0;
	
	b.indexAddClicked.connect(function(){
		indexForm.parentId = 0;
		indexForm.num = -1;
		indexForm.nameField = '';
		indexForm.weightField = '';
		indexForm.borneFField = '';
		indexForm.borneUField = '';
		indexForm.valueField = '';
		indexForm.open();
	});
	b.moduleAddClicked.connect(function(){
		console.log('Adding module to indicator');
	});
	return b;
}

function render(){
	clear();
	blocks.push(makeIndicator());
	var x = 5;
	console.log(app.indexes);
	for(var i in app.indexes){
		var c = app.indexes[i];
		var b = builder.createObject(content);
		b.name = c.name;
		b.num = c.num;
		b.type = 'index';
		b.withIndexAdd = b.withModuleAdd = b.withReduce = false;
		b.closed.connect(function(){
			app.removeIndex(b.num);
		});
		blocks.push(b);

		b.x = x;
		b.y = 85;

		x += b.width + 10;
	}
}