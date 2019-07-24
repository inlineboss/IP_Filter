#ifndef PRINT_IF_H_
#define PRINT_IF_H_

#include "types.h"
#include <iostream>
#include <assert.h>

std::ostream& operator<< (std::ostream &out, const std::array<int,4> &item){
		out << item[0] <<'.'<< item[1] <<'.' << item[2] <<'.' << item[3] <<"\n";
	return out;
}

void print(const ip_pool_int& pool){
	for(const auto& item : pool){
		std::cout << item[0] <<"."<<item[1] <<'.' << item[2] <<'.' << item[3] <<"\n";
	}
}

void print(const std::array<int,4> &item){
		std::cout << item[0] <<"."<<item[1] <<'.' << item[2] <<'.' << item[3] <<"\n";
}

template<typename lamda_>
void print_if(const ip_pool_int& obj, const lamda_ Comp){
	for(const auto& item: obj){
		if(
			 Comp(item[0]) ||
			 Comp(item[1]) ||
			 Comp(item[2]) ||
			 Comp(item[3])
		){
			print(item);
		};
	}
}

template<int TargetPos, typename TargetItem>
bool print_if_impl(const std::array<int,4> & item, TargetItem ItemIP){
	return item[TargetPos] == ItemIP;
}

template<int TargetPos, int... PackPos,
		 typename TargetItem, typename... PackItem>
bool print_if_impl(const std::array<int,4> &item, TargetItem ItemIP, PackItem... PackItemIP){
	if(item[TargetPos] == ItemIP &&
			print_if_impl<PackPos...>(item, PackItemIP...)){
		return true;
	}
	return false;
}

template<int... Pos, typename... Item>
void print_if(const ip_pool_int& obj, Item ...item){
	for(const auto& it: obj){
		if(print_if_impl <Pos...>(it,item...)){
			print(it);
		}
	}
}




#endif /* PRINT_IF_H_ */
