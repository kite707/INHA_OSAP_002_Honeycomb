# Docker에서 프로젝트 실행
```
docker load -i build_test.tar   //build_test.tar 파일로부터 이미지 로드
docker run -it build_test  // 로드한 이미지 실행


cd build //build폴더 이동, build 폴더에 메인파일, 테스트파일 존재

./main.out //프로젝트 파일 실행
./tree_test //테스트 파일 실행
```