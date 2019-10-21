//control jQuery Attribute API

/*
<a id="target" href="./demo.html" checked="checked">opentutorials</a>
*/
//# -> id
var t = $('#target');
//print href attribute value
console.log(t.attr('href'));//./demo.html
console.log(t.prop('href'));//http://localhost/demo.html

//difference between attr and prop
console.log(t.attr('checked'));//checked
console.log(t.prop('checked'));//true
//set title 'opentutorials.org'
t.attr('title', 'opentutorials.org');
//remove
t.removeAttr('title');

