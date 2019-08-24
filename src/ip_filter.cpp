#include "types.h"
#include "print_if.h"
#include "split.h"

#include <algorithm>

int main()
{
	try{
		ip_pool_int obj;
		for(std::string line; std::getline(std::cin, line);)
		{
			std::string ip;
			std::tie(std::ignore, std::ignore, ip) =
					split<std::string, std::string, std::string>(line, '\t');
			auto [el4, el3, el2, el1] = split<int,int,int,int>(ip,'.');
			obj.push_back({el1, el2,el3, el4});
		}

		sort(obj.rbegin(), obj.rend());
		print(obj);
		print_if<0>(obj,1);
		print_if<0,1>(obj, 46, 70);
		print_if(obj, [](int in){
			return in == 46;
		});

	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
}

    return 0;
}
