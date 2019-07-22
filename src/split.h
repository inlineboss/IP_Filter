#ifndef SPLIT_H_
#define SPLIT_H_

#include "types.h"
#include <string>
#include <tuple>

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

template <typename Args>
const Args
cut_item(const std::string &str,
					char d, std::string::size_type& start_pos) {

	auto substring =
		str.substr(	start_pos, str.find_first_of(d, start_pos) - start_pos);

	start_pos += substring.length() + 1;

	if constexpr (std::is_same <Args, int>::value){
		return std::stoi(substring);
	} else{
		return substring;
	}

}

template <typename... Args>
std::tuple<const Args...>
split(const std::string &str, char d) {
	std::string::size_type start_pos = 0;
	return std::make_tuple<const Args...>(cut_item<Args>(str,d, start_pos)...);
}




#endif /* SPLIT_H_ */
