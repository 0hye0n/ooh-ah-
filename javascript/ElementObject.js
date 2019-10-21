//Element Object

//identifier API
//<li id="active" class="important current">JavaScript</li>
console.log(document.getElementById('active').tagName);
//tagname is read only!! if you excute below code, wiil not work
document.getElementById('active').tagName = 'a';

//Element.id
var active = document.getElementById('active');
console.log(active.id);
active.id = 'deactive';
console.log(active.id);


//Element.className -> class is used to grouping elements
active.className = "current";
active.className = active.className + " is important";

//Element.classList -> more convinent than className
var active1 = document.getElementById('active');
active.classList;
active.classList[0];//current
active.classList[1];//is
active.classList[1];//important
active.classList.length;//3
active.classList.add('abc');
active.classList.remove('abc');
active.classList.toggle('abc');

//eventually class is needed for many elements

/*
<a id = "target" href = "./demo1.html">ot</a>
*/

var target = document.getElementById(target);

//http://localhost/webjs/Element/demo1.html
console.log('target.href', target.href);
//./demo1.html
console.log('target.getAttribute("href")', target.getAttribute("href"));


//Element <- HTMLElement <- HTML00Element
