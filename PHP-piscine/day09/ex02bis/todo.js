
$(document).ready(function(){
    $('#new').click(newElem);
    $('#ft_list div').click(deleteEntry);
    ft_list = $('#ft_list');
    cookie = [];
    var tmp = document.cookie;
    if (tmp) {
        cookie = JSON.parse(tmp);
        cookie.forEach(newEntry);
    }
});

$(window).on('unload', unloadTODO);

function unloadTODO() {
    var list_now = ft_list.children();
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
    ft_list.prepend($('<div>' + new_element + '</div>').click(deleteEntry));
}

function deleteEntry() {
    if (confirm("Plese, confirm that you want to delete this task")){
        this.remove();
    }
}