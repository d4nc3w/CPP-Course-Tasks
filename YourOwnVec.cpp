#include <iostream>
#include <vector>

struct Phone {
    virtual void getRingtone() const {
        std::cout << "ring ring\n";
    }

    virtual std::string getModel() const {
        return "Phone";
    }

    friend std::ostream &operator<<(std::ostream &os, const Phone &phone) {
        return os << phone.getModel();
    }

    friend std::ostream &operator<<(std::ostream &os, const Phone *phone) {
        return os << phone->getModel();
    }
};

struct Iphone: Phone {
    void getRingtone() const override {
        std::cout << "Bzz Bzz\n";
    }

    std::string getModel() const override {
        return "Iphone";
    }
};

struct Samsung: Phone {
    void getRingtone() const override {
        std::cout << "Wrr Wrr\n";
    }

    std::string getModel() const override {
        return "Samsung";
    }
};

namespace our {
    template <typename T>
    class Vector {
        int size_ = 0;
        T* storage_ = nullptr;

    public:
        auto pushBack(const T &newElement) -> void {
            T *newStorage = new T[size_ + 1];
            std::ranges::copy_n(storage_, size_, newStorage);
            delete[] storage_;
            newStorage[size_] = newElement;
            storage_ = newStorage;
            size_++;
        }

        auto print() const -> void {
            for (int i = 0; i < size_; ++i) {
                std::cout << storage_[i] << std::endl;
            }
        }
         ~Vector() {
            delete[] storage_;
        }
    };
}

int main() {
    //wrong
    /*  {
        auto p = new Phone();
        auto i = new Iphone();
        auto s = new Samsung();

          auto phones = std::vector<Phone>();
          phones.push_back(*p);
          phones.push_back(*i);
          phones.push_back(*s);

          for (const auto &phone : phones) {
              phone.getRingtone();
          }
    } */
    {
        auto p = new Phone();
        auto i = new Iphone();
        auto s = new Samsung();

        auto phones = our::Vector<Phone *>();
        phones.pushBack(p);
        phones.pushBack(i);
        phones.pushBack(s);
        phones.print();
    }

}