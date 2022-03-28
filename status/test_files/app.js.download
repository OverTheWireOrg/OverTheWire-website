var checkInterval = 60 * 1000; // 1 minute
var reloadInterval = 24 * 3600 * 1000; // 1 day
var expireTime = 20 * 60 * 1000; // 20 minutes

var getLastUpdate = function (data) {
	var vals = data.map(e => parseFloat(e.timestamp));
	var lastUpdate = Math.max(...vals);
	return lastUpdate;
}

var loadData = function (app) {
	fetch("/games.json").then(
		function (response) {
			response.json().then(function (data) {
				app.games = data;
				var tsi = Math.floor((new Date()).getTime() / (1000 * 10));

				data.forEach(gamename => {
					fetch("/data/game-" + gamename + ".json?" + tsi).then(
						function (response) {
							response.json().then(function (gamedataobj) {
								// this makes sure data reactivity is triggered...
								Vue.set(app.gamedata, gamename, gamedataobj);
								app.lastUpdated[gamename] = getLastUpdate(gamedataobj);
							});
						});
				});
			});
		}
	);
}

var app = new Vue({
	el: "#app",
	data: {
		games: [],
		gamedata: {},
		lastUpdated: {},
	},
	methods: {
		makeArrow(str) {
			if (str == undefined) { return str; }
			var textArea = document.createElement('textarea');
			textArea.innerHTML = str.replace(">", "&rarr;").replace(" ", "&nbsp;");
			return textArea.value;
		},
		notUpdated(gamename) {
			// if no info, then indicate not updated
			if (app.lastUpdated[gamename] == undefined) return true;

			var elapsed = (new Date()).getTime() - (app.lastUpdated[gamename] * 1000);
			if (elapsed > expireTime) return true;

			return false;
		}
	},
	created: function () {
		var app = this;

		// start interval timers to reload data and page
		setInterval(function () { loadData(app); }, checkInterval);
		setInterval(document.location.reload, reloadInterval);

		loadData(app);
	}
});
