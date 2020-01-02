#include <iostream>
#include <string>
#include <typeinfo>

int main() {

    /* Kestrel */
    auto K = [](auto x) -> auto{
        return [x](auto y) -> auto{
            return x;
        };
    };

    /* Kite */
    auto KI = [](auto x) -> auto{
        return [x](auto y) -> auto{
            return y;
        };
    };

    /* Cardinal */
    auto C = [](auto f) -> auto{
        return [f](auto a) -> auto{
            return [f, a](auto b) -> auto{
                return f(b)(a);
            };
        };
    };

    auto TRUE = K;
    auto FALSE = KI;
    auto NOT = C;

    auto AND = [](auto p) -> auto{
        return [p](auto q) -> auto{
            return p(q)(p);
        };
    };

    auto OR = [](auto p) -> auto{
        return [p](auto q) -> auto{
            return p(p)(q);
        };
    };

    auto toBool = [](auto x) -> std::string{
        return x("true")("false");
    };

    std:: cout << "True : " << toBool(TRUE) << std::endl;
    std:: cout << "False : " << toBool(FALSE) << std::endl;
    std:: cout << "NOT True : " << toBool(NOT(TRUE)) << std::endl;
    std:: cout << "NOT False : " << toBool(NOT(FALSE)) << std::endl;
    std:: cout << "AND True True : " << toBool(AND(TRUE)(TRUE)) << std::endl;
    std:: cout << "AND False True : " << toBool(AND(FALSE)(TRUE)) << std::endl;
    std:: cout << "OR False True : " << toBool(OR(FALSE)(TRUE)) << std::endl;
    std:: cout << "OR False False : " << toBool(OR(FALSE)(FALSE)) << std::endl;

    return 0;
}