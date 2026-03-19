#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <filesystem>
#include <set>

std::vector<char> tokenizer(std::string path) { 
    std::ifstream data_stream(path);
    std::string datastring;
    if (data_stream.is_open()) {
        std::string word;
        while(std::getline(data_stream, word))
            datastring += word;
    } 
    else {
        std::cerr << "couldn't open file" << std::endl;
    }
    std::set<char> uchars (datastring.begin(), datastring.end());
    return std::vector<char>(uchars.begin(), uchars.end());
}

class Neuron {
public:
    double data;
    double grad;
    std::vector<Neuron*> _children;
    std::vector<double> _localgrads;
    Neuron (double data, double grad, std::vector<Neuron*> _children, std::vector<double> _localgrads) {
        this->data = data;
        this->grad = grad;
        this->_children = _children;
        this->_localgrads = _localgrads;
    }

};

int main() {
    // g++ microgpt.cpp -o microgpt && ./microgpt
    std::vector<char> tokenids = tokenizer("../input.txt");
    size_t BOS = tokenids.size();
    size_t vocab_size = tokenids.size() + 1;
    std::cout << "vocab size: " << vocab_size << std::endl;
}

