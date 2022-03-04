#include <iostream>
#include <cstdio>
#include "curl/curl.h"
#include "jsoncpp/json.h"

#define URL_LEN 100


size_t callBack(void *ptr, size_t size, size_t nmemb, void *stream){
    std::string *str = (std::string*)stream;  
    (*str).append((char*)ptr, size*nmemb);
    str = nullptr;  
    return size * nmemb;  
}

CURLcode curlGet(const std::string &url, std::string &response){
    CURL *curl = curl_easy_init();
    CURLcode ret;
    if(curl){
        // set params  
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); // url 
        // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false); // if want to use https  
        // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false); // set peer and host verify false  
        // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);  
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);  
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callBack);  
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);  
        // curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);  
        // curl_easy_setopt(curl, CURLOPT_HEADER, 1);  
        // curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3); // set transport and time out time  
        // curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);

        ret = curl_easy_perform(curl);
        return ret;
    }
    else{
        std::cout << "curl init failed" << "\n";
        return CURL_LAST;
    }
}

int main(int argc, char* argv[]){
    char url[URL_LEN] = {0};
    if(argc < 3){
        sprintf(url, "https://www.yiketianqi.com/free/day?appid=%s&appsecret=%s&unescape=1", "51396431", "LNY47Ewu");
    }
    else{
        sprintf(url, "https://www.yiketianqi.com/free/day?appid=%s&appsecret=%s&unescape=1", argv[1], argv[2]);
    }
    std::string strUrl(url);
    std::string strResponse;
    CURLcode ret = curlGet(strUrl, strResponse);
    std::cout << "ret is " << ret << "\n";
    Json::Reader reader;
    Json::Value value;
    if(CURLE_OK == ret && strResponse.length() > 0){
        auto ret = reader.parse(strResponse, value);
        std::cout << "the ip's city: " << value["city"].asString() << "\n"; 
        std::cout << "the city weather is " << value["wea"].asString() << "\n";
    }
    return 0;
}