//browser objct model
//전역 객체 window는 자바의 Object와 같이 최상위에 있는 부모 클래스라고 생각하면 될거 같다.
//window는 DOM, BOM, javascript라는 자식들을 가짐

//alert no return value....?
alert("ok");

//confirm return value is bool -> true, false;
confirm("ok?");
if(confirm("ok?")) console.log("good!");

//prompt is return result string that user entered into text box
prompt('id?');
console.log(prompt("id?"));
if(prompt("id?") === "bueno")
{
    console.log("welcome");
}

else console.log("bye^^");

//location is indicate url of currently showed docoument

//href method is more prefered
console.log(location.toString(), location.href);
alert(loaction);

//URL Parsing
console.log(location.protocol, location.host, location.port, location.pathname, location.search, location.hash);

//change URL
location.href = 'http://www.naver.com/';
location = 'http://www.naver.com/';

//reload
location.reload();
location.href = location.href;

//Navigator Object
console.dir(navigator);

//cross browsing, almost browser(ex, ee, ff, safari, chrome) is fit in w3c, ecma
//netscape, microsoft - web standard is important;;;

window.open('BOM.html');
window.open('BOM.html', '_self');
window.open('BOM.html', '_blank');
//if same element is not exist make new tab
window.open('BOM.html', 'ot');
window.open('BOM.html', '_blank', 'width = 200 height = 200, resizable = yes');

//access new window
 
function winopen()
{
    win = window.open("", 'ot', 'width=300px, height==500px');
}

function winmessage(msg)
{
    win.document.getElementById('message').innerText=msg;
}

function winclose()
{
    win.close();
}

//browser security
//pop up will be 차단 with no user interaction

