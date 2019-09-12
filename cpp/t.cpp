#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <fstream>

void transpose(std::string source)
{
  std::shared_ptr<std::istream> in_str;
  if (source == "")
  {
    in_str.reset(&std::cin, [](...){});
  }
  else
  {
    in_str.reset(new std::ifstream(source.c_str()));
  }

  if (! in_str->good())
  {
    throw std::runtime_error("Couldn't read input stream.");
  }

  std::vector<std::string> ret;
  std::string line;
  uint64_t fc = 0;
  uint64_t lc = 0;
  bool first = true;
  while (std::getline(std::cin, line))
  {
    uint64_t fc_ref = 0;
    lc++;
    std::stringstream ss(line);
    std::string field;
    while(ss >> field)
    {
      ret.push_back(field);
      if (first)
      {
        fc++;
      }
      else
      {
        fc_ref++;
      }
    }
    if (first)
    {
      first = false;
    }
    else if (fc != fc_ref && fc_ref > 0)
    {
      throw std::runtime_error("Inconsistent number of columns in input.");
    }
  }
  for (uint64_t i = 0; i < fc; i++)
  {
    for (uint64_t j = 0; j < lc; j++)
    {
      uint64_t idx = j * fc + i;
      std::cout << ret[idx];
      if (j == (lc - 1))
      {
        std::cout << '\n';
      }
      else
      {
        std::cout << '\t';
      }
    }
  }
}

int main(int argc, char ** argv)
{
  try
  {
    transpose("");
  }
  catch(std::runtime_error& e)
  {
    std::cerr << "[Transpose::error] " << e.what() << '\n';
    return 1;
  }
  return 0;
}
