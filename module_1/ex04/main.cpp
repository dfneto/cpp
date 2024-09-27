
#include	<iostream>
#include	<fstream>

std::string	ft_replace(std::string content, std::string old_str, std::string new_str) {
	// Start searching from the beginning of the string
	size_t pos = 0;

	while ((pos = content.find(old_str, pos)) != std::string::npos) {

		content.erase(pos, old_str.length());
		content.insert(pos, new_str);

		// Move the position ahead to avoid infinite loop in case new_str contains old_str
		pos += new_str.length();
	}

	return (content);
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "error: missing or to many args ..." << std::endl;
		return (1);
	}
	
	// File paths
    std::string sourceFile = argv[1];
    std::string destinationFile = argv[1];
	destinationFile.append(".replace");

	// Open source file for reading
	std::ifstream inFile(sourceFile);
	if (!inFile) {
		std::cerr << "Error opening source file: " << sourceFile << std::endl;
        return 1;
	}
	// Open destination file for writing
    std::ofstream outFile(destinationFile);
    if (!outFile) {
        std::cerr << "Error opening destination file: " << destinationFile << std::endl;
        return 1;
    }

	std::string line;
	std::string content;
	while (getline(inFile, line)) {
		content += line.append(1, '\n');
	}
	outFile << ft_replace(content, argv[2], argv[3]) << std::endl;

	// Close both files
    inFile.close();
	outFile.close();

    std::cout << "File replaced successfully!" << std::endl;
	return (0);
}
