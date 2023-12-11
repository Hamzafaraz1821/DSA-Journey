#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include<bits/stdc++.h>
#define cls system("cls");

class Node {
public:
    Node(std::string word, Node* previous = nullptr)
            : word(word), previous(previous), frequency(0) {}

    std::string getWord() const { return word; }
    int getFrequency() const { return frequency; }

    bool hasChild(const std::string& childWord) const {
        return children.find(childWord) != children.end();
    }

    Node* getChild(const std::string& childWord) const {
        if (!hasChild(childWord)) {
            return nullptr;
        }
        return children.at(childWord);
    }

    void addChild(std::string childWord) {
        if (!hasChild(childWord)) {
            children[childWord] = new Node(childWord, this);
        }
        children[childWord]->frequency++; // Increment frequency
    }

    std::vector<std::string> predictNextWords(int max_predictions = 4) const {
        std::vector<std::string> predictions;
        std::priority_queue<std::pair<int, std::string>> max_heap;
        for (const auto& child : children) {
            max_heap.push(std::make_pair(child.second->frequency, child.second->word));
            if (max_heap.size() > max_predictions) {
                max_heap.pop();
            }
        }
        while (!max_heap.empty()) {
            predictions.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return predictions;
    }

private:
    std::string word;
    Node* previous;
    int frequency;
    std::unordered_map<std::string, Node*> children;
};

std::vector<std::string> split(const std::string& sentence) {
    std::vector<std::string> words;
    std::string word = "";
    for (const auto& c : sentence) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);
    return words;
}

void buildTree(Node* root, std::string sentence) {
    Node* previousWord = nullptr;
    for (const auto& word : split(sentence)) {
        if (previousWord) {
            previousWord->addChild(word);
        }
        previousWord = root->getChild(word);
        if (!previousWord) {
            root->addChild(word);
            previousWord = root->getChild(word);
        }
    }
}

void printPredictions(const std::vector<std::string>& predictions) {
    std::cout << "Predictions: ";
    for (const auto& prediction : predictions) {
        std::cout << prediction << " ";
    }
    std::cout << std::endl;
}

int main(){
    Node* root = new Node("");

    // Read sentences from user input
    std::string sentence;
    while (true) {
        std::cout << "Enter a sentence (or 'STOP' to end input): ";
        std::getline(std::cin, sentence);

        if (sentence == "STOP") {
            break; // Exit the input loop
        }

        buildTree(root, sentence);
    }

    std::string word;
    while (true) {
        std::cout << "Enter a word: ";
        std::cin >> word;
        if (word == "exit") {
            break;
        }
        Node* node = root;
        for (const auto& c : word) {
            if (!node->hasChild(std::string(1, c))) {
                std::cout << "No predictions found" << std::endl;
                break;
            }
            node = node->getChild(std::string(1, c));
        }
        printPredictions(node->predictNextWords());
    }
    return 0;
}


