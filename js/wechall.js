function displayWechallBox(data) {
    console.log("Displaying box "+data);
    // create a div, draggable, with form inside
    var $div = $('<div />').appendTo('#content');
    $div.attr('id', 'wechallform');

    $("#wechallform").hide();
    $("#wechallform").html(
    		"<form action=\""+data["form"]+"\" enctype=\"application/x-www-form-urlencoded\" method=\"post\">"+
		"<input type=\"hidden\" name=\"wfid\" value=\""+data["wfid"]+"\" />"+
		"<input type=\"text\" name=\"password_solution\" value=\"\" placeholder=\"Level token\"/>"+
		"<input type=\"submit\" name=\"igotitnow\" value=\"Submit\" />"+
		"</form>"
		);
    $("#wechallform").draggable({zIndex: 2500});
    $("#wechallform").show();
}


$(document).ready(function() {
    $.ajax({
	dataType: "json",
	url: "/js/wechall-data.json",
	success: function(data) {
	    console.log("[wechall] JSON data loaded");
	    if(window.location.pathname in data) {
		console.log("[wechall] JSON contains data for this page, rendering...");
	        displayWechallBox(data[window.location.pathname]);
	    }
	}
    });
});

