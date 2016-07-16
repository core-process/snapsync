#include "snap.hh"
#include <iostream>

using namespace std;
using namespace boost::filesystem;
using namespace snapsync;

int main(int argc, char** argv) {

  auto usage = [&argv]{
    std::cerr << "Usage: " << std::endl
      << "1) " << argv[0] << " create <directory:in> <image:out>" << std::endl
      << "2) " << argv[0] << " extract <image:in> <directory:out>" << std::endl;
  };

  if(argc < 4) {
    usage();
    return 1;
  }

  try {
    std::string command = argv[1];
    if(command == "create") {
      snap::create(path(argv[2]), path(argv[3]));
      return 0;
    }
    else
    if(command == "extract") {
      snap::extract(path(argv[2]), path(argv[3]));
      return 0;
    }
    else {
      usage();
      return 1;
    }
  }
  catch(const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return 2;
  }
  catch(...) {
    std::cerr << "Exception: unknown" << std::endl;
    return 2;
  }
}