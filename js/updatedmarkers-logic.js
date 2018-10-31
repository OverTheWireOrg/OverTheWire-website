function getSeenTimestamp(link) {
	return window.localStorage["seen-"+link];
}

function setSeenTimestamp(link, value) {
	window.localStorage["seen-"+link] = value;
}


function shouldDisplay(updatedts, lastseents) {
	if(updatedts == undefined) return false;
	if(lastseents == undefined) return true;
	return updatedts > lastseents;
}


function renderUpdatedMarkers() {
	$(".updatedmarker").each(function(idx, marker) {
		var markerdata = $(marker).data();
		var markerlink = markerdata["link"];
		var updatedts = updatedmarkers[markerlink];
		var seents = getSeenTimestamp(markerlink);

		if(shouldDisplay(updatedts, seents)) {
			$(marker).addClass("updatedmarker-active");
		}

	});

	// go over every entry in the updatedmarkers dict and
	// check whether we are currently on that page.
	// If we are, update the seen timestamp
	var currentpage = window.location.pathname;
	for(var key in updatedmarkers) {
		if(currentpage == key) {
			setSeenTimestamp(currentpage, updatedmarkers[key]);
		}
	}
};

renderUpdatedMarkers();

