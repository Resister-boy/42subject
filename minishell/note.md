### Todos
1. ambiguous redirect를 핸들링하는 방법에 대하여
>  ambiguous redirect는 export a="ls ls"와 같은 방식으로 환경 변수를 선언하고, 이를 > $a와 같은 방식으로 redirect의 filename의 위치에 넣을 경우 발생한다. 파싱 단계에서 이를 확인하고 redirection type에 하나를 추가해서 실행 단계에서 ambiguous redirect를 반환하는 방식으로 해결할 수 있다. 
