#include <exception>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using std::cout;

char digit_to_char(const int d)
{
    char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    return digits[0] + d;
}

int main(int argc, char* argv[])
try
{
    /* Basic exception checking */
    if (argc != 2)
        throw std::length_error{"Must pass ONE integer number\n"};

    std::string dec_num_str{argv[1]};

    for (char c : dec_num_str)
        if (!isdigit(c))
            throw std::invalid_argument{"Must pass an INTEGER\n"};

    /* Conversion */
    std::string bin_num_str{};
    long long dec_num = atoll(argv[1]);
    while (dec_num) {
        char bit      = digit_to_char(dec_num % 2);
        long long res = dec_num / 2;

        cout << std::setw(20) << std::right
             << std::to_string(dec_num) + " % 2 = " + bit
             << "\t";
        bin_num_str.push_back(bit);
        cout << std::setw(30) << std::right
             << std::to_string(dec_num) + " / 2 = " + std::to_string(res)
             << std::endl;
        dec_num = res;
    }
    std::reverse(bin_num_str.begin(), bin_num_str.end());
    cout << "   ---------------------------------------------------\n" << "   "
         << dec_num_str + " = " + bin_num_str + " in binary\n";
}
catch (std::invalid_argument e)
{
    cout << e.what();
    return -1;
}
catch (std::length_error e)
{
    cout << e.what();
    return -1;
}
catch (...)
{
    return -1;
}
