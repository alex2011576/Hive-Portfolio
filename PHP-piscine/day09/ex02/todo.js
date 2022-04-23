var ft_list;
var cookie = []; 

function loadTODO() {
    ft_list = document.getElementById('ft_list');
    var tmp = document.cookie;
    if (tmp) {
        cookie = JSON.parse(tmp);
        cookie.forEach(newEntry);
    }
}

function unloadTODO() {
    var list_now = ft_list.children;
    var newCookie = [];
    for (var i = 0; i < list_now.length; i++)
        newCookie.unshift(list_now[i].innerHTML);
    document.cookie = JSON.stringify(newCookie);
    
} 

function newElem() {
	let new_element = prompt("Create new task:");
	 if (new_element === "")
		 return;
	newEntry(new_element);
}

function newEntry(new_element) {
    var new_entry = document.createElement("div");
	new_entry.innerHTML = new_element;
    new_entry.addEventListener("click", deleteEntry);	
    ft_list.prepend(new_entry);
}

function deleteEntry() {
    if (confirm("Plese, confirm that you want to delete this task")){
        this.remove();
    }
}