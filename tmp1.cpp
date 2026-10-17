#include <iostream>
#include <climits>
#define uint unsigned int

template<uint... N>
struct Stat;

template<>
struct Stat<>{
  static constexpr uint sum=0;
  static constexpr uint count=0;
  static constexpr uint min=INT_MAX;
  static constexpr uint max=0;
  static constexpr double avg=0;
};

template<uint Head,uint... Tail>
struct Stat<Head,Tail...>{
  static constexpr uint sum=Head+Stat<Tail...>::sum;
  static constexpr uint count=1+Stat<Tail...>::count;
  static constexpr uint min=Head>Stat<Tail...>::min?Stat<Tail...>::min:Head;
  static constexpr uint max=Head<Stat<Tail...>::max?Stat<Tail...>::max:Head;
  static constexpr double avg=(double)sum/count;
};

int main(){
  std::cout<<Stat<1,2,3,4,5>::avg<<std::endl;
}