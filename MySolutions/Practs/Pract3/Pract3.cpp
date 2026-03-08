#include <iostream>
#include <print>
//#include <optional>

class Book {
private:
    std::string title_;
    std::string author_;
    int pages_;

public:
    Book() : title_(""), author_(""), pages_(0) {
        std::print("Default constructor called");
    }

    Book(const std::string& title, const std::string& author, int pages) : title_(title), author_(title), pages_(pages) {
        std::print("Parameterized constructor called");
    }

    Book(const Book& book) {
        this->title_ = book.title_;
        this->author_ = book.author_;
        this->pages_ = book.pages_;

        std::print("Copy constructor called");
    }

    void printInfo() {
        std::print("Title: {}\nAuthor: {}\nNumber of pages{}", this->title_, this->author_, this->pages_);
    }

    ~Book() {
        std::print("Destructor called for {}", this->title_);
    }
};

class Character {
private:
    std::string name_;
    int level_;
    int health_;
    int mana_;
    int strength_;
    int agility_;

    Character(std::string& name, int level, int health, int mana, int strength, int agility) : name_(name), level_(level), health_(health), mana_(mana), strength_(strength), agility_(agility) {
        
    }

public:
    class Builder {
    public:
        std::string name_;
        int level_;
        int health_;
        int mana_;
        int strength_;
        int agility_;

        Builder(const std::string& name) : name_(name), level_(1), health_(100), mana_(50), strength_(10), agility_(10) {

        }

        Builder& setLevel(int level) {
            this->level_ = level;
            return *this;
        }

        Builder& setHealth(int health) {
            this->health_ = health;
            return *this;
        }

        Builder& setMana(int mana) {
            this->mana_ = mana;
            return *this;
        }

        Builder& setStrength(int strength) {
            this->strength_ = strength;
            return *this;
        }

        Builder& setAgility(int agility) {
            this->agility_ = agility;
            return *this;
        }

        Character build() {
            return Character(name_, level_, health_, mana_, strength_, agility_);
        }
    };

    void printStats() {
        std::print("Name: {}\nLevel: {}\nHealth: {}\nMana: {}\nStrength: {}\nAgility: {}", name_, level_, health_, mana_, strength_, agility_);
    }
};

class LinkedList {
    struct Node {
        int data;
        Node* next;

        Node() : data(0), next(nullptr) {}
        Node(int data) : data(data), next(nullptr) {}
    };

    Node* head_;

    void copyFrom(const LinkedList& source) {
        if (source.head_ == nullptr) {
            head_ = nullptr;
            return;
        }

        head_ = new Node(source.head_->data);
        Node* lastCopied = head_;
        Node* sourceNode = source.head_->next;
        while (sourceNode != nullptr) {
            lastCopied->next = new Node(sourceNode->data);
            lastCopied = lastCopied->next;
            sourceNode = sourceNode->next;
        }
    }

    void free() {
        Node* current = head_;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head_ = nullptr;
    }
public:
    LinkedList() : head_(nullptr) {}
    LinkedList(const LinkedList& list) {
        copyFrom(list);
    }

    ~LinkedList() {
        free();
    };

    LinkedList& pushFront(int data) {
        Node* newNode = new Node(data);
        newNode->next = head_;
        head_ = newNode;

        return *this;
    }

    LinkedList& pushBack(int data) {
        if (head_ == nullptr)
        {
            head_ = new Node(data);
            return *this;
        }

        Node* tail = head_;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        tail->next = new Node(data);
        return *this;
    }

    void print() {
        Node* current = head_;
        while (current != nullptr) {
            std::print("{} ", current->data);
            current = current->next;
        }
        std::print("\n");
    }
};

int main()
{
    // 1
    //Book book{};
    //Book book1{"Az", "ti", 3};
    //Book book2{book1};

    //book.printInfo();
    //book1.printInfo();
    //book2.printInfo();

    // 2
    /*Character ch = Character::Builder("Ivcho gei")
        .setAgility(12)
        .build();

    ch.printStats();*/

    // 3
    LinkedList list = LinkedList();
    list.pushBack(1).pushBack(2).pushFront(3);
    list.print();
}