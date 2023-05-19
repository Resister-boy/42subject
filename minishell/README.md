# 42Seoul Minishell 팀 프로젝트

### 팀원 및 역할
* 파싱 : jaehulee
* 실행 : seonghle

### 작업 방식
* 각자의 develop branch에서 작업한 뒤 코드 리뷰 후 main branch에 merge
  * branch는 `develop/intraId`로 만들어 작업

### 파일 네이밍 컨벤션
* 하나의 기능당 하나의 파일로 작성
  * 예시
    * `기능명.c`
  * 하나 더 필요한 경우 `기능명_util.c` 로 작성
  * 기능별로 10개의 함수 이내로 작성 지향

### 커밋 컨벤션
* 아래와 같이 태그에 맞게 작성

|태그 이름|설명|
|---|---|
|feat|새로운 기능 추가|
|fix|버그 수정|
|refactor|기존 기능 변경|
|test|테스트 관련 파일 또는 코드 변경|
|docs|문서 수정|
|remove|파일 삭제|
* 예시
  * `feat: main 기능 추가`
  * `refactor: xx기능 ~~되도록 변경`

### 코딩 컨벤션
* Norminette에 맞게 작성
