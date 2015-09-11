 console.log("Hello Sweetie");

 var taskArray=[];
var taskNumber = taskArray.length;
    var taskListDiv = document.getElementById('taskList');

//update the tasks that are being shown
var updateTask = function(){
    
    // var taskNumber = taskArray.length;

    // var taskListDiv = document.getElementById('taskList');

    taskListDiv.innerText = '';

    for (i = 0; i < taskNumber; i++) {
    	
    	var newTask = document.createElement('div');
    	newTask.id = i;
    	newTask.className = 'task';

    	var task = document.createElement('p');
    	task.innerText = taskArray[i];

    	newTask.appendChild(task);

    	//delete Button
        var deleteButton = document.createElement('button');

         deleteButton.innerText = "x";

         deleteButton.addEventListener('click',function(event){
	        event.preventDefault();
	         deleteTask(event);


         });
        
        newTask.appendChild(deleteButton);

        taskListDiv.appendChild(newTask);
        

    };
};



//the delete function of the delete button
var deleteTask = function(){

	var deleteTaskNumber = event.target.parentElement.id;
	console.log("Now I am deleting" + taskArray[deleteTaskNumber]);
	taskArray.splice(deleteTaskNumber,1);

};

//create delete all button if there are tasks already.
var deleteAll = function(event){
	taskArray.splice(0,taskNumber);
	updateTask();
};

if (taskNumber > 0){
	var deleteAllTask = document.createElement('button');
	deleteAllTask.innerText = "Delete All";
	deleteAllTask.id = "deleteAllTask";

	deleteAllTask.addEventListener('click',function(event){
		event.preventDefault();
		deleteAll();
	});

	taskListDiv.appendChild(deleteAllTask);
};




// add task to list of tasks
var saveTask = function(){

	var taskInput = document.getElementById('newTask');
	var taskValue = taskInput.value;

	if (taskValue!== ""){
		taskArray.push(taskValue);
	    taskValue = "";
	    updateTask();

	};

};

// look in the text box to get task when mouse click;
 var initialize = function(){

 	var addButton = document.getElementById('addButton');
 
    addButton.addEventListener('click',function(event){
 		event.preventDefault();
 		saveTask();
 	});

 };

 window.onload = initialize();