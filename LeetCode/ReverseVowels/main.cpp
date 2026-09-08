#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// we can use array or stach instead of vector
// and can optimize further

// this does not work on python, strings are immutable

std::string& reverseVowel(std::string& word) {   
    std::unordered_map<char, bool> vowels = {{'a', true},
                                            {'e', true},
                                            {'i', true},
                                            {'o', true},
                                            {'u', true}};
    std::vector<char> stack;
    std::vector<int> idx;
    int i {};
    while (i < word.size()) {
        if (vowels[word[i]]) {
            stack.push_back(word[i]);
            idx.push_back(i);
        }
        i++;
    }
    
    int j {};
    while (j < idx.size()) {
        word[idx[j]] = stack.back();
        stack.pop_back();
        j++;
    }
    return word;
}

int main() {
    std::string word { "pot bat squat" };
    std::cout << "original: " << word << '\n'
            << "reversed: " << reverseVowel(word);

    return 0;
}
