function solution(n) {
    var answer = 0;
    
    var str = "";
    
    while(parseInt(n) > 0)
    {
        var temp = (n % 3) + '';
        str += parseInt(temp);
        n = n / 3;
    }
    
    for(let i = str.length - 1; i >= 0; --i)
    {
        let ch = str[i];
        let t = ch * Math.pow(3, str.length-i-1);
        answer += t;
    }
    
    return answer;
}
