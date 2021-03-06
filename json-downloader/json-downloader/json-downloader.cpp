// json-downloader.cpp
//

#include "pch.h"

std::shared_ptr<spdlog::logger> console = spdlog::stdout_color_mt("console");
std::string strDecopressionOption;

int download(std::string url, std::string filename);
int decompress(std::list<std::string> filenames);
void printHelp(std::string arg0);

int main(int argc, char* argv[])
{
	strDecopressionOption.clear();

	if ( console == nullptr )
	{
		console = spdlog::stdout_color_mt("console");
	}

	if ( argc < 2 )
	{
		printHelp( std::string(argv[0]) );
		return 1;
	}

	// make lower
	std::string arg1 = std::string(argv[1]);
	std::transform(arg1.begin(), arg1.end(), arg1.begin(),
		[](unsigned char c) { return std::tolower(c); });

	if (arg1 == "-h" ||
		arg1 == "--h" ||
		arg1 == "-help" ||
		arg1 == "--help" ||
		arg1 == "/?")
	{
		printHelp(std::string(argv[0]));
		return 1;
	}

	std::string jsonFilename(argv[1]);
	std::ifstream jsonFile( jsonFilename );
	if (!jsonFile.is_open())
	{
		console->error( "Failed to load {0}", jsonFilename );
		return (-1);
	}

	json downloadListJson;

	try
	{
		downloadListJson = json::parse(jsonFile);
	}
	catch (json::parse_error& e)
	{
		console->error( "{0}", e.what() );
		return (-2);
	}

	curl_global_init(CURL_GLOBAL_ALL);

	std::list<std::string> filenameList;


	for (auto& x : downloadListJson.items())
	{
		std::string strKey = x.key();
		if (strKey.empty())
			continue;

		std::string strValue = x.value(); 
		if (strValue.empty())
			continue;

		if ( strKey == "decompress" )
		{
			strDecopressionOption = strValue;
			continue;
		}

		int ret = download( strKey, strValue );
		if (ret != 0) 
		{
			console->error( "Failed to download : {0}", strKey);
			continue;
		}
		filenameList.push_back(strValue );
	}

	if (!strDecopressionOption.empty())
	{
		int ret = decompress( filenameList );
	}

	curl_global_cleanup();

	return 0; 
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
	console->info(" {0}, {1}", size, nmemb );
	return written;
}

int download(std::string url, std::string filename)
{
	CURL* curl_handle = curl_easy_init();

	curl_easy_setopt( curl_handle, CURLOPT_URL, url.c_str() );
	curl_easy_setopt( curl_handle, CURLOPT_VERBOSE, 1L );
	curl_easy_setopt( curl_handle, CURLOPT_NOPROGRESS, 1L );
	curl_easy_setopt( curl_handle, CURLOPT_WRITEFUNCTION, write_data );

	FILE* pagefile = fopen( filename.c_str(), "wb" );
	if ( !pagefile )
	{
		console->error( "Failed to create file : {0}", filename );
		curl_easy_cleanup(curl_handle);
		return (-1);
	}

	curl_easy_setopt( curl_handle, CURLOPT_WRITEDATA, pagefile );

	console->info( "Download : {0}", url );
	curl_easy_perform( curl_handle );
	fclose( pagefile );
	console->info( "Success to download : {0}", url );

	curl_easy_cleanup(curl_handle);
	return 0;
}

int decompress(std::list<std::string> filenames)
{
	// strDecopressionOption 
	return 0;
}

void printHelp(std::string arg0)
{
	std::cout << std::endl;
	std::cout << " json-downloader" << std::endl; 
	std::cout << " - usage: json-downloader <JSON FILE> " << std::endl;
	std::cout << " - format of JSON: { URL1 : LocalFileName1, URL2 : LocalFileName2 }\n" << std::endl;

	std::string platformData;

	platformData.append( std::string(" Compiler:msvc") );
	platformData.append( std::to_string(_MSC_VER) );

	platformData.append(std::string(", Platform:"));
#ifdef _WIN64 
		platformData.append( std::string("x64") );
#else
		platformData.append(std::string("x86"));
#endif

    platformData.append(std::string(", Built:"));
	platformData.append(std::string(__DATE__));

	std::cout << platformData << std::endl;

	std::cout << " See https://github.com/j2doll/json-downloader for more information." << std::endl;
	std::cout << " Leave me a issue. https://github.com/j2doll/json-downloader/issues " << std::endl;
}
