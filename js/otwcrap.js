function htmlEntities(str) {
    return str.replace(/[\u00A0-\u99999<>\&]/gim, function(i) {
        return '&#'+i.charCodeAt(0)+';';
    });
}

function capitaliseFirstLetter(string) {
    return string.charAt(0).toUpperCase() + string.slice(1);
}

function renderCode(path) {
    var rndID = Math.random().toString(36).substring(7);
    document.write("<div id='"+rndID+"'></div>");
    var oReq = new XMLHttpRequest();
    oReq.onload = function() {
        var newDiv = document.getElementById(rndID);
        newDiv.innerHTML = "";
        var newPre = document.createElement("pre");
        var newCode = document.createElement("code");
        newPre.appendChild(newCode);
        newDiv.appendChild(newPre);
        newCode.innerHTML = htmlEntities(this.responseText);
        hljs.highlightBlock(newCode);
    };
    oReq.open("GET", path, true);
    oReq.send();
}

function renderLevelsMenu(name) {
    var oReq = new XMLHttpRequest();
    oReq.onload = function() {
        var newDiv = document.getElementById("sidemenu");
	var data = JSON.parse(this.responseText);
	
	var newHTML = "";
	if("host" in data[name] && "port" in data[name]) {
	    newHTML += "<div id='sshinfo'><sh>SSH Information</sh><br>Host: "+data[name].host+"<br>Port: "+data[name].port+"</div>";
	}
	newHTML += "<ul><li><a href=\"/wargames/"+name+"\"><sh>"+capitaliseFirstLetter(name)+"</sh></a></li>";

	for(var i = 0; i <= data[name].lastlevel; i++) {
	    var url = "";
	    var urlname = "";
	    url = "/wargames/"+name+"/"+name+i+".html";
	    if(!("specialNumbering" in data[name])) {
		if(i == 0) {
		    urlname = "Level "+i;
		} else {
		    urlname = "Level "+(i-1)+" &rarr; Level "+i;
		}
	    } else {
		    urlname = "Level "+i+" &rarr; Level "+(i+1);
	    }

	    if(window.location.pathname == url) {
		newHTML += "<li><a class='selected' href=\""+url+"\">"+urlname+"</a></li>";
	    } else {
		newHTML += "<li><a href=\""+url+"\">"+urlname+"</a></li>";
	    }
	}

	newHTML += "</ul>";
        newDiv.innerHTML = newHTML;
    };
    oReq.open("GET", "/games.json", true);
    oReq.send();
}

function renderLevelTitle(name, level) {
    var oReq = new XMLHttpRequest();
    oReq.onload = function() {
        var newDiv = document.getElementById("title");
	var data = JSON.parse(this.responseText);

	if(!("specialNumbering" in data[name])) {
	    if(level == 0) {
		title = capitaliseFirstLetter(name) + " Level "+level;
	    } else {
		title = capitaliseFirstLetter(name) + " Level "+(level-1)+" &rarr; Level "+level;
	    }
	} else {
		title = capitaliseFirstLetter(name) + " Level "+level+" &rarr; Level "+(level+1);
	}
        newDiv.innerHTML = "<h1>"+title+"</h1>";

        // also set the webpage title
        document.title += ": " + title.replace('&rarr;', '\u2192');
    };
    oReq.open("GET", "/games.json", true);
    oReq.send();
}

function checkAdBlock() {
    if(typeof fuckAdBlock === 'undefined') {
	alert("congrats on running adblock");
    } else {
	alert("not running adblock");
    }
}
