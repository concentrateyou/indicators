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
// Global variables
var builder = null;
var components = [];
var action = null;
var values = {};

// Initialization
function init() {
	builder = Qt.createComponent("../Block.qml");
	if(builder.status != Component.Ready)
	    console.log("Error: " + builder.errorString());
	app.init();
}

// Indicator Functions
function createIndicator(name){
	app.init();
	app.create(name);
}

// Menu actions handling
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

// Indexes Handling
function addIndex(parentId, nameField, weightField, borneFField, borneUField, valueField){
	console.log('Adding an index ...');
	// todo: check and validate values !
	app.addIndex(nameField, parseInt(parentId), parseFloat(weightField), 
		parseFloat(valueField), parseFloat(borneFField), parseFloat(borneUField));
}
function editIndex(id, nameField, weightField, borneFField, borneUField, valueField){
	console.log('Editing an index ...');
	console.log('F: ' + borneFField +' & U: ' + borneUField);
	// todo: check and validate values !
	app.editIndex(parseInt(id), nameField, parseFloat(weightField), 
		parseFloat(valueField), parseFloat(borneFField), parseFloat(borneUField));
}
function submitIndex(parentId, num, nameField, weightField, borneFField, borneUField, valueField){
	if(num == -1)
		addIndex(parentId, nameField, weightField, borneFField, borneUField, valueField);
	else
		editIndex(num, nameField, weightField, borneFField, borneUField, valueField);
}

// Module Handling
function addModule(parentId, nameField, weightField){
	console.log('Adding a Module ...');
	// todo: check and validate values !
	app.addModule(nameField, parseInt(parentId), parseFloat(weightField));
}
function editModule(id, nameField, weightField){
	console.log('Editing a Module ...');
	// todo: check and validate values !
	app.editModule(parseInt(id), nameField, parseFloat(weightField));
}
function submitModule(parentId, num, nameField, weightField){
	if(num == -1)
		addModule(parentId, nameField, weightField);
	else
		editModule(num, nameField, weightField);
}

// Design Functions
// Box Class
var Box = function(parentId, id, type, name, childs){
	this.parentId = parentId;
	this.id = id;
	this.type = type;
	this.name = name;
	this.childs = childs;
	this.component = null;
	this.totalWidth = 0;
	this.totalHeight = 0;

	this.makeComponent();
}
// Static attributes of Box
Box.data = {}; // application data
Box.blocks = {}; // interface blocks
// Static methods of Box
Box.clear = function (){
	for(var i in Box.blocks){
		if(Box.blocks[i].component != null){
			Box.blocks[i].component.visible = false;
			Box.blocks[i].component.destroy();
			Box.blocks[i].component = null;
		}
	}
	Box.blocks = {};
	content.visible = false;
	content.visible = true;
}
Box.init = function(){
	// Loading data from the application
	Box.data.indicator = app.indicator;
	Box.data.indexes = app.indexes;
	Box.data.modules = app.modules;
	// Creating boxes
	var i = Box.data.indicator;
	Box.blocks[0] = new Box(-1, 0, 'indicator', i.name, i.childs);
	for(var key in Box.data.indexes){
		i = Box.data.indexes[key];
		Box.blocks[i.num] = new Box(i.parentId, i.num, 'index', i.name + '('+i.num+')', i.childs);
	}
	for(var key in Box.data.modules){
		i = Box.data.modules[key];
		Box.blocks[i.num] = new Box(i.parentId, i.num, 'module', i.name + '('+i.num+')', i.childs);
	}
}
Box.draw = function(){
	Box.blocks[0].drawAt(5, 5);
	content.visible = false;
	content.visible = true;
}
// Instance methods of Box
Box.prototype.makeComponent = function(){
	// parentId, id, type, name, childs, component, totalWidth, totalHeight
	this.component = builder.createObject(content);
	this.component.num = this.id;
	this.component.name = this.name;
	this.component.type = this.type;
	this.component.visible = false;
	switch(this.type){
		case 'indicator':
			this.makeIndicator();
		break;
		case 'index':
			this.makeIndex();
		break;
		case 'module':
			this.makeModule();
		break;
	}
}
Box.prototype.makeIndicator = function(){
	this.component.withReduce = this.component.withClose = false;
	this.component.indexAddClicked.connect(function(){
		indexForm.parentId = 0;
		indexForm.num = -1;
		indexForm.nameField = '';
		indexForm.weightField = '';
		indexForm.borneFField = '';
		indexForm.borneUField = '';
		indexForm.valueField = '';
		indexForm.open();
	});
	this.component.moduleAddClicked.connect(function(){
		moduleForm.parentId = 0;
		moduleForm.num = -1;
		moduleForm.nameField = '';
		moduleForm.weightField = '';
		moduleForm.open();
	});
}
Box.prototype.makeIndex = function(){
	var self = this;
	this.component.withIndexAdd = this.component.withModuleAdd = this.component.withReduce = false;
	this.component.closed.connect(function(){
		app.removeIndex(self.id);
	});
	this.component.doubleClicked.connect(function(){
		indexForm.parentId = -1;
		indexForm.num = self.id;
		indexForm.nameField = self.name;
		indexForm.weightField = Block.data.indexes[self.id].weight;
		indexForm.borneFField = Block.data.indexes[self.id].borneFav;
		indexForm.borneUField = Block.data.indexes[self.id].borneUnfav;
		indexForm.valueField = Block.data.indexes[self.id].value;
		indexForm.open();
	});
}
Box.prototype.makeModule = function(){
	var self = this;
	this.component.withIndexAdd = this.component.withModuleAdd = this.component.withReduce = true;
	this.component.closed.connect(function(){
		app.removeModule(self.id);
	});
	this.component.indexAddClicked.connect(function(){
		indexForm.parentId = self.id;
		indexForm.num = -1;
		indexForm.nameField = '';
		indexForm.weightField = '';
		indexForm.borneFField = '';
		indexForm.borneUField = '';
		indexForm.valueField = '';
		indexForm.open();
	});
	this.component.moduleAddClicked.connect(function(){
		moduleForm.parentId = self.id;
		moduleForm.num = -1;
		moduleForm.nameField = '';
		moduleForm.weightField = '';
		moduleForm.open();
	});
	this.component.doubleClicked.connect(function(){
		moduleForm.parentId = -1;
		moduleForm.num = self.id;
		moduleForm.nameField = self.name;
		moduleForm.weightField = Block.data.modules[self.id].weight;
		moduleForm.open();
	});
}
Box.prototype.drawAt = function(x, y) {
	console.log('Drawing box ' + this.id + ' at (' + x + ', ' + y + ')');
	this.component.x = x;
	this.component.y = y;
	this.component.visible = true;
	y = y + this.component.height + 10;
	for(var i in this.childs){
		Box.blocks[this.childs[i]].drawAt(x, y);
		x = x + Box.blocks[this.childs[i]].component.width + 10;
	}
};
// Rendering function
function render(){
	console.log('Rendering ...');
	app.show();
	Box.clear();
	Box.init();
	Box.draw();
}