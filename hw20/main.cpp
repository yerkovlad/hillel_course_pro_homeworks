#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/optional.hpp>
#include <sstream>

boost::optional<size_t> getFileSize(const std::string& path) {
    boost::filesystem::path filePath(path);
    if (boost::filesystem::exists(filePath) && boost::filesystem::is_regular_file(filePath)) {
        return boost::filesystem::file_size(filePath);
    }
    return boost::none;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " file1 file2 file3 ..." << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::string filePath = argv[i];
        boost::optional<size_t> fileSize = getFileSize(filePath);

        if (fileSize) {
            std::cout << "File: " << filePath << " exists, size: " << *fileSize << " bytes." << std::endl;
        } else {
            std::cout << "File: " << filePath << " does not exist." << std::endl;
        }
    }

    return 0;
}
