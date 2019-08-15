# json-downloader

> *Read this in other languages: [English](README.md), :kr: [한국어](README.ko.md)*

## Introduction
- File Downloader for Windows Console
- It is written for personal purpose.

### DONE
- Ability to download files continuously
- Getting a download list from a json file

### TODO
- Extract files from compressed files	

## How to use program
- Execute 'json-downloader.exe' with json parameter 
```cmd
json-downloader.exe data.json
```

### Json file format
- The json file(such as data.json) consists of the following:
```json
{
	"https://raw.githubusercontent.com/j2doll/json-downloader/master/README.md" : "README.md" ,
	"https://raw.githubusercontent.com/j2doll/json-downloader/master/LICENSE" : "LICENSE" 
}
```
- The first argument is the URL of the file you want to download.
- The second argument is the name of the file to be saved locally.

## Requred Build Environment
- Visual Studio 2017 (x86/x64)

## License and links
- json-downloader is under LGPL 3 license. [https://github.com/j2doll/json-downloader](https://github.com/j2doll/json-downloader)
  - Please leave an issue if you want a commercial version. [https://github.com/j2doll/json-downloader/issues](https://github.com/j2doll/json-downloader/issues)
- curl is under MIT style license. [https://curl.haxx.se/docs/copyright.html](https://curl.haxx.se/docs/copyright.html)
- JSON for Modern C++ is under MIT license. [https://github.com/nlohmann/json/releases](https://github.com/nlohmann/json/releases)
- spdlog is under MIT license. [https://github.com/gabime/spdlog](https://github.com/gabime/spdlog)
