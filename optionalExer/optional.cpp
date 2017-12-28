#include<boost/optional.hpp>
#include<boost/algorithm/string.hpp>
#include<iostream>
#include<sstream>
#include<string>
#include<functional>

using namespace boost;

auto words = [](std::string str) -> optional<std::list<std::string>> {
    std::list<std::string> results;
    split(results, str, is_any_of(" "));
    return (results.size() == 3) ?
    optional<std::list<std::string>>(results) :
    optional<std::list<std::string>>();
};

auto to_num = [](std::string str)->optional<int> {
    int n = 0;
    std::istringstream iss(str);
    return ((iss >> n) && iss.eof()) ? optional<int>(n) : optional<int>();
};

auto binop_add = [](int a, int b) {return optional<int>(a + b);};
auto binop_sub = [](int a, int b) {return optional<int>(a - b);};
auto binop_mul = [](int a, int b) {return optional<int>(a * b);};
auto binop_div = [](int a, int b) {
    return b ? optional<int>(a / b) : optional<int>();
};

typedef std::function<optional<int>(int, int)> binop_t;
auto to_binop = [](std::string str) -> optional<binop_t> {
    if ("+" == str) return optional<binop_t>(binop_add);
    if ("-" == str) return optional<binop_t>(binop_sub);
    if ("*" == str) return optional<binop_t>(binop_mul);
    if ("/" == str) return optional<binop_t>(binop_div);
    return optional<binop_t>();
};

int main()
{
    try {
        std::string expr;
        std::getline(std::cin, expr);
        auto ws = words(expr);       if (!ws) throw ws;
        auto iter = ws->begin();
        auto a = to_num(*iter++);    if (!a)  throw a;
        auto op = to_binop(*iter++); if (!op) throw op;
        auto b = to_num(*iter++);    if (!b)  throw b;
        auto n = (*op)(*a, *b);      if (!n)  throw n;
        std::cout<<*n<<std::endl;
        return 0;
    }catch(...){
        std::cout<<"invalid"<<std::endl;
        return 1;
    }
    return 0;
}

