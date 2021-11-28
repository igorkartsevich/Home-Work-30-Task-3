#include "CMakeProject3.h"

std::string set_data(std::map<std::string, std::string>& data_map) {
	while (true) {
		std::string text;
		int pos_space;

		while (true) {
			std::getline(std::cin, text);
			pos_space = text.find(" ", 0);
			if (pos_space == -1) {
				if (text == "post" || text == "get") return text;
			}
			data_map[text.substr(0, pos_space)] = text.substr(pos_space + 1);
		}
	}
}

void make_request(std::map<std::string, std::string>& data_map, std::string type_of_request) {
	cpr::Response r;
	std::string data;
	std::map<std::string, std::string>::iterator it;

	for (it = data_map.begin(); it != data_map.end(); it++) {
		data += ("&" + it->first + "=" + it->second);
	}
	data.erase(0, 1);
	
	(type_of_request == "get") ? r = cpr::Get(cpr::Url("https://httpbin.org/get" + ("?" + data))) :
								 r = cpr::Post(cpr::Url("https://httpbin.org/post"), data.c_str());

	std::cout << r.text << std::endl;
}

int main()
{
	std::map<std::string, std::string> data_map;
	make_request(data_map, set_data(data_map));
	return 0;
}