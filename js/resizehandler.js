let compactView = false; //Compact View is false in case of Desktop Mode

let container, header, sidemenu, content;
container = document.body;
header = document.querySelector('header');
sidemenu = document.querySelector('#sidemenu');
content = document.querySelector('#content');

let bodyHt, bodyWt, headerHt, sidemenuTopGap, sidemenuWt, contentLeftGap;
headerHt = header.offsetHeight;

function resizeElements(){
    bodyHt = container.offsetHeight;
    bodyWt = container.offsetWidth;
    headerHt = header.offsetHeight;
    sidemenuWt = sidemenu.offsetWidth;
    if(!compactView){//Desktop Mode:
        sidemenuTopGap = headerHt + 20;
        contentLeftGap = sidemenuWt + 40;
        console.log("Setting margin left to: " + contentLeftGap);

        sidemenu.style.top = sidemenuTopGap + "px";
        content.style.marginLeft = contentLeftGap + "px";
    }
}

resizeElements();

window.addEventListener("resize", function(){
    resizeElements();
})