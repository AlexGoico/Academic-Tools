#include <exception>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout;

inline void cout_rep_sym(char c, int n)
{
  for (int i = 0; i < n; ++i)
    cout << c;
}

inline std::string str_bin_comp(std::string& s)
{
  std::string ret;
  ret.resize(s.size());
  for (int i = 0; i < s.size(); ++i)
    ret[i] = s[i] == '0' ? '1' : '0';

  bool found = false;
  for (int i = s.size()-1; !found && i > 0; --i)
    if (ret[i] == '0') {
      ret[i] = '1';
      found = true;
    }

  if (!found) std::fill(ret.begin(), ret.end(), '0');

  return ret;
}

int main(int argc, char* argv[])
try
{
  /* Basic exception checking */
  if (argc != 2 && argc != 3)
    throw std::length_error("Must pass ONE binary number\n");

  auto is_bin_num = [](char c){ return c != '0' && c != '1'; };
  std::string num{argv[1]};
  for (char c : num)
    if (is_bin_num(c))
      throw std::invalid_argument{"Must pass a BINARY number\n"};

  // Check for a signed or unsigned number if specified. Defaults to unsigned.
  bool signed_num = false;
  if (argc == 3) { 
    std::string num_type_option = argv[2];
    if (num_type_option == "s" || num_type_option == "signed")
      signed_num = true;
    else if (num_type_option == "u" || num_type_option == "unsigned")
      signed_num = false;
    else
      throw std::invalid_argument("Must pass signed or unsigned as third "
                                  "argument\n");
  }

  std::string signed_bin_num;
  if (signed_num) {
    signed_bin_num = str_bin_comp(num);
    std::cout << "Fliping " << num << " -> " << signed_bin_num << "\n";
  }

  /* Conversion */
  /* 
     bit position conversions are zero indexed.
     101
     ^^^
     |||
     ||------------- 2^0 * 1
     |-------------- 2^1 * 0
     --------------- 2^2 * 1
  */

  long long dec_num = 0;
  std::string bin_num = signed_num ? signed_bin_num : num;
  int bit_position = bin_num.size() - 1;  
  for (char bit : bin_num) {
    if (bit == '1') {
      long long cur_conv = pow(2, bit_position);
      dec_num += cur_conv;

      cout << std::setw(14) << std::right
           << "2^" + std::to_string(bit_position) + " * 1 = "
           << cur_conv << std::endl;
    } else {
      cout << std::setw(14) << std::right
           << "2^" + std::to_string(bit_position) + " * 0 = " << "0"
           << std::endl;
    }

    --bit_position;
  }
  cout_rep_sym('-', 80);
  cout << std::endl;
  cout << bin_num << " = ";
  if (signed_num) cout << "-";
  cout << dec_num << " in decimal.\n";
}
catch (std::invalid_argument e)
{
  std::string usage_prompt =
    "usage: bin2dec binary_number [unsigned | u | signed | signed]\n";
  cout << e.what() << usage_prompt;
  return -1;
}
catch (std::length_error e)
{
  std::string usage_prompt =
    "usage: bin2dec binary_number [unsigned | u | signed | signed]\n";
  cout << e.what() << usage_prompt;
  return -1;
}
catch (...)
{
  return -1;
}
