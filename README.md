# json-downloader

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

## Requred Environment
- Visual Studio 2017 x64
- Windows 10 x64 (Maybe it will also build on Windows 7/8 x64.)

## License and links
- json-downloader is under GPL 3 license. [https://github.com/j2doll/json-downloader](https://github.com/j2doll/json-downloader)
- curl is under MIT style license. [https://curl.haxx.se/docs/copyright.html](https://curl.haxx.se/docs/copyright.html)
- JSON for Modern C++ is under MIT license. [https://github.com/nlohmann/json/releases](https://github.com/nlohmann/json/releases)
- spdlog is under MIT license [https://github.com/gabime/spdlog](https://github.com/gabime/spdlog)
- unarr is under LGPL 3 license. [https://github.com/selmf/unarr](https://github.com/selmf/unarr)
