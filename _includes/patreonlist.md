{% raw %}
<div id="patreoncontainer">
</div>

<div id="container-angel" class="patreon-tier patreon-tier-angel" style="display: none">
	<h1>"Angel" Support Level</h1>
</div>

<div id="container-fancy" class="patreon-tier patreon-tier-fancy" style="display: none">
	<h1>"Fancy" Support Level</h1>
    <div id="parent-fancy">
    </div>
</div>






<script id="item-angel" type="text/template">
    <div class="patron-angel">
		<a href="{{url}}">
			<div class="logo"><img src="{{logo}}"></div>
			<div class="content">
				<span class="name">{{name}}</span>
				<div class="text">{{text}}</div>
			</div>
		</a>
    </div>
</script>

<script id="item-fancy" type="text/template">
    <span>{{name}}</span>
</script>


<script>
    var templates = [
		{ 'name': '"Angel" Support Level', 'container': '#container-angel', 'parent': '#container-angel', 'template': '#item-angel' },
		{ 'name': '"Fancy" Support Level', 'container': '#container-fancy', 'parent': '#parent-fancy', 'template': '#item-fancy' },
    ];

    fetch("/patreon/patrons.json").then(response => response.json()).then(function(data) {
        console.log(data);

		templates.forEach(function(te) {
			var c = $(te.container);
			var p = $(te.parent);
			var entries = data[te.name];
			var template = $(te.template).html();

			if(entries && template) {
				entries.forEach(function(item) {
					var html = Mustache.render(template, item);
					p.append(html);
				});

				// show the container
				if(entries.length > 0) { c.show(); }
			}
        });
    }).catch(console.log);

</script>

{% endraw %}
