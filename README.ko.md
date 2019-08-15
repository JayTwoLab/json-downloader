# json-downloader

> *Read this in other languages: [English](README.md), :kr: [한국어](README.ko.md)*

## 소개
- Windows 콘솔용 파일 다운로더
- 개인적 목적으로 작성된 것입니다.

### DONE
- 파일을 지속적으로 다운로드 할 수있는 기능
- json 파일에서 다운로드 목록 가져 오기

### TODO
- 압축 파일에서 파일 추출

## 프로그램 사용 방법
- json 매개 변수로 'json-downloader.exe' 실행
```cmd
json-downloader.exe data.json
```

### Json 파일 포맷
- json 파일(예: data.json)은 다음으로 구성됩니다.
```json
{
	"https://raw.githubusercontent.com/j2doll/json-downloader/master/README.md" : "README.md" ,
	"https://raw.githubusercontent.com/j2doll/json-downloader/master/LICENSE" : "LICENSE" 
}
```
- 첫 번째 인수는 다운로드 할 파일의 URL입니다.
- 두 번째 인수는 로컬에 저장할 파일의 이름입니다.

## 필요한 빌드 환경
- Visual Studio 2019 (x86/x64)

## 라이센스와 링크
- json-downloader는 LGPL 3 라이센스 입니다. [https://github.com/j2doll/json-downloader](https://github.com/j2doll/json-downloader)
  - 상업용 버전을 원하시면 이슈를 남겨주세요. [https://github.com/j2doll/json-downloader/issues](https://github.com/j2doll/json-downloader/issues)
- curl는 MIT 스타일 라이센스 입니다. [https://curl.haxx.se/docs/copyright.html](https://curl.haxx.se/docs/copyright.html)
- JSON for Modern C++는 MIT 라이센스 입니다. [https://github.com/nlohmann/json/releases](https://github.com/nlohmann/json/releases)
- spdlog는 MIT 라이센스 입니다. [https://github.com/gabime/spdlog](https://github.com/gabime/spdlog)
