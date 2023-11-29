# 이미지의 기반이 될 베이스 이미지 선택
FROM ubuntu:latest

# 작업 디렉토리 설정
WORKDIR /app

# 소스 코드 및 CMakeLists.txt를 컨테이너에 복사
COPY . .

# 필요한 패키지 및 의존성 설치
RUN apt-get update \
    && apt-get install -y g++ cmake 

# 프로젝트 빌드
RUN mkdir build && cd build
RUN cd build && cmake .. && make