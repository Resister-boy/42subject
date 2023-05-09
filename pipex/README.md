## requirements
1. argc를 통해 인자가 5개 이상인지 판단
2. argv를 통해 들어온 파일과 명령어를 확인
3. argv[0]은 실행파일 ./pipex
4. argv[1]은 임의의 파일
5. argv[2], argv[3]은 임의의 명령어
6. argv[4]은 임의의 파일
7. argv[2], argv[3]는 인자로 받은 envp를 통해 명령어의 바이너리의 위치를 찾아 해당 경로를 execve()로 실행
8. 