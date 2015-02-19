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
var blockBuilder = null;
var linkBuilder = null;
var components = [];
var action = null;
var values = {};

// Initialization
function init() {
	blockBuilder = Qt.createComponent("../Block.qml");
	if(blockBuilder.status != Component.Ready)
	    console.log("Error: " + blockBuilder.errorString());
	linkBuilder = Qt.createComponent("../Link.qml");
	if(linkBuilder.status != Component.Ready)
	    console.log("Error: " + linkBuilder.errorString());
	app.init();
}

// Indicator Functions
function createIndicator(name){
	app.init();
	app.create(name);
}

// Menu actions handling
var tempId = null;
function setAction(a, tid){
	action = a;
	tempId = tid;
}
function doAction(filename){
	filename = filename.toString().replace('file://', '');
	switch(action){
		case 'save':
			app.save(filename);
		break;
		case 'load':
			app.load(filename);
		break;
		case 'export:PDF':
			miniMenu.height = 0;
			content.color = '#ffffff';
			if(filename.lastIndexOf('.') == -1 || filename.substring(filename.lastIndexOf('.')).trim() != '.pdf')
				filename += '.pdf';
			app.exportAsPDF(filename);
			content.color = '#cccccc';
			miniMenu.height = 35;
		break;
		case 'export:PNG':
			miniMenu.height = 0;
			content.color = '#ffffff';
			if(filename.lastIndexOf('.') == -1 || filename.substring(filename.lastIndexOf('.')).trim() != '.png')
				filename += '.png';
			app.exportAsJPG(filename);
			content.color = '#cccccc';
			miniMenu.height = 35;
		break;
		case 'export:XML':
			if(filename.lastIndexOf('.') == -1 || filename.substring(filename.lastIndexOf('.')).trim() != '.xml')
				filename += '.xml';
			app.exportAsXML(filename);
		break;
		case 'export:CSV':
			if(filename.lastIndexOf('.') == -1 || filename.substring(filename.lastIndexOf('.')).trim() != '.csv')
				filename += '.csv';
			app.exportAsCSV(filename);
		break;
		case 'import:XML':
			app.init();
			app.importXML(filename);
			render();
		break;
		case 'import:module':
			app.importModuleFromXML(tempId, filename);
			render();
		break;
		case 'export:module':
			if(filename.lastIndexOf('.') == -1 || filename.substring(filename.lastIndexOf('.')).trim() != '.xml')
				filename += '.xml';
			app.exportModuleAsXML(tempId, filename);
		break;
	}
	action = null;
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
var Box = function(parentId, id, dataId, type, name, childs){
	this.parentId = parentId;
	this.id = id;
	this.dataId = dataId;
	this.type = type;
	this.name = name;
	this.childs = childs;
	this.component = null;
	this.totalWidth = 0;
	this.totalHeight = 0;
}
// Static attributes of Box
Box.data = {}; // application data
Box.blocks = {}; // interface blocks
Box.links = [];
Box.reduced = [];
// Static methods of Box
Box.clear = function (){
	for(var i in Box.blocks){
		if(Box.blocks[i].component != null){
			Box.blocks[i].component.visible = false;
			Box.blocks[i].component.destroy();
			Box.blocks[i].component = null;
		}
	}
	for(var i in Box.links)
		if(Box.links[i] != null){
			Box.links[i].visible = false;
			Box.links[i].destroy();
		}
	Box.blocks = {};
	Box.links = [];
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
	Box.blocks[0] = new Box(-1, 0, 0, 'indicator', i.name, i.childs);
	for(var key in Box.data.indexes){
		i = Box.data.indexes[key];
		Box.blocks[i.num] = new Box(i.parentId, i.num, key, 'index', i.name, i.childs);
	}
	for(var key in Box.data.modules){
		i = Box.data.modules[key];
		Box.blocks[i.num] = new Box(i.parentId, i.num, key, 'module', i.name, i.childs);
	}
}
Box.indexAt = function(id){
	return Box.blocks[id];
}
Box.moduleAt = function(id){
	return Box.blocks[id];
}
Box.makeComponents = function(){
	for(var i in Box.blocks)
		Box.blocks[i].makeComponent();
}
Box.computeWH = function(){
	var wh = Box.blocks[0].getWH();
	// console.log('tw: ' + wh.w);
	// console.log('th: ' + wh.h);
	return wh;
}
Box.draw = function(){
	Box.makeComponents();
	var dim = Box.computeWH();
	content.width = Math.max(content.width, dim.w);
	content.height = Math.max(content.height, dim.h);
	Box.blocks[0].drawAt((content.width - dim.w) / 2, 5);
	content.visible = false;
	content.visible = true;
}
Box.drawLink = function(startX, startY, endX, endY){
	var temp = Math.min(startX, endX);
	endX = Math.max(startX, endX);
	startX = temp;
	// console.log('link from ('+startX+' , '+startY+' ) to ( '+endX+' , '+endY+' )');
	var l = linkBuilder.createObject(content);
	l.x = startX;
	l.y = startY;
	l.width = endX - startX + 2;
	l.height = endY - startY + 2;
	Box.links.push(l);
}
// Instance methods of Box
Box.prototype.makeComponent = function(){
	// parentId, id, type, name, childs, component, totalWidth, totalHeight
	this.component = blockBuilder.createObject(content);
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
	var self = this;
	this.component.withReduce = this.component.withClose = false;
	this.component.value = Box.data.indicator.value;
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
	this.component.doubleClicked.connect(function(){
		// indicatorForm.nameField = self.name;
		// indicatorForm.open();
	});
}
Box.prototype.makeIndex = function(){
	var self = this;
	this.component.withIndexAdd = this.component.withModuleAdd = this.component.withReduce = false;
	this.component.value = Box.data.indexes[self.dataId].value;
	this.component.weight = 'W: ' + Box.data.indexes[self.dataId].weight;
	this.component.borneF = 'BF: ' + Box.data.indexes[self.dataId].borneFav;
	this.component.borneU = 'BU: ' + Box.data.indexes[self.dataId].borneUnfav;
	this.component.closed.connect(function(){
		app.removeIndex(self.id);
		render();
	});
	this.component.doubleClicked.connect(function(){
		indexForm.parentId = -1;
		indexForm.num = self.id;
		indexForm.nameField = self.name;
		indexForm.weightField = Box.data.indexes[self.dataId].weight;
		indexForm.borneFField = Box.data.indexes[self.dataId].borneFav;
		indexForm.borneUField = Box.data.indexes[self.dataId].borneUnfav;
		indexForm.valueField = Box.data.indexes[self.dataId].value;
		indexForm.open();
	});
}
Box.prototype.makeModule = function(){
	var self = this;
	this.component.withIndexAdd = this.component.withModuleAdd = this.component.withReduce = true;
	this.component.value = Box.data.modules[self.dataId].value;
	this.component.weight = 'W: ' + Box.data.modules[self.dataId].weight;
	if(Box.reduced.indexOf(this.id) != -1)
		this.component.isReduced = true;
	this.component.closed.connect(function(){
		app.removeModule(self.id);
		render();
	});
	this.component.reduced.connect(function(){
		Box.reduced.push(self.id);
		render();
	});
	this.component.expand.connect(function(){
		var ii = Box.reduced.indexOf(self.id);
		if(ii != -1)
			Box.reduced.splice(ii, 1);
		render();
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
		moduleForm.weightField = Box.data.modules[self.dataId].weight;
		moduleForm.open();
	});
}
Box.prototype.getWH = function() {
	if(this.totalHeight === 0 && this.totalWidth === 0){
		this.totalWidth = 10;
		this.totalHeight = 10;
		if(this.type === 'index' || Box.reduced.indexOf(this.id) != -1){
			this.totalWidth += this.component.width;
			this.totalHeight += this.component.height;
		} else {
			var t = {w: 0, h: 0};
			for(var k in this.childs){
				var i = Box.blocks[this.childs[k]].getWH();
				t.w += i.w;
				t.h += i.h;
			}
			this.totalWidth += Math.max(this.component.width, t.w);
			this.totalHeight += Math.max(this.component.height, t.h);
		}
	}
	return {
		w: this.totalWidth,
		h: this.totalHeight
	};
}
Box.prototype.drawAt = function(x, y) {
	// console.log('Drawing box ' + this.id + ' at (' + x + ', ' + y + ')');
	this.component.x = x + (this.totalWidth - this.component.width) / 2;
	this.component.y = y;
	this.component.visible = true;
	if(Box.reduced.indexOf(this.id) != -1)
		return;
	y = y + this.component.height + 16;
	var flag = false;
	for(var i in this.childs){
		var child = Box.blocks[this.childs[i]];
		child.drawAt(x, y);
		Box.drawLink(
			this.component.x + this.component.width / 2,
			this.component.y + this.component.height + 8,
			x + child.totalWidth / 2,
			this.component.y + this.component.height + 8
		);
		Box.drawLink(
			x + child.totalWidth / 2,
			this.component.y + this.component.height + 8,
			x + child.totalWidth / 2,
			this.component.y + this.component.height + 16
		);
		x = x + child.totalWidth;
		flag = true;
	}
	if(flag)
		Box.drawLink(
			this.component.x + this.component.width / 2,
			this.component.y + this.component.height,
			this.component.x + this.component.width / 2,
			this.component.y + this.component.height + 8
		);
};
// Rendering function
function render(){
	app.updateValue();
	Box.clear();
	Box.init();
	Box.draw();
	console.log(Box.blocks[0].getWH());
}

// Checking Functions
function check(form){
	var result = false;
	switch(form){
		case 'indicator':
			result = checkIndicator();
		break;
		case 'index':
			result = checkIndex();
		break;
		case 'module':
			result = checkModule();
		break;
	}
	return result;
}
function checkIndicator(){
	var result = true;
	
	if(indicatorForm.nameField.trim() == ''){
		result = false;
		indicatorForm.nameColor = '#ee0000';
	} else indicatorForm.nameColor = '#000000';
	
	return result;
}
function checkIndex(){
	var result = true;

	if(indexForm.nameField.trim() == ''){
		result = false;
		indexForm.nameColor = '#ee0000';
	} else indexForm.nameColor = '#000000';
	
	if(isNaN(indexForm.weightField) || indexForm.weightField.trim() == ''){
		result = false;
		indexForm.weightColor = '#ee0000';
	} else indexForm.weightColor = '#000000';

	if(isNaN(indexForm.borneFField) || indexForm.borneFField.trim() == ''){
		result = false;
		indexForm.borneFColor = '#ee0000';
	} else indexForm.borneFColor = '#000000';

	if(isNaN(indexForm.borneUField) || indexForm.borneUField.trim() == ''){
		result = false;
		indexForm.borneUColor = '#ee0000';
	} else indexForm.borneUColor = '#000000';

	if(isNaN(indexForm.valueField) || indexForm.valueField.trim() == ''){
		result = false;
		indexForm.valueColor = '#ee0000';
	} else indexForm.valueColor = '#000000';

	return result;
}
function checkModule(){
	var result = true;

	if(moduleForm.nameField.trim() == ''){
		result = false;
		moduleForm.nameColor = '#ee0000';
	} else moduleForm.nameColor = '#000000';
	
	if(isNaN(moduleForm.weightField) || moduleForm.weightField.trim() == ''){
		result = false;
		moduleForm.weightColor = '#ee0000';
	} else moduleForm.weightColor = '#000000';

	return result;
}