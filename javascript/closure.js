/**클로져는 내부함수와 밀접한 관계를 가지고 있는 주제임
 * 내부함수는 외부함수의 자역변수에 접근 가능한데 외부함수의 실행이 끝나서 외부함수가 소멸함 이후에도 내부함수가 외부함수의 변수에 접근할 수 있다.
 * 이러한 메커니즘을 클로저라고 한다.
*/

//기본적인 형태
/*
function outter(){
    var outter_var = 1;
    return function(){
        console.log(outter_var);
    }
}

var inner = outter();
inner(); 
*/

//private variable
/*
function f(title)
{
    return {
        get_title : function (){
            return title;
        },
        
        set_title : function(_title){
            if(typeof _title === 'string')
            {
                title = _title;
            }

            else console.log("not String");
            
        }
    }
}

var a = f('a');
var b = f('b');

console.log(a.get_title());
a.set_title("basdf");
console.log(a.get_title());
*/

//frquently occured mistakes

var arr = [];
for(var i = 0; i < 5; i++)
{
    arr[i] = function(temp_i){
        return function(){
            console.log(temp_i);
        }
    }(i);
}

for(var index in arr)
{
    arr[index]();
}