#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <climits>

#define lv uint32_t
#define llv uint64_t

class BigInt{
private:
	std::vector<lv>limbs;
public:
	BigInt(const std::string&str):limbs(limbify(str)){}
	BigInt(const std::vector<lv>&limbs):limbs(limbs){}
	std::vector<lv>limbify(const std::string&str){
		std::vector<lv>limbs;
		for(char x:str){
			lv carry=lv(x-48);
			for(size_t i=0;i<limbs.size();i++){
				llv bign=llv(limbs[i])*10+carry;
				limbs[i]=lv(bign&UINT32_MAX);
				carry=lv(bign>>32);
			}
			if(carry)limbs.push_back(lv(carry));
		}
		return limbs;
	}
	std::vector<lv>operator+(const BigInt&b)const{
		const auto&limbs_a=limbs;
		const auto&limbs_b=b.limbs;
		std::vector<lv>res_limbs;
		auto it_a=limbs_a.begin();
		auto it_b=limbs_b.begin();
		llv sum=0;lv carry=0;
		while(it_a!=limbs_a.end()||it_b!=limbs_b.end()){
			lv lval=(it_a!=limbs_a.end())?*it_a:0;
			lv rval=(it_b!=limbs_b.end())?*it_b:0;
			sum=llv(lval)+rval+carry;
			res_limbs.push_back(lv(sum&0xFFFFFFFF));
			carry=lv(sum>>32);
			if(it_a!=limbs_a.end())it_a++;
			if(it_b!=limbs_b.end())it_b++;
		}
		if(carry>0)res_limbs.push_back(carry);
		return res_limbs;
	}
	std::vector<lv>operator-(const BigInt&b)const{
		const auto&limbs_a=limbs;
		const auto&limbs_b=b.limbs;
		std::vector<lv>res_limbs;
		auto it_a=limbs_a.begin();
		auto it_b=limbs_b.begin();
		llv sum=0;lv carry=0;llv borrow=0;
		while(it_a!=limbs_a.end()||it_b!=limbs_b.end()){
			lv lval=(it_a!=limbs_a.end())?*it_a:0;
			lv rval=(it_b!=limbs_b.end())?*it_b:0;
			if(lval<rval)borrow=UINT_MAX;
			sum=(llv(lval)+borrow)-(llv(rval)+carry);
			res_limbs.push_back(lv(sum&0xFFFFFFFF));
			carry=lv((llv(lval)+borrow)>>32);
			if(it_a!=limbs_a.end())it_a++;
			if(it_b!=limbs_b.end())it_b++;
		}
		return res_limbs;
	}
};



int main(int argc,char*argv[]){
	std::cout<<"HELLO WORLD"<<std::endl;
	std::string bigboynum=argv[1];
	//bigint_addition(bigboynum);
	return 0;
}