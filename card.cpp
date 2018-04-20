#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<string> vecs;

class card {
    virtual void pay(double money) = 0;
    virtual void query() = 0;
    virtual void deposit(double money) = 0;
};


class deposit_card : card {
private:
    vecs _recode;
    string _card_id;
    string _release_day;
    string _owner;
    double _money;
    double _overdraft;
public:
    virtual void pay(double money) {

    }
    virtual void query() {
        
    }
    virtual void deposit(double money) {
        
    }
    void to_other_deposit_card(double money, deposit_card card) {

    }
    void to_campus_card(double money) {

    }
    
    vecs recode() {
        return _recode;
    }
    string card_id() {
        return _card_id;
    }
    string release_day() {
        return _release_day;
    }
    string owner() {
        return _owner;
    }
    double overdraft() {
        return _overdraft;
    }
};

class campus_card : card {
private:
    vecs _recode;
    string _student_id;
    string _name;
    string _college;
    vector<deposit_card *> _bind;
    double _money;
public:
    virtual void pay(double money) {

    }
    virtual void query() {

    }
    virtual void deposit(double money) {

    }
    void bind(deposit_card * card) {
        _bind.push_back(card);
    }

    vecs recode() {
        return _recode;
    }
    string student_id() {
        return _student_id;
    }
    string name() {
        return _name;
    }
    string college() {
        return _college;
    }
    vector<deposit_card *> bind() {
        return _bind;
    }
};